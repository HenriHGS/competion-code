#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define pb push_back
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 1e5+10, M = 2e5+1000 + 10;
int e[M<<1], ne[M<<1], h[N], idx;
int low[N], dfn[N], dfs_clock;
int top = 0, stk[N];
bool is_bridge[M<<1];
void tarjan(int x, int fa){
    dfn[x] = low[x] = ++dfs_clock;
    stk[++top] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j,x);
            low[x] = min(low[x], low[j]);
            if(low[j] > dfn[x]) is_bridge[i] = is_bridge[i^1] = true;
        }else if(j != fa && dfn[j] <= dfn[x]) low[x] = min(low[x], dfn[j]);
    } 
}
int ecc_cnt;
vector<int> ecc[N];
int id[N];
void dfs(int x){
    ecc[ecc_cnt].pb(x); id[x] = ecc_cnt;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(id[j] || is_bridge[i]) continue;
        dfs(j);
    }
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m, q;
int dpt[N], f[N], eid[N][2];
int e2[M<<1], ne2[M<<1], idx2, h2[N];
bool have[M<<1];
void add2(int a, int b){
    e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2++; 
}
void dfs2(int x){
    if(f[x] == -1) dpt[x] = 1;
    else dpt[x] = dpt[f[x]] + 1;
    for(int i = h2[x]; ~i; i = ne2[i]){
        int j = e2[i];
        if(j != f[x]){
            eid[x][0] = i;
            eid[j][1] = i;
            f[j] = x;
            dfs2(j);
        }
    }
}
int ans = 0;
void link(int a, int b){
    if(dpt[a] < dpt[b]) swap(a,b);
    while(dpt[a] > dpt[b]){
        int ind = eid[a][1];
        if(have[ind]) ans--;
        have[ind] = have[ind^1] = 0;
        a = f[a];
    }
    while(a != b){
        int inda = eid[a][1], indb = eid[b][1];
        if(have[inda]) ans--;
        if(have[indb]) ans--;
        have[inda] = have[inda^1] = 0;
        have[indb] = have[indb^1] = 0;
        a = f[a];
        b = f[b];
    }
}

void init(){
    For(i,0,ecc_cnt) ecc[i].clear();
    ans = idx2 = idx = ecc_cnt = top = dfs_clock = 0;
    mst(is_bridge,0); mst(id,0);
    mst(dfn,0); mst(h,-1);
    mst(h2,-1); mst(have,0); mst(eid,0);
}
int cas = 0;
void sol(){
    init();
    For(i,1,m){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b); add(b,a);
    }
    For(i,1,n) if(!dfn[i])tarjan(i,-1);
    For(i,1,n) if(!id[i]){
        ecc_cnt++;
        dfs(i);
    }
    for(int i = 0; i < idx; i += 2){
        int a = id[e[i]], b = id[e[i^1]];
        if(a != b){
            ans++;
            add2(a,b); add2(b,a);
        }
    }
    fill(have, have + idx2, 1);
    f[1] = -1;
    dfs2(1);
    if(cas)puts("");
    printf("Case %d:\n",++cas);
    scanf("%d", &q);
    while(q--){
        int a, b; scanf("%d %d", &a, &b);
        if(id[a] != id[b]){
            //b to a
            int idb = id[b], ida = id[a];
            link(ida,idb);
        }
        printf("%d\n", ans);
    }
}
int main(){
    while(scanf("%d %d", &n, &m) &&(n&&m)){
        sol();
    }
    return 0;
}