#include <iostream>
#include <algorithm>
#include <iomanip>  
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 200+10;
double dp[N][N][N];
double p[N];
int a[N];
int main(){
    ios::sync_with_stdio(0);
    int n, k, l;
    cin>>n>>k>>l;
    fori(i,0,n){
        cin>>p[i];
        p[i] /= 100;
    }
    fori(i,0,n)cin>>a[i];
    dp[0][0][min(l,n)] = 1;
    fori(i,0,n)For(j,0,i){
        For(k,0,n){
            dp[i+1][j][k] += dp[i][j][k]*(1-p[i]);//false;
            if(a[i] == -1){
                dp[i+1][j+1][k] += dp[i][j][k]*p[i];
            }else {
                int nn = min(k + a[i] + 1, n);//wa
                dp[i+1][j+1][nn] += dp[i][j][k]*p[i];
            }
        }
    }
    double ans = 0;
    //k = min(k,n);
    For(j,k,n){
        For(i,j,n)ans += dp[n][j][i];
    }
    cout<< fixed << setprecision(20)<< ans<<endl;
    return 0;
}