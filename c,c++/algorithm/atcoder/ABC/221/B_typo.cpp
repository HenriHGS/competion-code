#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    string a, b;
    cin>>a>>b;
    bool ok = a == b;
    fori(i,0,a.size()-1){
        string t = a;
        swap(t[i],t[i+1]);
        ok |= t==b;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}