/*
根据题意：
就是根据桥 缩点后，求一遍树的直径。

读错题了，干干！！！！！
*/
#pragma comment(linker, "/STACK:102400000,102400000") //手动开大栈区

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
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

const int maxn = 3e5 + 6;
const int maxm = 6e5+10;

int n, m;
int dfn[maxn], low[maxn], dfs_clock, id[maxn];
int stk[maxn], top;
int e[maxm], ne[maxm], h[maxn], idx;
bool is_bridge[maxm];
int dcc_cnt;


void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int x, int from){
    dfn[x] = low[x] = ++dfs_clock;
    stk[++top] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            dfs(j,i);
            low[x] = min(low[x], low[j]);
            if(dfn[x] < low[j]) is_bridge[i] = is_bridge[i^1] = 1;
        }else if(i != (from^1)) low[x] = min(low[x], dfn[j]);
    }
    if(dfn[x] == low[x]){
        ++dcc_cnt;
        int y ;
        do{
            y = stk[top--];
            id[y] = dcc_cnt;
        }while(y != x);
    }
}
int h2[maxn], e2[maxm], ne2[maxm], idx2; 
void add2(int a, int b){
    e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2++; 
}

//树形dp求直径
int vis[maxn], dis[maxn];
int ans = 0;
void dfs2(int x){
    vis[x]=1;
    for(int i=h2[x];i!=-1;i=ne2[i]){
        int v = e2[i];
        if(vis[v]) continue;
        dfs2(v);
        ans = max(ans,dis[x]+dis[v]+1);
        dis[x] = max(dis[x],dis[v]+1);
    }
}

void init(){
    mst(h,-1); mst(dfn,0);
    mst(h2,-1);
    mst(id,0);
    top = dcc_cnt = dfs_clock = idx =  idx2 = 0;
}

void sol(){
    init();
    scanf("%d%d", &n, &m);
    For(i,1,m){
        int u,v ;
        scanf("%d%d", &u, &v);
        add(u,v); add(v,u);
    }
    dfs(1,-1);
    fori(i,0,idx){
        if(is_bridge[i]){
            int u = id[e[i]];
            int v = id[e[i^1]];
            add2(u,v);
        }
    }
    dfs2(1);
    cout<<ans<<endl;
}

int main() {
   // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}