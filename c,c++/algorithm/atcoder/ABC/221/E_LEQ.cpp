//rank 1000
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 3e5+10;
const int mod = 998244353;
int ans[N];
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k &1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
int bin[N], inv[N];
void init(){
    inv[0] = bin[0] = 1;
    fori(i,1,N) bin[i] = 1ll*bin[i-1]*2%mod;
    inv[N-1] = qpow(bin[N-1],mod-2,mod);
    for(int i = N - 2; i >= 0; i -- ) inv[i] = 1ll*inv[i+1]*2%mod;
}
int n;
int tr[N];
int lowbit(int x){ return x&-x; }
void mody(int x, int v){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] = (tr[i] + v)%mod;
}
int sum(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)){
        res += tr[i];
        res %= mod;
    }
    return res;
}
int sum(int l, int r){
    int res = (1ll*sum(r) - sum(l-1) + mod)%mod;
    return res;
}
PII p[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    init();
    For(i,1,n)cin>>p[i].fi,p[i].se = i;
    sort(p+1,p+1+n,greater<PII>());
    int ans = 0;
    For(i,1,n){
        int h = p[i].fi, id = p[i].se;
        int add = sum(id,n);
        ans += 1LL*add*inv[id+1]%mod;
        ans %= mod;
        mody(id,bin[id]);
    }
    cout<<ans<<endl;
    return 0;
}