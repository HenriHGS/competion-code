#include <cstdio>
#include <cstring>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 310;
ll dp[2][N][N];
void sol(){
    int n, H, S;
    scanf("%d %d %d", &n, &H, &S);
    int cur = 0;
    For(i,1,n){
        int h, w, s;
        cur ^= 1;
        scanf("%d %d %d", &h, &s, &w);
        For(j,0,H)For(k,0,S){
            if(k < s && s - k + h < j){
                int sub = s-k + h;
                dp[cur][j][k] = max(dp[cur][j][k],dp[cur^1][j - sub][0] + w);
                dp[cur][j][k] = max(dp[cur][j][k],dp[cur^1][j][k]);
            }else if(k>=s && j - h > 0){
               dp[cur][j][k] = max(dp[cur][j][k],dp[cur^1][j - h][k - s] + w);
               dp[cur][j][k] = max(dp[cur][j][k],dp[cur^1][j][k]);
            }else dp[cur][j][k] = dp[cur^1][j][k];
        }
    }
    printf("%lld\n",dp[cur][H][S]);
}
int main(){
    sol();
    return 0;
}