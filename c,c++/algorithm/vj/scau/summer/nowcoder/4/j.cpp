#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef double db;
typedef long long ll;
const db eps = 1e-6;
const int N = 1e5+10;

void sol(){
    vector<vector<db>>ar(2);
    int len[2]{}, k[2]{};
    fori(i,0,2)cin>>len[i], ar[i].resize(len[i]);
    fori(i,0,2) cin>>k[i];
    fori(rot,0,2)fori(i,0,len[rot])cin>>ar[rot][i];
    db ans[2] = {0,0};
    vector<db> b(max(len[1],len[0]));
    vector<db> sum(max(len[1],len[0]));
    fori(p,0,2){
        db L = 0, R = 1e6;
        vector<db>& a = ar[p];
        while(R - L > eps){
            db mid = (L+R)/2;
            fori(i,0,len[p]) b[i] = a[i] - mid;
            fori(i,0,len[p]) sum[i+1] = sum[i] +b[i];
            db mi = ((ll)1<<31) - 1, mx = -1e14;
            For(i,k[p],len[p]){
                mi = min(mi,sum[i-k[p]]);
                mx = max(mx,sum[i] - mi);
            }
            if(mx >= 0) L = mid;
            else R = mid;
        }
        ans[p] = R;
    }
    printf("%.6f\n",ans[0] + ans[1]);
}
int main(){
    ios::sync_with_stdio();
    return 0;
}