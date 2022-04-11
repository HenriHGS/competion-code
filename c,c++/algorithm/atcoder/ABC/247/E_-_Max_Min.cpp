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

const int maxn = 2e5 + 10;
const int N = 2e5+10;
int stk[maxn], top;
int a[maxn], n, x, y;
const int MX_LOG = 21;
int logn[maxn+1];
int mx[N][MX_LOG];
int mi[N][MX_LOG];
/* void init(){
    logn[1] = 0, logn[2] = 1;
    fori(i,3,N){
        logn[i] = logn[i/2] + 1;
    }
 For(j,1,MX_LOG){
     for(int i = 1; i + (1<<j) - 1<= n; i++){
         mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
         mi[i][j] = min(mi[i][j-1], mi[i + (1<<(j-1))][j-1]);
     }
 }
}
int check1(int l, int r){
    int mxa, mib;
    int s = logn[r - l + 1];
    mxa = max(mx[l][s], mx[r - (1<<s)+1][s]);
    return mxa;
    mib = min(mi[l][s],mi[r - (1<<s)+1][s]);
} */
void init(){
    logn[1] = 0, logn[2] = 1;
    for(int i = 2; i < maxn; i ++ ) logn[i] = logn[i/2] + 1;
    for(int j = 1; j < MX_LOG; j ++ ) 
        for(int i = 1; i + (1<<j) - 1 <= n; i ++ ) {
            mi[i][j] = min(mi[i][j-1], mi[i + (1<<(j-1))][j-1]);
            mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
        }
}
int check1(int l, int r){
    int s = logn[r - l + 1];
    return max(mx[l][s], mx[r - (1<<s) + 1][s]);
}
int check2(int l, int r){
    int mxa, mib;
    int s = logn[r - l + 1];
    // mxa = max(mx[l][s], mx[r - (1<<s)+1][s]);
    // return mxa;
    mib = min(mi[l][s],mi[r - (1<<s)+1][s]);
    return mib;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>x>>y;
    for(int i = 1; i <= n; i ++ ) cin>>mx[i][0], mi[i][0] = mx[i][0];
    init();
    ll ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        int l1 = i, r1 = n;
        while(l1 < r1) {
            int mid = l1 + r1 >> 1;
            if(check1(i,mid) >= x) r1 = mid;
            else l1 = mid + 1;   
            //ok
        }
        int l2 = i, r2 = n;
        while(l2 < r2) {
            int mid = l2 + r2 + 1>> 1;
            if(check1(i,mid) <= x) l2 = mid;
            else r2 = mid - 1;   
            //
        }
        // printf("i:%d, l1:%d, l2 %d,",i, l1, l2);
        // cout<<l1<<l2<<endl;
        if(check1(i,l2) != x) {
        //    putchar('\n');
            continue;
        }

        int l3 = i, r3 = n;
        while(l3 < r3) {
            int mid = l3 +r3>>1;
            if(check2(i,mid) <= y) r3 = mid;
            else l3 = mid + 1;
        }
        int l4 = i, r4 = n;
        while(l4 < r4) {
            int mid = l4 + r4 + 1>> 1;
            if(check2(i,mid) >= y) l4 = mid;
            else r4 = mid - 1;   
        }
        // printf("l3:%d, l4 %d\n",l3, l4);
        if(check2(i,l3) != y) continue;
        int l = max(l1,l3), r = min(r2,r4);
        if(l <= r) ans += r - l + 1;
    }
    cout<<ans<<endl;
    return 0;
}