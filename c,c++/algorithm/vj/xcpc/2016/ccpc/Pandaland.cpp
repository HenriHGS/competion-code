#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#include <map>
#include <cmath>
#define mp make_pair
#define X first
#define Y second
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 7e6, M = 4000*3;
typedef pair<int,int> PII;

struct pairhash{
public:
    template<typename T, typename U>
    std::size_t operator() (const std::pair<T,U>& x) const{
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

unordered_map<PII,int,pairhash> ma;

bool ban[M];
int e[M], ne[M], w[M], idx, h[N];
int n, m;
struct Edge{
    PII p1, p2;
    int w;
}edge[M];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], w[idx] = c, h[b] = idx++;
}
const int INF = 0x3f3f3f3f;
int dist[N];
bool vis[N];
void dij(int u,int val){
    For(i,0,n) vis[i] = 0, dist[i] = INF;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,u}); dist[u] = 0;
    while(!q.empty()){
        u = q.top().Y;
        int dis = q.top().X;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = h[u]; ~i; i = ne[i]){
            if(ban[i] || w[i] > val) continue;
            int j = e[i], val = w[i];
            if(dist[j] > dis + val){
                dist[j] = dis + val;
                q.push({dist[j],j});
            }
        }
    }
}

void init(){
    idx = 0;
    fori(i,0,M) ban[i] = 0;
    For(i,0,n) h[i] = -1;
}
int ans;
void sol(){
    scanf("%d", &m);
    ma.clear();
    n = 0;
    For(i,1,m){
        int x1, x2, y1, y2, val;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &val);
        edge[i] = {{x1,y1},{x2,y2}, val};
        PII p1 = {x1,y1}, p2 = {x2,y2};
        if(!ma.count(p1)) ma[p1] = ++n;
        if(!ma.count(p2)) ma[p2] = ++n;
    }
    init();
    //add
    For(i,1,m){
        PII &p1 = edge[i].p1, &p2 = edge[i].p2;
        int u = ma[p1], v = ma[p2];
        //debug(u); debug(v);
        add(u,v,edge[i].w);
    }
    int ans = INF;
    For(i,1,m){
        int i1 = i*2-1, i2 = i1^1;
        ban[i1] = ban[i2] = 1;
        int u = ma[edge[i].p1];
        int v = ma[edge[i].p2];
        dij(u, edge[i].w);
        if(dist[v] != INF)ans = min(ans, dist[v] + edge[i].w);
        ban[i1] = ban[i2] = 0;
    }
    printf("%d\n", ans == INF?0:ans);
}
int main(){
    int tt; scanf("%d", &tt);
    For(i,1,tt){
        printf("Case #%d: ", i);
        sol();
    }
    return 0;
}