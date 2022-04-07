#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, s, t, a, b;
long double F(ll xx){
    long double ans = a*(xx - 1) /2.0 + b*n*1.0/xx;
    return ans;
}
int main(){
    cin>>n>>s>>t>>a>>b;
    ll xx = sqrt(2.0*b*n/a);
    long double ans = F(t);
    int cnt = 1;
    for(cnt = 1, xx = xx - 5; cnt <= 10; cnt ++, xx++){
        if(xx > t || xx <= 0) continue;
        ans = min(ans, F(xx));
    }
    if(s <= t) ans = min(ans, ((long double )t-s)*a);
    cout.precision(20);
    cout<<ans<<endl;
    return 0;
}