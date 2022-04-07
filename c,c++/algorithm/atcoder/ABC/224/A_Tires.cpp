//rank 392 rating 1800,
//还是要切出abcdef g才可以加更多的分。
//这次只切出了 abcef， d没出有点可惜。。。。
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s; cin>>s;
    reverse(s.begin(),s.end());
    string end = s.substr(0,2);
    reverse(end.begin(),end.end());
    if(end == "er") cout<<"er"<<endl;
    else cout<<"ist"<<endl;
    return 0;
}