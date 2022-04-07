#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
using namespace std;
const int maxn = 510;
const int N = 2010, M = (N*N)*2; 
bool g[N][N];
bool st[maxn];
int lk[N], wife[N];
int n, m;
int idx, h[N], e[M], ne[M], tot;
int h2[N];

bool find(int x){
  //  for(int j = 1; j <= m; j ++ ){
        //if(!st[j] && g[x][j]){
    for(int i = h2[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(lk[j] == 0 || find(lk[j])){
                lk[j] = x;
                wife[x] = j;
                return true;
            }
        }
    }
    return false;
}


int dfn[N], low[N], dfs_clock;
int scc_cnt, id[N];
int top, stk[N];
bool in_stk[N];

void tarjan(int x){
    dfn[x] = low[x] = ++dfs_clock;
    stk[++top] = x, in_stk[x] = true;
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
            id[y] = scc_cnt;
            in_stk[y] = false;
        }while(y != x);
    }
}

void add(int a, int b, int h[]){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int ans[N][N];
void init(){
    fori(i,0,maxn)ans[i][0] = 0;
    fori(i,0,N) h2[i] = h[i] = -1, dfn[i] = 0;
    fori(i,0,N) fori(j,0,N) wife[i] = lk[i] = g[i][j] = 0;
    tot = scc_cnt = top = dfs_clock = idx = 0;
}
void sol(){
    init();
    scanf("%d %d", &n, &m);
    For(i,1,n){
        int k; scanf("%d", &k);
        For(j,1,k){
            int v; scanf("%d", &v);
            g[i][v] = 1;
            add(i,v,h2);
        }
    }
    int mx = 0;
    For(i,1,n){
        mst(st,0); 
        mx += find(i);
    }
   // debug(mx);
    //int tot = mx;
    int y = m, x = n;
    For(i,1,n) if(!wife[i]){
        wife[i] = ++y, lk[y] = i;
        For(j,1,n + m - mx) g[j][y] = 1;
    }
    For(i,1,y) if(!lk[i]) {
        lk[i] = ++x, wife[x] = i;
        For(j,1,y) g[x][j] = 1;
    }
    For(i,1,y){
        int prince = lk[i];
        For(j,1,y) if(g[prince][j] && j != i) add(i,j,h);
    }
    For(i,1,y)if(!dfn[i])tarjan(i);
    For(i,1,n){
        int ind = id[wife[i]];
        For(j,1,m){
            if(g[i][j] && id[j] == ind) ans[i][++ans[i][0]] = j;
        }
    }
    //debug("ans");
    For(i,1,n){
        printf("%d",ans[i][0]);
        bool fir = true;
        For(j,1,ans[i][0]) {
            int x = ans[i][j];
            printf(" %d", x);
        }
        puts("");
    }
}
int main(){
    int tt; scanf("%d", &tt);
    For(i,1,tt){
        printf("Case #%d:\n",i);
        sol();
    }
    return 0;
}
//https://vjudge.net/solution/30967252
//666