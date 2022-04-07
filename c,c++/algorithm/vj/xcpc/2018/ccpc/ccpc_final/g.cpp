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
const int mod = 1e9+7;
typedef pair<int,int> PII;

int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}

int frac[N], inv[N];
void init(){
    frac[0] = 1;
    fori(i,1,N) frac[i] = 1ll*frac[i-1]*i%mod;
    inv[N-1] = qpow(frac[N-1], mod-2,mod);
    for(int i = N - 2; i >= 0; i -- ) inv[i] = 1ll*inv[i+1]*(i+1)%mod;
}
int C(int a, int b){
    if(a > b) return 0;
    return 1ll*frac[b]*inv[a]%mod*inv[b-a]%mod;
}
void sol(){
   int n, m;
   scanf("%d %d", &n, &m);
    int ans = 1ll*( (C(4,n) + C(3,n)) %mod )* ( (C(4,m) + C(3,m))%mod )%mod;
    printf("%d\n", ans);
}

int cas;
int main(){
    init();
    int tt; scanf("%d", &tt);
    while(tt--){
        printf("Case %d: ",++cas);
        sol();
    }
    return 0;
}