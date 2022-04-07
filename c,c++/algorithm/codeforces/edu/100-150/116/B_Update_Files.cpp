#include <cstring>
#include <string>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--){
        ll n, k;
        ll ans = 0;
        cin>>n>>k;
        ll st = 1;
        while(1){
            if(st >= n) break;
            if(st <= k) st *= 2, ans++;
            else {
                ans += (n - st + k - 1)/k;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}