#include <cstdio>
#include <cstring>
using namespace std;

#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define mst(x,a) memset(x,a, sizeof x)

template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}

const int mod = 1e6;
const int N = 10;
typedef long long ll;
//ll a[N][N];
ll tmp[N][N];
ll add(ll a, ll b){
    a += b;
    a %= mod;
    return a;
}
ll  mul(ll a, ll b){
    a = a*b%mod;
    return a;
}
void multi(ll a[][N], ll b[][N], ll n){
    mst(tmp,0);
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ )
        for(int k = 1; k <= n; k ++ )
            tmp[i][j] = add(tmp[i][j],mul(a[i][k], b[k][j]));
    }
    for(int i = 1; i <= n; i ++ )
    for(int j = 1; j <= n; j ++ )
        a[i][j] = tmp[i][j];
}
void print_square(int n, ll a[][N]){
    For(i,1,n)For(j,1,n)print(a[i][j], j==n?'\n': ' ');
}
ll res[N][N];
void squareQpow(ll a[][N], ll n, ll k){
    mst(res,0);
    for(int i = 1; i <= n; i ++ ) res[i][i] = 1;
    while(k){
        if(k&1) multi(res,a,n);
        multi(a,a,n);
        k >>= 1;
    }
}
int main(){
    ll n, c1, c2;
    scanf("%lld %lld %lld", &n, &c1, &c2);
    c1 %= mod;
    c2 %= mod;
    ll b[N][N]{};
    b[1][1] = c1 % mod;
    b[2][1] = 0;
    b[3][1] = (b[1][1]*c1%mod + b[2][1]*c1%mod)%mod;
    b[4][1] = c2%mod;
    ll a[N][N] = {  {0,0,0,0},
                    {0,0,0,1,0},
                    {0,0,0,0,1},
                    {0,0,0,c1,c1},//(c1 - 1 + mod)%mod
                    {0,c2,c2,0,0}//
                };
    ll ans = 0;
    if(n/5== 1){
        ans = (b[1][1] + b[2][1]) % mod;
    }else if(n/5== 2){
        ans = (b[3][1] + b[4][1]) % mod;
    }else {
        /*
        puts("");
        puts("");
        print_square(4,a);
        */
        squareQpow(a,4,n/5-2);
        /*
        puts("");
        puts("");
        print_square(4,a);
        puts("");
        puts("");
        print_square(4,b);
        */
        multi(res,b,4);
        /*
        puts("");
        puts("");
        print_square(4,res);
        */
        ans = (res[3][1] + res[4][1]) % mod;
    }
    printf("%06lld\n",ans);
    return 0;
}