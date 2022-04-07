#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 5e5+10;
int h[N*2], e[N*2], ne[N*2], idx;
int f[N][21], dep[N], d[N][21];
inline void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
inline int read(){
    int f = 0, x = 0; char ch = getchar();
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10+ ch - '0', ch = getchar();
    return f ? -x : x;
}
int n, m;
int q[N];
inline void bfs(int u){
    memset(dep,0x3f,sizeof dep);
    int hh = 0, tt = 0;
    q[0] = u, dep[0] = 0, dep[u] = 1;
    while(hh <= tt){
        u = q[hh++];
        for(register int i = h[u]; ~i; i = ne[i]){
            int ver = e[i];
            if(dep[ver] > dep[u] + 1){
                dep[ver] = dep[u] + 1;
                q[++tt] = ver;
                f[ver][0] = u;
                d[ver][0] = 1;
                for(int k = 1; k <= 19; k ++ ){
                    int anc = f[ver][k-1];
                    f[ver][k] = f[anc][k-1];
                    d[ver][k] = d[anc][k-1] + d[ver][k-1];
                }
            }
        }
    }
}
inline int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a,b);
    for(int k = 20; k >= 0; k -- )
        if(dep[f[a][k]] >= dep[b]) a = f[a][k];
    if(a == b) return a;
    for(register int k = 20; k >= 0; k -- )
        if(f[a][k] != f[b][k]){
            a = f[a][k];
            b = f[b][k];
        }
    return f[a][0];
}
int main(){
    memset(h,-1,sizeof h);
    n = read(); m = read();
    for(int i = 1; i <= n-1; i ++ ){
        int a = read(), b = read();
        add(a,b); add(b,a);
    }
    bfs(1);
    for(register int i = 1; i <= m; i ++ ){
        int v[3]{};
        for(register int j = 0; j < 3; j ++ ) {
            v[j] = read();
        }
        int ans = 1e9+10;
        int ansp;
        for(register int p = 0; p < 3; p ++ ) for(register int q = p + 1; q < 3; q ++ ){
            int o = lca(v[p], v[q]);
            int tmp = 0;
            for(register int j = 0; j < 3; j ++ ){
                int oo = lca(v[j],o);
                int dist = dep[v[j]] + dep[o] - 2*dep[oo];
                tmp += dist;
            }
            if(ans > tmp){//ans = min(ans, tmp);
                ans = tmp;
                ansp = o;
            }
        }
        /* int a = read(), b = read(), c = read(), ans;
        int lca1 = lca(a, b), lca2 = lca(b, c), lca3 = lca(a, c);
        if(lca1 == lca2) ans = lca3;
        else if(lca2 == lca3) ans = lca1;
        else if(lca3 == lca1) ans = lca2;
        printf("%d %d\n", ans, dep[a] + dep[b] + dep[c] - dep[lca1] - dep[lca2] - dep[lca3]); */
        printf("%d %d\n",ansp,  ans);
    }
    return 0;
}