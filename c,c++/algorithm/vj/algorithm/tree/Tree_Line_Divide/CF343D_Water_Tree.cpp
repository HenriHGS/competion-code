#include <cstdio>
#include <cstring>
#include <cctype>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 5e5+10, M = 2*N;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-');
    if(x >= 10) print(x/10);
    putchar(x%10+'0');
}
template<typename T> void print(T x, char let){
    print(x); putchar(let);
}
int e[M], ne[M], idx, h[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], h[b] = idx ++;
}
int siz[N];
int dfn[N], seq[N], top[N], dep[N], son[N], fa[N], dfs_clock;
void dfs1(int x){
    siz[x] = 1;
    dep[x] = dep[fa[x]] + 1;
    for(int i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x]) continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[son[x]] < siz[v]) son[x] = v;
    }
}
void dfs2(int x){
    seq[dfn[x] = ++dfs_clock] = x;
    if(son[fa[x]] == x) top[x] = top[fa[x]];
    else top[x] = x;
    if(son[x]) dfs2(son[x]);
    for(int i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x] || v == son[x]) continue;
        dfs2(v);
    }
}

struct Node{
    int l, r;
    int col, lazy;
}  tr[N<<2];
#define ls u<<1
#define rs u <<1|1
void build(int u, int l, int r){
    tr[u] = {l,r,1,-1};
    if(l == r) return ;
    else {
        int mid = l + r >> 1;
        build(ls,l,mid); build(rs, mid + 1, r);
    }
}
void pushdown(int u){
    if(tr[u].lazy!= -1){
        tr[ls].lazy = tr[u].lazy, tr[rs].lazy = tr[u].lazy;
        int col = tr[u].lazy;
        if(col == 0){
            tr[ls].col = 1;
            tr[rs].col = 1;
        }else {
            tr[rs].col = 2;
            tr[ls].col = 2;
        }
        tr[u].lazy = -1;
    }
}
void pushup(int u){
    int col1 = tr[ls].col, col2 = tr[rs].col;
    if(col1 != col2) tr[u].col = 3;
    else tr[u].col = col1;
}
void mody(int u, int l, int r, int col){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].col = col+1;
        tr[u].lazy = col;
        return ;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;

        pushdown(u);
        if(l <= mid) mody(ls,l,r,col);
        if(r > mid) mody(rs,l,r,col);
       // printf("L=  %d , R = %d\n", tr[u].l, tr[u].r);
        pushup(u);
        //printf("tr[%d].col = %d\n", u, tr[u].col);
    }
}
int qury(int u, int x){
    if(tr[u].l == x && tr[u].r == x){
        return tr[u].col;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        pushdown(u);
        if(x <= mid) return qury(ls,x);
        else return qury(rs,x);
    }
}
int n, m;
int main(){
    memset(h,-1,sizeof h);
    n = read();
    For(i,1,n - 1){
        int a = read(), b = read();
        add(a,b);
    }
    dfs1(1);
    dfs2(1);
    //For(i,1,n) printf("dfn[%d] = %d\n", i, dfn[i]);
    build(1,1,n);
    m = read();
    while(m -- ){
        int op = read(), u = read();
        if(op == 3){
            print((int)(qury(1,dfn[u]) - 1), '\n');
        }else if(op == 2){
            int x = u;
            while(x){
              // printf("L=  %d , R = %d\n", dfn[top[x]], dfn[x]);
               mody(1,dfn[top[x]], dfn[x],0);
                x = fa[top[x]];
            }
            
           /*  puts("color is0:");
            for(int i = 1; i <= n; i ++ )printf("%d ",(qury(1,dfn[i]) - 1));
            puts(""); */
        }else {
            int l = dfn[u], r = dfn[u] + siz[u] - 1;
           // printf("L=  %d , R = %d\n", l, r);
            mody(1, l, r, 1);
            /* puts("color is1:");
            for(int i = 1; i <= n; i ++ )printf("%d ",(qury(1,dfn[i]) - 1));
            puts(""); */
        }
    }
    return 0;
}