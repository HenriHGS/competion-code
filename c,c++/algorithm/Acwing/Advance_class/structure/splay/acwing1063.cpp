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

const int N = 5e5 + 10;
#define ls tr[x].ch[0]
#define rs tr[x].ch[1]
struct Node{
    int ch[2], siz, v, p, id;
    void init(int _v, int _p, int _id){
        v = _v;
        p = _p;
        id = _id;
        siz = 1;
    }
} tr[N];
int fa[N];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int root[N], idx;
void pushup(int x){
    tr[x].siz = tr[ls].siz + tr[rs].siz + 1;
}
bool get(int x){
    int y = tr[x].p;
    return x == tr[y].ch[1];
}
void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = get(x);
    tr[z].ch[get(y)] = x, tr[x].p = z;
    tr[y].ch[k] = tr[x].ch[k^1], tr[tr[x].ch[k^1]].p = y;
    tr[x].ch[k^1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}
void splay(int x, int k, int b){
    while(tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if(z != k)
            if(get(x) ^ get(y)) rotate(x);
            else rotate(y);
        rotate(x);
    }
    if(!k) root[b] = x;
}
void insert(int v, int id, int b){
    int x = root[b], p = 0;
    while(x)p = x, x = tr[x].ch[v > tr[x].v];
    x = ++idx;
    if(p) tr[p].ch[v > tr[p].v] = x;
    tr[x].init(v,p,id);
    splay(x,0,b);
    return ;
}
int get_k(int k, int b){
    int x = root[b];
    while(x){
        if(tr[ls].siz >= k) x = ls;
        else if(tr[ls].siz + 1 == k) return tr[x].id;
        else k -= tr[ls].siz + 1, x = rs;
    }
    return -1;
}
void merge(int x, int b){
    if(ls)merge(ls,b);
    if(rs)merge(rs,b);
    insert(tr[x].v, tr[x].id, b);
}
void sol(){
    int n, m;
    scanf("%d%d", &n, &m);
    For(i,1,n){
        fa[i] = root[i] = i;
        int v;
        scanf("%d", &v);
        tr[i].init(v,0,i);
        //fa[i] = i, root[i] = i;
    }
    idx = n;
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if(a != b){
            merge(root[a],b);
            fa[a] = b;
        }
    }
    scanf("%d", &m);
    while(m--){
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(*op == 'B'){
            a = find(a), b = find(b);
                if(a != b){
                merge(root[a],b);
                fa[a] = b;
            }
        }else {
            a = find(a);
            if(tr[root[a]].siz < b) puts("-1");
            else printf("%d\n", get_k(b,a));
        }
    }
}
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}