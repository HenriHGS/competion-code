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
//#define endl '\n' 
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

vector<LL> d[2];
const LL limit = 1e18;
int p[20], n;
void dfs(LL x, int id, vector<LL>& d){
    d.pb(x);
    for(int i = id; i <= n; i +=2 ){
        if(x <= limit/p[i]){
            dfs(x*p[i],i, d);
        }else break;
    }
}

LL k;
void sol(){
    cin>>n;
    For(i,1,n)cin>>p[i];
    cin>>k;
    dfs(1,1,d[0]);
    dfs(1,2,d[1]);
    /*
    for(int i = 1; i <= n; i += 2){
        dfs(p[i],i,d[1]);
    }
    */
    fori(i,0,2)sort(ALL(d[i]));
    LL ans = 0;
    LL l = 1, r = limit;
    while(l <= r){
        LL mid = l+r>>1;
       // debug(l);
       // debug(r);
        LL cnt = 0;
        fori(i,0,sz(d[1])){
            cnt += upper_bound(ALL(d[0]),mid/d[1][i]) - d[0].begin();
            if(cnt >= k) break;
        }
        if(cnt >= k) r = mid-1, ans = mid;
        else l = mid+1;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}