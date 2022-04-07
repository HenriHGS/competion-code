#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool used[20];
int ans[20];
void dfs(int x){
    if(x == n) {
        for(int i = 0; i < n; i ++ ) cout<<ans[i]<<' ';
        cout<<endl;
        return ;
    }
    for(int i = 1; i <= n; i ++ ) {
        if(!used[i]){
            used[i] = 1;
            ans[x] = i;
            dfs(x+1);
            used[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 1; i <= n; i ++ ) ans[i] = i;
    do{
        for(int i = 1; i <= n; i ++ ) cout<<ans[i]<<' ';
    }while(next_permutation(ans + 1, ans + 1 + n));
   // dfs(0);
    return 0;
}