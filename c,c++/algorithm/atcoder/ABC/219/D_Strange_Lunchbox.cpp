#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dp[2][610][610];
const int INF = 0x3f3f3f3f;
int main(){
    int n; scanf("%d", &n);
    int x, y; scanf("%d %d", &x, &y);
    memset(dp,0x3f,sizeof dp);
    dp[0][0][0] = 0;
    int last = 0;
    int suma = 0, sumb = 0;
    for(int i = 1; i <= n; i ++ ){
        int a, b; scanf("%d %d", &a, &b);
        int now = last^1;
        for(int j = 0; j <= 600; j ++ ) for(int k = 0; k <= 600; k ++ ) dp[now][j][k] = dp[last][j][k];
        for(int j = 0; j <= x; j ++ ) for(int k = 0; k <= y; k ++ ) {
            if(dp[last][j][k] != INF) {
                int jj = min(j+a,x);
                int kk = min(k+b,y);
                dp[now][jj][kk] =min( dp[now][jj][kk],dp[last][j][k] + 1);
             //   cout<<now<< ' '<<j+a<<' '<<k<<' '<<" dp[now][j+a][k]:"<<dp[now][j+a][k]<<endl;
            }
        }
        last ^= 1;
    }
    int ans = INF;
    for(int i = x; i <= 600; i ++ )for(int j = y; j <= 600; j ++ ) ans = min(ans,dp[last][i][j]);
   // for(int i = x; i <= x+3; i ++ )for(int j = y; j <= y + 3; j ++ ) cout<<dp[last][i][j]<<endl;
    if(ans == INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}