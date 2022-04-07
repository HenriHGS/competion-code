#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int mod = 998244353;
const int N = 410;
bool g[N][N];
int dp[N][N];
int n;
int fac[N*2], inv[N*2];
int qpow(int a, int k, int p){
    int res =1;
    while(k){
        if(k & 1) res = 1LL*res*a%p;
        a = 1LL*a*a%p;
        k >>= 1; 
    }
    return res;
}
void init(){
    fac[0] = inv[0] = 1;
    fori(i,1,N*2) fac[i] = 1LL*fac[i-1] * i %mod;
    inv[N*2 - 1] = qpow(fac[N*2-1],mod-2,mod);
    for(int i = N*2 - 2; i; i -- ) inv[i] = 1LL*inv[i+1]*(i+1)%mod;
}
int C(int a, int b){
    return 1LL*fac[b]*inv[a]%mod*inv[b-a]%mod;
}
int dping(int l, int r){
    if(l > r) return 1;
    if(dp[l][r] != -1) return dp[l][r];
    int &ans = dp[l][r] = 0;
    for(int i = l + 1; i <= r; i ++ ){
        int len1 = i - l - 1, len2 = r - i;
        if(len1%2 || !g[l][i]) continue;
        int tmp = 0;
        int cal1 = dping(l+1, i - 1);
        int cal2 = dping(i + 1, r);
        len1 /= 2, len2 /= 2;
        tmp = 1LL*cal1*cal2 % mod * C(len2,len1+len2+1) % mod;
        //这里记得有步数。类似于走格子
        ans = (ans + tmp) % mod;
    }
    return ans;
}
int main(){
    init();
    memset(dp,-1, sizeof dp);
    int n, m;
    scanf("%d %d", &n, &m);
    For(i,1,m){
        int a, b; scanf("%d %d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    printf("%d\n", dping(1,2*n));
    return 0;
}