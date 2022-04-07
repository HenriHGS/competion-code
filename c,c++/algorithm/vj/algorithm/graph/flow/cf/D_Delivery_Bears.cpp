#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define debug(a) cout<<#a<<":"<<a<<endl
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

const int N = 60, M = 1100;
#define db double
const db eps= 1e-6;
int n, m, x;
int h[N], e[M], ne[M], f[M], d[N];
int cur[N], idx, q[N];
int S, T;

struct Edge{
    int a,b,c;
}edge[M];

void init(){
    For(i,0,n+1) h[i] = -1;
    idx = 0;
}
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0, h[b] = idx++;
}
bool bfs(){
    mst(d,-1);
    int tt = 0, hh = 0, x = S;
    q[0] = x, d[x] = 0, cur[x] = h[x]; 
    while(hh <= tt){
        x = q[hh++];
        for(int i = h[x]; ~i; i = ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[x] + 1;
                q[++tt] = ver;
                cur[ver] = h[ver];
                if(ver == T) return true;
            }
        }
    }
    return false;
}
int find(int x, int limit){
    int flow = 0;
    if(x == T) return limit;
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
const int INF = 1e9;
int dinic(){
    int r = 0, flow;
    while(bfs()) while(flow = find(S,INF)){
        r += flow;
       // debug(flow);
    } 
    return r;
}
bool check(db mx){
    init();
    S = 0, T = n + 1;
  //  debug(mx);
    For(i,1,m){
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        c = min(c/mx, 1e9);
        //cout<<"c:"<<c<<endl;
        add(a,b,c);
    }
    add(S,1,x);
    add(n,T,x);
    int res = dinic();
   // debug(res);
   // cout<<endl;
    return res>= x;
}
int main(){
    mst(h,-1);
    scanf("%d %d %d", &n, &m, &x);
    db l = 0, r = 0;
    For(i,1,m){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        edge[i] = {a,b,c};
        l = min(l,(db)c), r = max(r,(db)c);
    }
    db ans = INF;
   // debug(l);debug(r);
  //  while(l + eps < r){//
    for(int i = 1; i <= 60; i ++ ){
        db mid = (l + r) / 2;
        if(check(mid)){
            ans = mid*x;
            l = mid;
        }else r = mid;
    }
    printf("%.10f\n", ans);
    return 0;
}