#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int mod = 998244353;
typedef long long ll;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return  f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x /10);
    putchar(x%10 + '0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
const int N = 1e5 + 5e4 + 10, M = 2*N;
int e[M], ne[M], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dep[N];
int top[N], son[N], siz[N], fa[N], dfn[N], seq[N], dfs_clock;

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
        if(e[i] == fa[x] || e[i] == son[x]) continue;
        dfs2(e[i]);
    }
}
struct Node{
    int l, r;
    int sum, lazy;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r){
    tr[u] = {l,r,0,-1};
    if(l == r) return ;
    else {
        int mid = l + r >> 1;
        build(ls,l,mid); build(rs,mid+1,r);
    }
}
void pushdown(int u){
    if(tr[u].lazy != -1){
        int lazy = tr[u].lazy;
        if(tr[ls].lazy != -1) tr[ls].lazy += lazy, tr[ls].lazy %= mod;
        else tr[ls].lazy = lazy;
        if(tr[rs].lazy != -1) tr[rs].lazy += lazy, tr[rs].lazy %= mod;
        else tr[rs].lazy = lazy;
        
        if(tr[ls].l == tr[ls].r) tr[ls].sum += lazy, tr[ls].sum %= mod;
        if(tr[rs].l == tr[rs].r) tr[rs].sum += lazy, tr[rs].sum %= mod;
        tr[u].lazy = -1;
    }
}
void mody(int u, int l, int r, int val){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].sum += 1ll*(tr[u].r - tr[u].l + 1) * val % mod;
        tr[u].sum %= mod; 
        //printf("mody tree:  l:%d, r: %d\n", tr[u].l, tr[u].r);
        //printf("val: %d, mody val: %d\n", val, 1ll*(tr[u].r - tr[u].l + 1) * val % mod);
        if(tr[u].lazy == -1) tr[u].lazy = val;
        else tr[u].lazy += val, tr[u].lazy %= mod;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) mody(ls,l,r,val);
        if(r > mid) mody(rs,l,r,val);
    }
}
int qury(int u, int x){
    if(tr[u].l == x && tr[u].r == x){
        return tr[u].sum;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        pushdown(u);
        if(x <= mid) return qury(ls,x);
        else return qury(rs,x);
    }
}
int n, m;
int lazy[N];
int invn;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
int qury(int x){
    int anc = x;
    int res = 0;
    while(fa[top[x]]){
        int f = fa[top[x]];
        int v = top[x];
        res += 1ll*lazy[f]*(n-siz[v])%mod;
        res %= mod;
        x = f;
    }
    return res;
}
void sol(){
    memset(h,-1,sizeof h);
    n = read(), m = read(); invn = qpow(n,mod-2,mod);
    For(i,1,n-1){
        int a = read(), b = read();
        add(a,b); add(b,a);
    }
    dfs1(1);dfs2(1);
    build(1,1,n);
    while(m -- ){
        int op = read();
        if(op == 1){
            int v = read(), d = read();
            int l, r;
            //u out of the trees of V
            int val1 = 1ll*siz[v]*d%mod;
            l = dfn[v], r = l + siz[v] - 1;
            if(1 <= l - 1) mody(1,1, l-1, val1);
            if(r + 1 <= n) mody(1,r+1,n, val1);
            //u in th trees of v
            //son[v] update, other lazy
            lazy[v] += d; lazy[v] %= mod;
            val1 = 1ll*(n)*d%mod;
            mody(1,dfn[v],dfn[v],val1);
            if(!son[v]) continue;
            val1 = 1ll*(n - siz[son[v]])*d%mod;
            //printf("u in th trees of v,  val1:%d\n", val1);
            l = dfn[son[v]], r = l + siz[son[v]] - 1;
            //printf("l:%d, r: %d\n", l, r);
            mody(1,l,r,val1);
            // v == u
            
            

            //puts("");
        }else {
            int v = read();
            int ans1 = qury(1,dfn[v]);
            int ans2 = qury(v);
            //printf("i:%d\n", v);    
            //printf("ans1: %d, ans2 = %d\n", ans1, ans2);

            int ans = 1ll*(ans1+ans2)%mod*invn%mod;
            print( ans,'\n');
        }
    }
}
int main(){
    sol();
    return 0;
}