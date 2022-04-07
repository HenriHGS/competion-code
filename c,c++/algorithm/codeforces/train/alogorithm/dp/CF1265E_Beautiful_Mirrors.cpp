#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10, mod = 998244353;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = (ll)res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
int p[N];
int main(){
    ios::sync_with_stdio(0);
    int n; cin>>n;
    int ans = 0;
    int x = 1;
    for(int i = 1; i <= n; i ++ ) cin>>p[i];
    for(int i = n; i >= 1; i -- ){
        x = 1ll*x * 100%mod * qpow(p[i],mod-2,mod)%mod;
        ans = (ans +  x) % mod; 
    }
    cout<<ans<<endl;
    return 0;
}