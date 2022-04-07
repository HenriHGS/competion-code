#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define debug(a) cout<<#a<<":"<<a<<endl
#define mp make_pair
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N = 1e3+10;
int dp[2][N<<1];
int n;
void sol(){
    memset(dp,-1,sizeof dp);
    cin>>n;
    int last = 0;
    dp[0][0] = 0;
    For(i,1,n){
        int x; cin>>x;
        int now = last^1;
        fori(j,0,N*2) dp[now][j] = -1;
        For(j,0,2000){
            int& pre = dp[last][j];
            if(pre == -1) continue;
            if(j - x < 0) {
                int& a = dp[now][0];
                if(a == -1) {
                    a = pre + x - j;
                }else a = min(a,pre + x - j);
            }else {
                int& a = dp[now][j-x];
                if(a == -1) {
                     a = pre;
                }else a = min(a,pre);
            }
            if(j + x <= 2000){
                int& a = dp[now][j+x];
                int& pre = dp[last][j];
                if(a == -1) a = max(pre,j+x);
                else a = min(a,max(pre,j+x)) ;
            }
        }
        last ^= 1;
    }
    int mi = 1e9;
    For(i,0,2000) if(dp[last][i] != -1)mi = min(mi,dp[last][i]);
    cout<<mi<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}