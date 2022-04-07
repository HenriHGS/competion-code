#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int mod = 425;
const int N = 1e5+10;
int v[N];
typedef long long ll;
const int MX_log = 21;
int logn[N+1];
int mi[N][MX_log+1];
void init(){
    logn[1] = 0, logn[2] = 1;
    fori(i,3,N){
        logn[i] = logn[i/2] + 1;
    }
}
const ll INF = 1e18;
ll check(int l, int r){
    if(l > r) return INF;
    int mib;
    int s = logn[r-l+1];
    mib = min(mi[l][s],mi[r-(1<<s)+1][s]);
    return mib;
}
int main(){
    int n; scanf("%d", &n);
    init();
    For(i,1,n) scanf("%d", &mi[i][0]);
    For(j,1,MX_log){
        for(int i = 1; i + (1<<j) - 1 <= n; i ++ ){
            mi[i][j] = min(mi[i][j-1], mi[i+(1<<(j-1))][j-1]);
        }
    }
    ll ans = 0;
    For(i,1,n){
        int ed = n;
        if(i == 1) ed = n-1;
        ll sum1 = min(check(i,ed),check(1,i-2));
      //  int last = (i-1 + n) %n;
      //  if(last == 0) last++;
        ll sum2 = 0;
        ans = max(ans,sum1+sum2);
    }
    printf("%lld\n", ans);
    return 0;
}