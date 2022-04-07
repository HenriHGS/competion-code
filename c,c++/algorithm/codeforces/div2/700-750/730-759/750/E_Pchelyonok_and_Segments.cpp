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
int a[maxn];
int n;
ll pre[maxn];
// bool check(int k){
//     bool ok = false;
//     int kk = k, cnt = 0;
//     for(int i = 1; i <= n; i ++, kk = k, cnt = 0){
//         int l = i, r;
// //        if(r > n) break;
//        // cnt = 1;
//      //   if(cnt == k) return true;
//         ll pre_sum = 0;
//         //l = r + 1; kk -- ;
//         while(1){
//             r = l + kk - 1;
//             if(r > n) break;
//             if(pre[r] - pre[l-1] <= pre_sum) l ++;
//             else {
//                 cnt++;
//                 /*
//                 if(k == 2){
//                     cout<<"debug:"<<cnt<<endl;
//                     cout<<"l:"<<l<<", r:"<<r<<endl;
//                     if(cnt == 2) cout<<"i:"<<i<<endl;
//                 }
//                 */pre_sum = pre[r] - pre[l - 1];
//                 l = r + 1;
//                 kk--;
                
                
//                 if(cnt == k) return true;
//             }
//         }
//     }
//     return false;
// }
void sol(){
    n = read();
    For(i,1,n) a[i] = read();
    For(i,1,n) pre[i] = pre[i-1] + a[i];
   // int l = 1, r = n, ans = 1;
    /* while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    } */
    int ans = 0;
    int mn = sqrt(n);
    while((mn + 1) * (mn + 2)/2 <= n) mn++;
    vector<vector<ll>> dp(n+20, vector<ll>(mn + 10, 0));
    for(int i =  n; i >= 1; i -- ) {
        int len = sqrt(n - i + 1);
        int k = len;
        while(i + (k + 1)*(k+2)/2 - 1<= n) k++;
      //  debug(i);
        for(k; k >= 1; k-- ){
           // debug(k);
            //cout<<k<<' '<<i<<endl;
            dp[i][k] = dp[i+1][k];
            ll  cur = pre[i + k - 1] - pre[i - 1];
            if(cur < dp[i+k][k - 1] || k == 1)
                dp[i][k] = max(dp[i][k], cur);
            if(dp[i][k]) ans = max(ans,k);
        }
    }
  //  debug(ans);
    print(ans,'\n');
}

int main() {
  //  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = read();
    while(tt--) sol();
    return 0;
}