#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int M = 20010, N = 200;
typedef long long ll;
long long dp[M], num[M];
int v[N], k[N];
bool vis[M];
int main(){
    int n; scanf("%d", &n);
    For(i,1,n) scanf("%d", v + i);
    For(i,1,n) scanf("%d", k + i);
    int m; scanf("%d", &m);
    memset(dp,-1,sizeof dp);
    memset(num,0x3f,sizeof num);
    num[0] = 0;
    dp[0] = 1;
    for(int i = 1; i <= n; i ++ ){
        for(int j = m; j >= 1; j -- ){
            for(int p = 1; p <= k[i]; p ++ ){
                if(1ll*p*v[i] <= j){
                    int pre =  j - p*v[i];
                    if(dp[pre] != -1){
                        if(dp[j] == -1) dp[j] = 0;
                        dp[j] += dp[pre];
                        num[j] = min(num[j], num[pre] + p);
                    }
                }
            }
        }
    }
    if(dp[m]== -1) {
        puts("0");
        puts("no possible");
    }
    else {
        printf("%lld\n%lld\n", dp[m], num[m]);
    }
    return 0;
}