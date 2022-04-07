#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define debug(a) cout<<#a<<":" << a<<endl
#define pb push_back
#define sz(a) (int)a.size()
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long LL;
const int N = 300+10;
const int mod = 1e9+7;
vector<int> e[N];
int siz[N],dp[N][N];
void dfs1(int x, int fa){
    siz[x] = 1;
    for(auto v: e[x]){
        if(v != fa){
            dfs1(v,x);
            siz[x] += siz[v];
        }
    }
   // debug(x);
    //debug(siz[x]);
}
int root;
int ans;
void add(int &a, int b){
    a = (a + b)%mod;
    return;
}
int mul(int a, int b){
    return (LL)a*b%mod;
}
int dsum[N], inv[N];
int n, m;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (LL)res*a%p;
        a = (LL)a*a%p;
        k>>=1;
    }
    return res;
}
void init(){
    inv[0] = 1;
    fori(i,1,N) inv[i] = qpow(i,mod-2,mod);
}
void dfs2(int x, int fa, int d){
    if(x < root){
        for(int i = 0; i < d; i ++ ){
            add(ans,  mul(mul(dsum[i], inv[n]), dp[i][d-i]));
        }
    }
    for(auto v: e[x]){
        if(v != fa){
            dsum[d] = siz[x] - siz[v];
            dfs2(v,x,d+1);
        }
    }
}
void sol(){
    init();
    cin>>n;
    for(int i = 1; i < n; i ++ ){
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
        e[b].pb(a);
    }
    For(i,0,n) {
        dp[0][i] = 1;
        dp[i][0] = 0;
    }
    For(i,1,n)For(j,1,n) dp[i][j] = (dp[i-1][j]*(LL)inv[2]%mod + (LL)dp[i][j-1]*inv[2]%mod)%mod;
    for(int i = 1; i <= n; i ++ ){
        root = i;
        dfs1(i,-1);
        dfs2(i,-1,0);
    }
    cout<<ans<<endl;
}
int main(){
    sol();
    return 0;
}