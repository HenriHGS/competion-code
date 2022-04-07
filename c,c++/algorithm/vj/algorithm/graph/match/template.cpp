#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
using namespace std;
typedef long long ll;
//#define int ll
#define pb push_back
#define dob(x) (x)*(x)
#define rep(i,n) for(int i = 0; i < n; i ++ )
#define all(x) x.begin(),x.end()
const ll infLL = LLONG_MAX/3;
const ll inf = infLL;
//const int inf=INT_MAX/2-100;

template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

using vi = vc<ll>;
using vi = vc<ll>;

template<class T>
T sq(const T&t){
    return t*t;
}

template<class E, class D>
struct hungarian{
    ll n,m;
    const vvc<E>&g;
    vc<D> l,r,q;
    //l,r:顶标， q：slack数组
    vi to,ot,p;
    vc<char> lu, ru;
    ll sz = 0;
    D ans = 0;
    //每次增广后，需要用$O(n^2)$计算所有点的初始slack
    void L(int i){
        lu[i] = 1;
        for(auto e:g[i]) if(!ru[e.to]){
            D w = l[i] + r[e.to] - e.cost;
            if(q[e.to] > w){
                p[e.to] = i;
                q[e.to] = w;
            }
        }
    }
    bool arg(){
        fill(all(p), -1);
        fill(all(q),inf);
        fill(all(lu),0);
        fill(all(ru),0);
        int turn = 0;
        rep(i,n) if(to[i] == -1) L(i);//第一次初始化所有松弛量，需要O（n^2）
        while(1){
            turn++;
            debug(turn);
            ll x = -1;
            rep(i,m) if(!ru[i] && p[i] != -1 && (x == -1 || q[x] > q[i])) x = i;
            if(x == -1) return 0;
            //没有增广路 修改顶标
            D w = q[x];
            cout<<"ding biao pre: "<<endl;
            cout<<"L:";rep(i,n) cout<<l[i]<<' '; cout<<endl;
            //puts("");
            cout<<"R:";rep(i,m) cout<<r[i]<<' '; cout<<endl;
            //puts("");
            rep(i,n) if(lu[i]) l[i] -= w;// S

            rep(i,m) if(ru[i]) r[i] += w; else if(p[i] != -1) q[i] -=w;
            //T T':对于T'中的边 - 去delta可能提供相等边
            if(ot[x] == -1){
                //x 是未盖点，则找到增广路
                //找到新的未匹配点 更新匹配点 p 数组记录着“非匹配边”上与之相连的点
                while(x!=-1){
                    ot[x] = p[x];
                    swap(to[ot[x]],x);
                }
                sz++;
                return 1;
            }
            ru[x] = 1;//
            L(ot[x]);
        }
    }
    hungarian(ll nn, ll mm, const vvc<E>&gg):n(nn), m(mm), g(gg),
        l(n),r(m),q(m),to(n,-1),ot(m,-1),p(m),lu(n),ru(m){
            D mx = -inf;
            rep(i,n) for(auto e:g[i]) mx = max(mx,e.cost);
            fill(all(l),mx);
            int cnt = 0;
            while(arg()){
                ans = max(ans,get());
                cnt++;
                debug(cnt);
                cout<<endl;// puts("");
            } 
        }
    D get(){
        D mn = *min_element(all(l));
        return accumulate(all(l), accumulate(all(r), (-n+sz)*mn));
    }
};
struct E{
    ll to,cost;
};
void solve(){
    ll n, m; cin>>n>>m;
    vvc<E> g(n);
    rep(i,m){
        ll a, b, c;
        cin>>a>>b>>c;
        a--,b--;
       // cin>>a>>b>>c;
        g[a].pb(E{b,c});
    }
    /*
    rep(i,n){
        ll x, y,z,v; cin>>x>>y>>z>>v;
        rep(t,n){
            g[i].pb(E{t,-(dob(x) + dob(y) + dob(z+t*v))});
        }
    }
    */
    printf("%lld\n", hungarian<E,ll>(n,n,g).get());
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}