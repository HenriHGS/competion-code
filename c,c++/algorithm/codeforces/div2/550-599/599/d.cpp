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
#define adj vector<int>
set<int>node;
adj e[maxn];
int vis[maxn];
void sol(){
    int n, m;
    cin>>n>>m;
    For(i,1,m){
        int a, b;
        cin>>a>>b;
        e[a].pb(b);
        e[b].pb(a);
    }
    For(i,1,n)node.insert(i);
    int T = 0;
    auto bfs = [&](int x){
        queue<int>que;
        que.push(x);
       // int t = 0;
        node.erase(x);
        while(!que.empty()){
            int u = que.front();que.pop();
            //node.erase(u);
            T++;
            for(auto v:e[u]){
                vis[v] = T;// 标记以便降低时间复杂度
            }
            adj etem;
            //直接遍历点集，来降低时间复杂度
            for(auto v: node)if(vis[v] != T)etem.pb(v); 
            for(auto v: etem) que.push(v), node.erase(v);
        }
    };
    int ans = 0;
    For(i,1,n){
        if(node.count(i)){
            bfs(i);
            ans++;//记录 “0” 联通块的个数
        } 
    }
    cout<<ans-1<<endl;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}