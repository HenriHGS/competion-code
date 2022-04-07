#include <cstdio>
#include <cstring>
#include <queue>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e3+10;
int dist[N];
long long path[N];
int n, m, st, ed;
int idx, h[N], e[N], w[N], ne[N];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
void init(){
    memset(h, -1, sizeof(h));
    idx = 0;
    scanf("%d %d", &n, &m);
    For(i,1,m){
        int a, b, c;
        scanf("%d%d%d", &a, &b,&c);
        add(a,b,c);
    }
    scanf("%d %d", &st, &ed);
}
struct node{
    int u, dis;
    bool operator < (const node& x)const{
        return dis > x.dis;
    }
};
void dij(){
    memset(dist,0x3f, sizeof(dist));
    memset(path,0, sizeof(path));
    priority_queue<node> que;
    que.push((node){st,0});
    dist[st] = 0;
    path[st] = 1;
    while(!que.empty()){
        auto nod = que.top();
        int u = nod.u;
        que.pop();
        if(nod.dis > dist[u]) continue;
        for(int i = h[u]; ~i; i = ne[i]){
            int v = e[i];
            if(dist[v] > dist[u] + w[i]){
                dist[v] = dist[u] + w[i];
                path[v] = path[u];
                que.push((node){v,dist[v]});
            }else if(dist[v] == dist[u] + w[i]){
                path[v] = path[v] + path[u];
            }
        }
    }
}
void sol(){
    init();
    dij();
    printf("%lld\n", path[ed]);
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}