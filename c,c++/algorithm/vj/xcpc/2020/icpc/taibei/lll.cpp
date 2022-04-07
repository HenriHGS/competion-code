#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <numeric>
#include <stack>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#define pb push_back
#define mst(x,a) memset(x,a,sizeof x)
#define debug(a) cout<<#a<<':'<<a<<endl
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
typedef pair<ll, int> PII;
const int N = 1e3+10, M = 1e6+10;
const int INF = 1e9;

int n, m;
int h[N], e[M<<1], ne[M<<1], idx, id[N];
int low[N], dfn[N], dfs_clock, root;
int stk[N], top;
bool is_bridge[M<<1], is_cut[N];
int dcc_cnt, num[M];
vector<int> dcc[N];
int ans1, ans2, ans3, ans4;
void init(){
    mst(num,0);
    ans1 = ans2 = ans3 = ans4 = 0;
    mst(low,0);
    memset(h,-1,sizeof h); mst(dfn,0); mst(id,0); mst(is_cut,0);
    mst(is_bridge,0);
    top = dcc_cnt = dfs_clock = 0;
    idx = 0;
    fori(i,0,N) dcc[i].clear();
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
struct Edge{
    int u, v;
};
stack<Edge> estk;
int vis[M<<1];
bool have[N][N];
void tarjan(int x,int fa){
    low[x] = dfn[x] = ++dfs_clock;
    stk[++top] = x;
    /* if(root == x && h[x] == -1){
        dcc_cnt++;
        dcc[dcc_cnt].pb(stk[top--]);
        return ;
    } */
    int child = (fa != -1);
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!vis[i]){
            vis[i] = vis[i^1] = true;
            estk.push(Edge{x,j});
        }
        if(!dfn[j]){
           // estk.push(Edge{x,j});
            tarjan(j,x);
            low[x] = min(low[x], low[j]);
            if(dfn[x] <= low[j]){
                child++;
                
               // if(x != root || child > 1) ans1++;// if(low[j] >= dfn[x]) ans1++;//is_cut
                if(low[j] > dfn[x]) is_bridge[i] = is_bridge[i^1] = true, ans2++;
                int y;
                dcc_cnt++;
                int cnt_mx = 0;
                while(1){
                    Edge xx = estk.top(); estk.pop();
                    cnt_mx++;
                    if(xx.u == x && xx.v == j) break;
                }
                do{
                  //  cnt_mx++;
                    y = stk[top--];
                    dcc[dcc_cnt].pb(y);
                }while(y != j);
              //  ans4 = max(ans4,cnt_mx);
                dcc[dcc_cnt].pb(x);
            }
        }else if(j != fa && dfn[j] < dfn[x]) {
           // estk.push(Edge{x,j});
            low[x] = min(low[x], dfn[j]);
        }
    }
    if(child > 1) ans1++;
}
void sol(){
    init();
    mst(have,0);
    scanf("%d %d", &n, &m);
    //exit(0);
    For(i,1,m){
        int a, b; scanf("%d %d", &a, &b);
        add(a,b); add(b,a);
        have[a][b] = have[b][a] = 1;
    }
   // exit(0);
   mst(vis,0);
    for(root = 1; root <= n; root++) if(!dfn[root]) tarjan(root,-1);
   /*  For(i,1,dcc_cnt){
        debug(dcc_cnt);
        for(auto x:dcc[i]) cout<<x<<' ';
        cout<<endl;
    } */
    ans3 = dcc_cnt;
    ans4 = 0;
    for(int k = 1; k <= dcc_cnt; k ++ ){
        auto & v = dcc[k];
        int mx_cnt = 0;
        fori(i,0,v.size())fori(j,0,v.size()) mx_cnt += have[v[i]][v[j]];
        ans4 = max(ans4,mx_cnt/2);
    }
    int d = gcd(ans3, ans4);
    printf("%d %d %d %d\n", ans1, ans2, ans3/d, ans4/d);
}

int main(){
    int tt, cas = 0; scanf("%d", &tt);
    while(tt--) {
        //printf("Case #%d: ",++cas);
        sol();
    }
    return 0;
}
/*
1
6 6
1 2
2 3
3 4
4 5
5 6
6 1
*/
// 0 0 1 6
/*
1
6 7
1 2
2 3
3 1
4 5
5 6
6 4
1 4
*/
//2 1 1 1
/*
3
6 7
1 2
2 3
3 1
4 5
5 6
6 4
1 4
6 6
1 2
2 3
3 4
4 5
5 6
6 1
3 2
1 2
2 3
*/