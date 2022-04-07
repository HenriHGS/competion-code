#include <cstdio>
#include <string>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int main(){
    int a[26]{};
    string s; cin>>s;
    fori(i,0,3) a[s[i]-'a']++;
    int ans = 6;
    fori(i,0,26){
        For(j,1,a[i]) ans /= j;
    }
    cout<<ans<<endl;
    return 0;
}