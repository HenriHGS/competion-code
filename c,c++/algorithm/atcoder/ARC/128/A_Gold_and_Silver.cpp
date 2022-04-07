#include <map>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define mst(x,a) memset(x,a,sizeof x)
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll dp[N][2];
ll a[N];
int path[N][2];
int ansp[N];
//dp 方程应该没有错的，只不过应该是没考虑到极端的数据。被卡死了
// hack: 1e9 1 1e9 1 1e9 1 1e9 1 1e9 1 1e9 1,这样乘几次就爆了。
int main(){
    int n; cin>>n;
    int pre = -1;
    For(i,1,n) {
        int x;
        cin>>x;
        if(pre != -1 && pre > x) {
            ansp[i-1] ^= 1;
            ansp[i] ^= 1;
        }
        pre = x;
    }
    For(i,1,n) cout<<ansp[i]<<" \n"[i==n];
    return 0;
}
/* int main(){
    int n; 
    cin>>n;
    dp[0][1] = 1;
    ll ans = 1;
    mst(path,-1);
    path[0][0] = path[0][1] = 0;
    For(i,1,n){
        int x; cin>>x;
        dp[i][0] = dp[i-1][0];
        path[i][0] = path[i-1][0];
        dp[i][1] = dp[i-1][1];
        path[i][1] = path[i-1][1];
        //dp[i][0] = max(dp[i][0], dp[i-1][1]*x);
        ll sil = dp[i-1][1]*x;
        if(dp[i][0] < sil){
            dp[i][0] = sil;
            path[i][0] = i; 
        }
        ll gold = dp[i-1][0]/x;
        //dp[i][1] = max(dp[i][1], dp[i-1][0]/x);
        if(dp[i][1] < gold){
            dp[i][1] = gold;
            path[i][1] = i;
        }
        ans = max(ans,dp[i][1]);
    }
    //cout<<ans<<endl;
    if(ans != 1){
        int pos = 0;
        For(i,1,n){
            if(ans == dp[i][1]){
                pos = i; 
                break;
            }
        }
        int col = 1;
        for(int i = pos; i; i = path[i][col]){
            col ^= 1;
            ansp[i] = 1;
        }
    }
    For(i,1,n) cout<<ansp[i]<<" \n"[i==n];
    return 0;
} */