#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 100;

int a[N][N];
int main(){
    int n, m; cin>>n>>m;
    For(i,1,n) For(j,1,m) cin>>a[i][j];
    bool ok = true;
    For(i1,1,n)For(i2,i1+1,n)For(j1,1,m)For(j2,j1+1,m)
        ok &= (a[i1][j1] + a[i2][j2] <= a[i2][j1] + a[i1][j2]);
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}