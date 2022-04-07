#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
const int N = 1e5+10, M = 2*N;
int e[M], ne[M], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int dep[N], f[N][21], q[N];
void bfs(int u){
    memset(dep, 0x3f, sizeof dep);
    dep[0] = 0, dep[u] = 1;
    int hh = 0, tt = 0;
    q[0] = u;
    while(hh <= tt){
        u = q[hh++];
        for(int i = h[u]; ~i; i = ne[i]){
            int ver = e[i];
            if(dep[ver] > dep[u] + 1){
                dep[ver] = dep[u] + 1;
                q[++tt] = ver;
                f[ver][0] = u;
                for(int k = 1; k <= 20; k ++ ) {
                    int anc = f[ver][k-1];
                    f[ver][k] = f[anc][k-1];
                }
            }
        }
    }
}
int n, m;
int lca(int a,int b){
    if(dep[a] < dep[b]) swap(a,b);
    for(int k = 20; k >= 0; k -- ) 
        if(dep[f[a][k]] >= dep[b]) a = f[a][k];
    if(a == b) return a;
    for(int k = 20; k >= 0; k -- )
        if(f[a][k] != f[b][k]){
            a = f[a][k];
            b = f[b][k];
        }
    return f[a][0];
}
int siz[N];
void dfs(int x){
    siz[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(f[x][0] == v) continue;
        dfs(v);
        siz[x] += siz[v];
    }
}
int step(int x, int kk){
    for(int k = 20; k >= 0; k -- ){
        if( (1<<k) <= kk){
            kk -= (1<<k);
            x = f[x][k];
        }
    }
    return x;
}
int main(){
    memset(h,-1,sizeof h);
    n = read();
    for(int i = 1; i <= n - 1; i ++ ){
        int a = read(), b = read();
        add(a,b); add(b,a);
    }
    bfs(1);
    dfs(1);
    int m = read();
    while(m--){
        int a = read(), b = read();
        if(dep[a] < dep[b]) swap(a,b);
        int anc = lca(a,b);
        int dist;
        if(anc == b) dist = dep[a] -dep[b];
        else dist = dep[a] + dep[b] - 2*dep[anc];
        int ans = 0;
        if(dep[a] == dep[b]){
            int da = dep[a] - dep[anc];
            int db = dep[b] - dep[anc];
            int ca = step(a, da - 1);
            int cb = step(b, db - 1);
            ans = siz[1] - siz[ca] - siz[cb];
            if(a ==b) ans = n;
        }else {
            //a -> mo
            if(dist &1){
                //puts("0");
                //continue;
            }else {
                //a -> mid
                int mo1 = step(a,dist/2);
                int oo = step(a,dist/2 - 1);
                ans = siz[mo1] - siz[oo];
              //  printf("%d\n", ans);
            }
        }
        printf("%d\n", ans);
       /*  if(anc == b){
            if(dist &1){
                puts("0");
                continue;
            }else {
                //a -> mid
                int mo1 = step(a,dist/2);
                int oo = step(a,dist/2 - 1);
                int ans = siz[mo1] - siz[oo];
                printf("%d\n", ans);
            }
        }else {
            if(dep[a] == dep[b]){
                int da = dep[a] - dep[anc];
                int db = dep[b] - dep[anc];
                int ca = step(a, da - 1);
                int cb = step(b, db - 1);
                int ans = siz[1] - siz[ca] - siz[cb];
            }else {
                //a -> mo
                if(dist&1)
            }
        } */
    }
    return 0;
}