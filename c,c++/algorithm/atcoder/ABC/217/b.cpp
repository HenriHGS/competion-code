#include <string>
#include <iostream>
using namespace std;
const  string con[] = {"ABC", "ARC", "AGC", "AHC"};
int main(){
    string s[3];
    for(int i = 0; i < 3; i ++ )cin>>s[i];
    for(int i = 0; i < 4; i ++ ) {
        int cnt = 0;
        for(int j = 0; j < 3; j ++ ) cnt += (s[j] != con[i]);
        if(cnt == 3){
            cout<<con[i];
            return 0;
        }
    }
    return 0;
}