#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e4+10, M = 1e7+10;
int e[M], ne[M], idx, h[N];
int scc_cnt, stk[N], id[N], top;
int dfn[N], low[N], dfs_clock;
bool in_stk[N];
int n;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
 //   e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}
void tarjan(int x){
    dfn[x] = low[x] = ++dfs_clock;
    stk[++top] = x; in_stk[x] = true;
    for(int i = h[x]; ~i; i =  ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[x] = min(low[x],low[j]);
        }else if(in_stk[j]) low[x] = min(low[x], dfn[j]);
    }
    if(low[x] == dfn[x]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
        }while(y != x);
    }
}
int din[N], dout[N];
void init(){
    memset(h,-1,sizeof h);
    scanf("%d", &n);
    int a, b;
    For(a,1,n)while( scanf("%d", &b) && b){
        //scanf("%d", &b);
        add(a,b);
    }
}

int main(){
    init();
    For(i,1,n) if(!dfn[i]) tarjan(i);
    For(x,1,n){
        for(int i = h[x]; ~i; i = ne[i]){
            int b = e[i]; b = id[b];
            int a = x; a = id[a];
            if(a == b) continue;
            din[b]++;
            dout[a]++;
        }
    }
    int ma, mb;
    ma = mb = 0;
    For(i,1,scc_cnt){
        if(din[i] == 0)ma++;
        if(dout[i] == 0)mb++;
    }
    if(scc_cnt == 1){
        printf("1\n0\n");
        return 0;
    }
    printf("%d\n", ma);
    printf("%d\n", max(ma,mb));
    return 0;
}