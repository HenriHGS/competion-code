#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define pb push_back
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int n, k;
vector<int>lx;
int frac[N], inv[N];
const int mod = 1e9+7;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = 1LL*res*a%mod;
        a = 1LL*a*a%mod;
        k >>= 1;
    }
    return res;
}
void init(){
    frac[0] = inv[0] = 1;
    fori(i,1,N) frac[i] = 1LL*frac[i-1]*i%mod;
    inv[N-1] = qpow(frac[N-1],mod-2,mod);
    for(int i = N - 2; i; i -- ) inv[i] = 1LL*inv[i+1]*(i+1)%mod;
}
int C(int b, int a){
    return 1LL*frac[a]*inv[b]%mod*inv[a-b]%mod;
}
int l[N], r[N];

int sum[N*2];
int lowbit(int x){ return x&-x; }
void mody(int x,int val){
    for(int i = x; i <= lx.size(); i += lowbit(i)){
        sum[i] += val;
    }
}
int qury(int x){
    int res = 0;
    for(int i = (x); i; i -= lowbit(i)) res += sum[i];
    return res;
}

int main(){
    scanf("%d %d", &n, &k);
    init();
    For(i,1,n){
        scanf("%d %d", &l[i], &r[i]);
        lx.pb(l[i]), lx.pb(r[i]+1);
    }
    sort(all(lx));
    lx.erase(unique(all(lx)),lx.end());
   // build(1,1,lx.size());
    For(i,1,n){
        int lp = lower_bound(all(lx),l[i]) - lx.begin() + 1;
        int rp = lower_bound(all(lx), r[i]+1) - lx.begin() + 1;
      //  mody(1,lp,rp - 1,1);
        mody(lp,1); mody(rp,-1);
    }
    int ans = 0;
    fori(i,1,sz(lx)){
        int has = qury(i);
        if(has < k) continue;
        //cout<<"lx[i] - lx[i-1]"<<(lx[i] - lx[i-1])<<" has:"<<has<<endl;
        ans += 1LL*(lx[i] - lx[i-1])*C(k,has)%mod;
        ans %= mod;
       // cout<<ans<<endl;
    }
    printf("%d\n", ans);
    return 0;
}