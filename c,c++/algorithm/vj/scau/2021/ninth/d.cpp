#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <map>
#define For(i,x,y) for(int i=(x); i<=(y); i++)
#define fori(i,x,y) for(int i=(x); i<(y); i++)
#define rep(i,y,x) for(int i=(y); i>=(x); i--)
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define sz(a) (int)a.size()
#define ALL(x) x.begin(),x.end()
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n'
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

const db eps = 1e-8;
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

const int maxn = 5e5+10;
int dfn[maxn], low[maxn], sccno[maxn], dfs_clock, scc_cnt;
int stk[maxn], top;
//vector<int>G[maxn];
int h1[maxn], e1[maxn], idx1, ne1[maxn];
void dfs(int u){
    dfn[u] = low[u] = ++dfs_clock;
    stk[++top] = u;//S.push(u);
    for(int i = h1[u]; ~i; i = ne1[i]){//i < sz(G[u]); i ++ ){
        int v = e1[i];//G[u][i];
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else if(!sccno[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        scc_cnt ++;
        int x;
        do{
            x = stk[top--];//x = S.top(); S.pop();
            sccno[x] = scc_cnt;
        }while(x != u);
    }
}
void find_scc(int n){
    dfs_clock = scc_cnt = 0;
   // mst(sccno,0);
 //   mst(dfn,0);
    For(i,1,n)if(!dfn[i])dfs(i);
}
int val[maxn];
int h[maxn], e[maxn], ne[maxn], idx;
int ver[maxn];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int st, p, root;
int bar_i[maxn], bar[maxn];
int n, m;
int dp[maxn];
void add1(int a, int b){
    e1[idx1] = b, ne1[idx1] = h1[a], h1[a] = idx1++;
}
void dfs2(int x){
   // debug(x);
   if(dp[x]!=-1) return;
    if(x == root || bar[x]) dp[x] = ver[x];
    else dp[x] = 0;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        //debug(j);
        dfs2(j);
        if(dp[j])dp[x] = max(dp[x],dp[j]+ver[x]);
    }
    return ;
}
struct EDGE{
    int a, b;
}edg[maxn];
void sol(){
    n = read(), m =read();//scanf("%d%d", &n, &m);
    mst(h1,-1);
    mst(dp,-1);
    For(i,1,m){
        int a, b;
        a = read(), b = read();//scanf("%d%d", &a, &b);
       // G[a].pb(b);
        add1(a,b);
        edg[i] = {a,b};
    }
    For(i,1,n)val[i] = read();//scanf("%d", val+i);
    st = read(), p = read();// scanf("%d%d", &st, &p);
    For(i,1,p){
        int x;
        x = read();//scanf("%d", &x);
        bar_i[x] = 1;
    }
    find_scc(n);
    For(i,1,n){
        int id = sccno[i];
        ver[id] += val[i];
        if(st == i){
            root = id;
        }
        if(bar_i[i]){
           // debug("bar");
            //debug(i);
           // debug(id);
            bar[id] = 1;
        }
    }
    /*
    int sum = 0;
    For(i,1,scc_cnt){
        sum += ver[i];
        debug(ver[i]);
        debug(sum);

        debug("bar");
        debug(bar[i]);
    }
    */
    mst(h,-1); idx = 0;
    For(i,1,m){
        //if(G[i].empty())continue;
        int u = edg[i].a, v = edg[i].b;
        //for(auto v: G[u]){
            if(sccno[u] == sccno[v]) continue;
          //  debug(sccno[u]);
          //  debug(sccno[v]);
           // debug(u);
          //  debug(v);
            add(sccno[u], sccno[v]);
        //}
    }
  //  debug(root);
    dfs2(root);
    print(dp[root], '\n');//printf("%d\n", dp[root]);
}

//#define LOCAL
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
freopen("in.txt", "r", stdin);
#endif // LOCAL
    sol();
    return 0;
}
