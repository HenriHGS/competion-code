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
const int mod = 998244353;
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

struct triple{
    int x, y, d;
};
int dis[2000][2000][4];
int vis[2000][2000][4];
int dx[] = {-1,-1,1,1};
int dy[] = {-1,1,1,-1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int ax, ay, bx, by;
    cin>>n>>ax>>ay>>bx>>by;
    ax--,ay--,bx--,by--;
    vector<string> g(n);
    for(int i = 0; i < n; i ++ ) cin>>g[i];
    deque<triple> que;
    memset(dis, 0x3f,sizeof dis);
    for(int i = 0; i < 4; i ++ ) {
        int tx = dx[i] + ax;
        int ty = dy[i] + ay;
        if(tx< 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] == '#') continue;
        dis[tx][ty][i] = 1;
        que.push_front({tx,ty,i});
    }
    while(!que.empty()){
        auto node = que.front(); que.pop_front();
        int x = node.x, y = node.y, d = node.d;
        if(vis[x][y][d]) continue;
        vis[x][y][d] = 1;
       // cout<<x<<' '<<y<<endl;
        for(int i = 0; i < 4; i ++ ) {
            int tx = dx[i] + node.x;
            int ty = dy[i] + node.y;
            if(tx< 0 || tx >= n || ty < 0 || ty >= n || g[tx][ty] == '#') continue;
            //dis[tx][ty][i] = 1;
            if(i == d){
                if(dis[tx][ty][d] > dis[x][y][d]){
                    que.push_front({tx,ty,i});
                    dis[tx][ty][d] = dis[x][y][d];
                }
            }else {
                if(dis[tx][ty][i] > dis[x][y][d] + 1){
                    que.push_back({tx,ty,i});
                    dis[tx][ty][i] = dis[x][y][d] + 1;
                }
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < 4; i ++ ) ans = min(ans, dis[bx][by][i]);
    if(ans == inf) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}