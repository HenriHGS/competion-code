#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>
#include <cctype>
#include <map>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
vector<int> v[N];
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f? -x : x;
}
map<vector<int>, int > ma[N];
int main(){
    int n = read();
    int ans = 0;
    For(i,1,n){
        ans ++;
        int len = read();
        v[i].pb(len);
        For(j,1,len){
            int x = read(); v[i].pb(x);
        }
        auto& a = v[i];
        if(ma[len].count(a)) ans--;
        ma[len][a] = 1;
    }
    cout<<ans<<endl;
    return 0;
}