#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        if(s.find("114514") != string::npos) cout<<"AAAAAA"<<endl;
        else cout<<"Abuchulaile"<<endl;
    }
    return 0;
}