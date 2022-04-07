#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 510;
int dp[2][N][N];
int a[N];
int ans[N], id = 0;
int main(){
    int n, m; scanf("%d %d", &n, &m);
    For(i,1,n) scanf("%d", &a[i]);
    memset(dp,-1,sizeof dp);
    dp[0][0][0] = 1;
    int last = 0;
    For(i,1,n){
        int cur = last^1;
        For(j,0,m)For(k,0,m) dp[cur][j][k] = dp[last][j][k];
        for(int l = 0; l<= m; l ++ ){
            for(int r = 0; r<= m; r ++ ){
                if(dp[last][l][r] != -1 && l + a[i] <= m) dp[cur][l+a[i]][r] = 1;
                if(dp[last][l][r] != -1 && r + a[i] <= m) dp[cur][l][a[i] + r] = 1;
            }
        }
        /* cout<<"i = "<<i<<endl;
        int cnt = 0;
        for(int j = 0; j <= m; j ++ ) for(int k = 0;k <= m; k ++ ) if(dp[cur][j][k] !=-1){
            printf("dp[%d][%d] = %d ", j,k,dp[cur][j][k]);
            if(cnt%10==0)puts("");
            cnt++;
        }
        puts(""); */
        last = cur;
    }
    For(l,0,m) if(dp[last][l][m-l] != -1) ans[++id] = l; 
    sort(ans+1,ans+1+id);
    id = unique(ans+1,ans+1+id) - (ans + 1);
    printf("%d\n", id);
    For(i,1,id) printf("%d ", ans[i]);
    return 0;
}