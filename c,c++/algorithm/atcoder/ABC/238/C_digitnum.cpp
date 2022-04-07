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

const int maxn = 100000 + 6;

//999 (999 - 100 + 1) 900
//989 
//...
//100 
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
int inv2;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin>>n;
    inv2 = qpow(2,mod-2,mod);
    ll ten = 1;
    int cnt = 0;
    vector<ll> v; v.pb(1);
    for(;ten < ll(1e18);) ten *= 10,  v.pb(ten);
    ten = v[upper_bound(ALL(v), n) - v.begin() - 1];
   // debug(ten);
    cnt = upper_bound(ALL(v), n) - v.begin() - 1;
    ll a = 0, b = 0;
    ll ans = 0;
    a = 1, b = n - ten + 1;
    ans = ans + (a + b)%mod*(b%mod)%mod*inv2%mod;
    ans %= mod;
    //debug(b);
    //debug(ans);
    ten = 1;
    ll pre = 1;
    for(int i = 0; i < cnt; i ++ ){
        ten*= 10;
        a = 1;
        b = (ten-1) - pre + 1;
        ans = ans + (a + b)%mod*(b%mod)%mod*inv2%mod;
        ans %= mod;
        pre = ten;
    }
    cout<<ans<<endl;
    return 0;
}