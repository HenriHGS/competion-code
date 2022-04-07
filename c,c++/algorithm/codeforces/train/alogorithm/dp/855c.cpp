#include <iostream>
#include <cstdio>
#include <vector>
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
#define eb emplace_back
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

const int maxn = 100000 + 6;
vector<int> e[maxn];
int tmp[maxn][12][3];
int dp[maxn][12][3];
int n, m, k, x;
void upd(int &x, int y){
    x = (x + y) % mod;
}
void dfs(int u, int fa){
    dp[u][0][0] = k - 1;
    dp[u][1][1] = 1;
    dp[u][0][2] = m - k;
    for(auto v: e[u]){
        if(v != fa){
            dfs(v,u);
            For(j,0,x+1)fori(k,0,3) tmp[u][j][k] = 0;
            For(j,0,x)For(k,0,j){
                //0表示u小于k
                upd(tmp[u][j][0], (LL)dp[u][j-k][0] * ((LL)dp[v][k][1] + dp[v][k][0] + dp[v][k][2]) % mod);
                //1表示等于k
                upd(tmp[u][j][1], (LL)dp[u][j-k][1] * (dp[v][k][0]) % mod);
                //2表示大于k
                upd(tmp[u][j][2], (LL)dp[u][j-k][2] * (dp[v][k][0] + dp[v][k][2]) % mod);
            }
            For(j,0,x+1)fori(k,0,3)dp[u][j][k] = tmp[u][j][k];
        }
    }
    return;
};
void sol(){
   // int n, m, k, x;
    scanf("%d%d", &n, &m);
    //auto add(int a, int b)
    For(i,1,n-1){
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].pb(b);  
        e[b].pb(a);  
    }
    scanf("%d%d", &k, &x);
    dfs(1,-1);
    int ans = 0;
    For(j,0,x)fori(k,0,3) upd(ans,dp[1][j][k]);
    printf("%d\n", ans);
}

int main() {
   // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}