# include <iostream>
# include <string>
using namespace std;
const int mod = 47;
int cal(string s){
    int res = 1;
    for(int i = 0; i < s.size(); i ++ )res = res*(s[i]-'A'+1)%mod;
    return res;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(cal(s1) == cal(s2)) cout<<"GO"<<endl;
    else cout<<"STAY"<<endl;
    return 0;
}