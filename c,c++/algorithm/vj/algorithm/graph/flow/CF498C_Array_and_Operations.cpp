#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x* 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) x = -x, putchar('-');
    if(x >= 10) print(x / 10);
    putchar(x%10+'0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
const int INF = 1e9;
const int N = 1010, M = N*N*2;
int h[N], e[M], ne[M], f[M], idx;
int cur[N], d[N], q[N];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx ++ ;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx ++ ;
}
int tot, S, T;
map<int,int> fact[N];
bool bfs(){
    For(i,1,tot) d[i] = -1;
    int hh = 0, tt = -1;
    d[S] = 0, cur[S] = h[S], q[++tt] = S;
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                q[++tt] = ver;
                if(ver == T) return true;
            }
        }
    }
    return false;
}
int find(int x, int flow_limit){
    int flow = 0;
    if(x == T) return flow_limit;
    for(int& i = cur[x]; ~i && flow < flow_limit; i = ne[i]){
        int ver = e[i];
        if(d[ver] == d[x] + 1 && f[i]){
            int t = find(ver, min(f[i], flow_limit - flow));
            if(!t) d[ver] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}
int dinic(){
    int r = 0, flow;
    while(bfs()) while(flow = find(S,INF))r += flow;
    return r;
}
map<int,int> divide(int x){
    map<int,int> v;
    int mid = sqrt(x);
    for(int i = 2; i <= mid; i ++ ){
        while(x % i == 0) v[i]++, x /= i;
    }
    if(x > 1) v[x]++;
    return v;
}
int a[N];
map<pair<int,int>,int>ma;
int ID(int x, int pr){
    pair<int,int> id = {x,pr};
    if(!ma.count(id)) ma[id] = ++tot;
    return ma[id];
}
int main(){
    memset(h,-1,sizeof h);
    int n = read(), m = read();
    For(i,1,n) a[i] = read(), fact[i] = divide(a[i]);
    S = ++tot, T = ++tot;
    For(i,1,n){
        for(auto d: fact[i]) {
            if(i&1)add(S,ID(i,d.first), d.second);
            else add(ID(i,d.first), T, d.second);
        }
    }
    For(i,1,m){
        int u = read(), v = read();
        if(v & 1) swap(u,v);
        for(auto d1: fact[u]) if(fact[v].count(d1.first)) add(ID(u, d1.first), ID(v,d1.first), INF);
    }
    print(dinic(), '\n');
    return 0;
}