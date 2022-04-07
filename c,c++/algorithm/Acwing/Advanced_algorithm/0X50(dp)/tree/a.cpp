//树形dp模板题
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

const int maxn = 6e3 + 6;

int dp[maxn][2];//选或者不选

int e[maxn<<1], ne[maxn<<1], idx, h[maxn];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int happy[maxn];
void dfs(int x){
    dp[x][1] = happy[x];
    dp[x][0] = 0;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        dfs(j);
        dp[x][1] += dp[j][0];
        //这里的转移错了
        dp[x][0] += max(dp[j][1],dp[j][0]);
    }
}
int n;
int fa[maxn];
void sol(){
    mst(h,-1); idx = 0;
    scanf("%d", &n);
    For(i,1,n) scanf("%d", happy+i);
    int root = -1;
    For(i,1,n)fa[i] = i;
    For(i,1,n-1){
        int u, v;
        scanf("%d%d", &u, &v);
        add(v,u);
        fa[u] = v;
    }
    For(i,1,n)if(fa[i] == i)root = i;
    dfs(root);
    printf("%d\n", max(dp[root][1], dp[root][0]));
}
int main() {
   // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   sol();
    return 0;
}