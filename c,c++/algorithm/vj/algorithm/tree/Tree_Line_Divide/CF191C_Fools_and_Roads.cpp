#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x :x;
}
const int N = 1e5+10, M = 2*N;

int e[M], ne[M], idx, h[N], eid[M];
int vToE[N];
void add(int a, int b, int id){
    e[idx] = b, ne[idx] = h[a], eid[idx] = id, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], eid[idx] = id, h[b] = idx++;
} 
int fa[N];
int top[N], dep[N];
int son[N], siz[N], dfn[N], dfs_clock;
int seq[N];
void dfs1(int x){
    dep[x] = dep[fa[x]] + 1;
    siz[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]){
        int ver = e[i];
        if(ver == fa[x]) continue;
        fa[ver] = x;
        dfs1(ver);
        siz[x] += siz[ver];
        if(siz[ver] > siz[son[x]]) son[x] = ver;
    }
}
void dfs2(int x, int last){
    seq[dfn[x] = ++dfs_clock] = x;

    if(last != -1)vToE[x] = eid[last];

    if(son[fa[x]] == x) top[x] = top[fa[x]];
    else top[x] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int ver = e[i];
        if(ver == son[x]){
            dfs2(son[x],i);
        }
    }
    for(int i = h[x]; ~i; i = ne[i]){
        int ver = e[i];
        if(ver == fa[x] || ver == son[x]) continue;
        dfs2(ver, i);
    }
}

struct Node{
    int l, r;
    ll sum, lazy;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r){
    tr[u] = {l,r};
    if(l == r) return ;
    else {
        int mid = l + r >> 1;
        build(ls,l, mid); build(rs, mid + 1, r);
    } 
}
void pushup(int u){
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void pushdown(int u){
    if(tr[u].lazy){
        auto& root = tr[u], &cl = tr[ls], &cr = tr[rs];
        cl.lazy += root.lazy; cr.lazy += root.lazy;
        cl.sum += root.lazy*(cl.r - cl.l + 1);
        cr.sum += root.lazy*(cr.r - cr.l + 1);
        root.lazy = 0;
    }
}
void mody(int u, int l, int r, int x){
    if(l <= tr[u].l && tr[u].r <= r) {
        tr[u].sum += (tr[u].r - tr[u].l + 1) *x;
        tr[u].lazy += x;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) mody(ls,l,r,x);
        if(r > mid) mody(rs,l,r,x);
        pushup(u);
    }
}
int qury(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r){
        return tr[u].sum;
    }else {
        pushdown(u);
        int sum = 0, mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) sum += qury(ls,l,r);
        if(r > mid) sum += qury(rs,l,r);
        return sum;
    }
}
void mody(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x,y);
        mody(1, dfn[top[x]], dfn[x] , 1);
        //printf("l: %d r:%d\n", dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(x == y) return;
    if(dep[x] < dep[y]) swap(x,y);
    //printf("l: %d r:%d\n", dfn[y] + 1, dfn[x]);
    mody(1,dfn[y] + 1, dfn[x], 1);
}

int n, k;
int ans[N];
int main(){
    memset(h,-1,sizeof h);
    n = read();
    For(i,1,n-1){
        int a = read(), b = read();
        add(a,b,i);
    }
    dfs1(1);
    dfs2(1,-1);
    /* For(i,1,n){
        printf("dfn[%d] = %d\n", i, dfn[i]);
    } */
    build(1,1,n);
    k = read();
    while(k--){
        int a = read(), b = read();
        mody(a,b);
    }
    For(i,2,n) {
        int ind = vToE[i];
        //printf("ver:%d, e:%d\n", i, ind);
        ans[ind] = qury(1,dfn[i], dfn[i]);
    }
    For(i,1,n-1) printf("%d%c",ans[i], " \n"[i==n-1]);
    return 0;
}