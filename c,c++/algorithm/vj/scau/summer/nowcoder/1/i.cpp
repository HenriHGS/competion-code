#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long LL;
int sum[N][N][2], cnt[N][N][2];
bool st[N][N][2];
LL mod = 998244353;
int n;
int a[N];
int xt[N];
int qtpow(int x, int y)
{
    int ans = 1;
    while (y)
    {
        if (y & 1) ans = 1ll * ans * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ans;
}
void init()
{
    for(int i=0;i<N;i++)
    {
        xt[i]=qtpow(i,mod-2);
    }
    return;
}
int dp(int x, int y, int op)
{
    //cout<<x<<" "<<y<<" "<<op<<endl;
    if (sum[x][y][op] != -1)
        return sum[x][y][op];
    sum[x][y][op] = 0;
    if (op == 0)
    {
        int num=0;
        for (int i = x + 1; i <= n; i ++ )
        {
            if ((a[i]>a[x])&&(a[i]>a[y]))
            {
                num ++;
                sum[x][y][op] = (sum[x][y][op] + dp(i, y, 1)) % mod;
            }
        }
        if(num!=0)
        {
        sum[x][y][op]=((LL)xt[num]*sum[x][y][op]+1)%mod;
        }

    }
    else
    {
        int num=0;
        for (int i = y + 1; i <= n; i ++ )
        {
            if ((a[i] > a[y]) && (a[i] > a[x]))
            {
                num ++;
                sum[x][y][op] = (dp(x, i, 0)  + sum[x][y][op]) % mod;
            }
        }
            if(num!=0)
            {
            sum[x][y][op]=((LL)xt[num]*sum[x][y][op]+1)%mod;

            }

    }
    return sum[x][y][op] % mod;
}

int main()
{
    init();
    a[0] = 0;
    memset(sum, -1, sizeof sum);
    //cin >> n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &a[i]);
    printf("%d\n", dp(0,0,0));//cout<<dp(0, 0, 0)<<endl;
}
