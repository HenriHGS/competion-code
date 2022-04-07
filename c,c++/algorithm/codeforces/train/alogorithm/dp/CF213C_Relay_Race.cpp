#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 310;
int f[N<<1][N][N];
int a[N][N];
int main(){
    int n; cin>>n;
    For(i,1,n)For(j,1,n) cin>>a[i][j];
    memset(f,-0x3f,sizeof f);
    f[1][1][1] = a[1][1];

    For(i,2,2*n-1)For(j,1,n)For(k,1,n){
        int jj = i - j + 1, kk = i - k + 1;
        if(jj < 1 || jj > n || kk < 1 || kk > n) continue;
        int t = a[j][jj] + a[k][kk];
        if(j == k && kk == jj) t -= a[j][jj];
        int px[] = {0,0,-1,-1};
        int py[] = {0,-1,0,-1};
        fori(p,0,4){
            int tj = j + px[p];
            int tk = k + py[p];
            f[i][j][k] = max(f[i][j][k], f[i-1][tj][tk] + t);
        }
    }
    cout<<f[2*n-1][n][n]<<endl;
    return 0;
}