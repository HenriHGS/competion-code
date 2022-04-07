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

void sol(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>dp(n,vector<int>(n,0));//low
    int cur = 0;
    fori(i,0,n){
        cin>>a[i];
        fori(j,0,i) cur += a[j] > a[i];
    }
    fori(i,0,n){
        fori(j,0,n){
            if(a[j] < a[i]){
                if(j)dp[i][j] = dp[i][j-1] + 1;
                else dp[i][j] = 1;
            }else {
                if(j)dp[i][j] = dp[i][j-1];
            }
        }
    }
  //  debug(cur);
    int ans = cur, cnt = 0;
    fori(i,0,n){
        fori(j,i+1,n){
            if(a[i] < a[j])continue;
            int mi1 = dp[i][j] - dp[i][i];
            int mi2 = dp[j][j] - dp[j][i];
            int tmp = cur + 2*mi2 - 2*mi1;
            tmp++;
            if(tmp == ans) cnt++;
            if(tmp < ans){
               // debug(i), debug(j);
              //  debug(mi1);
               // debug(mi2);
                ans = tmp;
                cnt = 1;
            }
        }
    }
    cout<<ans<<' '<<cnt<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}