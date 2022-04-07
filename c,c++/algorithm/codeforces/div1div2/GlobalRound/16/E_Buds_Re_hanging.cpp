#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int n, k;
bool have_leaf[N], leaf[N], but[N];
vector<int> e[N];
void dfs(int x, int fa){
    if(e[x].size() == 1 && x != 1) return ;
    bool is_but = true;
    for(auto j: e[x]){
        if(j == fa)continue;
        dfs(j,x);
        is_but &= but[j]||leaf[j];//dfs(j,x);
        have_leaf[x] |= leaf[j];
    }
    if(is_but && !have_leaf[x]) leaf[x] = true;
    if(is_but && have_leaf[x] && x != 1) but[x] = true, k ++ ;//,debug(x);
    return ;//leaf[x]||but[x];
}
void solve(){
    k = 0;
    scanf("%d", &n);
    //init
    For(i,1,n) e[i].clear(), have_leaf[i] = but[i] = leaf[i] = false;
    //
    For(i,1,n-1){
        int a, b; scanf("%d %d", &a, &b);
        e[a].pb(b);
        e[b].pb(a);
        if(a != 1)leaf[a] = sz(e[a]) == 1;
        if(b != 1) leaf[b] = sz(e[b]) == 1; 
    }
    dfs(1,-1);
    int ans = n;
    if(have_leaf[1]) ans = ans - 2*k-1;
    else ans -= 2*k;
    printf("%d\n", ans); 
}
int main(){
    int tt; scanf("%d", &tt);
    while(tt--) solve();
    return 0;
}