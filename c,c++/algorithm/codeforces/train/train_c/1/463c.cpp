#include <cstdio>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long LL;
const int N = 2e3+10;
LL dia1[2*N], dia2[2*N];
int a[N][N];
void sol(){
    int n;
    cin>>n;
    For(i,1,n)For(j,1,n){
        cin>>a[i][j];
        dia1[i+j] += a[i][j];
        dia2[i - j + n] += a[i][j];
    }
    LL sum1, sum2;
    sum1 = sum2 = -1;
    int x1,y1,x2,y2;
    For(i,1,n)For(j,1,n){
        LL tmp = dia1[i+j] + dia2[i - j + n] - a[i][j];
        if( (i+j) %2 == 0){
            if(tmp > sum1) {
                sum1 = tmp;
                x1 = i, y1 = j;
            }
        }else {
            if(tmp > sum2){
                sum2 = tmp;
                x2 = i, y2 = j;
            }
        }
    }
    cout<<sum1+sum2<<endl;
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    sol();
    return 0;
}