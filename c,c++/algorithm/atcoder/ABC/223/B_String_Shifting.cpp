#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    string s; cin>>s;
    string mx = s, mi = s;
    fori(i,0,s.size() - 1){
        string t = s.substr(1);
        s = t + s[0];
        mx = max(mx, s);
        mi = min(mi, s);
    }
    cout<<mi<<endl;
    cout<<mx<<endl;
    return 0;
}