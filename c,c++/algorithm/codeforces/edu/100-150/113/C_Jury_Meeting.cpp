#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int mod = 998244353;
const int N = 2e5+10;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = 1LL*res*a%p;
        a = 1LL*a*a%p;
        k >>= 1;
    }
    return res;
}
int fac[N], inv[N];
void init(){
    fac[0] = inv[0] = 1;
    fori(i,1,N) fac[i] = 1LL*fac[i-1]*i%mod;
    inv[N-1] = qpow(fac[N-1],mod-2,mod);
    for(int i = N - 2; i ; i -- )inv[i] = 1LL*inv[i+1]*(i+1)%mod;
}
int C(int b, int a){
    return 1LL*fac[a]*inv[a-b]%mod*inv[b]%mod;
}
int A(int b, int a){
    return 1LL*C(b,a)*fac[b]%mod;
}
void solve(){
    int n;
    scanf("%d", &n);
    vector<int> a(n),b(n);
    fori(i,0,n) scanf("%d", &a[i]), b[i] = a[i];
    sort(all(b));
    int ans = 1;
    For(i,1,n-1) ans = 1LL*i*ans%mod;
    b.erase(unique(all(b)),b.end());
    int m = sz(b);
    int mx1 = 0, mx2 = 0;
    fori(i,0,n) if(a[i] == b[m-1]) mx1++;
    else if(a[i] == b[m-2]) mx2++;
    if(b.back() == b[0] || mx1>=2) printf("%d\n", 1LL*ans*n%mod);
    else if(b[m-1] - b[m-2] >= 2) puts("0");
    else {
        ans = 1LL*ans*n%mod;
        int sub = 0;
        for(int i = 1; i + mx1 <= n; i ++ ){
            int l = 1, r = i;
            int len = r - l + 1;
            if(len < mx2) continue;
            int add = 1LL*A(mx2-1,len-1)*mx2%mod*A(mx1,n-len)%mod*fac[n-mx1-mx2]%mod;
          //  debug(add);
            sub = sub + add;
            sub %= mod;
        }
        ans = (1LL*ans - sub + mod)%mod;
        printf("%d\n", ans);
    }
}
int main(){
    init();
    //debug(A(0,1));
    int tt;
    scanf("%d", &tt);
    while(tt-- ) solve();
    return 0;
}