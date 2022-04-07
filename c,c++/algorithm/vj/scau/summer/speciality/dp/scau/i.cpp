#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int num[20];
const int N = 1e5+10;
ll dp[20][N];
int cas;
int n, a, k;
int p[20];
int cal(int x){
    int res = 0;
    int base = 1;
    while(x){
        res += x%10*base;
        x /= 10;
        base *= 2;
    }
    return res;
}

ll dfs(bool limit, bool zero, ll sta, int dep){
    if(dep < 0) return sta >= 0;
    if(sta < 0) return 0;
   // if(sta > k) return 0;
    if(!limit && !zero && (~dp[dep][sta])) return dp[dep][sta];
    ll res = 0;
    int up = limit?num[dep]:9;
    for(int i = 0; i <= up; i ++ ){
        res += dfs(limit && i == up, zero&&i==0,sta - p[dep]*i, dep - 1);
    }
    if(!limit&&!zero) dp[dep][sta] = res;
    return res;
}
ll count(int n){
    int len = 0;
    if(n == 0) return cal(n)>=k;
    while(n){
        num[len++] = n%10;
        n /= 10;
    }
    return dfs(true,true,k,len-1);
}
void sol(){
    scanf("%d%d", &a,&n);
    k = cal(a);
    int x = n;
    int base = 1, tot = 0;
    while(x){
        p[tot++] = base;
        base *= 2;
        x /= 10;
    }
    printf("Case #%d: %lld\n",++cas, count(n));
}
int main(){ 
    memset(dp,-1,sizeof dp);
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}