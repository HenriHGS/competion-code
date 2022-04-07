#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 300010;
int h[N], e[M], w[M], ne[M], idx;
int cnt[N], dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

bool spfa()
{
    stack<int> q;
    q.push(0);
    st[0] = true;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        st[u] = false;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[u] + w[i])
            {
                dist[j] = dist[u] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    cnt[j] = cnt[u] + 1;
                    if (cnt[j] > n) return true;
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i ++ )
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) add(b, a, 0), add(a, b, 0);
        else if (op == 2) add(a, b, 1);
        else if (op == 3) add(b, a, 0);
        else if (op == 4) add(b, a, 1);
        else add(a, b, 0);
    }
    for (int i = n; i >= 1; i -- ) add(0, i, 1);

    if (spfa()) puts("-1");
    else
    {
        int ans = 0;
        for (int i = 1; i <= n; i ++ ) ans += dist[i];
        cout << ans << endl;
    }
    return 0;
}