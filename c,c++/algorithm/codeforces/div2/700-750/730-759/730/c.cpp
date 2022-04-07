#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <iomanip>  //头文件
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
#define eb emplace_back
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
const db pi = atan2(0.0,-1.0);

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

const int maxn = 100000 + 5;
db ans = 0;
db c0, m0, p0, v0;
LL c, m, p, v;
const int base = 200000;
//这波叫自做聪明。。。。。。老实double不就行了，干嘛要换算，导致wawa，还被fst
//。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
/*
1
0.2 0.2 0.6 0.2
*/
void dfs(LL c, LL m, LL p, db pre, int cur){
    LL ctmp = c;
    ans += pre*((db)p/base)*cur;
   // cout<<endl<<c<<' '<<m<<' '<<p<<endl;
    //debug(pre*((db)p/base));
    if(ctmp > v){
        if(m)dfs(c - v, m + v/2, p + v/2, pre * ((db)c/base), cur+1);
        else dfs(c - v, 0, p + v, pre * ((db)c/base), cur+1);
    }else if(ctmp){
        if(m)dfs(0, m + c/2, p + c/2, pre * ((db)c/base),cur+1);
        else dfs(0, 0, p + c, pre * ((db)c/base),cur+1);
    }
    LL mtmp = m;
    if(mtmp > v){
        if(c)dfs(c + v/2, mtmp - v, p + v/2, pre*((db)m/base),cur+1);
        else dfs(0, mtmp - v, p + v, pre*((db)m/base),cur+1);
    }else if(mtmp){
        if(c)dfs(c + mtmp/2, 0, p + mtmp/2, pre*((db)m/base),cur+1);
        else dfs(0, 0, p + mtmp, pre*((db)m/base),cur+1);
    }
}
void sol(){
    ans = 0;
    cin>>c0>>m0>>p0>>v0;
    //c = (LL)((c0+0.000001)*base);
    c = (LL)(c0*base + 0.5);
    //m = (LL)((m0+0.000001)*base);
    m = (LL)(m0*base + 0.5);
    //p = (LL)((p0+0.000001)*base);
    p = (LL)(p0*base + 0.5);
    //v = (LL)((v0+0.000001)*base);
    v = (LL)(v0*base + 0.5);
   // debug(c);
    dfs(c,m,p,1.0,1);
    cout<< fixed << setprecision(6)<< ans<<endl;//精度输出
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    debug(pi);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}