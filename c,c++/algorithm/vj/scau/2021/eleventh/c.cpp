#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n' 
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 5e4 + 10;
int n, k;
int ne[maxn<<1], e[maxn<<1], idx, h[maxn], dfn[maxn], dfs_clock, seq[maxn];
void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
LL ans = 0;
LL dp[maxn][501];
void dfs(int u, int fa, int x){
    seq[dfn[u] = ++dfs_clock] = u;
    for(int i = h[u]; ~i; i = ne[i]){
        int v = e[i];
        if(v != fa){
            dp[u][x] += dp[v][x-1];
            dfs(v,u,x);
        }
    }
    //if(fa!=-1)dp[u][x] += dp[fa][x-1];
}
int p[maxn], q[maxn];
void sol(){
    //cin>>n>>k;
    n = read(), k = read();
    mst(h,-1);
    fori(i,1,n){
        int u, v;
        u = read(), v = read();//cin>>u>>v;
       add(u,v);
       add(v,u);
    }
    mst(dp,0);
    For(i,1,n)dp[i][0] = 1;
    For(i,1,k){
        dfs_clock = 0;
        dfs(1,-1,i);
    }
   // For(j,1,k)For(i,1,n)print(dp[i][j], i == n?'\n':' ');
    int pt, qt;
    pt = qt = 0;
    For(i,1,n){
        int u = seq[i];
        ans += dp[i][k];
        qt = 0;
        vector<int>tmp;
        for(int j = h[u]; ~j; j = ne[j]){
            int v = e[j];
            if(dfn[v] < dfn[u])continue;
            tmp.pb(v);
        }
        //LL add = 0;
       // debug("cal1");
       // debug(ans);
        LL ca[502]{};
        for(auto v:tmp){
            LL add[502]{};
           // cout<<"dp"<<endl;
            For(j,0,k-1){
                add[j+1] += dp[v][j];
                //cout<<j<<' '<<dp[v][j]<<endl;
            }
            For(j,1,k-1)ans += (LL)add[j]*ca[k-j];//For(j,1,k-1)ans -= (LL)add[j]*add[k-j], ca[j] += add[j];
            For(j,1,k-1)ca[j]+=add[j];
        }
//        For(j,1,k-1)ans += (LL)ca[j]*ca[k-j];
      //  debug("cal2");
       // debug(ans);
    }
    /*
    For(i,1,n){
        ans+=dp[i][k];
        LL tmp = 0;
        For(j,1,k-1)tmp += (LL)dp[i][j]*dp[i][k-j]; 
        ans += tmp/2;
    }
    */
    print(ans,'\n');//cout<<ans/2<<endl;
}

int main() {
  //  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}
/*
hack:
6 2
1 2
2 3
3 4
4 5
5 6
hack1:
6 1
1 2
2 3
3 4
4 5
5 6
hack2:
5 2
1 2
2 3
1 4
4 5
hack3:
5 3
1 2
2 3
1 4
4 5
hack4:
5 4
1 2
2 3
1 4
4 5
hack5:
5 5
1 2
2 3
1 4
4 5
hack6:
5 11
1 2
2 3
1 4
4 5
hack7:
10 3
1 2
2 3
2 4
1 5
5 6
5 7
1 8
8 9
8 10
hack8:
10 1
1 2
2 3
2 4
1 5
5 6
5 7
1 8
8 9
8 10
*/