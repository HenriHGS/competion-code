#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 5010;
int a[N], b[N], n;
const int mod = 998244353;
int p[N];
int main(){
    p[0] = 1;
    For(i,1,N-1)p[i] = 1LL*p[i-1]*2%mod;
    scanf("%d", &n);
    For(i,1,n) scanf("%d", &a[i]);
    For(i,1,n) scanf("%d", &b[i]);
    int ans = 0;
    For(w,1,5000){
        int cnt1 = 0, cnt2 = 0;
        For(i,1,n){
            if(a[i] == w && b[i] <= w) cnt1++;
            else if(a[i] < w && b[i] <= w)cnt2++;
        }
        if(cnt1 == 0) continue;
        int add = 1LL*(p[cnt1] - 1 + mod)%mod;
        ans += 1LL*add*p[cnt2]%mod;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}