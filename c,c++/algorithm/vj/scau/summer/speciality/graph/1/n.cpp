#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 510;
long long  g[N][N], x[N];
int n;
vector<int>node;
void sol(){
    cin>>n;
    For(i,1,n)For(j,1,n)cin>>g[i][j];
    For(i,1,n) cin>>x[i];
    long long sum = 0;
    reverse(x+1, x+1+n);
    vector<long long >ans;
    For(k,1,n){
        node.pb(x[k]);
        int kk = x[k];
        sum = 0;
        For(i,1,n)For(j,1,n) g[i][j] = min(g[i][j], g[i][kk]+g[kk][j]);
        for(auto i : node)for(auto j: node){
            sum += g[i][j];
        }
        ans.pb(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto xx: ans) cout<<xx<<' ';
}
int main(){
    ios::sync_with_stdio(0);
    sol();
    return 0;
}