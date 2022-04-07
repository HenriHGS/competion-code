#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 410, M = N*N;
int e[M], h[N], idx, ne[M];
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
struct Edge{
    int a, b;
} edge[M];
bool vis[M];
int cur[M];
int dis[N], path[N];
vector<int> px;
const int INF = 0x3f3f3f3f;
void bfs(int op){
    memset(dis,0x3f,sizeof dis);
    int s = 1;
    For(i,1,n) cur[i] = h[i];
    queue<int>que;
    que.push(s);
    dis[1] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
       // cout<<u<<endl;
        for(int& i = cur[u]; ~i; i = ne[i]){
            if(!vis[i]) continue;
            int j = e[i];
            if(dis[j] > dis[u] + 1){
                dis[j] = dis[u] + 1;
                path[j] = i;
               // if(edge[i].a != u && op) swap(edge[i].a,edge[i].b);
                que.push(j);
            }
        }
    }
}
int ans[M];
int main(){
    memset(h,-1,sizeof h);
    scanf("%d %d", &n, &m);
    fori(i,0,m){
        int a, b; scanf("%d %d", &a, &b);
        add(a,b);
        edge[i] = {a,b};
        vis[i] = 1;
    }
    bfs(1);
    if(dis[n] == INF){
        For(i,1,m) puts("-1");
        return 0;
    }
    int x = n;
    while(x != 1){
        px.pb(path[x]);
        x = edge[path[x]].a;
    }
   // for(int i = 0; i < sz(px); i ++ ) cout<<px[i]<<endl;
    
    fori(i,0,m) ans[i] = dis[n];
    fori(k,0,sz(px)){
        vis[px[k]] = 0;
        bfs(0);
        ans[px[k]] = dis[n];
        vis[px[k]] = 1;
    }
    fori(i,0,m) printf("%d\n", ans[i] == INF?-1:ans[i]);
    return 0;
}