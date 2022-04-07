#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;
typedef long long LL;
const int N = 1000010;
int a[N];

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    int n, m, mx = 0;
   scanf("%d%d",&n,&m);//cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), mx = max(mx, a[i]);
    int k = 0;
    for (int i = 1; i <= m; i ++ )
    {
        int x;
        scanf("%d", &x);
        x = abs(x);
        k = gcd(k, x);
    }
    bool succ = true;
    for (int i = 1; i <= n; i ++ )
    {
        if ((mx - a[i]) % k) succ = false;
    }
    if (succ) puts("Yes");
    else puts("No");
    return 0;
}
