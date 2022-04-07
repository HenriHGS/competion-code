#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
using namespace std;
const int N = 2e5+10, M = 4e6+10;
int e[M], ne[M], h[N], idx; 
int e2[M], ne2[M], h2[N], idx2; 
int n, m;
int low[N], dfn[N], dfs_clock;
int ecc_cnt, id[N], top;
int stk[N];

void tarjan(int x, int last){
    low[x] = dfn[x] = ++dfs_clock;
    stk[++top] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j,i);
            low[x] = min(low[x],low[j]);
        }else if((i^1) != last && dfn[j] < dfn[x]) low[x] = min(low[x], dfn[j]);
    }
    if(dfn[x] == low[x]){
        int y;
        ecc_cnt++;
        do{
            y = stk[top--];
            id[y] = ecc_cnt;
        }while(y != x);
    }
}

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void add2(int a, int b){
    e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2++;
}
//vector<int> e2[N];

int ans = 0;
int dfs(int x, int fa){
    int mx = 0;
    for(int i = h2[x]; ~i; i = ne2[i]){
        int j = e2[i];
        if(j == fa) continue;
        int son = dfs(j,x);
        ans = max(ans, mx + son + 1);
        mx = max(son+1,mx);
    }
    return mx;
}

void init(){
    ans = 0;
   // For(i,0,ecc_cnt) e2[i].clear();
    For(i,0,n) h[i] = -1;
    For(i,0,ecc_cnt) h2[i] = -1;
    For(i,0,n) dfn[i] = 0;
    ecc_cnt = idx2 = idx = dfs_clock = top = 0;
    //mst(h,-1); mst(dfn,0);
}
void sol(){
   // init();
    For(i,1,m){
        int a, b; scanf("%d %d", &a, &b);
        add(a,b); add(b,a);
    }
    tarjan(1,-1);
    for(int i = 0; i < idx; i += 2){
        int a = id[e[i]], b = id[e[i^1]];
        if(a != b){
            //e2[a].pb(b); e2[b].pb(a);
            add2(a,b); add2(b,a);
        }
    }
   // debug(ecc_cnt);
   // debug(dfs(1,-1));
    dfs(1,-1);
    int res = ecc_cnt - 1 - (ans);
    printf("%d\n", res);
}
int main(){
    mst(h,-1); mst(h2,-1);
    while(scanf("%d %d", &n, &m) && (n&&m)){
        sol();
        init();
    }
    return 0;
}