#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll k){
    ll res = 1;
    while(k){
        if(k&1) res = res*a;
        a = a*a;
        k >>= 1;
    }
    return res;
}
int main(){
    int n; 
    ll ans1, ans2;
    cin>>n;
    //cal ans1
    {
        if(n == 1) ans1 = 1;
        else if(n == 2) ans1 = 2;
        else if(n == 3) ans1 = 2;
        else if(n == 4) ans1 = 3;
        else {
            vector<int> num;
            int sum = 2, i = 2;
            for(i = 2; sum <= n;){
                num.push_back(i);
                i++;
                sum += i;
            }
            int rem = sum - n;
            if(rem != i){
                int add = i - rem;
                for(int i = (int)num.size() - 1; i >= 0; i -- ){
                    num[i]++;
                    add--;
                    if(add == 0) break;
                }
            }
            ans1 = 1;
            for(auto x: num){
                //cout<<x<<endl;
                ans1 *= x;
            } 
        }
    }
    //cal ans2
    {
        if(n % 3 == 0) ans2 = qpow(3,n/3);
        else if(n%3 == 1) ans2 = 4*qpow(3,(n-4)/3);
        else if(n%3 == 2) ans2 = 2*qpow(3,(n-2)/3);
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}