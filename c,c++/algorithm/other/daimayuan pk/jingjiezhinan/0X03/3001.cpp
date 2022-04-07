#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5003;
int dp[N][N];
template <typename T1, typename T2> void ckmax(T1 &a, T2 b) { a = max(a, b); }
int main() {
  ios::sync_with_stdio(0);
  int n, r;
  cin >> n >> r;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    x++, y++;
    int add;
    cin >> add;
    dp[x][y] += add;
    ckmax(mx, x);
    ckmax(mx, y);
    // mx = max()
  }
  int ans = 0;
  n = mx;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
      if (r) {
        int len_x = min(i, r), len_y = min(j, r);
        int temp = dp[i][j] - dp[i - len_x][j] - dp[i][j - len_y] +
                   dp[i - len_x][j - len_y];
        // cout << temp << endl;
        ckmax(ans, temp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
