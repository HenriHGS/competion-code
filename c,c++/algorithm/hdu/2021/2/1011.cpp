#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 100;

typedef long long LL;
int a[N], b[N];
int mx_a[N], mx_b[N];
int mi_a[N], mi_b[N];
LL c[N];
int mod = 998244353;

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
        for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]);
        for (int i = n - 1; i >= 0; i -- )
        {
            mx_a[i] = a[i];
            mx_b[i] = b[i];
            mi_a[i] = a[i];
            mi_b[i] = b[i];
            for (int j = 0; j < 20 ; j ++ )
            {
                if (!((i >> j) & 1))
                {
                    if (i + (1 << j) < n)
                    {
                        mx_a[i] = max(mx_a[i], mx_a[i + (1 << j)]);
                        mx_b[i] = max(mx_b[i], mx_b[i + (1 << j)]);
                        mi_a[i] = min(mi_a[i], mi_a[i + (1 << j)]);
                        mi_b[i] = min(mi_b[i], mi_b[i + (1 << j)]);
                    }
                    else break;
                }
            }
        }
        c[n] = -2e18;
        for (int i = n - 1; i >= 0; i -- )
        {
            //c[i] = max(1ll * a[i] * mx_b[i], 1ll * b[i] * mx_a[i]);
            //c[i] = max(c[i], max(1ll * a[i] * mi_b[i], 1ll * b[i] * mi_a[i]));
            c[i] = -2e18;
            c[i] = max(c[i],1ll*mx_a[i]*mx_b[i]);
            c[i] = max(c[i],1ll*mi_a[i]*mi_b[i]);
            c[i] = max(c[i],1ll*mx_a[i]*mi_b[i]);
            c[i] = max(c[i],1ll*mx_b[i]*mi_a[i]);
            c[i] = max(c[i + 1], c[i]);
        }
        LL ans = 0;
        for (int i = 0; i < n; i ++ ) ans = (ans + c[i]%mod+mod) % mod;
        ans = (ans % mod + mod) % mod;
        printf("%lld\n", ans);
    }
}