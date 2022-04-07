/*
本题是一道好题。
有两个关键点：
tag1：
    对于大边，肯定可以走到其他小边，由此启发可以重新建图“从最小的边开始加”。（赛时差建图了。。。
    。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。）
tag2：
    对于每次加边，都把边权相同的同时加。
    此时边权相同的，可以按照一定次序加。
    为了方便操作，可以在原图进行一次dfs。计算出每一个点的dfs序，以便后面的操作。
    
    由于是从“小边到大边：建图，所以当边权相等时，先加谁呢？
    答：可想而知，应该是 “先” 加上面dfs序中点的dfs序较大的点开始，
    方便处理出一条边的“左集合”（这里定义为一条边，中深度较深的那个点，即dfs序大的那个）
    “右集合”：为该森林大小 - “左集合大小”
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <map>
#define For(i,x,y) for(int i=(x); i<=(y); i++)
#define fori(i,x,y) for(int i=(x); i<(y); i++)
#define rep(i,y,x) for(int i=(y); i>=(x); i--)
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define sz(a) (int)a.size()
#define ALL(x) x.begin(),x.end()
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

const db eps = 1e-8;
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

const int maxn = 1e5+10;
const int maxm = 2e5+10;
int h[maxn], e[maxm], ne[maxm], idx, w[maxm];
void add(int a, int b, int c){
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int siz[maxn], dfn[maxn], dfs_clock;
void dfs(int x, int fa){
   // siz[x] = 1;
    dfn[x] = ++dfs_clock;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        dfs(j,x);
      //  siz[x] += siz[j];
    }
}

struct EDGE{
    int a, b;
    int id;
    int w;
    int seq;
    bool operator< (const EDGE& x) const{
        if(w!=x.w)return w < x.w;
        return seq > x.seq; 
    }
} edg[maxn];
int tot;
int f[maxn];
int find(int x){
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}
int cot[maxn];
int n;
void sol(){
    cin>>n;
    mst(h,-1);
    For(i,1,n)f[i] = i, siz[i] = 1;
    For(i,1,n-1){
        int a, b, c;
        cin>>a>>b>>c;
        edg[tot++] = {a,b,i,c};
        add(a,b,c);
        add(b,a,c);
    }
    dfs(1,-1);
    fori(i,0,tot){
        int a = edg[i].a, b = edg[i].b;
        if(dfn[a] < dfn[b])swap(a,b);
        edg[i].seq = dfn[a];
    }
    sort(edg, edg+ tot);
    vector<pai>ans;
    LL mx = 0;
    fori(i,0,tot){
        int w = edg[i].w;
        int j = i;
        while(j < tot && edg[j].w == w){
            int a, b;
            a = edg[j].a;
            b = edg[j].b;
            if(dfn[a] < dfn[b]) swap(a,b);
            int A = find(a);
            cot[a] = siz[A];
            int B = find(b);
            if(A!=B){
                f[A] = B;
                siz[B] += siz[A];
            }
            j++;
        }
        fori(k,i,j){
            int a, b;
            a = edg[k].a;
            b = edg[k].b;
            if(dfn[a] < dfn[b]) swap(a,b);
            int A = find(a);
            int B = find(b); 
            LL sum = (LL)2*cot[a]*(siz[A]-cot[a]);
            ckmax(mx,sum);
            ans.pb({sum,edg[k].id});
        }
        i = j-1;
    }
    sort(ALL(ans));
    reverse(ALL(ans));
    vector<int>v;
    fori(i,0,sz(ans)){
        if(ans[i].fi == mx)v.pb(ans[i].se);
    }
    sort(ALL(v));
    cout<<mx<<' '<<sz(v)<<endl;
    for(auto x:v)cout<<x<<' ';
    cout<<endl;
}

//#define LOCAL
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
freopen("in.txt", "r", stdin);
#endif // LOCAL
    sol();
    return 0;
}