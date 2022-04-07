#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
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

const int N = 2e5+10, M = 4e5+10;
int h[N], e[M], ne[M], w[M], idx;
int val[N], e_id[M];
int dpt[N], fa[N], siz[N], son[N], seq[N], dfn[N], dfs_clock, top[N];
int sub[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, s, q;
void dfs1(int x){
    int i;
    dpt[x] = dpt[fa[x]] + 1;
    siz[x] = 1;
    for(i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x])continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[v] > siz[son[x]]) son[x] = v;
    }
}
void dfs2(int x){
    int i;
    seq[dfn[x] = ++dfs_clock] = x;
    if(son[fa[x]] == x) top[x] = top[fa[x]];
    else top[x] = x;
    //
    if(son[x])dfs2(son[x]);
    for(int i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x] || v == son[x]) continue;
        dfs2(v);
    }
    sub[x] = dfs_clock;
}
struct Node{
    int l, r;
    ll mx;
    ll lazy;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
void pushup(int u){
    tr[u].mx = max(tr[ls].mx , tr[rs].mx);
}
void build(int u, int l, int r){
    if(l==r)tr[u]={l,r,val[seq[l]]};///一个结点的值，从dfs序中取。现在的点只是dfs序，而不是原来点的权值。
    else {
        int mid = l+r>>1;
        tr[u]={l,r};
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(u);
    }
}
void pushdown(int u){
    if(tr[u].lazy){
        auto &now = tr[u], &l = tr[ls], &r = tr[rs];
        l.mx += now.lazy, r.mx += now.lazy;
        l.lazy += now.lazy, r.lazy += now.lazy;
        now.lazy = 0;   
    }
}
void mody(int u, int l, int r, int x){
    if(l <= tr[u].l &&  tr[u].r <= r){
        tr[u].mx += x;
        tr[u].lazy += x;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid)mody(ls,l,r,x);
        if(mid<r)mody(rs,l,r,x);
        pushup(u);
    }
}
ll query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r)return tr[u].mx;
    else {
        pushdown(u);
        int mid = tr[u].l+tr[u].r>>1;
        LL res = 0;
        if(l <= mid) res = max(res,query(ls,l,r));
        if(r>mid) res = max(res,query(rs,l,r));;
        return res;
    }
}
ll Tquery(int x, int y){
    ll res = 0;
    while(top[x] != top[y]){
        if(dpt[top[x]] < dpt[top[y]]) swap(x,y);
        res += query(1,dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    //if(x == y)return res; //边权才加
    if(dfn[x] < dfn[y]) swap(x,y);
    //普通点权res += query(1,dfn[y], dfn[x]);
   // return res + query(1,dfn[son[y]], dfn[x]);
    return res + query(1,dfn[y], dfn[x]);
}
void sol(){
    mst(h,-1);
    n = read();//, q = read(), s = read();
    fori(i,0,n-1){
        int a, b, c;
        a = read(), b = read();//, c = read();
        add(a,b);
    }
    dfs1(1);

    dfs2(1);

    build(1,1,n);
    int u = s, v, x;
    q = read();
    while(q--){
        int op;
        op = read();
        if(op == 2){
            v = read();
            print(query(1,dfn[v],sub[v]),'\n');
        }else {
            v = read(), x =read();
            //debug()
           // cout<<"l : "<<dfn[v]<<", r:"<<sub[v]<<endl;
            mody(1,dfn[v],sub[v],x);
            ///修改的点是dfs序列
        }
    }
}

//#define LOCAL
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
freopen("in.txt", "r", stdin);
#endif // LOCAL
    sol();
    return 0;
}
