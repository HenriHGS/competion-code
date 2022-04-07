#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1200+100, M = (600*3 + 20 + 40 + 100)*2;
const int INF = 1e9;
int e[M], f[M], w[M], ne[M], h[N], idx;
int q[N], d[N], pre[N], incf[N];
bool st[N];
int n, m, S, T;
int id[N][N], cnt, a[N][N];
void add(int a, int b, int c, int d){
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx++;
}
bool spfa(){
    int tt = 1, hh = 0;
    memset(d,-0x3f,sizeof d);
    memset(incf,0,sizeof incf);
    q[0] = S, d[S] = 0, incf[S] = INF;
    while(hh != tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        for(int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if(f[i] && d[ver] < d[t] + w[i]){
                d[ver] = d[t] + w[i];
                pre[ver] = i;
                incf[ver] = min(f[i], incf[t]);
                if(!st[ver]){
                    st[ver] = true;
                    q[tt++] = ver;
                    if(tt == N) tt = 0;
                }
            }
        }
    }
    return incf[T] > 0;
}
int EK(int&cost, int& flow){
    cost = flow = 0;
    while(spfa()){
        int t = incf[T];
        cost += t*d[T];
        flow += t;
        for(int i = T; i != S; i = e[pre[i]^1]){
            f[pre[i]] -= t;
            f[pre[i]^1] += t;
        }
    }
    return cost;
}
int main(){
    scanf("%d %d", &m ,&n);
    S = ++cnt;
    T = ++ cnt;
    For(i,1,n)For(j,1,m+i-1){
        scanf("%d", a[i] + j);
        id[i][j] = ++cnt;
    }
    int flow, cost;
    //
    idx = 0;
    memset(h, - 1, sizeof h);
    For(i,1,n)For(j,1,m+i-1){
        if(i == 1) add(S, id[i][j]*2,1,0);
        if(i == n) add(id[i][j]*2+1,T,1,0);
        add(id[i][j]*2,id[i][j]*2+1,1,a[i][j]);
        if(i < n) {
            add(id[i][j]*2+1, id[i+1][j+1]*2,1,0);
            add(id[i][j]*2+1, id[i+1][j]*2,1,0);
        }
    }
    printf("%d\n", EK(cost,flow));
    //
    idx = 0;
    memset(h, - 1, sizeof h);
    For(i,1,n)For(j,1,m+i-1){
        if(i == 1) add(S, id[i][j]*2,1,0);
        if(i == n) add(id[i][j]*2+1,T,INF,0);
        add(id[i][j]*2,id[i][j]*2+1,INF,a[i][j]);
        if(i < n) {
            add(id[i][j]*2+1, id[i+1][j+1]*2,1,0);
            add(id[i][j]*2+1, id[i+1][j]*2,1,0);
        }
    }
    printf("%d\n", EK(cost,flow));
    //
    idx = 0;
    memset(h, - 1, sizeof h);
    For(i,1,n)For(j,1,m+i-1){
        if(i == 1) add(S, id[i][j]*2,1,0);
        if(i == n) add(id[i][j]*2+1,T,INF,0);
        add(id[i][j]*2,id[i][j]*2+1,INF,a[i][j]);
        if(i < n) {
            add(id[i][j]*2+1, id[i+1][j+1]*2,INF,0);
            add(id[i][j]*2+1, id[i+1][j]*2,INF,0);
        }
    }
    printf("%d\n", EK(cost,flow));
    return 0;
}