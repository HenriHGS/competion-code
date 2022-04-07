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

const int maxn = 100000 + 6;

void table(){
    LL limit = 1e18;
    LL sum = 0;
    LL i = 1;
    int cnt = 0;
    for(i = 1; sum <= limit; i *= 2 ){
        sum += i;
        cnt++;
    }
    debug(sum);
    debug(cnt);
    debug(i);
//    cout<<sum<<' '<<i<<endl;
}
/*
sum: 1152921504606846975
cnt: 60
i: 1152921504606846976
*/
int tot = 0;
LL qpow(LL a, LL k, LL p){
    LL res = 1;
    a %= p;
    while(k){
        if(k&1) res = (LL)res*a%p;
        a = (LL)a*a%p;
        k>>=1;
    }
    return res;
}
LL getSum(LL r){
    LL l = 1;
    LL sum = 0;
    int now = 1;
    LL odd = 1, even = 2;
    LL st_odd, st_even;
    st_odd = 1;
    st_even = 2;
    LL res = 0;
    for(LL i = 1; i <= r;){
        if(now&1){
            LL mi = min(odd, r - i+1);
            LL tmp  = (st_odd%mod + (mi-1)%mod*2%mod)%mod;
             tmp = (st_odd%mod + tmp)%mod*(mi%mod)%mod;
         //   debug(tmp);
            res = (res + tmp)%mod;
            st_odd += mi*2; 
            i += mi;
            odd *= 4;
        }else {
            LL mi = min(even, r - i+1);
            LL tmp =  (st_even + (mi-1)%mod*2%mod)%mod;
            tmp = (st_even + tmp)%mod*(mi%mod)%mod;
          //  debug(mi);
           // debug(tmp);
            res = (res + tmp)%mod;
            i += mi;
            st_even += mi*2;
            even *= 4;
        }
        now ^= 1;
    }
    return res;
}
void sol(){
    LL l, r;
    cin>>l>>r;
   // init(r);
    LL ans = (getSum(r) - getSum(l-1) + mod) % mod;
    ans = ans*qpow(2,mod-2,mod)%mod;
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // table();
    sol();
    return 0;
}