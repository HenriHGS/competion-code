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

const int maxn = 2e5 + 6;
int n, m;
int a[maxn], b[maxn];
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (LL)res*a%p;
        a = (LL)a*a%p;
        k >>= 1;
    }
    return res;
}
vector<pa> seq;
int frac[maxn], frac2[maxn],inv[maxn];
void init(int p){
    frac[0] = frac2[0] = inv[0] = 1; 
    fori(i,1,maxn) frac2[i] = (LL)frac2[i-1]*2%p;
    fori(i,1,maxn) frac[i] = (LL)frac[i-1]*i%p;
    inv[maxn - 1] = qpow(frac2[maxn-1],p-2,p);
    for(int i = maxn-2; i >= 1; i --) inv[i] = (LL)inv[i+1]*2%p;
}
void sol(){
    cin>>n;
    For(i,1,n)cin>>a[i], seq.pb({a[i],i});
    For(i,1,n)cin>>b[i], seq.pb({b[i],i});
    cin>>m;
    init(m);
    sort(ALL(seq));
    int ans = 1;
    fori(i,0,2*n){
        int l = i, r = i;
        int cnt = 0;
        //debug(seq[i].fi);
        //debug(seq[i].se);
        for(r; r < 2*n; r ++ ){
            if(r && seq[r] == seq[r-1])cnt++;
            if(seq[r].fi == seq[l].fi)continue;
            else break;
        }
        r--;
        /*
        debug(r);
        debug(l);
        */
        for(int k = 1; k <= r-l+1; k ++ ){
            if(k%2==0&&cnt){
                ans = (LL)ans*k/2%m;
                cnt--;
            }else ans = (LL)ans*k%m;
        }
        //ans = (LL)ans*frac[r-l+1]%m*inv[cnt]%m;
        //debug()
        //debug(ans);   
        i = r;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}