#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i <= (y); i ++ )
#define pb push_back
using namespace std;
typedef long long ll;
const string ans[2] = {"NO","YES"};
void sol(){
    ll s, n, k;
    cin>>s>>n>>k;
    if(s < k) cout<<ans[0]<<endl;
    else if(s == k) cout<<ans[1]<<endl;
    else {
        //分出（n/k）段，每段最多2*k，
        //可以发现 把中间多余的 (n/k)*k 插在一些地方，当 s <= mx-1时，是可以构造出答案的。
        //主要是（n/k）段中有一段要少1，就好说了。
        ll mx = (n/k)*(2*k) + (n%k);
        cout<<ans[s < mx]<<endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;//scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}