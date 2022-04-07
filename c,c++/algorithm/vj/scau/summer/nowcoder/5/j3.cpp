#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef long long LL;
const int maxm = 300*300*2 + 300*2 + 300*2 + 100;
const int N = 600 + 10;
struct edge {
  int v, next;
  ll f, c;
} e[maxm];
struct node {
  int v, e;
} p[10005];
struct mypair {
  ll dis;
  int id;
  bool operator<(const mypair& a) const { return dis > a.dis; }
  mypair(ll d, int x) { dis = d, id = x; }
};
ll dis[N], h[N];
int head[N] , vis[N];
int n, m, s, t, cnt = 1;
ll maxf, minc;
void addedge(int u, int v, int f, ll c) {
  e[++cnt].v = v;
  e[cnt].f = f;
  e[cnt].c = c;
  e[cnt].next = head[u];
  head[u] = cnt;
}
bool dijkstra() {
  priority_queue<mypair> q;
  for (int i = 1; i <= n; i++) dis[i] = INF, vis[i] = 0;
  //memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  q.push(mypair(0, s));
  while (!q.empty()) {
    int u = q.top().id;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      ll  nc = e[i].c + h[u] - h[v];
      if (e[i].f && dis[v] > dis[u] + nc) {
        dis[v] = dis[u] + nc;
        p[v].v = u;
        p[v].e = i;
        if (!vis[v]) q.push(mypair(dis[v], v));
      }
    }
  }
  return dis[t] != INF;
}
void spfa() {
  queue<int> q;
  memset(h, 63, sizeof(h));
  h[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i].f && h[v] > h[u] + e[i].c) {
        h[v] = h[u] + e[i].c;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
}
int x[N], y[N], z[N], v[N];
int main()
{
    scanf("%d", &n);
    //mxmf.init(maxn);
    s = 2*n + 1;
    t = 2*n + 2;
    fori(t,0,n){
        int nv = n + t + 1;
        addedge(s, nv, 1, 0);
        addedge(nv, s, 0, 0);
        //mxmf.add(s,n+t+1,1,0);
    }
    For(i,1,n){
        scanf("%d%d%d%d", x+i, y+i, z+i, v+i);
        ll w = x[i]*x[i] + y[i]*y[i];
        fori(t,0,n){
            int nv = n + t + 1, u = i, f = 1;
            ll c = w + (ll)(z[i] + v[i]*t) * (z[i] + v[i]*t);
           // mxmf.add(pre,i,1,tw);
            addedge(nv, u, f, c);
            addedge(u, nv, 0, -c);
        }
        //mxmf.add(i,t,1,0);
        addedge(i, t, 1, 0);
        addedge(t, i, 0, 0);
    }
    n = 2*n+2;
    spfa();  // 先求出初始势能
    while (dijkstra()) {
        ll minf = INF;
        for (int i = 1; i <= n; i++) h[i] += dis[i];
        for (int i = t; i != s; i = p[i].v) minf = min(minf, e[p[i].e].f);
        for (int i = t; i != s; i = p[i].v) {
        e[p[i].e].f -= minf;
        e[p[i].e ^ 1].f += minf;
        }
        maxf += minf;
        minc += minf * h[t];
    }
    printf("%lld\n", minc);
    //printf("%d %d\n", maxf, minc);
    /*
    ll cost;
    mxmf.MincostMaxflow(s,t,cost);
    printf("%lld", cost);
    */
    return 0;
}