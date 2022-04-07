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
bool st[N+1];
int primes[N+1], tot;
int cnt[N+1];
void sieve(){
    for(int i = 2; i <= N; i ++ ){
        if(!st[i]) primes[tot++] = i;
        for(int j = 0; i<=N/primes[j]; j ++ ){
            st[i*primes[j]] = 1;
            if(i%primes[j] == 0) break;
        }
    }
}
int main()
{
   // cout<<gcd(-6,-3);
    //cout<<6%(-3);
    sieve();
    int n, m, mx = 0;
    scanf("%d%d",&n,&m);//cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]), mx = max(mx, a[i]);
    int k = 1;
    for (int i = 1; i <= m; i ++ )
    {
        int x;
        scanf("%d", &x);
        //k = gcd(k, x);
        x = abs(x);
        for(int j = 0; x /primes[j]>= primes[j]; j ++ ){
            if(x%primes[j] == 0){
                while(x%primes[j] == 0)x/=primes[j];
                cnt[primes[j]]++;
            }
        }
        if(x>1)cnt[x]++;
    }
    for(int i = 2; i < tot; i ++ ) if(cnt[i] == m) k *= i;
    bool succ = true;
  // cout<<k<<endl;
    for (int i = 1; i <= n; i ++ )
    {
        if ((mx - a[i]) % k) succ = false;
    }
    if (succ) puts("Yes");
    else puts("No");
    
    return 0;
}
