#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int dp[N], a[N], b[N];
vector<int> e[N];
int main(){
    int n, m; scanf("%d %d", &n, &m);
    For(i,1,m) {
        scanf("%d %d", &a[i], &b[i]);
        e[a[i]].pb(b[i]);
    }
    For(i,1,n) sort(e[i].begin(), e[i].end(), greater<int>());
    vector<int> w;
    For(i,1,n){
        for(auto j: e[i]) w.pb(j);
    }
    int len = 1;
    dp[1] = w[0];
    fori(i,1,m){
        if(dp[len] < w[i]) dp[++len] = w[i];
        else {
            int ps = lower_bound(dp+1,dp+1+len,w[i]) - dp;
            dp[ps] = w[i];
        }
    }
    printf("%d\n", len);
    return 0;
}