#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
   // int tt; cin>>tt;
  //  while(tt--){
        int l, r;
        cin>>l>>r;
        if(l == r && l == 0){
            cout<<"Not a moose";
            return 0;
        }
        if(l == r)cout<<"Even ";
        else cout<<"Odd ";
        cout<<max(l,r)*2<<endl;
   // }
    return 0;
}