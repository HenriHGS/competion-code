#include <iostream>
#include <cstdio>
#include <vector>
#include <assert.h>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define db double
//#define endl '\n'
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 3e5 + 10;

vector<int> G[maxn];
int dfn[maxn], low[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int>S;

void tarjan(int u){
    dfn[u] = low[u] = ++dfs_clock;
    S.push(u);
    cout<<u<<endl;//debug(u);
    //assert(false);
    for(int i = 0; i < G[u].size(); i ++ ){
        int v = G[u][i];
        //cout<<v<<endl;
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if(!sccno[v]) ckmin(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        scc_cnt++;
        int x;
//        cout<<"u = "<<u<<endl;
        do{
            x = S.top(); S.pop();
            /*
            cout<<x<<endl;
            if(x != u)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            */
            sccno[x] = scc_cnt;
            //if(x == u) break;
            //cout<<(bool)(x!=u)<<endl;
            //bool fl = x!=u;
        }while(x != u);
       // cout<<endl;
    }
}
int n, m;
int val[maxn];
void find_scc(int n){
    dfs_clock = scc_cnt = 0;
    mst(sccno,0);
    mst(dfn,0);
    for(int i = 1; i <= n; i ++ ){
        if(!dfn[i])tarjan(i);
        //cout<<"ok"<<i<<endl;
    }
}
struct Edge{
    int a, b;
};
vector<pa> scc_val[maxn];
int deg[maxn];
void sol(){
    cin>>n;
    For(i,1,n)cin>>val[i], G[i].clear();
    cin>>m;
    vector<Edge>e;
    For(i,1,m){
        int u, v;
        cin>>u>>v;
        e.pb({u,v});
        G[u].pb(v);
    }
    find_scc(n);
   // cout<<"ok"<<endl;
   /*
    fori(i,0,m){
        int u = e[i].a, v = e[i].b;
        int a = sccno[u], b = sccno[v];
        if(a != b){
            deg[a]++;
            deg[b]++;
        }
        //scc_val[a].insert({val[u],u});
        scc_val[a].pb({val[u],u});
        //scc_val[b].insert({val[v],v});
        scc_val[b].pb({val[v],v});
    }
    LL ans1 = 0, ans2 = 1;
    For(i,1,scc_cnt){
        sort(ALL(scc_val[i]));
        scc_val[i].erase(unique(ALL(scc_val[i])), scc_val[i].end());
        if(deg[i] == 1){
            auto va = scc_val[i][0];
            int it1 = lower_bound(ALL(scc_val[i]), va) - scc_val[i].begin();
            va.second = inf;
            int it2 = upper_bound(ALL(scc_val[i]), va) - scc_val[i].begin();
            //ans1 +=  it2 - it1;
            ans1 += scc_val[i][0].first;
            ans2 = ans2 * (it2-it1) % mod;
        }
    }
    */
   LL ans1 = 0, ans2 = 0;
    cout<<ans1<<' '<<ans2<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}
