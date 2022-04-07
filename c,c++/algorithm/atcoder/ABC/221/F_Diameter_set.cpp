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
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k &1) res = 1ll*res*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res;
}
vector<int> e[N];
int ansd = 0, ans = 0;
int dis[N],num[N];
void dfs(int x,int fa){
    if(e[x].size() == 1) dis[x] = 1, num[x]++;
    for(auto j : e[x]){
        if(j == fa) continue;
        dfs(j,x);
        if(ansd < dis[x] + dis[j] + 1){
            ansd = dis[x] + dis[j] + 1;
            if(dis[x] == 0){
                ans = num[j];
            }else if(dis[x] == dis[j]){
                num[x] += num[j];
                ans = 1ll*(num[x])*(num[x]-1)%mod;
            }else {
                ans = 1ll*(num[x])*(num[j])%mod;
            }
        }
        if(dis[x] < dis[j]){
            dis[x] = dis[j];
            num[x] = dis[j];
        }else if(dis[x] == dis[j]){
            
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    int n; cin>>n;
    For(i,1,n){
        int u, v;
        cin>>u>>v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1,-1);
    return 0;
}