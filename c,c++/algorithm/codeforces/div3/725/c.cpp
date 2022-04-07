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
int lowbit(int x){ return x&-x;}
int tr[maxn], a[maxn], b[maxn], c[maxn];
int n, tot;
void add(int x, int v){
    for(int i = x; i <= tot; i += lowbit(i)) tr[i] += v;
}
int sum(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
void sol(){
    multiset<int>S;
    int l, r;
    cin>>n>>l>>r;
    For(i,1,n)cin>>a[i], c[i] = b[i] = a[i];
    sort(b+1,b+1+n);
    tot = unique(b+1,b+1+n) - (b+1);
    For(i,1,n){
        a[i] = lower_bound(b+1,b+1+tot,a[i]) - b;
        tr[i] = 0;
    }
    LL ans = 0;
    For(i,1,n){
        if(i != 1){
            int L = l-c[i];
            L = lower_bound(b+1,b+1+tot,L) - b;
            L--;
            //int tmp = i - 1 - sum(L);
            int R = r-c[i];
            R = upper_bound(b+1,b+1+tot,R) - b;
            R = min(R - 1,tot);
           // debug(L);
          //  debug(R);
            int add1 = sum(L);
            int add2 = sum(R);
          //  debug(add1);
           // debug(add2);
            if(add2>=add1)ans += add2 - add1;
        }
        add(a[i],1);
    }
    cout<<ans<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}