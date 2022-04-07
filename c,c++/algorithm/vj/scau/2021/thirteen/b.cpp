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

const int maxn = 4e5 + 6;

int n;
int vis[maxn];
int x[maxn], y[maxn];
vector<int>lx, ly;
int tr[maxn];
int lowbit(int x){
    return x & -x;
}
int nn;
void add(int x, int v){
    for(int i = x; i <= nn; i += lowbit(i)) tr[i] += v;
}
int qury(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
void init(){
    cin>>n;
    For(i,1,n)cin>>x[i]>>y[i];
    For(i,1,n){
        lx.pb(x[i]);
        ly.pb(y[i]);
    }
    sort(ALL(lx));
    sort(ALL(ly));
    lx.erase(unique(ALL(lx)), lx.end());
    ly.erase(unique(ALL(ly)), ly.end());
    nn = sz(lx);
    For(i,1,n){
        x[i] = lower_bound(ALL(lx),x[i]) - lx.begin() + 1;
        y[i] = lower_bound(ALL(ly),y[i]) - ly.begin() + 1;
    }   
}
struct Point {
    int x, y;
    bool operator < (const Point & a){
        if(y != a.y) return y > a.y;
        return x < a.x;
    }
}p[maxn];
void sol(){
    init();
    For(i,1,n) p[i].x = x[i], p[i].y = y[i];
    sort(p + 1, p + 1 + n);
    LL ans = 0;
    For(i,1,n){
        int j = i;
        vector<int>tmp;
        while(j <= n && p[j].y == p[i].y){
            if(!vis[p[j].x])add(p[j].x,1), vis[p[j].x] = 1;
            tmp.pb(p[j].x);
            j++;
        }
        int pre = -1;
        for(auto x: tmp){
            int sum1 = qury(x);
            int sum2 = qury(nn) - sum1;
            sum1--;
            /*
            debug(x);
            debug(sum1);
            debug(sum2);
            */
            LL cur = (sum1+1)*(sum2+1);
            //debug(cur);
            ans += (LL)(sum1+1)*(sum2+1);
            ans -= (LL)(sum2+1)*(pre+1);
            pre = sum1;
            //debug(ans);
        }
        i = j - 1;
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}