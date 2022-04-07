#include <cstdio>
#include <cstring>
using namespace std;

#define db double
int cas;
db ans = 0;
db dp[110][210];
db dfs(int x, int p, int q){
    db res = 0;
    if(dp[p][q] > 0) return dp[p][q];
    if(q >= 200) return dp[p][q] = x-1+100.0/p;//几何分布
    //fail
    res = 0;
    res += (1-1.0*p/100)*dfs(x+1,p,q+3);
    //win && get
    res += win1*x*q/200;
    //win && !get
    res += dfs(win1*(1-1.0*q/200),x+1,p,q+4);
    return dp[p][q] = res;
}
void sol(){
   
    ans = 0;
    int p, q = 4;
    scanf("%d", &p);
    printf("Case %d: %.6f\n", ++cas,dfs(1,1,p,q));
}
int main(){
    int tt; memset(dp,0,sizeof dp);
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}