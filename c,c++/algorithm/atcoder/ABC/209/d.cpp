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
const int N = 1e5+10, M = N*2;
int e[M], ne[M], head[M], w[M], idx;
int dist[N], depth[N], fa[N][17];
int n, m;
void add(int a, int b, int c){
    e[idx]=b, ne[idx]=head[a],w[idx]=c, head[a] = idx++;
}

void bfs(int u){
    memset(depth,0x3f, sizeof depth);
    queue<int>q;
    q.push(u);
    depth[0] = 0, depth[u] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i =ne[i]){
            int v = e[i];
            if(depth[v]>depth[u]+1){
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + w[i];
                q.push(v);
                fa[v][0] = u;
                for(int k = 1; k <=16; k ++ ) fa[v][k] = fa[fa[v][k-1]][k-1];
            }
        }
    }
}
int lca(int a, int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int k = 16; k>=0; k--){
        if(depth[fa[a][k]] >= depth[b]) a = fa[a][k];
    }
    if(a==b)return a;
    for(int k = 16; k >= 0; k -- ){
        if(fa[a][k]!=fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}
int main(){
    memset(head,-1, sizeof head);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n-1; i ++ ){
        int a, b, c;
        scanf("%d%d", &a, &b);
        c = 1;
        add(a,b,c),add(b,a,c);
    }
    bfs(1);
    for(int i = 0; i < m ; i++ ){
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a,b);
       // printf("%d\n", dist[a]+dist[b]-2*dist[p]);
        int dis = dist[a]+dist[b]-2*dist[p];
        if(dis%2)puts("Road");
        else puts("Town");
    }
    return 0;
}