#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 5e5+10;
int ans[maxn], cnt[maxn];
int main(){
    int n, k, m;
    cin>>n>>k>>m;
    for(int i = 1; i <= m; i ++ ){
        int a, b;
        cin>>a>>b;
    }
    for(int i = 1; i <= n*k; i ++ ){
        int x;
        cin>>x;
        ans[i] = ++cnt[x];
    }
    for(int i = 1; i <= n*k; i ++ )cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}