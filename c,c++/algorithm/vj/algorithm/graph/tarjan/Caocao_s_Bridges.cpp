#include <cstdio>
#include <cstring>
#include <vector>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e3+10, M = N*N*2;
int e[M], ne[M], h[N], w[M], idx;
int dfn[N], low[N], dfs_clock;
int top, stk[N];
bool is_bridge[M];
int ecc_cnt = 0;
const int INF = 1e9;
int ans = INF, n, m;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++; 
    e[idx] = a, ne[idx] = h[b], w[idx] = c, h[b] = idx++;
}
void init(){
    idx = 0;
    ans = INF;
    fori(i,0,2*m) is_bridge[i] = 0;
    For(i,0,n) h[i] = -1, dfn[i] = 0;
    dfs_clock = top = 0;
}
void tarjan(int x, int last){
    dfn[x] = low[x] = ++dfs_clock;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j,i);
            low[x] = min(low[x], low[j]);
            if(dfn[x] < low[j]) is_bridge[i] = is_bridge[i^1] = true;
        }else if((last^1) != i) low[x] = min(low[x], dfn[j]);
    }
}
void sol(){
    init();
    For(i,1,m){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        add(a,b,c);
    }
    tarjan(1,-1);
    For(i,1,n) if(!dfn[i]) {
        //tarjan(i,-1);
        printf("0\n");
        return ;
    }
    for(int i = 0; i < idx; i += 2){
        if(is_bridge[i]) ans = min(ans,w[i]);
    }
    if(ans == INF) printf("-1\n");
    else if(ans == 0) printf("1\n");
    else printf("%d\n", ans);
}
int main(){
    memset(h,-1,sizeof h);
    while(scanf("%d %d", &n, &m) &&(n&&m)){
        sol();
    }
    return 0;
}