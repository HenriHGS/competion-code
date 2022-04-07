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
#define X first
#define Y second
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
typedef pair<ll,ll>pal;
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

const int N = 5e3+10;
const int M = N*N*2;
ll e[N][N];
int n;
pal p[N];
ll getDist(pal i, pal j){
    return (i.X - j.X)*(i.X - j.X) + (i.Y - j.Y)*(i.Y - j.Y);
}
bool st[N];
ll dist[N];
bool prim(int s, ll&ans){
    For(i,1,n) dist[i] = 6e18, st[i] = false;
    priority_queue<pal,vector<pal>,greater<pal>>que;
    que.push(mp(0,s));
    dist[s] = 0;
    int time = 0;
    while(!que.empty() && time < n){
        int x = que.top().second;
        ll d = que.top().first;
        que.pop();
        if(st[x]) continue;
        time++;
        ans = max(ans,d);
        st[x] = true;
        for(int i = 1; i <= n; i ++ ){
            if(dist[i] > e[x][i]){
                dist[i] = e[x][i];
                que.push(mp(dist[i],i));
            }
        }
    }
    return time == n;
}
void sol(){
    ll ans = 0;
    n = read();
    For(i,1,n)p[i].X = read(), p[i].Y = read();
    For(i,1,n)For(j,i,n){
        e[i][j] = e[j][i] = getDist(p[i],p[j]);
    }
    prim(1,ans);
    print(ans,'\n');
}

int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = read();
    while(tt--) sol();
    return 0;
}