#include <cstdio>
#include <cstring>
using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int N =  2e5+10;
const int mod = 1e9+7;
char s[N];
int dp[N];
int main(){
    scanf("%s", s);
    int n = strlen(s);
    dp[0] = 1;
    fori(i,0,n){
       // printf("i = %d\n", i);
        for(int j = i - 1; ; j -- ){
            //printf("dp[%d] = %d,", j,dp[j]);
            dp[i+2] += dp[j+1]; 
            dp[i+2] %= mod;
            if(j == -1||s[i] == s[j]) break;
        }
       // puts("");
    }
    int ans = 0;
    /*
    puts("dp:");
    For(i,2,n+2){
        printf("dp[%d] = %d,", i,dp[i]);
    }
    puts("");
    */
    For(i,2,n+2)ans = (ans + dp[i]) % mod;
    printf("%d\n", ans);
    return 0;
}