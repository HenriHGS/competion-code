#include <cstring>
#include <string>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--){
        string s; cin>>s;
        if(s[0] != s.back()) s.back() = 'b' - s.back() + 'a';
        cout<<s<<endl;
    }
    return 0;
}