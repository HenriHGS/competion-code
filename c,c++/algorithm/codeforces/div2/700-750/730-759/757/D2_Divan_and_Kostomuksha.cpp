#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#define CF
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int maxm = 2e7+10;
int cnt[maxm+1];
ll dp[maxm+1];

int primes[maxm], tot;
int st[maxm + 1];
void init(){
    for(int i = 1; i <= maxm; i ++ ) st[i] = i;
    for(int i = 2; i <= maxm; i ++ ){
        if(st[i] == i) primes[tot++] = i;
        for(int j = 0; j < tot && i <= maxm/ primes[j]; j ++ ){
            st[i *primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}
int main(){
    #ifdef CF
    ios::sync_with_stdio(0);
    #endif
    int n; cin>>n;
    For(i,1,n) {
        int x;cin>>x;
        cnt[x]++;
    }
    init();
    for(int i = 0, pr; i < tot; i ++ ){
        pr = primes[i];
        for(int j = maxm/pr; j > 0; j -- ){
            cnt[j] += cnt[j*pr];
        }
    }
    dp[1] = cnt[1];
    ll ans = 0;
    for(int i = 1;  i < maxm; i ++ ){
        for(int j = 0, pr = primes[j]; j < tot && 1ll*pr*i <= maxm; j ++, pr = primes[j]){
            dp[i*pr] = max(dp[i*pr], dp[i] + 1ll*(i*pr - i)*cnt[i*pr]);
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
} 