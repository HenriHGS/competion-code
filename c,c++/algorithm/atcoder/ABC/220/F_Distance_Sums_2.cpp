#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define pb push_back
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 3e5+10;
const int mod = 998244353;
vector<ll> e[N], siz(N), ret(N);
void dfs1(int x, int fa){
    for(auto j: e[x]){
        if(j != fa) {
            dfs1(j,x);
            siz[x] += siz[j], ret[x] += siz[j] + ret[j]; 
        }
    }
}
int n;
void dfs2(int x, int fa){
    if(x != 1) ret[x] = ret[fa] - siz[x] + n - siz[x];
    for(auto j : e[x]){
        if(j != fa){
            dfs2(j,x);
        }
    }
}
int main(){
    scanf("%d", &n);
    fill(siz.begin(), siz.end(), 1);
    //fill(siz, n + 5, 1);
    For(i,1,n-1){
        int a, b; scanf("%d %d", &a, &b);
        e[a].pb(b), e[b].pb(a);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    For(i,1,n) printf("%lld\n", ret[i]);
    return 0;
}
//https://atcoder.jp/contests/abc220/submissions/26152559
//https://atcoder.jp/contests/abc220/submissions/26162312
//https://atcoder.jp/contests/abc220/submissions/26135579
//https://www.luogu.com.cn/blog/sflsrick/note-how-to-change-root
//学习地址