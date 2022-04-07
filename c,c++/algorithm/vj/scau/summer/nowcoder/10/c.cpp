#include <cstdio>
#include <cstring>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;

int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}

const int N = 6e4+10, M = 6e6+10;
const int  INF = 1e8;
int h[N], e[M], f[M], ne[M], idx;
void add(int a, int b, int c){
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}
int n, m, S, T;
int q[N], d[N], cur[M];
bool bfs(){
    memset(d,-1,sizeof d);
    int tt = 0, hh = 0;
    q[0] = S; d[S] = 0, cur[S] = h[S];
    while(hh <= tt){
        int x = q[hh++];
        for(int i = h[x]; ~i; i = ne[i]){
            int j = e[i];
            if(d[j] == -1 && f[i]){
                d[j] = d[x] + 1;
                cur[j] = h[j];
                if(j == T) return true;
                q[++tt] = j;
            }
        }
    }
    return false;
}

int find(int x, int limit){
    if(x == T) return limit;
    int flow = 0;
    for(int i = cur[x]; ~i && flow < limit; i = ne[i]){
        cur[x] = i;
        int j = e[i];
        if(d[j] == d[x] + 1 && f[i]){
            int t = find(j, min(f[i], limit - flow));
            if(!t) d[j] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}

int dinic(){
    int flow = 0, r;
    while(bfs()) while(r = find(S,INF)) flow += r;
    return flow;
}
void init(){
    n = read();
    For(woman,1,n){
        int k = read();//read(k);
        For(j,1,k){
            int man = read();
            //man_dislike[man].pb(woman);
           // woman_dislike[woman].pb(man);
        }
    }
}
int main(){
    init();
    printf("%d\n", dinic());
    return 0;
}