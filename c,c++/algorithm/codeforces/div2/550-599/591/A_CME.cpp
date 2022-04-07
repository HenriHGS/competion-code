#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
void sol(){
    int n; cin>>n;
    if(n == 2) cout<<2<<endl;
    else cout<<(n%2)<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--) sol();
    return 0;
}