#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
#define mst(x,a) memset(x,a,sizeof x )
using namespace std;
const int N = 310*2, M = N*N*4, INF = 1e9;
int h[N], e[M], ne[M], idx;
int f[M];
int q[N], d[N], cur[N];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}
int S, T;
bool bfs(){
    mst(d, -1);
    int hh = 0, tt = 0;
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if(ver == T) return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}
int find(int x, int limit){
    if(x == T) return limit;
    int flow = 0;
    for(int&i = cur[x]; ~i && flow < limit; i = ne[i]){
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
bool vis[N];
int match[N];
vector<int> edge[N];
//match
int dfs(int x){
    for(auto j : edge[x]){
        if(!vis[j]){
            vis[j] = 1;
            if(!match[j] || dfs(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int n;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x / 10);
    putchar(x%10+'0');
}
int w[N];
int main(){
    mst(h,-1);
    n = read();
    For(i,1,n){
        int m = read();
        For(j,1,m){
            int x = read();
            edge[i].pb(x + n);
            edge[x + n].pb(i);
        }
    }
    For(i,1,n){
        mst(vis,0);
        dfs(i);
    }
    S = 0, T = 2*n + 1;
    For(i,1,n) for(auto j:edge[i]){
        add(i,match[j],INF);
    }
    int sum = 0;
    For(i,1,n){
        int t = read();
        t = -t;
        if(t > 0) add(S,i,t), sum += t;
        else if(t < 0) add(i,T,-t);
    }
    print(dinic() - sum);
    return 0;
}