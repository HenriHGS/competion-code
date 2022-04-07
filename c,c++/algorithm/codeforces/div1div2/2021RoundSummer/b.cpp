#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
typedef long long ll;
int a[N];
void sol(){
    int n;
    scanf("%d", &n);
    int cnt[2]{};
    ll sum[2]{};
    ll tot[2]{};
    For(i,1,n) {
        scanf("%d", a+i);
        a[i] = a[i]&1;
        cnt[a[i]]++;
        sum[a[i]] += i;
        tot[i&1] += i;
    }
    int dis = abs(cnt[0]-cnt[1]);
    if(dis >= 2){
        puts("-1");
        return ;
    }
    ll ans = 1e18;
    //ll ans = min( abs(sum[0]-tot[0]) + abs(sum[1]-tot[1]), 
    if(n&1){
        if(cnt[1]&1)ans = min(ans,abs(sum[0]-tot[0]) + abs(sum[1]-tot[1]));
        else ans = min(ans, abs(sum[0]-tot[1]) + abs(sum[1]-tot[0]) );
    }else {
        ans = min(ans,abs(sum[0]-tot[0]) + abs(sum[1]-tot[1]));
        ans = min(ans, abs(sum[0]-tot[1]) + abs(sum[1]-tot[0]) );
    }
    //abs(sum[0]-tot[1]) + abs(sum[1]-tot[0]) );
    printf("%lld\n", ans/2);
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}