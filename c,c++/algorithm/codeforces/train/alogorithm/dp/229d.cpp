#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mst(x,a) memset(x,a,sizeof(x)) 
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 5010;
const int inf = 1e9+10;
int dp[N], mi_height[N], h[N];
int main(){
    int n;
    scanf("%d", &n);
    For(i,1,n) scanf("%d", h + i), h[i] += h[i - 1];
    For(i,1,n)dp[i] = inf, mi_height[i] = inf;
    For(i,1,n)fori(j,0,i){
        if(h[i] - h[j] >= mi_height[j] && dp[i] >= dp[j] + i - j - 1){
            dp[i] = dp[j] + i - j - 1;
            mi_height[i] = min(mi_height[i],h[i] - h[j]);
        }
    }
    printf("%d\n", dp[n]);//cout<<dp[n]<<endl;
    return 0;
}