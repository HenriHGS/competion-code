#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long LL;
typedef long long ll;
const int mod = 1e9+7;
const int M = 2e5+10, N = 2e5+10;
int fac[M], inv[M];
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (ll)res * a % p;
        a = (ll)a*a%p;
        k >>= 1;
    }
    return res;
}
void init(){
    //fac[0] = 1;
    //fori(i,1,M) fac[i] = (ll)fac[i-1]*i%mod;
    for(int i = M - 1; i >= 0; i -- ) inv[i] = qpow(i, mod-2,mod);
}
int a[N];
int pre_mx[N], pre_mi[N], suf_mx[N], suf_mi[N];
void getS(){

}
void sol(){
    int n, m;
    scanf("%d%d", &n, &m);
    For(i,1,n) scanf("%d", a+i);
    getS();
}
int main(){
    init();
    sol();
}