#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
using namespace std;

typedef long long LL;
const int N = 8010;
const LL INF = 0x3f3f3f3f;
int f[N][N];
int a[N];
struct Tree1
{
    int l, r;
}_tr[N << 2];

int tr[N][N << 2];

void push_up(int k, int u)
{
    tr[k][u] = min(tr[k][u << 1], tr[k][u << 1 | 1]);
}

void build(int l, int r, int u)
{
    _tr[u] = {l, r};
    if (l == r) return ;
    int mid = l + r >> 1;
    build(l, mid, u << 1);
    build(mid + 1, r, u << 1 | 1);
}

void update(int k, int x, LL C, int u)
{
    if (_tr[u].l == _tr[u].r)
    {
        tr[k][u] = C;
        return ;
    }
    int mid = _tr[u].l + _tr[u].r >> 1;
    if (x <= mid) update(k, x, C, u << 1);
    else update(k, x, C, u << 1 | 1);
    push_up(k, u);
}

LL query(int k, int l, int r, int u)
{
    if (_tr[u].l >= l && _tr[u].r <= r)
    {
        return tr[k][u];
    }
    int mid = _tr[u].l + _tr[u].r >> 1;
    LL res = INF;
    if (l <= mid) res = min(res, query(k, l, r, u << 1));
    if (r > mid) res = min(res, query(k, l, r, u << 1 | 1));
    return res;
}

int main()
{
    int n;
    cin >> n;
    stack<int> stk;
    memset(tr, 0x3f, sizeof tr);
    memset(f, 0x3f, sizeof f);
    f[0][1] = 0;
    build(1, n, 1);
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        f[i][1] = max(f[i - 1][1], a[i]);
        update(1, i, f[i][1], 1);
        while (stk.size() && a[stk.top()] < a[i]) stk.pop();
        int k = 0;
        if (stk.size()) k = stk.top();
        stk.push(i);
        for (int j = 2; j <= i; j ++ )
        {
            f[i][j] = f[k][j];
            int x = query(j - 1, max(k, j - 1), i - 1, 1);
            f[i][j] = min(f[i][j], x + a[i]);
            update(j, i, f[i][j], 1);
        }
    }
    sort(a + 1, a + 1 + n, greater<int>());
    LL sum = 0;
    for (int i = 1; i <= n; i ++ )
    {
        sum += a[i];
        cout << f[n][i] << " " << sum << "\n";
    }
    return 0;
}

