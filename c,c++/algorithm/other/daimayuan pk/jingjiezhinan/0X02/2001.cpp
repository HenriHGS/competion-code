#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> ans;
void dfs(int x){
    if(x == n+1){
        for(auto xx: ans) cout<<xx<<' ';
        cout<<endl;
        return ;
    }
    dfs(x+1);
    ans.push_back(x);
    dfs(x+1);
    ans.pop_back();
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}