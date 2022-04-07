#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define CF
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int maxm = 5e6+10;
int cnt[maxm];
ll dp[maxm];
int main(){
    #ifdef CF
    ios::sync_with_stdio(0);
    #endif
    int n; cin>>n;
    For(i,1,n) {
        int x;cin>>x;
        cnt[x]++;
    }
    fori(i,1,maxm){
        for(int j = i+i; j < maxm; j += i){
            cnt[i] += cnt[j]; 
        }
    }
    ll ans = 0;
    for(int i = maxm - 1; i >= 1; i -- ){
        dp[i] = 1ll*cnt[i]*i;
        for(int j = i + i; j < maxm; j += i){
            dp[i] = max(dp[i], dp[j] + 1ll*(cnt[i] - cnt[j])*i);
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
} 