#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll pre[N];
int main(){
    int n; cin>>n;
    For(i,1,n){ //cin>>a[i];{
        ll x; cin>>x;
        pre[i] = pre[i - 1] + x;
    }
    ll x; cin>>x;
    ll ans = 0 + x/pre[n]*n;
    x = x - x / pre[n] * pre[n];
    int add = lower_bound(pre + 1, pre +1 + n, x) - pre;
    if(pre[add] == x) add++;
    ans += add;
    cout<<ans<<endl;
    
    return 0;
}