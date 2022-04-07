#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    string s;
    cin>>s;
    if(s[n-1] == 'o')puts("Yes");
    else puts("No");
    return 0;
}