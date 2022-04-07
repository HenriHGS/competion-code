#include <stack>
#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x);  i <= (y); i ++ )
using namespace std;
const int N = 1e5+10;
int vis[N], nxt[N], dpt[N], dp[N];
bool visited[N];
int n;
stack<int>stk;
int dfs(int x, int dis){
    int v = nxt[x];
    if(dp[v]) return dp[x] = dp[v]+1;
    visited[x] = vis[x] = 1;
    dpt[x] = dis;
    stk.push(x);
    if(vis[v]){
        while(!stk.empty()){
            int u = stk.top();
            stk.pop();
            dp[u] = dpt[x] - dpt[v] + 1;
            if(u == v)break;
        }
    }else {
        int val = dfs(v,dis+1);
        if(!dp[x]){
            dp[x] = 1 + val;
            stk.pop();
        }
    }
    vis[x] = 0;
    return dp[x];
}
int main(){
    memset(dp, 0, sizeof dp);
    int n;
    scanf("%d", &n);
    For(i,1,n)scanf("%d", nxt + i);
    For(i,1,n) if(!visited[i])dfs(i, 1);
    For(i,1,n){
        printf("%d",dp[i]);
        printf("%s","\n");
    }
    return 0;
}