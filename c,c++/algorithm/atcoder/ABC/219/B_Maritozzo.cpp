#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    string s[4];
    for(int i = 1; i <= 3; i ++ )cin>>s[i];
    string ans = "", t;
    cin>>t;
    for(int i = 0; i < t.size(); i ++ ) ans += s[t[i]-'0'];
    cout<<ans;
    return 0;
}