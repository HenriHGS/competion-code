#include <iostream>
using namespace std;
typedef long long ll;
int qpow(int a, int k, int p){
    int res = 1 % p;
    while(k){
        if(k &1) res = 1ll*res * a % p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
void sol(){
    int m, n;
    cin>>m>>n;
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        int a, b; 
        cin>>a>>b;
        ans = ans + qpow(a,b,m);
        ans %= m;
    }
    cout<<ans<<endl;
}
int main(){
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}