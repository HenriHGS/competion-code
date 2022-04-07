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
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f? -x : x;
}
typedef long long ll;
ll t[N];
int col[N];
vector<int> e[N];
void dfs(int x){
    if(col[x]) return ;
    col[x] = 1;
    for(auto j:e[x]){
        if(col[j]) continue;
        dfs(j);
    }
}
int main(){
    int n = read();
    For(i,1,n){
        t[i] = read();
        int k = read();
        For(j,1,k){
            int v = read();
            e[i].pb(v);
        }
    }
    dfs(n);
    ll ans = 0;
    For(i,1,n) if(col[i])ans += t[i];
    cout<<ans<<endl;
    return 0;
}