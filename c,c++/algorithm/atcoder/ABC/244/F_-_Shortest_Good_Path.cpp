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

const int maxn = (1 << 20);

int dp[maxn][20];
vector<int> e[20];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--; // w[u][v] = w[v][u] = 1;
    e[u].push_back(v), e[v].push_back(u);
  }
  memset(dp, 0x3f, sizeof dp);
  int N = 1 << n;
  queue<pair<int, int>> que;
  for (int i = 0; i < n; i++)
    dp[1 << i][i] = 1, que.push({1 << i, i});
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    int s = p.fi, u = p.se;
    for (auto v : e[u]) {
      int sn = 1 << v ^ s;
      if (dp[sn][v] < inf)
        continue;
      dp[sn][v] = dp[s][u] + 1;
      que.push({sn, v});
    }
  }
  ll ans = 0;
  for (int i = 1; i < N; i++) {
    int add = inf;
    for (int j = 0; j < n; j++)
      add = min(add, dp[i][j]);
    ans += add;
  }
  cout << ans << endl;
  return 0;
}