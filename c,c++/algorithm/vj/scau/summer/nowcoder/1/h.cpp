#include <cstdio>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 5e6+10;
int a[N], vis[N];
int main(){
    int n;
    cin>>n;
    For(i,1,n)cin>>a[i];
    for(int mod = n; ; mod++){
        For(i,0,mod)vis[i] = 0;
        bool ok = true;
        For(i,1,n){
            if(!vis[a[i]%mod]){
                vis[a[i]%mod] = 1;
                
            }else {
                ok = false;
                break;
            }
        }
        if(ok){
            cout<<mod<<endl;
            return 0;
        }
    }
    return 0;
}