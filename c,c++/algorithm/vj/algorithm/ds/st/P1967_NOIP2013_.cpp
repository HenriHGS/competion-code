#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
const int N = 1e4+10, M = 5e5+10;
int e[M], ne[M], idx, w[M], h[N];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
struct Edge{
    int a, b, c;
    bool operator < (const Edge&x) const{
        return c > x.c;
    }
} edge[M];
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
struct DSU{
    int f[N];
    int _n;
    void init(){
        for(int i = 1; i <= _n; i ++ ) f[i] = i;
    }
    DSU(int n):_n(n){
        init();
    }
    int find(int x){
        if(f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    void merge(int a, int b){
        int fa = find(a), fb = find(b);
        if(fa != fb){
            f[fa] = fb;
        }
    }
};
int n, m, q;
int que[N], dep[N];
int f[N][15], mi[N][15];
void bfs(int u){
    int hh = 0, tt = 0;
    que[0] = u, dep[0] = 0, dep[u] = 1;
    while(hh <= tt){
        u = que[hh++];
        for(int i = h[u]; ~i; i = ne[i]){
            int ver = e[i];
            if(dep[ver] > dep[u] + 1){
                dep[ver] = dep[u] + 1;
                que[++tt] = ver;
                f[ver][0] = u, mi[ver][0] = w[i];
                for(int k = 1; k <= 14; k ++ ){
                    int anc = f[ver][k-1];
                    f[ver][k] = f[anc][k-1];
                    mi[ver][k] = min(mi[ver][k-1], mi[anc][k-1]);
                }
            }
        }
    }
}
int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a,b);
    int res = 1e9;
    for(int k = 14; k >= 0; k -- )
        if(dep[f[a][k]] >= dep[b]) {
            res = min(res, mi[a][k]);
            a = f[a][k];
        }
    if(a == b) return res;
    for(int k = 14; k >= 0; k -- )
        if(f[a][k] != f[b][k]){
            res = min(res,mi[a][k]);
            res = min(res,mi[b][k]);
            a = f[a][k];
            b = f[b][k];
        }
    res = min(res,mi[a][0]);
    res = min(res,mi[b][0]);
    return res;
}
int vis[N];
int main(){
    memset(mi,0x3f,sizeof mi);
    memset(dep,0x3f,sizeof dep);
    memset(h,-1,sizeof h);
    n = read(), m = read();
    for(int i= 1; i <= m; i ++ ){
        int a = read(), b = read(), c = read();
        //add(a,b,c); add(b,a,c);
        edge[i] = {a,b,c};
    }
    sort(edge + 1, edge + 1 + m);
    DSU dsu(n);
    int cnt = 0;
    for(int i = 1; i <= m; i ++ ){
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        if(dsu.find(a) != dsu.find(b)){
            dsu.merge(a,b);
            cnt++;
            add(a,b,c); add(b,a,c);
        }
        if(cnt == n - 1) break;
    }
    for(int i = 1; i<= n; i ++ ) dsu.find(i);
    for(int i = 1; i <= n; i ++ ) {
        int fa = dsu.find(i);
        if(vis[fa]) continue;
       // cout<<"fa:"<<fa<<endl;
        vis[fa] = 1;
        bfs(fa);
    }
    q = read();
    for(int i = 1; i <= q; i ++ ){
        int a = read(), b = read();
        if(dsu.find(a) != dsu.find(b)) {
            puts("-1");
            continue;
        }
        printf("%d\n", lca(a,b));
    }
    return 0;
}