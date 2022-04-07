#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define pb push_back
vector<int>ans;
int ans_mul;
void dfs(int x, int sum, int mul, int limit, int mx, int tot, vector<int>&num){
    if(tot == mx){
        if(sum != limit) return;
        if(mul <= ans_mul)ans = num;
        return ;
    }
    for(int i = x; i<=mx;i ++ ){
        if(sum + i <= limit){
            num.pb(i);
            dfs(i,sum+i,mul*i,limit,mx,tot+1,num);
            num.pop_back();
        }
    }
}
void cal(int mx){
    int sum = (mx+1)*mx/2;
    ans_mul = 1;
    For(i,1,mx)ans_mul *= i; 
    vector<int>num;
    dfs(1,0,1,sum,mx,0,num);
}

int main(){
    int mx = 1;
    for(int i = 1; i <= 5; i ++ ){
        mx *= 2;
        ans.clear();
        cal(mx-1);
        for(auto x:ans)cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}