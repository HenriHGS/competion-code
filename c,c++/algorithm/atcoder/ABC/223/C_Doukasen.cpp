#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const double eps = 1e-5;
bool lowe(double a, double b){
    if(b - a > eps) return true;
    if(fabs(b- a) <= eps) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    int n; cin>>n;
    vector<double> a(n+1), b(n+1);
    double tot = 0;
    For(i,1,n){
        cin>>a[i]>>b[i];
        tot += a[i]/b[i];
    }
    double mid = tot / 2;
    double ans = 0;
    For(i,1,n){
        if(lowe(a[i]/b[i],mid)){
            ans += a[i];
            mid -= a[i]/b[i];
        }else {
            ans += b[i]*mid;
            break;
        }
    }
    cout.precision(20);
    cout<<ans<<endl;
    return 0;
}