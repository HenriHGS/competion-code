#include <cstdio>
#include <cstring>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e4+10,M = 5e4+10;
int e[M], ne[M], h[N], idx;
int id[N], low[N], dfn[N], dfs_clock, siz[N], scc_cnt;
int stk[N], top;
bool in_stk[N];
void tarjan(int x){
    dfn[x] = low[x] = ++dfs_clock;
    in_stk[x] = true; stk[++top] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[x] = min(low[x], low[j]);
        }else if(in_stk[j]) low[x] = min(low[x], dfn[j]);
    }
    if(low[x] == dfn[x]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt]++;
        }while(y != x);
    }
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dout[N];
int n, m;
int main(){
    idx = top = 0;
    memset(h,-1,sizeof h);
    scanf("%d %d", &n, &m);
    For(i,1,m){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b);
    }
    For(i,1,n) if(!dfn[i]) tarjan(i);
    For(x,1,n){
        for(int i = h[x]; ~i; i = ne[i]){
            int j = e[i];
            int a = id[x], b = id[j];
            if(a == b) continue;
            dout[a]++;
        }
    }
    int zeros = 0, sum = 0;
    For(i,1,scc_cnt){
        if(dout[i]) continue;
        zeros++;
        sum += siz[i];
        if(zeros > 1){
            sum = 0;
        }
    }
    printf("%d\n", sum);
    return 0;
}