#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e4+10;
const int M = 1e6+10;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int n, m;
struct Edge{
    int a, b, w;
    bool operator < (const Edge &x ) const{
        return w < x.w;
    }
} edge[M];
int h[N], e[M], ne[M], idx, w[M];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a],w[idx] = c,  h[a] = idx ++;
}
struct DSU{
    int f[N];
    int _n;
    DSU(int n) : _n(n){
        init();
    }
    void init(){
        For(i,1,_n) f[i] = i;
    }
    int find(int x){
        if(x == f[x]) return x;
        return f[x] = find(f[x]);
    }
    void merge(int a, int b){
        int fa = find(a), fb = find(b);
        if(fa != fb){
            f[fa] = fb;
        }
    }
};
int q[N], dep[N], f[N][20], mx[N][20];
void bfs(int u){
    memset(f,0,sizeof f);
    memset(mx,0,sizeof mx);
    memset(dep,0x3f,sizeof dep);
    int hh = 0, tt = 0;
    q[0] = u; dep[0] = 0, dep[u] = 1;
    while(hh <= tt){
        u = q[hh++];
        for(int i = h[u]; ~i; i = ne[i]){
            int ver = e[i];
            if(dep[ver] > dep[u] + 1){
                dep[ver] = dep[u] + 1;
                f[ver][0] = u;
                mx[ver][0] = w[i];
                q[++tt] = ver;
                for(int k = 1; k <= 19; k ++ ){
                    int anc = f[ver][k-1];
                    f[ver][k] = f[anc][k-1];
                    mx[ver][k] = max(mx[ver][k-1], mx[anc][k-1]);
                }
            }
        }
    }
}
int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a,b);
    int res = 0;
    for(int k = 19; k >= 0; k -- ) if(dep[f[a][k]] >= dep[b]) {
        res = max(res,mx[a][k]);
        a = f[a][k];
    }
    if(a == b) return res;
    for(int k = 19; k >= 0; k -- )
        if(f[a][k] != f[b][k]){
            res = max(res, mx[a][k]);
            res = max(res, mx[b][k]);
            a = f[a][k];
            b = f[b][k];
        }
    res = max(res, mx[a][0]);
    res = max(res,mx[b][0]);
    return res;
}
bool vis[M];
void init(){
    n = read(); m = read();
    For(i,1,n) h[i] = -1;
    idx = 0;
    For(i,1,m) {
        int a = read(), b = read(), c = read();
        edge[i] = {a,b,c};
        vis[i] = 0;
    }
}
void sol(){
    init();
    sort(edge +1 ,edge + 1 + m);
    int cntv = 0;
    DSU dsu(n);
    //dsu.init();
    int ans1 = 0;
    For(i,1,m){
        int a = edge[i].a, b = edge[i].b, c = edge[i].w;
        //cout<<dsu.find(a)<<' '<<dsu.find(b);
        if(dsu.find(a) != dsu.find(b)){
            dsu.merge(a,b);
            cntv++;
            ans1 += c;
            add(a,b,c); add(b, a,c);
            vis[i] = 1;
        }
    }
   // printf("ans1: = %d\n", ans1);
        bfs(1);
        For(i,1,m){
            if(vis[i]) continue;
            int a = edge[i].a, b = edge[i].b, c = edge[i].w;
            if(lca(a,b) == c){
                puts("No");
                return;
            }
        }
        printf("%d\n", ans1);
}
int main(){
    int tt = read();
    while(tt-- ) sol();
    return 0;
}