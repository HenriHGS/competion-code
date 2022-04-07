#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
typedef long long LL;
const int N = 1e5+10;
int a[N];
typedef pair<int,int>PII;
map<int,int>ma;
int main(){
    ll ans = 0;
    int n; ll k;
    scanf("%d %lld", &n, &k);
    priority_queue<PII>que;
    For(i,1,n){
        int x;
        scanf("%d", &x);
        ma[x] += 1;
    }
    for(auto x: ma){
        que.push({x.first,x.second});
    }
    int now = 0;
    que.push({0,0});
  //  ll ans = 0;
    while(1){
        auto u = que.top();
        que.pop();
        if(u.x <= 0) break;
        auto v = que.top();
        que.pop();
        ll mx = (ll)(u.x - v.x) * u.y;
        ll times = min(mx,k);
        ll dis = times/u.y;
        ll rem = times%u.y;
        ll sum1 = dis*(u.x-dis+1+u.x)/2;
        ll sum2 = (u.x-dis) * rem;
        ans += sum1 * u.y;
        ans += sum2;
        k -= times;
        if(k == 0) break;
        /*
        PII nu = {u.x - dis,u.y - rem};
        if(rem){
            PII nu2 = {u.x - dis - 1, rem};
            if(nu2.x == v.x) {
                v.y += nu2.y;
                que.push(v);
            }else que.push(nu2);
            que.push(nu);
        }else {
            */
           // if(nu.x == v.x) {
                v.y += u.y;
                que.push(v);
           // }else que.push(nu);
    //    }
    }
    printf("%lld\n", ans);//cout<<ans<<endl;
    return 0;
}