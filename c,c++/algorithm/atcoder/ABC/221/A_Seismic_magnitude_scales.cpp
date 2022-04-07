#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    int a, b;
    cin>>a>>b;
    ll ans = 1;
    for(int i = 1; i <= a - b; i ++ ){
        ans *= 32;
    }
    cout<<ans<<endl;
    return 0;
}