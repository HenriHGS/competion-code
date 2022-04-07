#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
long long  dp[40][40];
int main(){
    ios::sync_with_stdio(0);
    int n, h;
    cin>>n>>h;
    For(i,0,n)dp[0][i] = 1;
    For(i,1,n)For(j,1,n){
        fori(k,0,i){//枚举分界点
            dp[i][j] += dp[k][j-1]*dp[i-k-1][j-1];
        }
    }
    cout<<dp[n][n] - dp[n][h-1]<<endl;
    return 0;
}