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

const int maxn = 1e3 + 10;
int dp[maxn];
void init(){
    mst(dp,0x3f);
   // cout<<dp[0]<<endl;
    dp[1] = 0;
    fori(i,1,maxn){
        For(j,1,i){
            int c = (i/j);
            if(i + c < maxn)dp[i + c] = min(dp[i+c], dp[i] + 1);
        }
    }
}

void sol(){
    int n, k; cin>>n>>k;
    vector<int> b(n+1), c(n+1), w(n+1);
    For(i,1,n) cin>>b[i];
    For(i,1,n) cin>>c[i];
    int V = min(k, n*15);
    vector<int> f(V+2,0);
    For(i,1,n){
        w[i] = dp[b[i]];
        for(int j = V; j >= w[i]; j -- ) f[j] = max(f[j], f[j - w[i]] + c[i]);
    }
    int ans = 0;
    For(i,0,V) ans = max(ans, f[i]);
    cout<<ans<<endl;
}
//1 - 2 - 4 - 8 - 16 - 32
//1 - 2 - 3 - 5 - x

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    /* int mx = 0;
    for(int i = 1; i < maxn ; i ++) mx = max(mx,dp[i]);
    cout<<mx<<endl; */
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}