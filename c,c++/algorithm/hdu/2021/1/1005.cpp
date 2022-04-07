#include <cstdio>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
using namespace std;
typedef long long LL;
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--){
        LL n;
        cin>>n;
        LL ans = 0;
        if(n >= 4){
            LL tot = n / 2 - 1;
            ans += tot*(6+2*tot)/2;
        }
        //debug(ans);
        if(n >= 3){
            LL tot = n/2;
            if(n%2==0)tot--;
            ans += tot*(4+2*tot);
        }
        cout<<ans<<endl;
    }
    return 0;
}