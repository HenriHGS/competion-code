#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

typedef long long ll;
const int mod = 998244353;

int main(){
    int n; cin>>n;
    vector<int>a(n), b(n);
    vector<vector<int>> dp(n+2,vector<int>(3000+1,0));
    fori(i,0,n) cin>>a[i];
    fori(i,0,n) cin>>b[i];
    dp[0][0] = 1;
    fori(i,1,3001)dp[0][i]  = 1;//= dp[0][i-1] + 1;
    
    int ans = 0;
    fori(i,0,n){
        For(j,a[i],b[i]){
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= mod;
            if(i == n-1) ans = (ans + dp[i+1][j])%mod;
        }
        For(j,1,3000) dp[i+1][j] = (dp[i+1][j-1]+dp[i+1][j])%mod;
    }
    cout<<ans<<endl;
    return 0;
}