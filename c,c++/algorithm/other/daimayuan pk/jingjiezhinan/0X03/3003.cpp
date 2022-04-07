#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(0);
  ll ans1 = 0, pos = 0, neg = 0;
  ll n, pre = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    if (pre != -1){
        // ans1 += abs(x - pre);
        if(x > pre) {
            ll cur = x - pre;
            if(neg) {
                ll sub = min(cur,neg);
                cur -= sub;
                neg -= sub;
            }
            pos += cur;
            ans1 += cur;
        }else if(x < pre){
            ll cur = pre - x;
            if(pos) {
                ll sub = min(cur, pos);
                cur -= sub;
                pos -= sub;
            }
            neg += cur;
            ans1 += cur;
        }
        //if(x > pre) pos += x - pre;
        //else neg += pre - x;
    }
    pre = x;
  }
  cout << ans1 << endl;
  cout<<pos + neg + 1<<endl;
  // cout<<ans2<<endl;
  return 0;
}