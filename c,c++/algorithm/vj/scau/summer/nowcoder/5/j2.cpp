#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef long long LL;
const int N = 600 + 10;
struct edge {
  int v, next;
  ll f, c;
} e[100005];
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
  for (int i = 1; i <= n; i++) dis[i] = INF;
  memset(vis, 0, sizeof(vis));
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
/*
int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for (int i = 1; i <= m; i++) {
    int u, v, f, c;
    scanf("%d%d%d%d", &u, &v, &f, &c);
    addedge(u, v, f, c);
    addedge(v, u, 0, -c);
  }
  spfa();  // 先求出初始势能
  while (dijkstra()) {
    int minf = INF;
    for (int i = 1; i <= n; i++) h[i] += dis[i];
    for (int i = t; i != s; i = p[i].v) minf = min(minf, e[p[i].e].f);
    for (int i = t; i != s; i = p[i].v) {
      e[p[i].e].f -= minf;
      e[p[i].e ^ 1].f += minf;
    }
    maxf += minf;
    minc += minf * h[t];
  }
  printf("%d %d\n", maxf, minc);
  return 0;
}
*/
int x[maxn], y[maxn], z[maxn], v[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    mxmf.init(maxn);
    int s = 2*n + 1;
    int t = 2*n + 2;
    fori(t,0,n){
        int v = n + t + 1;
        addedge(s, v, 1, 0);
        addedge(v, s, 0, 0);
        //mxmf.add(s,n+t+1,1,0);
    }
    For(i,1,n){
        scanf("%d%d%d%d", x+i, y+i, z+i, v+i);
        ll w = x[i]*x[i] + y[i]*y[i];
        fori(t,0,n){
            int v = n + t + 1, u = i, f = 1;
            ll c = w + (ll)(z[i] + v[i]*t) * (z[i] + v[i]*t);
           // mxmf.add(pre,i,1,tw);
            addedge(u, v, f, c);
            addedge(v, u, 0, -c);
        }
        //mxmf.add(i,t,1,0);
        addedge(i, t, 1, 0);
        addedge(t, i, 0, 0);
    }
    spfa();  // 先求出初始势能
    while (dijkstra()) {
        int minf = INF;
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