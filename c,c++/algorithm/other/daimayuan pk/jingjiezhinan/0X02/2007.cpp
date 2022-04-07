#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[20][20];
char a[6], b[6];
char cur;
void open(int i, int k) {
  if (cur == '1')
    a[i] |= (1 << k);
  else
    a[i] &= ~(1 << k);
}
void change(int i, int k) { b[i] ^= (1 << k); }
void sol() {
  int ans = -1;
  for (int i = 1; i <= 5; i++)
    cin >> (s[i]);
  for (int i = 1; i <= 5; i++)
    for (int j = 0; j < 5; j++) {
      cur = s[i][j];
      open(i, j);
    }
  for (int bitmask = 0; bitmask < 1 << 5; bitmask++) {
    int anst = 0;
    memcpy(b, a, 6);
    for (int i = 0; i < 5; i++) {
      int left = bitmask >> i & 1;
      // int  right = b[1]>>i&1;
      if (left) {
        change(1, i), anst++;
        if (i)
          change(1, i - 1);
        if (i + 1 < 5)
          change(1, i + 1);
        change(2, i);
      }
    }
    // if (bitmask == 1)
    //   for (int i = 1; i <= 5; i++)
    //     cout << (int)b[i] << endl;
    for (int i = 1; i <= 4; i++) {
      for (int j = 0; j < 5; j++) {
        int left = b[i] >> j & 1;
        if (left == 0) {
          //   if (bitmask == 1)
          //     cout << "i:" << i << ", j:" << j << endl;
          if (j)
            change(i + 1, j - 1);
          change(i + 1, j);
          if (j + 1 < 5)
            change(i + 1, j + 1);
          change(i, j);
          if (i + 1 <= 5)
            change(i + 2, j);
          anst++;
        }
      }
    }
    // if (bitmask == 1)
    //   for (int i = 1; i <= 5; i++)
    //     cout << (int)b[i] << endl;
    if (anst > 6)
      continue;
    bool ok = true;
    // cout << "bitmask:" << bitmask << endl;
    // for (int i = 1; i <= 5; i++)
    //   cout << (int)b[i] << endl;
    for (int i = 0; i < 5; i++)
      ok &= (b[5] >> i & 1);
    if (!ok)
      continue;
    if (ans == -1)
      ans = anst;
    else
      ans = min(ans, anst);
  }
  cout << ans << endl;
}
int main() {
  int n;
  cin >> n;
  while (n--)
    sol();
  return 0;
}