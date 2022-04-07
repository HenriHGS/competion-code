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
const int N = 310;
int g[N][N];
int dis[N];
int vis[N];
int pre[N];
int ans[N], col[N];
vector<int>e[N], trees[N];
int n;
void sol(){
    cin>>n;
    For(i,1,n)For(j,1,n)cin>>g[i][j], g[i][j] = g[i][j] == -1 ? inf: g[i][j];
    auto spfa = [&](int x){
        queue<int>que;//pa poi = {0,x};
        mst(dis,0x3f);
        mst(vis,0);
        mst(pre,0);
        dis[x] = 0;
        vis[x] = 1;
        que.push(x);
        while(!que.empty()){
            x = que.front();//.fi;//int u = 
            //x = que.front().se;
            que.pop();
            vis[x] = 0;
            //if(vis[x]) continue;
            For(v,1,n){
                if(x == v) continue;
                if(dis[v] > dis[x] + g[x][v]){
                    dis[v] = dis[x] + g[x][v];
                    pre[v] = x;
                    if(!vis[v]){
                        vis[v] = 1;
                        que.push(v);
                    }
                }
            }
        }
    };
    auto cal = [&](int st){
        mst(col,0);
        int cnt_col = 0;
        //build
        //if(st == 1)For(i,1,n)debug(dis[i]);
        For(i,1,n)e[i].clear(), trees[i].clear();
        //trees build && son trees
        For(i,1,n){
            int a = i, b = pre[i];
            if(b == 0)continue;
            e[b].pb(a);
           // if(st == 1)cout<<"e: "<< a<<' '<<b<<endl;
        }
        for(auto v: e[st])trees[v].pb(v);
        queue<int>que;
        For(i,1,n){
            if(trees[i].empty()) continue;
            que.push(trees[i].back());
            cnt_col++;
            while(!que.empty()){
                int x = que.front();
                que.pop();
                col[x] = cnt_col;
                for(auto v: e[x]){
                    que.push(v);
                    trees[i].pb(v);
                }
            }
        }
        //cal1 s->to trees
        int res = inf;
        For(k,1,n){
            if(trees[k].empty()) continue;
            for(auto a: trees[k]){
                if(pre[a] == st) continue;
                if(dis[a] == inf) continue;
                if(g[a][st] != inf){
                    ckmin(res, dis[a] + g[a][st]);
                }
            }
        }
        //cal2 trees -> to trees
        For(k,1,n){
            if(trees[k].empty()) continue;
            for(auto a: trees[k]){
                if(dis[a] == inf) continue;
                For(l,1,n){
                    if(trees[l].empty()) continue;
                    if(k == l) continue;
                    for(auto b: trees[l]){
                        if(dis[b] == inf) continue;
                        if(g[a][b] == inf) continue;
                        /*
                        if(st == 1){
                            cout<<"e: "<< a<<' '<<b<<endl;
                            cout<<"dis[a]: "<<dis[a]<<" dis[b]: "<<dis[b]<<endl;
                        }
                        */
                        ckmin(res, dis[a] + dis[b] + g[a][b]);
                    }
                }
            }
        }
        if(res == inf) res = -1;
        ans[st] = res;
    };
    For(st,1,n){
        spfa(st);
        cal(st);
    }
    For(i,1,n)cout<<ans[i]<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}