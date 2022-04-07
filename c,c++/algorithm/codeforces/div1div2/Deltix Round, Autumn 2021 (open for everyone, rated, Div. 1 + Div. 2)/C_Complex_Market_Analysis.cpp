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

const int maxn = 1e6 + 5;

int primes[maxn + 1], tot;
int st[maxn + 1];
void init(){
    For(i,1,maxn) st[i] = i;
    For(i,2,maxn){
        if(st[i] == i) primes[tot++] = i;
        for(int j = 0; primes[j] <= maxn / i; j ++ ){
            st[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}

int a[maxn];
ll ans = 0;
int pre[maxn], suf[maxn];
void sol(){
    int n, e; cin>>n>>e;
    For(i,1,n) cin>>a[i];
    ans = 0;
    for(int k = n; k >= n - e + 1; k -- ){
        for(int i = k; i >= 1; i -= e){
            int x = a[i];
            if(st[x] == x){
                suf[i] = 0;
                if(x == 1) suf[i] = 1;
            }else suf[i] = 0;
            if(i + e <= n && a[i+e] == 1) suf[i] += suf[i + e];
        }
    }
    For(k,1,e){
        for(int i = k; i <= n; i += e){
            int x = a[i];
            if(st[x] == x){
                pre[i] = 0;
                if(x == 1) pre[i] = 1;
            } else pre[i] = 0;
            if(i - e >= 1 && a[i - e] == 1) pre[i] += pre[i - e];
            if(st[x] == x && x > 1 && (pre[i] || suf[i]))
            ans += 1ll*(pre[i] + 1) *(1 + suf[i]) - 1;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}