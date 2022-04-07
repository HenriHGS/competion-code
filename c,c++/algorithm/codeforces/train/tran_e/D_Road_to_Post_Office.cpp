#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    ll d, k, a, b, t;
    cin>>d>>k>>a>>b>>t;
    if(k >= d){
        cout<<d*a<<endl;
    }else {
        ll ans;
        if(k*a + t >= k*b) {
            ans = k*a + (d - k)*b;
        }else {
            ll time = d / k;
            ll sum = time*a*k;
            if(time) sum = sum + (time - 1) * t;
            ll rem = d - time*k;
            //drive
            {
                ans = sum + t + rem*a;
            }
            //walk
            {
                ans = min(ans, sum + rem*b);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}