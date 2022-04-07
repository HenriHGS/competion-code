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
const int maxn = 100;
const int maxm = 300 + 10;

struct DSU{
    int f[maxn];
    DSU(){
        fori(i,0,maxn) f[i] = i;
    }
    int find(int x){
        if(x == f[x]) return f[x];
        return f[x] = find(f[x]);
    }
    bool merge(int a, int b){
        int fa = find(a), fb = find(b);
        if(fa == fb) return false;
        f[fa] = fb;
        return true;
    }
};

struct Edge{
    int u, v, w, id, wx;
    bool operator < (const Edge& x) const{
        return wx < x.wx;
    }
} e1[maxm];
int n, m;
int eid[maxm*maxm*3][maxn];
vector<int>T;
ll p, k, a, b, c;
ll ans = 0, q;
ll calc(ll x){
    ll res = 0;
    int ind = lower_bound(T.begin(), T.end(), x) - T.begin();
    if(ind == T.size() ) ind--;
    auto& w = eid[ind];
    For(i,1,n - 1) res += abs(w[i] - x);
    return res;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // DSU dsu;
    //fori(i,0,10) cout<<dsu.f[i];
    cin >>n>>m;
    For(i,1,m){
        int u, v, w;
        cin>>u>>v>>w;
        e1[i] = {u,v,w,i};
    }
     T.pb(0);
    For(i,1,m)For(j,1,m)if(i!=j) {
        int w1 = e1[i].w, w2 = e1[j].w;
        T.pb((w1 + w2)/2);
        T.pb((w1 + w2)/2 - 1);
        T.pb((w1 + w2)/2 + 1);
    }
    sort(T.begin(),T.end());
    T.erase(unique(T.begin(),T.end()), T.end());
    fori(i,0,T.size()){
        DSU dsu;
        int x = T[i];
        For(j,1,m) e1[j].wx = abs(e1[j].w - x);
        sort(e1 + 1, e1 + 1 + m);
        int tot = 0;
        For(j,1,m){
            int a = e1[j].u, b = e1[j].v;
            if(dsu.merge(a,b)){
                eid[i][++tot] = e1[j].w;
            }
        }
    }
    
    cin>>p>>k>>a>>b>>c;
    
    For(i,1,p){
        cin>>q;
        ans ^= calc(q);
    }
    For(i,p+1,k){
        q = (q*a%c+b%c)%c;
        ans ^= calc(q);
    }
    cout<<ans<<endl;
    return 0;
}