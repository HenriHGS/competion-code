#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    int tt; scanf("%d", &tt);
    bool first = true;
    while(tt--){
        if(first) first = false;
        else puts("");
        ll n[5];
        For(i,2,4) scanf("%lld", &n[i]);
        ll r3 = n[3]/2;
        ll ans = 0;
        if(n[4] && r3){
            ll mi = min(r3,n[4]);
            n[4] -= mi;
            r3 -= mi;
            ans += mi;
        }
        if(n[2] && r3){
            ll mi = min(r3,n[2]/2);
            n[2] -= mi*2;
            r3 -= mi;
            ans += mi;
        }
        if(n[4]){
            ll mi = min(n[4]/2,n[2]);
            ans += mi;
            n[4] -= mi*2;
            n[2] -= mi;
            if(n[4]){
                ll mi = min(n[4], n[2]/3);
                ans += mi;
                n[2] -= mi*3;
            }
        }
        ans += n[2]/5;
        printf("%lld", ans);
    }
}