#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
template<class t> using vc = vector<t>;
using vi = vc<int>;
int main(){
    int n; cin>>n;
    vi ans(n);
    for(int i = 0; i < n; i ++ ) {
        int x;
        cin>>x; x--;
        ans[x] = i +1;
    }
    for(int i = 0; i < n; i ++ ) cout<<ans[i]<<" \n"[i==n-1];
    return 0;
}