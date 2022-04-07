#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#define pb push_back
#define debug(a) cout<<#a<<':'<<a<<endl
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5+10;
const int INF = 1e9+10;
const int mod = 1e9+7;

const int maxn = 210;
int n, m, k;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k & 1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}

void sol(){
    scanf("%d %d %d", &n, &m, &k);
    int ans = 0;
    ans += qpow(k,n*m,mod);
    int tot = n*m;
    for(int i = 1; i <= n; i ++ ) for(int j = 1; j <= m; j ++ ){
        int line = n+m;
        int other = n*m - (line - 1);
        int mul1 = qpow(k,other,mod);
        for(int p = 2; p <= k; p ++ ){
            int mul2 = qpow(p-1,line - 2,mod);
            int add = 1ll*mul1*mul2%mod;
            ans += add;
            ans %= mod;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int tt; scanf("%d", &tt);
    For(i,1,tt){
        printf("Case #%d: ", i);
        sol();
    }
    return 0;
}