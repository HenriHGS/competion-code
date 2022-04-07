#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cmath>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int>PII;
const int INF = 1e9;
const int N = 1e3, M = (7000 + N) * 2;
PII edge[M];
int e[M], ne[M], f[M], h[N], idx;
void add(int a, int b, int c1, int c2){
    e[idx] = b, ne[idx] = h[a], f[idx] = c1, h[a] = idx ++ ;
    e[idx] = a, ne[idx] = h[b], f[idx] = c2, h[b] = idx ++;
}
int read(){
    int f = 0, x = 0; char ch = getchar();
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x: x;
}
int S, T;
int n, m, k;
int val[N], ans[N];
int d[N], cur[N];
int q[N];
void build(int k){
    memset(h,-1,sizeof h);
    idx = 0;
    S = 0, T = n + 1;
    For(i,1,n){
        if(val[i] != -1){
            if(val[i] >> k & 1) add(i,T,INF,0);
            else add(S,i,INF,0);
        }
    }
    For(i,1,m){
        int a = edge[i].x, b = edge[i].y;
        add(a,b,1,1);
    }
}
bool bfs(){
    memset(d,-1,sizeof d);
    int hh = 0, tt = -1;
    q[++tt] = S; d[S] = 0; cur[S] = h[S];
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[t] + 1;
                q[++tt] = ver;
                cur[ver] = h[ver];
                if(ver == T) return true;
            }
        }
    }
    return false;
}
int find(int x, int flow_limit){
    int flow = 0;
    if(x == T) return flow_limit;
    for(int& i = cur[x]; ~i && flow < flow_limit ; i = ne[i]){
        int ver = e[i];
        if(d[ver] == d[x] + 1 && f[i]){
            int t = find(ver, min(flow_limit - flow, f[i]));
            if(!t) d[ver] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}

void dinic(int k){
    build(k);
    int r = 0, flow;
    while(bfs()) while(flow = find(S,INF)) r += flow;
    for(int i = 1; i <= n; i ++ ){
        if(d[i] == -1 && val[i] == -1) ans[i] |= (1<<k);
    }
}

void sol(){
    memset(ans,0,sizeof ans);
    memset(val,-1,sizeof val);
    n = read(), m = read();
    For(i,1,m){
        int a = read(), b = read();
        edge[i] = {a,b};
    }
    k = read();
    For(i,1,k) {
        int a =  read(), b = read();
        val[a] = b;
        ans[a] = b;
    }
    for(int i = 0; i <= 30; i ++ ) dinic(i);
    For(i,1,n)printf("%d\n", ans[i]);
}
int main(){
    printf("ans1 = %d, ans2 = %d", (5^101 ) + (101^100), (5^4 ) + (4^100));
    int tt = read();
    while(tt-- ) sol();
    return 0;
}