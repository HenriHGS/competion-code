#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll mul(ll a, ll b, ll p) {
  a %= p, b %= p; // 保证ab都小于p这样 a*b/p的有效位会是18-19位
  ll c = (long double)a * b / p;
  ll ans = a * b - c * p;
  if (ans < 0)
    ans += p;
  else if (ans >= p)
    ans -= p;
  return ans;
  return 1;
}

int main() {
  ll a, b, p;
  cin >> a >> b >> p;
  /* ll ans = 0;
  while(b){
      if(b&1) ans = (ans + a) %p;
      a = a * 2 % p;
      b >>= 1;
  } */
  ll ans = mul(a, b, p);
  cout << ans << endl;
  return 0;
}

/*
250182048980811753
413715569939057660
133223633696258584
 */