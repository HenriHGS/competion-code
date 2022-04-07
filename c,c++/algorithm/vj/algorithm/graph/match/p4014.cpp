#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <climits>
#include <vector>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;
//const int INF = INT_MAX/2-100;
typedef long long ll;
const ll INF = LLONG_MAX/3;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
using vi = vc<int>;

struct E{
    int to;
    ll cost;
};

template<class E, class D>
struct hungarian{
    int n, m;
    const vvc<E>& g;
    vc<D> l,r,q;
    vi to,ot,p;
    vc<char> lu,ru;
    int sz = 0;
    D ans = -INF;
    void L(int i){
        lu[i] = 1;
        for(auto e: g[i]) if(!ru[e.to]){
            D w = l[i] + r[e.to] - e.cost;
            if(w < q[e.to]){
                q[e.to] = w;
                p[e.to] = i;
            } 
        }
    }
    bool arg(){
        fill(all(p),-1);
        fill(all(q),INF);
        fill(all(lu),0);
        fill(all(ru),0);
        fori(i,0,n) if(to[i] == -1) L(i);
        while(1){
            int x = -1;
            fori(i,0,m) if(!ru[i] && p[i] != -1 && (x == -1 || q[x] > q[i])) x = i;
            if(x == -1) return 0;
            D w = q[x];
            fori(i,0,n) if(lu[i])l[i] -= w;
            fori(i,0,m) if(ru[i]) r[i] += w; else if(p[i] != -1) q[i] -= w;
            if(ot[x] == -1){
                while(x != -1){
                    ot[x] = p[x];
                    swap(to[ot[x]], x);
                }
                sz++;
                return 1;
            } 
            ru[x] = 1;
            L(ot[x]);
        }
    }
    hungarian(int nn, int mm, const vvc<E>&gg):n(nn), m(mm),g(gg),
        l(n),r(m),q(m),to(n,-1),ot(m,-1),p(m),lu(n),ru(m){
            D mx = -INF;
            ans = -INF;
            fori(i,0,n)for(auto e:g[i]) mx = max(mx,e.cost);
            fill(all(l),mx);
            while(arg()) ans = max(ans,get());
        }
    D get(){
        D nm = *min_element(all(l));
        return accumulate(all(l), accumulate(all(r), (sz - n)*nm));
    }
};

int n;
void solve(){
    scanf("%d", &n);
    vvc<E> g(n);
    fori(i,0,n)fori(j,0,n){
        int c;
        scanf("%d", &c);
        g[i].pb(E{j,c});
    }
    ll ans2 = hungarian<E,ll>(n,n,g).ans;
     //printf("%lld\n", hungarian<E,ll>(n,n,g).get());
     fori(i,0,n)fori(j,0,n){
       // int c;
     //   scanf("%d", &c);
        //g[i].pb(E{j,c});
        g[i][j].cost = g[i][j].cost*(-1);
    }
    ll ans1 = hungarian<E,ll>(n,n,g).ans;
     printf("%lld\n%lld\n",-ans1,ans2);
}
int main(){
    solve();
    return 0;
}