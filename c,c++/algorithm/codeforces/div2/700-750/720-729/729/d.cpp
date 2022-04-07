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
const int mod = 998244353;
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

const int maxn = 500 + 6;

int a[maxn], b[maxn], lx[maxn];
int dp[maxn][maxn];
//省去了一维：即第几个元素的贡献。
//dp[1][2][3]; 三维分别是：第i个，前j个元素的方案数，小于a[i]的个数 
void sol(){
    int n;
    cin>>n;
    int cnt = 0;
    For(i,1,n){
        char ch;
        cin>>ch;
        if(ch == '-')a[i] = -1;
        else {
            a[i] = 1;
            cin>>b[i];
           // lx[++cnt] = b[i];
        }
    }
    //sort(lx+1,lx+1+cnt);
    int ans = 0;
    For(i,1,n){//算每个元素的贡献
        if(a[i] == -1)continue;
        For(r,0,n)For(c,0,n)dp[r][c] = 0;
        dp[0][0] = 1;
        For(r,1,n){
            For(c,0,n){//枚举小于a[i]的个数
                int ways = dp[r-1][c];//dp[r-1][c] = 0;
                if(ways == 0) continue;
                //不选当前位置的方案数
                if(r != i) dp[r][c] = (dp[r][c] + ways)%mod;
                if(a[r] == -1) {
                     //-号 
                     //选择，删去集合T中的一个元素，求方案数
                    dp[r][max(c-1,0)] = (dp[r][max(c-1,0)] + ways)%mod;
                }else if(b[r] > b[i] || b[r] == b[i] && r > i || c == 0 && r > i ){
                    dp[r][c] = (dp[r][c] + ways)%mod;
                }else dp[r][c+1] = (dp[r][c+1] + ways)%mod;
            }
        }
        int allways = 0;
        For(c,0,n){
            if(c)allways = (allways + dp[n][c])%mod;
          //  debug(dp[n][c]);
           // dp[n][c] = 0;
        }
       // debug(allways);
        ans = (ans + ll(allways)*b[i]%mod)%mod;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}