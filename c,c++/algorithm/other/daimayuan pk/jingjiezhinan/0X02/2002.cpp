#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
vector<int> ans;
int n, m;
void dfs(int x, int tot){
    if(tot == m) {
        for(auto xx: ans) cout<<xx<<' ';
        cout<<endl; 
        return ;
    }
    if(x > n || n - x + 1 < m - tot) return ;
    ans.push_back(x);
    dfs(x+1,tot+1);
    ans.pop_back();
    dfs(x+1,tot);
}
int main(){
    cin>>n>>m;
    dfs(1,0);
    return 0;
}