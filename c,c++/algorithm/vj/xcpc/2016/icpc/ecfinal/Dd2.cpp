#include <bits/stdc++.h>
using namespace std;

const int N = 300010;
typedef long long LL;

LL a[N], b[N];
int n, k;

bool check(int x)
{
    for (int i = 1; i <= x; i ++ ) b[i] = 0;
    int tot = 1;
    for (int i = 1, j = 1; i <= n; i ++ ) 
    {
        if (a[i] / 2 >= b[j]) b[j ++] = a[i];
        if (j == x + 1) tot ++, j = 1;
        if (tot > k) return true;
    }
    return false;
}

int main()
{
    int T, ca = 0;
    cin >> T;
    while (T -- ) 
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i ++ ) scanf("%lld", &a[i]);
        int l = 0, r = n;
        sort(a + 1, a + 1 + n);
        while (l < r) 
        {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        printf("Case #%d: %d\n", ++ ca, l);
    }
    return 0;
}
