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

const int maxn = 2000 + 6;

LL c[maxn], k[maxn], cp[maxn];
int f[maxn];
pa p[maxn];
LL Get(int i, int j){
    LL dis = abs(p[i].fi - p[j].fi) + abs(p[i].se - p[j].se);
    return dis*(k[i]+k[j]);
}
int find(int x){
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}

struct Edge{
    int a, b;
    LL w;
    bool operator < (const Edge x)const{
        return w < x.w;
    }
}edge[maxn*maxn+maxn];
void sol(){
    int n;
    cin>>n;
    vector<pa>adj;
    vector<int>pow;
    For(i,1,n) f[i] = i;
    For(i,1,n)cin>>p[i].fi>>p[i].se;
    For(i,1,n)cin>>c[i];
    For(i,1,n)cin>>k[i];
    int tot = 0;
    For(i,1,n){
        edge[tot++] = {i,0,c[i]};
    }
    LL ans = 0;
    For(i,1,n){
        bool conc = false;
        For(j,i,n){
            if(i == j)continue;
            LL cop = Get(i,j);
            edge[tot++] = {i,j,cop};
        }
    }
    sort(edge,edge+tot);
    int cnt = 1;
    fori(i,0,tot){
        if(cnt == n + 1)break;
        int A = find(edge[i].a), B = find(edge[i].b);
        if(A==B)continue;
        else {
            if(A<B) swap(A,B);
            f[A] = B;
            ans += edge[i].w;
            if(edge[i].b == 0){
                pow.pb(edge[i].a);
            }else adj.pb({edge[i].a,edge[i].b});
        }
        cnt++;
    }
    cout<<ans<<endl;
    cout<<sz(pow)<<endl;
    for(auto x: pow)cout<<x<<' ';
    cout<<endl;
    cout<<sz(adj)<<endl;
    for(auto x: adj)cout<<x.fi<<' '<<x.se<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}