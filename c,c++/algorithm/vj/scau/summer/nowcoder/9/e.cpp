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
//#define LOCAL
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

const int N = 1e5+10, M = 2e5+10;
int h[N], e[M], ne[M], idx;
int out[N];
int val[N], e_id[M];
int dpt[N], fa[N], siz[N], son[N], seq[N], dfn[N], dfs_clock, top[N];
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
    out[x] = dfs_clock;
}
int find_anc(int x, int v){
    int pre = x;
    while(x!=1 && val[top[x]] <= v){
        if(fa[top[x]] > v) return top[x];
        x = fa[top[x]];
    }
    int r = dfn[x], l = dfn[top[x]], ans;
    while(l <= r){
        int mid = l + r >> 1;
        //cout<<"debug:"<<l<<' '<<r<<" val[seq[mid]]:"<<val[seq[mid]]<<endl;
        if(val[seq[mid]] <= v) ans = mid, r = mid -1;
        else l = mid + 1; 
    }
    return seq[ans];
}
int cal(int x, int v){
    int ans = 0;
 //   ans = out[x] - dfn[x] + 1;
    int end = x, cur = seq[out[x]];
    //cout<<"debug: dfn:cure, dfn[end]"<<dfn[cur]<<' '<<dfn[end]<<endl;
    while(dfn[cur]  >= dfn[end]){
        int r = dfn[cur], l = max(dfn[top[cur]],dfn[end]), res;
      //  cout<<"debug:"<<l<<' '<<r<<endl;
        if(val[seq[l]] >= v){
            while(l <= r){
                int mid = l+r>>1;
                if(val[seq[mid]] >= v) res = mid, l = mid+1;
                else r = mid - 1;
            }
         //   cout<<res<<endl;
          //  debug(res-l);
            ans += res - max(dfn[top[cur]],dfn[end]);
           // debug(seq[res]);
            if(val[seq[res]] >= v) ans++;
        } 
      //  debug(ans);
        if(cur == 1)break;
        cur = seq[dfn[top[cur]]-1];
    }
    return ans;
}
void sol(){
    mst(h,-1);
    n = read();//, q = read(), s = read();
    //vector<pa> vi;
    fori(i,0,n-1){
        int a, b;
        a = read(), b = read();
        add(a,b);add(b,a);
        //vi.pb({a,b});
    }
    dfs1(1);
    For(i,1,n)val[i] = read();
    dfs2(1);
    q = read();
    while(q--){
        int op;
        int x = read(), l = read(), r = read();
        int anc = x, ans = 0;
        if(val[x] < l || val[x] > r){
            printf("%d\n", ans);
            continue;
        }else {
            anc = find_anc(x,r);
           // debug(anc);
            print(cal(anc,l),'\n');
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
/*
4
1 2
1 3
2 4
10 8 7 6
3
1 10 10
2 6 7
3 7 10

4
1 2
1 3
2 4
10 8 7 6
3
1 10 10
2 6 7
4 6 8

4
1 2
1 3
2 4
10 8 7 6
3
1 10 10
2 6 7
4 6 6

4
1 2
1 3
2 4
10 8 7 6
3
1 10 10
2 6 7
3 6 10
*/