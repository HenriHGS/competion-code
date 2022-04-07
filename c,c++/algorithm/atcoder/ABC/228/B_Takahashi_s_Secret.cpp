#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, x;
    int ans = 0;
    cin>>n>>x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin>>a[i], a[i]--;
    vector<int> vis(n,-1);
    x--;
    while(vis[x] == -1){
        vis[x] = true;
        ans++;
        x = a[x];
    }
    cout<<ans<<endl;
    return 0;
}