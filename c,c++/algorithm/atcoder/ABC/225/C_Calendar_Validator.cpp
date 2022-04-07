#include <cstdio>
#include <string>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
int a[N][8];
int main(){
    ios::sync_with_stdio(0);
    int n, m;cin>>n>>m;
    For(i,1,n) For(j,1,m) cin>>a[i][j];
    bool ok = true;
    int col[8]{};
    For(j,1,m) col[j] = a[1][j]%7;
    For(i,1,n){
        For(j,1,m){
            if(j > 1) ok &= (a[i][j] == a[i][j-1] + 1);
            ok &= (a[i][j]%7 == col[j]);
        }
    }
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}