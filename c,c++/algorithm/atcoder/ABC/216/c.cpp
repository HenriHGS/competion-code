#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
typedef long long LL;
void check(){
    for(int j = 1; j <= 1000; j ++ ){
        ll n = j, cur = 0, pre = 0;
        for(ll i = 1LL<<62; i; i >>= 1){
            bool c = i&n;
            if(pre) cur*=2;//ans += 'B';
            if(c){
                cur += 1;
                pre = true;
              //  ans += 'A';
            }
        }
        if(cur != j) cout<<"NO";
    }
}
int main(){
  //  check();
    ll n;
    cin>>n;
    bool pre = false;
    /*
    cout<<__lg(1)<<endl;
    ll a = 1e18;
    cout<<a<<endl;
    int cnt2 = __lg(a);
    cout<<cnt2<<endl;
    */
    string ans = "";
   // ll a = 1LL<<62;
    //a>>=1;
    //cout<<a<<endl;
  //  bool c = a&n;
    //cout<<c<<endl;
    int len = __lg(n);
    for(ll i = 1LL<<len; i; i >>= 1){
        bool c = i&n;
        if(pre)ans += 'B';
        if(c){
            pre = true;
            ans += 'A';
        }
        pre = true;
    }
    cout<<ans<<endl;
    return 0;
}