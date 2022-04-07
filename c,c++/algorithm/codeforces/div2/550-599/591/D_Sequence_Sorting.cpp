#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
#define debug(a) cout<<#a<<":"<<a<<endl
const int N = 3e5+10;
int a[N];
vector<int> lx;
vector<int> e[N];
void sol(){
    int n; cin>>n;
    lx.erase(lx.begin(),lx.end());
    For(i,1,n) cin>>a[i], lx.push_back(a[i]);
    sort(lx.begin(), lx.end());
    lx.erase(unique(lx.begin(),lx.end()), lx.end());
    int tot = lx.size();
    //debug(tot);
    //debug(n);
    For(i,1,tot) e[i].clear();
    int ans = n;
    For(i,1,n){
        int x = lower_bound(lx.begin(), lx.end(), a[i]) - lx.begin() + 1;
        e[x].push_back(i);
    }
    int mx = 1, len = 1;
    ans = tot - 1;
    if(tot == 1) ans = 0;
    For(i,2,tot){
        if(e[i][0] > e[i-1].back()){
            len++;
            ans = min(ans,tot - len);
        }else len = 1;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--) sol();
    return 0;
}