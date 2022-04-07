#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
const int inf = 1e9;
typedef unsigned long long ull;
struct Tree
{
    int l, r, mi;
}tr[N << 2];
vector<int> g[N];
int p[N];
bool st[N];
int ans[N];
ull pp[N];

void pushup(int u) 
{
    tr[u].mi = min(tr[u << 1].mi, tr[u << 1 | 1].mi);
}

void build(int l, int r, int u) 
{
    tr[u] = {l, r, 0};
    if (l == r) return ;
    int mid = l + r >> 1;
    build(l, mid, u << 1);
    build(mid + 1, r, u << 1 | 1);
}

void update(int pos, int v, int u) 
{
    if (tr[u].l == tr[u].r) 
    {
        tr[u].mi = v;
        return ;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (pos <= mid) update(pos, v, u << 1);
    else update(pos, v, u << 1 | 1);
    pushup(u);
}

void init()
{
    for (int i = 2; i < N; i ++ ) 
    {
        if (!st[i])
            for (int j = i; j < N; j += i ) 
            {
                st[j] = true;
                g[j].push_back(i);
            }
    }
    pp[0] = 1;
    for (int i = 1; i < N; i ++ ) pp[i] = pp[i - 1] * 23333;
}
int main()
{
    init();
    int T;
    cin >> T;
    while (T -- ) 
    {
        unordered_map<int, int> vis;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i ++ )
        {
            scanf("%d", &p[i]);
            vis[p[i]] = i;
        }
        build(1, m, 1);
        int rr = n + 1;
        for (int i = 1; i <= n; i ++ ) 
        {
            for (int j = 0; j < g[i].size(); j ++ ) 
            {
                int x = g[i][j];
                if (vis.count(x)) 
                {
                    int pos = vis[x];
                    update(pos, inf, 1);
                }
            }
            if (tr[1].mi == inf) 
            {
                ans[i] = 0;
                rr = i;
                break;
            }
            else ans[i] = tr[1].mi + 1;
            for (int j = 0; j < g[i].size(); j ++ ) 
            {
                int x = g[i][j];
                if (vis.count(x)) 
                {
                    int pos = vis[x];
                    update(pos, ans[i], 1);
                }
            }
        }
        for (int i = rr; i <= n; i ++ ) ans[i] = 0;
        ull res = 0;
        for (int i = 1; i <= n; i ++ ) 
            res += pp[n - i] * ans[i];
        cout << res << endl;
    }
}