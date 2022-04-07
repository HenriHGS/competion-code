/**
 * 动态开点线段树+树剖
 * 动态开线段树，记得开40倍空间。
 * LCT也可以做。。。。。
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
struct node{
    int lc, rc;
    int mx, sum;
} tr[N*100];
int sz;// node
#define ls (tr[u].lc)
#define rs (tr[u].rc)
int n, q;
int c[N], w[N];
int root[N];
int e[N*2], ne[N*2], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dpt[N],siz[N], son[N];
int fa[N], top[N], seq[N], dfn[N], dfs_clock;
void dfs1(int x){
    dpt[x] = dpt[fa[x]] + 1;
    siz[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[x]) continue;
        fa[j] = x;dfs1(j);
        siz[x] += siz[j];
        if(siz[son[x]] < siz[j]) son[x] = j;
    }
}
void dfs2(int x){
    seq[dfn[x] = ++ dfs_clock] = x;
    if(son[fa[x]] == x) top[x] = top[fa[x]];
    else top[x] = x;

    if(son[x]) dfs2(son[x]);
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[x] || j == son[x]) continue;
        dfs2(j);
    }
}
void init(){
    memset(h,-1,sizeof h);
    scanf("%d %d", &n, &q);
    For(i,1,n) scanf("%d %d", &w[i], &c[i]);
    For(i,1,n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b); add(b,a);
    }
    dfs1(1);
    dfs2(1);
}
void pushup(int u){
    tr[u].mx = max(tr[ls].mx, tr[rs].mx);
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void update(int& u, int l, int r, int x, int v){
    if(!u)u = ++sz;
    
    if(l == x && r == x) {
        tr[u].mx = tr[u].sum = v;
    }else {
        int mid = l + r>>1;
        if(x <= mid) update(ls,l,mid,x,v);
        else update(rs,mid+1,r,x,v);
        pushup(u);
    }
}
int qurysum(int&u, int l, int r, int L, int R){
    if(!u) return 0;
    if(l <= L && R <= r) return tr[u].sum;
    else {
        int res = 0;
        int mid = L + R >>1;
        if(l <= mid) res += qurysum(ls,l,r,L,mid);
        if(r > mid) res += qurysum(rs,l,r,mid+1,R);
        return res;
    }
}
int Tqurysum(int x, int y, int c){
    int res = 0;
    while(top[x] != top[y]) {
        if(dpt[top[x]] < dpt[top[y]]) swap(x,y);
        res += qurysum(root[c],dfn[top[x]], dfn[x],1,n);
        x = fa[top[x]];
    }
    if(dfn[x] > dfn[y]) swap(x,y);
    res += qurysum(root[c], dfn[x],dfn[y], 1, n);
    return res;
}
int qurymx(int&u, int l, int r, int L, int R){
    if(!u) return 0;
    if(l <= L && R <= r) return tr[u].mx;
    else {
        int res = 0;
        int mid = L + R >>1;
        if(l <= mid) res = max(res,qurymx(ls,l,r,L,mid));
        if(r > mid) res = max(res, qurymx(rs,l,r,mid+1,R)); 
        return res;
    }
}
int Tqurymx(int x, int y, int c){
    int res = 0;
    while(top[x] != top[y]){
        if(dpt[top[x]] < dpt[top[y]])swap(x,y);
        res = max(res,qurymx(root[c],dfn[top[x]], dfn[x], 1, n));
        x = fa[top[x]];
    }
    if(dfn[x] > dfn[y]) swap(x,y);
    res = max(res, qurymx(root[c],dfn[x],dfn[y],1,n));
    return res;
}
char s[10];
void solve(){
    //build();
    For(i,1,n) update(root[c[i]], 1, n, dfn[i], w[i]);
    
    while(q--){
        int x, y;
        scanf("%s %d %d",s, &x, &y);
        if(s[1] == 'C'){
            update(root[c[x]], 1, n, dfn[x],0);//del
            update(root[y],1,n,dfn[x],w[x]);
            c[x] = y;
        }else if(s[1] == 'W'){
            w[x] = y;
            update(root[c[x]], 1, n, dfn[x],w[x]);//change
        }else if(s[1] == 'M'){
            printf("%d\n", Tqurymx(x,y,c[y]));
        }else {
            printf("%d\n", Tqurysum(x,y,c[y]));
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}