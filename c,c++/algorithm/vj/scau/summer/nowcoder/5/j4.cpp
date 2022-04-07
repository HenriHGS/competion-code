#include <cstdio>
#include <cstring>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 600 + 10;
const int maxm = 300*300*2 + 300*2 + 300*2 + 100;
typedef long long ll;
typedef long long LL;
struct edge { int v, ne, flow; ll cost; } a[maxm];
int h[maxn], n, m, tmp = 1, src = 1, dest = 2, tot = 2, maxflow;
int dis[maxn], now[maxn];
ll mincost, co;
bool vis[maxn];

template <class _Tp> void chkmin(_Tp &a, _Tp b) { if (a > b) a = b; }
void add(int x, int y, int flow, ll cost) { a[++tmp] = (edge){y, h[x], flow, cost}; h[x] = tmp; }
void add1(int x, int y, int flow, ll cost) { add(x, y, flow, cost), add(y, x, 0, -cost); }

int aug(int x, int want)
{
	if (x == dest) { mincost += co * want, maxflow += want; return want; }
	vis[x] = true;
	int get = 0;
	for (int i = now[x]; i != 0; i = a[i].ne)
	{
		if (a[i].flow > 0 && a[i].cost == 0 && vis[a[i].v] == false)
		{
			int f = aug(a[i].v, min(a[i].flow, want));
			a[i].flow -= f, a[i ^ 1].flow += f;
			want -= f, get += f;
		}
		now[x] = i;
		if (want == 0) break;
	}
	return get;
}

bool modlabel()
{
	ll tmp = 1e18;
	for (int x = 1; x <= tot; x++) if (vis[x])
		for (int i = h[x]; i != 0; i = a[i].ne)
			if (a[i].flow > 0 && vis[a[i].v] == false)
				chkmin(tmp, a[i].cost);
	if (tmp == 1e18) return false;
	for (int x = 1; x <= tot; x++) if (vis[x])
		for (int i = h[x]; i != 0; i = a[i].ne)
			a[i].cost -= tmp, a[i ^ 1].cost += tmp;
	co += tmp;
	return true;
}

void zkw()
{
	do	do	for (int i = 1; i <= tot; i++) now[i] = h[i], vis[i] = false;
		while (aug(src, 1e9));
	while (modlabel());
}
int x[maxn], y[maxn], z[maxn], v[maxn];
int main()
{
	//scanf("%d%d%d%d", &tot, &m, &src, &dest);
	/*
    for (int x, y, w, f, i = 1; i <= m; i++)
		scanf("%d%d%d%d", &x, &y, &w, &f), add1(x, y, w, f);
	zkw();
	printf("%d %d\n", maxflow, mincost);
	*/
    scanf("%d", &n);
    //mxmf.init(maxn);
    src = 2*n + 1;
    dest = 2*n + 2;
    fori(t,0,n){
        int pre = src, now = n + t + 1;
        //addedge(s, nv, 1, 0);
        //addedge(nv, s, 0, 0);
        //mxmf.add(s,n+t+1,1,0);
        add1(pre,now,0,1);//flow cost
    }
    For(i,1,n){
        scanf("%d%d%d%d", x+i, y+i, z+i, v+i);
        ll w = x[i]*x[i] + y[i]*y[i];
        int pre, now, f;
        fori(t,0,n){
            pre = n + t + 1, f = 1, now = i;
            ll c = w + (ll)(z[i] + v[i]*t) * (z[i] + v[i]*t);
           // mxmf.add(pre,i,1,tw);
           // addedge(nv, u, f, c);
           // addedge(u, nv, 0, -c);
           add1(pre,now,f,c);
        }
        pre = i, now = dest, f = 1;
        add1(pre,now,f,0);
        //mxmf.add(i,t,1,0);
       // addedge(i, t, 1, 0);
        //addedge(t, i, 0, 0);
    }
    /*
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
    */
   zkw();
    printf("%lld\n", mincost);
    return 0;
}
/*
https://www.luogu.com.cn/blog/Luan233/zkw-fei-yong-liu-jiang-xie-byluan
https://www.cnblogs.com/oier/p/10458540.html
https://blog.csdn.net/jzq233jzq/article/details/73123089
https://artofproblemsolving.com/community/c1368h1020435
http://blog.sina.com.cn/s/blog_76f6777d0101bbc8.html
可以用pushrelabel费用流，跑的飞快
一个优化的费用流板子
https://ac.nowcoder.com/acm/contest/view-submission?submissionId=48357811
*/