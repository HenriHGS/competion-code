#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
void table(ll n){
    ll tmp = n;
    vector<ll> p(14),p9(14);
    p[0] = 1;
    p9[0] = 0;
    For(i,1,9){
        p[i] = p[i-1]*10;
        p9[i] = p9[i-1]*10+9;
    }
    vector<int>ans(10);
    for(int i = 9; i >= 0; i -- ){
        if(p[i] <= n) ans[i] += n / p[i], n = n % p[i];
    }
    for(int i = 0; i < 10; i ++ ) printf("a[%d] = %d\n", i, ans[i]);
    ll res = 0;
    for(int i = 0; i < 10; i ++ ) res += ans[i]* p[i];
    cout<<(res == tmp);
}
/*
999999920999999999
a[0] = 9
a[1] = 9
a[2] = 9
a[3] = 9
a[4] = 9
a[5] = 9
a[6] = 9
a[7] = 9
a[8] = 9
a[9] = 999999920
1
*/
int main(){
    /* ll n;
    cin>>n;
    table(n); */
    
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--){
        ll ans = 0;
        int n, k; cin>>n>>k;
        k++;
        vector<ll> a(n + 1), p(14),p9(14), vis(10);
        For(i,1,n) cin>>a[i], vis[a[i]] = 1;
        p[0] = 1;
        p9[0] = 0;
        For(i,1,9){
            p[i] = p[i-1]*10;
            p9[i] = p9[i-1]*10+9;
        }
        ll cnt = 0;
        int pre = 0;
        for(int i = 0; i < 10; i ++ ){
            if(i > a[n]) break;
            if(vis[i])pre = i;
            if(cnt + p[i - pre]*9 > k){
                ll rem = k - cnt;
                ll mul = rem/p[i-pre];
               // debug(mul);
              //  debug(cnt);
              //  debug(ans);
                ans += (rem - mul*p[i-pre])*p[pre] + mul*p[i];cnt = k;
               // debug(ans);
             //   debug(i);
                break;
                
            }else {
                ans += p[i]*9;
                cnt += p[i-pre]*9;
               // debug(cnt);
              // debug(ans);
            }
        }
        if(cnt < k) ans += (k - cnt)*p[a[n]];
        cout<<ans<<endl;
    }
    return 0;
}