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

const int maxn = 200+10;

vector<int> e[maxn];
int n;
struct Edge{
    int a, b;
}edge[maxn];
int use[maxn], dp[maxn];
void dfs(int u, int fa, int& ans){
    for(auto v: e[u]){
        if(v == fa)continue;
        dfs(v,u,ans);
        ans = max(ans, dp[u] + dp[v] + 1);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}
int cal1(int u1, int u2){
    For(i,1,n)e[i].clear(), dp[i] = 0;
    For(i,1,n-1){
        if(use[i])continue;
        int a = edge[i].a, b = edge[i].b;
        e[a].pb(b);
        e[b].pb(a);
    }
    int res, ans1, ans2;
    ans1 = ans2 = 0;
    dfs(u1, -1, ans1), dfs(u2, -1, ans2);
    res = ans1*ans2;
    return res;
}
void sol(){
    cin>>n;
    For(i,1,n-1){
        int a, b;
        cin>>a>>b;
        edge[i] = {a,b};
    }
    int res = 0;
    For(i,1,n){
        use[i] = 1;
        int a = edge[i].a, b = edge[i].b;
        res = max(res,cal1(a,b));
        use[i] = 0;
    }
    cout<<res<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}