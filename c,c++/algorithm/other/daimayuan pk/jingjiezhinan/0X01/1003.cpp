#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define For(i, x, y) for (int i = (x); i <= (y); i++)
#define fori(i, x, y) for (int i = (x); i < (y); i++)
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x, a) memset(x, a, sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n'
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
typedef pair<int, int> pa;
typedef pair<ll, ll> pai;
typedef pair<db, db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template <typename T1, typename T2> void ckmin(T1 &a, T2 b) {
  if (a > b)
    a = b;
}
template <typename T1, typename T2> void ckmax(T1 &a, T2 b) {
  if (a < b)
    a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch))
    f |= ch == '-', ch = getchar();
  while (isdigit(ch))
    x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T> void print(T x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x >= 10)
    print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T> void print(T x, char let) { print(x), putchar(let); }
template <class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template <class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 100000 + 6;

int f[1 << 20][20];
int a[20][20];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  memset(f, 0x3f, sizeof f);
  f[1][0] = 0;//fori(i, 0, n) f[1 << i][i] = 0;
  fori(i, 0, n) fori(j, 0, n) cin >> a[i][j];
  for (int i = 0; i < 1 << n; i++) {
    for (int k = 0; k < n; k++)
      if ((i >> k) & 1)
        for (int j = 0; j < n; j++) {
          if (((i >> j) & 1) == 0)
            f[i ^ (1 << j)][j] = min(f[i ^ (1 << j)][j], f[i][k] + a[k][j]);
        }
  }
  int ans = f[(1 << n) - 1][n-1];
  //fori(i, 0, n) ans = min(ans, f[(1 << n) - 1][i]);
  cout << ans << endl;
  return 0;

}


/* 5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0 */