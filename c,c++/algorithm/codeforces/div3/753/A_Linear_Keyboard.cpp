#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
//#define IOS 
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
template<typename T> void print(T x){
    if(x < 0) putchar('-');
    if(x >= 10) print(x / 10);
    putchar(x % 10 + '0'); 
}template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
#include  <cctype>
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
void sol(){
    int pos[26]{};
    string keys; cin>>keys;
    fori(i,0,26) pos[keys[i] - 'a'] = i;
    string s; cin>>s;
    int pre = pos[s[0] - 'a'];
    int ans = 0;
    fori(i,1,s.size()){
        int cur = pos[s[i] - 'a'];
        ans += abs(pre - cur);
        pre = cur;
    }
    print(ans,'\n');
}
int main(){
    #ifdef IOS
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    #endif
    int tt = read();
    while(tt -- ) sol();
}