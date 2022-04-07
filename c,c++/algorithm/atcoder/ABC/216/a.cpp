#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define sz(a) a.size()
using namespace std;
int main(){
    string s;
    cin>>s;
    bool x = false;
    for(int i = 0; i < sz(s); i ++ ){
        if(!x){
            if(s[i] == '.')x = true;
            else {
                cout<<s[i];
            }
        }else {
            int dig = s[i] - '0';
            if(dig<=2)cout<<'-';
            else if(dig >=7) cout<<'+';
            //cout<<dig;
        }
    }
    return 0;
}