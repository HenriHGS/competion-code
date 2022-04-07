#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define pb push_back
#define sz(a) (int)(a.size())
#define mst(x,a) memset(x,a,sizeof(x))
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define fzhead EDGE(int u, int v, long long c, long long  f, long long w)
#define fzbody from(u), to(v), cap(c), flow(f), cost(w)
using namespace std;
typedef long long ll;
typedef long long LL;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int maxn=600+10;
const int maxm=40004;
struct EDGE
{
    int from,to;
    ll cap,flow,cost;
    EDGE(){}
    fzhead:fzbody{}
};
struct MXMF
{
    int n,m;
    vector<EDGE> edges;
    vector<int>g[maxn];
    int vis[maxn];//判断是否在队中
    ll d[maxn];//Bellman-Ford
    int p[maxn];//上一条弧
    ll a[maxn];//可改进量
    //
    void init(int n)
    {
        this->n=n;
        for(int i=0; i<n; i++)g[i].clear();
        edges.clear();
    }
    //
    void add(int from, int to, ll cap, ll cost)
    {
        edges.pb(EDGE(from,to,cap,0,cost));
        edges.pb(EDGE(to,from,0,0,-cost));
        m=edges.size();
        g[from].pb(m-2);
        g[to].pb(m-1);
    }
    //
    bool BellmanFord(int s, int t, ll&flow, ll &cost)
    {
        for(int i=0; i<n; i++)d[i]=INF;
        mst(vis,0);
        d[s]=0;vis[s]=1;p[s]=0;a[s]=INF;
        //
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            vis[u]=0;
            for(int i=0; i<sz(g[u]); i++)
            {
                EDGE&e=edges[g[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=g[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!vis[e.to])
                    {
                        q.push(e.to);
                        vis[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF)return false;
        flow+=a[t];
        cost+=(ll)d[t]*(ll)a[t];
        for(int u=t; u!=s; u=edges[p[u]].from)
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        return true;
    }
    ll MincostMaxflow(int s, int t, ll&cost)
    {
        ll flow=0;cost=0;
        while(BellmanFord(s,t,flow,cost));
        return flow;
    }
}mxmf;
int x[maxn], y[maxn], z[maxn], v[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    mxmf.init(maxn);
    int s = 2*n + 1;
    int t = 2*n + 2;
    fori(t,0,n)mxmf.add(s,n+t+1,1,0);
    For(i,1,n){
        scanf("%d%d%d%d", x+i, y+i, z+i, v+i);
        ll w = x[i]*x[i] + y[i]*y[i];
        fori(t,0,n){
            int pre = n + t + 1;
            ll tw = w + (ll)(z[i] + v[i]*t) * (z[i] + v[i]*t);
            mxmf.add(pre,i,1,tw);
        }
        mxmf.add(i,t,1,0);
    }
    ll cost;
    mxmf.MincostMaxflow(s,t,cost);
    printf("%lld", cost);
    return 0;
}