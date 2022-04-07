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

const int maxn = 100000 + 6;

map<string,int>ma;
vector<string> dir;
int getId(string s){
    if(ma.count(s)) return ma[s];
    dir.pb(s);
    return ma[s] = sz(dir);
}
/*
string getString(int id){
    return dir[id];
}
*/
int n, m;
int p[20], tot;
bool ban[20][20];
int ans;
vector<int>ansv;
void dfs(int x, int sum, vector<int>&v){
    if(x > n){
      //  debug(sum);
        if(sum > ans){
            ans = sum;
            ansv = v;
        }
        return ;
    }
    //select
    bool ok = true;
    for(auto u: v){
        if(ban[x][u])ok = false;//continue;   
    }
    if(ok){
        v.pb(x);
        dfs(x+1, sum + 1, v);
        v.pop_back();
    }
    //not
    dfs(x + 1, sum, v);
}
void sol(){
    cin>>n>>m;
    For(i,1,n){
        string name;
        cin>>name;
        int id = getId(name);
        p[i] = id;
    }
    For(i,1,m){
        string name1, name2;
        cin>>name1>>name2;
        int u = getId(name1);
        int v = getId(name2);
        ban[v][u] = ban[u][v] = 1;
    }
    vector<int>v;
    dfs(1,0,v);
   // debug(sz(dir));
    cout<<ans<<endl;
    vector<string>anss;
    fori(i,0,ans)anss.pb(dir[ansv[i]-1]);//cout<<dir[ansv[i]-1]<<endl;
    sort(ALL(anss));
    fori(i,0,ans)cout<<anss[i]<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}