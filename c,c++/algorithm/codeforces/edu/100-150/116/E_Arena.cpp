#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int md = 998244353;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = 1ll*res * a %p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
const int N = 510;
int fac[N+1], inv[N+1];
int dp[N][N];
void init(){
    fac[0] = inv[0] = 1;
    For(i,1,N) fac[i] = 1ll*fac[i-1]*i%md;
    inv[N] = qpow(fac[N],md-2,md);
    for(int i = N - 1; i >= 0; i -- ) inv[i] = 1ll*inv[i+1]*(i+1)%md;
}
int C(int b, int a){
    return 1ll*fac[a]*inv[a-b]%md*inv[b]%md;
}
int main(){
    ios::sync_with_stdio(0);
    init();
    int n, x; cin>>n>>x;
    For(i,2,n){
        For(j,1,x){
            if(i > j) dp[i][j] = qpow(j,i,md);
            else {
                dp[i][j] = qpow(i-1,i,md);
                for(int k = 0; k < i; k ++ ) dp[i][j] += 1ll* C(k,i)*qpow(i-1,k,md) % md*dp[i-k][j-i+1]%md,dp[i][j] %= md;
            }
        }
    }
    cout<<dp[n][x]<<endl;
    return 0;
}