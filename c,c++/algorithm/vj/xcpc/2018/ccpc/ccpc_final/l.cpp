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
const int N = 1e6+10;
typedef pair<int,int> PII;

int primes[N], tot;
bool st[N];
void sieve(){
    fori(i,2,N){
        if(!st[i]) primes[tot++] = i;
        for(int j = 0; primes[j] <= N/i; j ++ ){
            st[i*primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}
bool judge(ll x){
    ll mid = sqrt(x);
    for(int i = 0; i < tot && primes[i] <= mid; i ++ ){
        if(x % primes[i] == 0) return false;
    }
    return true;
}
void cal(ll x){
    for(int i = 0; i < tot; i ++ ){
        int xx = x - primes[i];
        if(!st[xx]) {
            printf("%d %d", primes[i], xx);
            return ;
        }
    }
}
void rem(ll x){
    if(x % 2 == 0){
        printf("2 2 2 ");
        cal(x - 6);
    }else {
        printf("2 2 3 ");
        cal(x - 7);
    }
}
void sol(){
    ll n;
    scanf("%lld", &n);
    if(n <= 11){
        puts("IMPOSSIBLE");
    }else{
        for(ll i = n - 10; ; i -- ){
            if(judge(i)){
                printf("%lld ", i);
                rem(n - i);
                break;
            }
        }
        puts("");
    }
}
int cas;
int main(){
    sieve();
    int tt; scanf("%d", &tt);
    while(tt--){
        printf("Case %d: ",++cas);
        sol();
    }
    return 0;
}