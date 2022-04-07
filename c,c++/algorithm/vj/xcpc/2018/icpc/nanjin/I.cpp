#include <cstdio>
#include <cstring>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 510 * 3, M = N*N*2;
const int INF = 1e9+10;
int h[N], f[M], e[M], ne[M], idx;
int q[N], d[N], cur[N];
int S, T, kk;
int n, m, k;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++ ;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++ ;
}
bool bfs(){
    memset(d, -1, sizeof d);
    int hh = 0, tt = 0;
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while(hh <= tt){
        int x = q[hh++];
        for(int i = h[x]; ~i; i =  ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[x] + 1;
                q[++tt] = ver;
                if(ver == T) return true;
                cur[ver] = h[ver];
            }
        }
    }
    return false;
}
int find(int x, int limit){
    if(x == T) return limit;
    int flow = 0;
    for(int& i = cur[x]; ~i && flow < limit; i = ne[i]){
        int ver = e[i];
        if(d[ver] == d[x] + 1 && f[i]){
            int t = find(ver, min(f[i], limit - flow));
            if(!t) d[ver] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}
int dinic(){
    int r = 0, flow;
    while(bfs()) while(flow = find(S,INF)) r += flow;
    return r;
}
void sol(){
    memset(h, -1, sizeof h); idx = 0;
    scanf("%d %d %d", &n, &m, &k);
     kk = n + m + 1, S = 0, T = n + m + 2;
    For(i,1,n){
        int x; scanf("%d",&x);
        For(j,1,x){
            int v; scanf("%d", &v);
            add(i,v + n, 1);
        }
        add(S,i,1);
    }
    For(i,1,m) add(i + n, T, 1);
   add(S,kk,k);
    For(i,1,n){
        add(kk,i,1);
    }
    printf("%d\n", dinic());
}

int main(){
    sol();
    return 0;
}