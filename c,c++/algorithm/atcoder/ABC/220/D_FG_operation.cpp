#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 3e5+10;
const int mod = 998244353;
int a[N];
int dp[10][2];
int main(){
    int n; cin>>n;
    For(i,1,n) cin>>a[i];
    int cnt = n;
    int v1 = (a[1] + a[2]) % 10;
    int v2 = (a[1] * a[2]) % 10;
    dp[v1][0]++;
    dp[v2][0]++;
    int last = 0;
    for(int i = 3; i <= n; i ++ ){
        int now = last^1;
        For(j,0,9) dp[j][now] = 0;
        for(int j = 0; j <= 9;  j++ ){
            int v1 = (j + a[i]) % 10;
            int v2 = (j * a[i]) % 10;
            dp[v1][now] += dp[j][last];
            dp[v1][now] %= mod;
            dp[v2][now] += dp[j][last];
            dp[v2][now] %= mod;
        }
        last ^= 1;
    }
    For(i,0,9) cout<<dp[i][last]<<endl;
    return 0;
}