#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <numeric>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
int a[N];
typedef long long ll;
ll sum, ans;
ll pre[N], c[N];
int main(){
    int n; scanf("%d %lld", &n, &sum);
    For(i,1,n){
        scanf("%d", &a[i]);
        pre[a[i]] += a[i], c[a[i]]++;
    }
    int mx = *max_element(a+1,a+1+n);
    For(i,1,mx*2){
        pre[i] += pre[i-1];
        c[i] += c[i-1];
    }
    For(i,1,mx){
        ll lastSum = 0, lastC = 0;
        ll cost = 0;
        for(int j = i; j <= mx + i; j += i){
            ll curSum = pre[j] - lastSum;
            ll curC = c[j] - lastC;
            cost += curC*j - curSum;
           /*  if(j ==3 || j == 4 || j == 9){
                cout<<curC*j - curSum<<" "<<curC*j<<" "<<curSum<<endl;
            } */
            lastSum = pre[j];
            lastC = c[j];
        }
      //  cout<<cost<<endl;
        if(cost <= sum) ans = max(ans,ll(i));
    }
    ll cost = 1LL*mx*n - pre[mx];
    if(cost < sum){
        ans = mx + (sum - cost)/n;
    }
    printf("%lld\n", ans);
    return 0;
}