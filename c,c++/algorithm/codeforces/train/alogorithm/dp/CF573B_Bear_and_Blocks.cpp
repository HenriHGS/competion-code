#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int h[N], f[N];
int main(){
    ios::sync_with_stdio(0);
    int n; cin>>n;
    for(int i = 1; i <= n; i ++ ) cin>>h[i];
    for(int i = 1; i <= n; i ++ ) f[i] = min(f[i-1] + 1, h[i]);
    for(int i = n; i >= 1; i -- ) f[i] = min(f[i + 1] + 1, f[i]);
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) ans = max(ans, f[i]);
    cout<<ans<<endl;
    return 0;
}