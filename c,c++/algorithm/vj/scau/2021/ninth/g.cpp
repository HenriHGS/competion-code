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
const int mod1 = 1e9+7;
const int mod2 = 1e9+3;
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

const int maxn = 1e6 + 6;
LL ha1[maxn], ha2[maxn];
LL p1[maxn], p2[maxn];
LL get1(int l, int r){
    return (ha1[r] - ha1[l-1]*p1[r-l+1]%mod1 + mod1)%mod1;
}
LL get2(int l, int r){
    return (ha2[r] - ha2[l-1]*p2[r-l+1]%mod2 + mod2) %mod2;
}
bool check(int l1, int r1, int l2, int r2){
    LL a1 = get1(l1,r1);
    LL b1 = get1(l2,r2);
    LL a2 = get2(l1,r1);
    LL b2 = get2(l2,r2);
    bool ok = true;
    ok &= a1 == b1;
    ok &= a2 == b2;
    return ok;
}
int n;
const  int q = 13331;
char s[maxn];
void init(){
    p1[0] = p2[0] = 1;
    For(i,1,n){
        p1[i] = (p1[i-1]*q)%mod1;
        p2[i] = (p2[i-1]*q)%mod2;
        ha1[i] = (ha1[i-1]*q%mod1 + s[i])%mod1;
        ha2[i] = (ha2[i-1]*q%mod2 + s[i])%mod2;
    }
}
int ans[maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>(s+1);
    //debug("ok");
    init();
    //debug("ok");
    For(i,1,n>>1){
        int l = 1, r = i;
        int x = 0;
        while(l<=r){
            int mid = l+r>>1;
            if(check(i-(mid-1),i+mid-1,n-i+1-(mid-1),n-i+1+mid-1))
                x = mid, l = mid+1;
            else r = mid-1;
        }
       // debug("ok");
       //debug(i-x+1);
        ans[i-x+1] = x*2-1;//,ans[i-x]);
    }
   // debug("ok");
    For(i,1,n+1>>1){
       // print(ans[i]==0?-1:ans[i], (i == n-1>>1) ? '\n': ' ');
        ans[i] = max(ans[i],ans[i-1]-2);
        if(ans[i] == 0) ans[i] = -1;
        print(ans[i],(i == n+1>>1) ? '\n': ' ');
    }
    return 0;
}