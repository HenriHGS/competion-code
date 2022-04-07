#include <iostream>
#include <cstdio>
using namespace std;
#define db double
const int maxn = 1e5+10;
db a[maxn], b[maxn];
const db eps = 1e-5;
int main(){
    ios::sync_with_stdio(0);
    int n, L; cin>>n>>L;
    for(int i = 1; i <= n; i ++ ) cin>>a[i];
    db l = -1e6, r = 1e6;
    auto check =[&](db x){
        db res = -1e10;
        for(int i = 1; i <= L; i ++ ){
            b[i] = a[i] - x;
            b[i] += b[i-1];
            res = b[L];
        }
        for(int i = L + 1; i <= n; i ++ ){
            b[i] = a[i] - x;
            b[i] += b[i-1];
            b[i-L] = min(b[i-L], b[i-L-1]);
            res = max(res, b[i] - b[i-L]);
        }
        return res >= 0;
    };
    while(l + eps < r){
        db mid = (l + r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout<<(int)(r*1000);
    return 0;
}