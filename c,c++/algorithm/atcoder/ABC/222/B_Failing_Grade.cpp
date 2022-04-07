#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int main(){
    int n, p; cin>>n>>p;
    int ans = 0;
    For(i,1,n){
        int x; cin>>x;
        ans += (x<p);
    }
    cout<<ans<<endl;
    return 0;
}