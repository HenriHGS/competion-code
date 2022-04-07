#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

typedef long long ll;
const int mod = 998244353;
const int N = 1000+10, M = N<<1;
int b[110];
//vector<int> e[N];
int e[N<<1], ne[N<<1], h[N], idx;
int fa[N], dpt[N], preE[N];

void dfs(int x){
    if(fa[x] != -1)dpt[x] = dpt[fa[x]] + 1;
    else dpt[x] = 1; 
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[x] || fa[j]) continue;
        fa[j] = x; preE[j] = i;
        dfs(j);
    }
}
int cnt[N];
void lca(int a, int b){
    if(dpt[a] < dpt[b]) swap(a,b);
    while(dpt[a] > dpt[b]){
        int ind = preE[a];
        cnt[ind/2+1]++; 
        a = fa[a];
    }
    while(a != b){
        int ind = preE[a];
        cnt[ind/2+1]++; 
        a = fa[a];
        int ind2 = preE[b];
        cnt[ind2/2+1]++; 
        b = fa[b];
    }
}
const int maxn = 4e5+10, zero = 2e5;
int dp[maxn][2];
void madd(int& a, int b){
    if(a == - 1) a = 0;
    a += b;
    a %= mod;
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main(){
    memset(h,-1,sizeof h);
    int n,m,k; cin>>n>>m>>k;
    For(i,1,m) cin>>b[i];
    For(i,1,n-1){
        int a, b; cin>>a>>b;
        //e[a].pb(b); e[b].pb(a);
        add(a,b); add(b,a);
    }
    fa[1] = -1;
    dfs(1);
    fori(i,1,m){
        lca(b[i], b[i+1]);
    }
    int last = 0;
    memset(dp,-1,sizeof dp);
    dp[zero][0] = 1; 
    int mul = 1;
    For(i,1,n-1){
        int now = last^1;
        int w = cnt[i];
        if(cnt[i] == 0){
            mul = (long long)mul*2%mod;
            continue;
        }
       // debug(w);
        fori(j,0,maxn) dp[j][now] = -1;
        fori(j,0,maxn) {
            if(dp[j][last] != -1) {
                if(j - w >= 0){
                    madd(dp[j-w][now],dp[j][last]);//dp[j][now] += dp[j-w][last];
                   // cout<<j-w<<",v: "<<j<<",add:"<<w<<endl;
                }
                if(j + w < maxn){
                    madd(dp[j+w][now], dp[j][last]);
                   // cout<<j+w<<",v: "<<j<<",sub:"<<w<<endl;
                }
            } 
            /* if(j + w < maxn && dp[j+w][last] != -1){
                madd(dp[j][now], dp[j+w][last]);
                cout<<j<<",v: "<<j+w<<",sub:"<<w<<endl;
            } */
        }
        last = last^1;
    }
    int ans = dp[k+zero][last];
    if(ans == -1) cout<<0<<endl;
    else cout<<(long long)ans*mul%mod<<endl;
    return 0;
}