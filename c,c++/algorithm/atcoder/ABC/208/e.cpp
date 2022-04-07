#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
typedef long long LL;
using namespace std;
LL n, k;
string num;
map<LL,LL>dp[30];

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}
 
  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}
/*
100 
80
*/
void sol(){
    cin>>n>>k;
    num = to_string(n);
    //cout<<num<<endl;
    reverse(num.begin(),num.end());
    int tot = num.size();
    num = " " + num;
    For(i,1,tot) num[i] -= '0';
    //cout<<num<<endl;
    auto dfs = MFP([&](auto dfs,bool limit, bool zero, LL dep, LL sta) -> LL{
        if(dep  == 0) return (sta<=k);
        if(sta > k) sta = k + 1;
        if(!limit && !zero && (dp[dep].count(sta))) return dp[dep][sta];
        //LL& ans = dp[dep][sta];
        int up = limit ? num[dep] : 9;
        LL res = 0;
        
        for(int i = 0; i <= up; i ++ ){
            res += dfs(limit&&i==up, zero && i == 0, dep-1, zero && i == 0?1:sta*i);
        }
       // cout<<dep<<' '<<sta<<' '<<res<<' '<<num[dep]<<endl;
        if(!limit && !zero) dp[dep][sta] = res;
        return res;
    });
    cout<<dfs(true,true,tot,1)-1<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    sol();
}