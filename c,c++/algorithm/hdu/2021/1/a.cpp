#include <cstdio>
#include <iostream>
#include <cmath>
#define endl '\n'
#define For(i,x,y) for(int i = (x); i <= (y); i ++ ) 
using namespace std;
typedef long long LL;
void table(int n){
    For(num,1,n){
        int ans = 0;
        For(i,1,num){
            ans |= num%i;
        }
        cout<<num<<' '<<ans<<endl;
    }
}
void sol(){
    LL a;
    cin>>a;
    LL dig = __lg(a);
   // cout<<dig<<endl;
    if((LL)pow(2,dig) == a) dig--;
    LL ans = max(0LL,((LL)pow(2,dig) - 1));
    cout<<ans<<endl;
}
int main(){
    //table(100);
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;//scanf("%d", &tt);
    while(tt--){
        sol();
    }
    return 0;
}