#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
const int N = 2e5+10;
int a[N], n, x, c[N];
ll cal(ll k){
    ll res = 0, cnt = 0, cntk = 0;
    for(int i = 1; i <= n; i ++ ){
        if(a[i] > k) cnt++;
        else cntk++,res += 1ll*c[i]*(k - a[i]);
    }
    if(cntk) cntk = 1;
    res += (cntk + cnt)*x;
    return res;
}

int main(){
    ios::sync_with_stdio(0);     
    cin>>n>>x;
    for(int i = 1; i <= n; i ++ ) cin>>a[i]>>c[i];
    int L = 0, R = 1e6;
    while(L < R){
        int lmid = L + (R - L) / 3;
        int rmid = R - (R - L) / 3;
      //  cout<<"lmid"<<lmid<<", rmid"<<rmid<<endl;
       // cout<<cal(lmid)<<' '<<cal(rmid)<<endl;
        if(cal(lmid) < cal(rmid)) R = rmid - 1;
        else L = lmid + 1;
    }
    printf("%lld\n", cal(L));
    return 0;
}