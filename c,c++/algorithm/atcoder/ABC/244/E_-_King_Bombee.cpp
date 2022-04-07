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
const int mod = 998244353;
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

const int maxn = 2000 + 10;
vector<int> e[maxn];
ll dp[maxn][maxn][2];
int src, dest, k, x, n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k >> src >> dest >> x;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  memset(dp, 0, sizeof dp);

  dp[src][0][0] = 1;
  for (int j = 1; j <= k; j++) {
    for (int u = 1; u <= n; u++) {
      for (auto v : e[u]) {
        if (v != x) {
          dp[v][j][0] = (dp[v][j][0] + dp[u][j - 1][0]) % mod;
          dp[v][j][1] = (dp[v][j][1] + dp[u][j - 1][1]) % mod;
        } else {
          dp[v][j][1] = (dp[v][j][1] + dp[u][j - 1][0]) % mod;
          dp[v][j][0] = (dp[v][j][0] + dp[u][j - 1][1]) % mod;
        }
      }
    }
  }
  cout << dp[dest][k][0] << endl;
  return 0;
}