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

const int N = 100000 + 6;

int n, m;
struct Node{
    int ch[2], p, v;
    //p父亲，v编号
    int siz, flag;
    //siz子树大小，flag懒惰标记
    void init(int _v, int _p){
        v = _v, p = _p;
        siz = 1;
    }
}tr[N];
int root, idx;
#define ls tr[x].ch[0]
#define rs tr[x].ch[1]
void pushup(int x){
    tr[x].siz = tr[ls].siz + tr[rs].siz + 1;
}
void pushdown(int x){
    if(tr[x].flag){
        swap(ls,rs);
        tr[ls].flag ^= 1;
        tr[rs].flag ^= 1;
        tr[x].flag = 0;
    }
}
void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].ch[1] == x; // k=0表示x是y的左儿子；k=1表示x是y的右儿子
    tr[z].ch[tr[z].ch[1] == y] = x, tr[x].p = z;
    tr[y].ch[k] = tr[x].ch[k^1], tr[tr[x].ch[k^1]].p = y;
    tr[x].ch[k^1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}
void splay(int x, int k){
    while(tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if(z != k)
            if((tr[y].ch[1] == x) ^ (tr[z].ch[1] == y)) rotate(x);
            else rotate(y);
        rotate(x);
    }
    if(!k) root = x;
}
void insert(int v){
    int u = root, p =0;
    while(u) p = u, u = tr[u].ch[v > tr[u].v];
    u = ++idx;
    if(p) tr[p].ch[v > tr[p].v] = u;
    tr[u].init(v,p);
    splay(u,0);//每次操作后，把儿子转到根
}
int get_k(int k){
    int x = root;
    while(true){
        pushdown(x);
        if(tr[ls].siz >= k) x =ls;
        else if(tr[ls].siz + 1 == k) return x;
        else k -= tr[ls].siz + 1, x = rs;
    }
    return -1;
}
void output(int x){
    pushdown(x);
    if(ls) output(ls);
    if(tr[x].v >= 1 && tr[x].v <= n) printf("%d ", tr[x].v);
    if(rs) output(rs);
}
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d%d", &n, &m);
    For(i,0,n+1)insert(i);
    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        l = get_k(l), r = get_k(r+2);
        splay(l,0), splay(r,l);
        int x = r;
        tr[ls].flag ^= 1;
    }
    output(root);
    return 0;
}