#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
#define pb push_back
#define all(a) a.begin(), a.end()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 510;
const ll INF = 0x3f3f3f3f3f3f3f3f;//LLONG_MAX/3;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

using vi =  vc<int>;

struct E{
    int to;
    ll cost;
};
template<class E, class D>
struct hungarian{
    int n, m;
    const vvc<E>&g;
    vc<D> l,r,q;
    vi to,ot,p;
    vc<char> lu, ru;
    ll sz = 0;
    D ans = 0;
    void L(int i){
        lu[i] =  1;
        for(auto e:g[i]) if(!ru[e.to]){
            D w = l[i] + r[e.to] - e.cost;
            if(q[e.to] > w){
                p[e.to] = i;
                q[e.to] = w; 
            }
        }
    }
    bool arg(){
        fill(all(p),-1);
        fill(all(q),INF);
        fill(all(lu),0);
        fill(all(ru),0);
        fori(i,0,n) if(to[i] == -1) L(i); //
        while(1){
            int x = -1;
            fori(i,0,m) if(!ru[i] && p[i] != -1 && (x == -1 || q[x] > q[i])) x = i;
            if(x == -1) return 0;
            //
            D w = q[x];
            fori(i,0,n) if(lu[i]) l[i] -= w;
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
    hungarian(int nn, int mm, const vvc<E>&gg):n(nn), m(mm), g(gg),
        l(n), r(m), q(m), to(n,-1), ot(m,-1), p(m), lu(n), ru(m){
            D mx = -INF;
            fori(i,0,n) for(auto e:g[i]) mx =  max(mx, e.cost);
            fill(all(l), mx);
            while(arg()) ans = max(ans,get());
        }
    D get(){
        D mn = *min_element(all(l));
        return accumulate(all(l), 1LL*accumulate(all(r), 1LL*mn*(-n+sz)));
    }
};
int map[N][N];
void solve(){
    int n, m;
    cin>>n>>m;
    vvc<E> g(n);
    For(i,1,m){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        map[a][b] = c;
        g[a].pb(E{b,c});
    }
    /*
     fori(i,0,n){
        fori(j,0,n)if(map[i][j]) continue;
            else g[i].pb(E{j,-INF}); 
    }
    */
    hungarian<E,ll> hg(n,n,g);
    cout<<hg.get()<<endl; 
    //printf("%lld\n", hg.get());
    auto& match = hg.ot;
    /* ll ans = 0;
    fori(i,0,n) ans += map[match[i]][i];
    cout<<ans<<endl; */
    fori(i,0,n) cout<<(match[i]+1)<<' ';
}
int main(){
    ios::sync_with_stdio(0);
    solve();
    return 0;
}