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
const int maxm = 2e5+10;
int h[maxn], e[maxm], w[maxm], ne[maxm], idx;
int n;
int fa[maxn], siz[maxn];
ll ans;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int mx, id1;
int dfs1(int x, int pref){
    siz[x] = 1;
    fa[x] = pref;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[x]) continue;
        siz[x] += dfs1(j,x);
    }
    return siz[x];
}
struct edge{
    int w, a, b;
    bool operator < (const edge& x)const{
        return w<x.w;
    }
} ee[maxm];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void sol(){
    cin>>n;
    For(i,1,n-1){
        int a, b, c;
        cin>>a>>b>>c;
        //add(a,b,c);
        //add(b,a,c);
        ee[i] = {c,a,b};
    }
    For(i,1,n) fa[i] = i, siz[i] = 1;
    int m = n - 1;
    sort(ee+1,ee+1+m);
    For(i,1,m){
        int a = ee[i].a, b = ee[i].b;
        a = find(a), b = find(b);
        //ll tot = siz[a] + siz[b];
        fa[a] = b;
        ans += (ll)siz[a]*siz[b]*ee[i].w;
        siz[b] += siz[a];
    }
    cout<<ans<<endl;
    //dfs1(1, -1);
    //dfs2(id1);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}