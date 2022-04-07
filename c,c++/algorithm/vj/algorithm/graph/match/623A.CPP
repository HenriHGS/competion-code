#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 550;
int g[N][N];
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
using vi = vc<int>;
int du[N];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vc<char> ans(n,'b');
    vi sb, sa, sc;
    For(i,1,m){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b --;
        g[a][b] = g[b][a] = 1;
        du[a]++, du[b]++;
        if(du[a] == n-1) sb.pb(a), ans[a] = 'b';
        if(du[b] == n-1) sb.pb(b), ans[b] = 'b';
    }
    //find a
    fori(i,0,n){
        if(du[i] == n - 1) continue;
        bool ok = true;
        for(auto x:sa) ok &= g[x][i];
        if(ok) sa.pb(i), ans[i] = 'a';
        else sc.pb(i), ans[i] = 'c';
    }
    //check b
    bool ok = true;
    for(auto x1:sc)for(auto x2:sc){
        if(x1 == x2) continue;
        ok &= g[x1][x2];
    }
    //check a&&b
    for(auto x1:sa)for(auto x2:sc){
        ok &= !(g[x1][x2]);
    }
    // fori(i,0,n)cout<<ans[i];
    // cout<<endl;
    if(ok){
        puts("Yes");
        for(auto x:ans)printf("%c",x);
    }else puts("No");
    return 0;
}
/* 
7 13
1 2
2 3
1 3
4 5
5 6
4 6
2 5
2 7
3 7
7 4
7 6
7 1
7 5
Participant's output
Yes
aaacccb
 */