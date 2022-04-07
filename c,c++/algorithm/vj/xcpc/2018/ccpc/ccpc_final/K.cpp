#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int INF = 1e9+10;
typedef pair<int,int> PII;

ll exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
#define ld long double
ll mul(ll a, ll b, ll p){
    ll x = (ld)a/p*b;
    return ((a*b - x*p)%p + p)%p;
}
ll qpow(ll a, ll k, ll p){
    ll res = 1;
    while(k){
        if(k & 1) res = mul(res,a,p);
        a = mul(a,a,p);
        k >>= 1;
    }
    return res;
}
ll n, c, x, y;
void sol(){
    scanf("%lld %lld", &n, &c);
    ll p = sqrt(n);
    while(n % p != 0)p--;
    ll q = n / p;
    ll phi = (p-1)*(q-1);
    ll t = (1ll<<30) + 3;
    exgcd(t,phi,x,y);
    x = (x%phi + phi)%phi;
    printf("%lld\n", qpow(c,x,n));
}

int cas;
int main(){
    int tt; scanf("%d", &tt);
    while(tt--){
        printf("Case %d: ",++cas);
        sol();
    }
    return 0;
}