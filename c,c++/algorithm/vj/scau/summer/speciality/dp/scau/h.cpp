#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int up = 1e9+10;
typedef long long ll;
map<ll,ll>dp[20];
//dp[pro][20]
int k;
ll n;
int num[20];
ll dfs(bool limit, bool zero, int dep, ll mul){
    if(dep < 0) return mul <= k;
    if(mul > k) mul = k + 1;
    if(!limit && !zero && dp[dep].count(mul)) return dp[dep][mul];
    //ll& ans = dp[dep][mul];
    int up = limit?num[dep]:9;
    ll res = 0;
    for(int i = 0; i <=up; i ++ ){
        res += dfs(limit&&i==up, zero&&i==0, dep-1, zero&&i==0?1:mul*i);
    }
    if(!limit && !zero) dp[dep][mul] = res;//ans = res;
    return res;
}
ll count(ll n){
    int len = 0;
    if(n == 0) return 0;
    while(n){
        num[len++] = n%10;
        n /= 10;
    }
    return dfs(true,true,len-1,1) - 1;
}
int main(){
    scanf("%lld%d",&n,&k);
    //printf("%lld\n",n);
    printf("%lld",count(n));
    return 0;
}