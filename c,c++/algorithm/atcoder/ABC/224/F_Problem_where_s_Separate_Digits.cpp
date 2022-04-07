#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;

const int mod = 998244353;
int p2[N];
void init(){
    p2[0] = 1;
    For(i,1,N-1) p2[i] = p2[i-1]*2%mod;
}
int main(){
    init();
    ios::sync_with_stdio(0);
    string s; cin>>s;
    int n = s.size();
    s = " " + s;
    int ans = 0, pre = 1;
    for(int i = n; i >= 1; i -- ){
        int mul1 = p2[i-1];
        int val = s[i] - '0';
        ans = (1LL*ans + (1LL*val* mul1%mod * pre % mod)) %mod;
        pre = (1LL*pre*10%mod + p2[n-i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}