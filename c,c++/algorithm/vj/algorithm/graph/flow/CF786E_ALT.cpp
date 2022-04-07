#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 4e5, M = 1e7;
const int INF = 1e9;
int read(){
    char ch = getchar();int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) putchar ('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10 + '0');
}
template<typename T> void print(T x,char let){
    print(x), putchar(let);
}
int h2[N], eid[M];
int vToE[N];
int e[M], ne[M], f[M], h[N], idx;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++ ;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++ ;
}
void add(int a, int b, int*h, int id){
    e[idx] = b, ne[idx] = h[a],  eid[idx] = id, h[a] = idx ++ ;
    e[idx] = a, ne[idx] = h[b],  eid[idx] = id, h[b] = idx ++ ;
}
int tot;
int S, T = N - 1;
int cur[N], q[N], d[N];
bool bfs(){
    d[T] = -1;
    For(i,0,tot) d[i] = -1;
    int hh = 0, tt = -1;
    q[++tt] = S, d[S] = 0, cur[S] = h[S];
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if(ver == T) return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}
int find(int x, int flow_limit){
    if(x == T) return flow_limit;
    int flow = 0;
    for(int &i = cur[x]; ~i && flow < flow_limit; i = ne[i]){
        int ver = e[i];
        if(d[ver] == d[x] + 1 && f[i]){
            int t = find(ver, min(f[i], flow_limit - flow));
            if(!t) d[ver] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}
int dinic(){
    int r = 0, flow;
    while(bfs()){
        //puts("ok1");
        while(flow = find(S,INF)) r += flow;
    }
    return r;
}
int n, m;
int dep[N];
int fa[N], son[N], top[N], siz[N], dfn[N], seq[N], dfs_clock;
void dfs1(int x){
    siz[x] = 1;
    dep[x] = dep[fa[x]] + 1;
    for(int i = h2[x]; ~i; i= ne[i]){
        int v = e[i];
        if(v == fa[x]) continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[son[x]] < siz[v]) son[x] = v;
    }
}
void dfs2(int x, int last){
    //print(x,'\n');
    seq[dfn[x] = ++dfs_clock] = x;
    if(last != -1)vToE[x] = eid[last];
    if(son[fa[x]] == x) top[x] = top[fa[x]];
    else top[x] = x;
    for(int i = h2[x]; ~i; i = ne[i]){
        int v = e[i];
        if(son[x] == v) {
            //printf("x: %d, son[x] = %d\n", x, son[x]);
            dfs2(son[x], i);
        }
    }
    //if(son[x]) dfs2(son[x], -1);
    for(int i = h2[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x] || v == son[x]) continue;
        dfs2(v,i);
    }
}

int leaf[N];
struct Node{
    int l, r;
    int id;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r, int fath){
    tr[u] = {l,r,++tot};
    if(fath != -1)add(fath,tr[u].id,INF);
    if(l == r){
        //结点dfs序的编号
        if(l!=1)add(tr[u].id, T, 1);
        leaf[l] = tot;
    }else {
        int mid = l + r >> 1;
        build(ls,l,mid,tr[u].id); build(rs,mid+1,r,tr[u].id);
    }
}
void link(int u, int l, int r, int citizens){
    int gardians = tr[u].id;
    if(l <= tr[u].l && tr[u].r <= r){
        add(citizens,gardians,INF);
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) link(ls,l,r,citizens);
        if(r > mid) link(rs,l,r,citizens);
    }
}
void link(int x, int y, int citizens){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x,y);
        int l = dfn[top[x]], r = dfn[x];
        link(1,l,r, citizens);
        x = fa[top[x]];
    }
    if(x == y) return ;
    if(dep[x] < dep[y]) swap(x,y);
    int l = dfn[son[y]], r = dfn[x];
    link(1,l,r,citizens);
}
void init(){
    memset(h2,-1,sizeof h2);
    memset(h,-1,sizeof h);
    n = read(); m = read();

    For(i,1,n-1){
        int a = read(), b = read();
        add(a,b,h2,i); 
    }
    dfs1(1); dfs2(1,-1);

    tot = m;
    build(1,1,n,-1);
    For(i,1,m){
        int x = read(), y = read();
        link(x,y,i);
        add(S,i,1);
    }
}
void sol(){
    init();
    int ans = dinic();
    print(ans,'\n');
    bfs();
    vector<int>ans1, ans2;
    For(i,1,m){
        if(d[i] == -1) ans1.push_back(i);
    }
    For(i,2,n){
        int ind = leaf[dfn[i]];
        int eind = vToE[i];
        if(d[ind] != -1) ans2.push_back(eind);
    }
    print(ans1.size(),' ');
    fori(i,0,ans1.size()) print(ans1[i],' ');
    puts("");
    print(ans2.size(),' ');
    fori(i,0,ans2.size()) print(ans2[i],' ');
    puts("");
}
int main(){
    sol();
    return 0;
}
