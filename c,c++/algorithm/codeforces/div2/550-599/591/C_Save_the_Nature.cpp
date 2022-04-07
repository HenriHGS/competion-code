#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;

const int N = 2e5+10;
typedef long long ll;
ll p[N];
ll x, y, n, a, b, k;
bool check(int mid){
    int cnt[3]{};
    For(i,1,mid){
        if(i%a == 0 && i % b != 0) cnt[0] ++;
        if(i%b == 0 && i % a != 0) cnt[1]++;
        if(i%a==0 && i % b == 0) cnt[2]++;
    }
    //if(x > y) swap(cnt[1],cnt[0]);
    ll sum = 0;
    for(int i = 1; i <= n; i ++ ){
        bool fl = true;
        fori(j,0,3) fl &= !(cnt[j] != 0);
        if(fl) break;
        if(cnt[2]) {
            cnt[2]--;
            sum += p[i] /100  * (x+y);
            continue;
        }
        if(cnt[1]){
            cnt[1]--;
            sum += p[i] / 100 * y;
            continue;
        }
        if(cnt[0]){
            cnt[0]--;
            sum += p[i]/ 100*x;
            continue;
        }
    }
    return sum >= k;
}
void sol(){
    cin>>n;
    For(i,1,n) cin>>p[i];
    sort(p+1,p+1+n); reverse(p+1,p+1+n);
    cin>>x>>a;// /100*x
    cin>>y>>b;
    if(x > y){
        swap(x,y); swap(a,b);
    }
    cin>>k;
    int ans = -1;
    int l = 1, r = n;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid))ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--) sol();
    return 0;
}