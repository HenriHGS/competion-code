#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#define mst(x,a) memset(x,a,sizeof x)
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
//const int N = 510, M = 2*3010;
const int N = 1e4, M = 2*N;
const int INF = 1e9;
int e[M], ne[M], f[M], idx;
int h[N], cur[N], q[N], d[N];

int w[N];
//0 -- 0, 1 -- 2, 2 -- 4, 3 -- 6
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], f[idx] = c, h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = c, h[b] = idx++;
}
int n, m;
int S, T;
bool bfs(){
    mst(d,-1);
    int tt = 0, hh = 0;
    q[0] = S, d[S] = 0, cur[S] = h[S];
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if(d[ver] == -1 && f[i]){
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if(ver == T) return true;
                q[++tt] = ver;
            }
        }
    }
    return false;
}
int find(int u, int limit){
    int flow = 0;
    if(u == T) return limit;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]){
        int ver = e[i];
        cur[u] = i;
        if(d[ver] == d[u] + 1 && f[i]){
            int t = find(ver, min(f[i], limit - flow));
            if(!t) d[ver] = -1;
            f[i] -= t, f[i^1] += t, flow += t;
        }
    }
    return flow;
}
int dinic(){
    int r = 0, flow;
    while(bfs()) while(flow = find(S, INF)) r += flow;
    return r;
}
int build(int s, int t){
    fori(i,0,m) {
        f[i*2] = w[i+1];
        f[(i*2)^1] = w[i+1];
    }
    S = s, T = t;
    return dinic();
}
int num[N];
int a[N], b[N];
int h1[N];
void add_edge(int a, int b, int c){
    e[idx] = b, f[idx] = c, ne[idx] = h1[a], h1[a] = idx++;
}
void MinCutTree(int l, int r){
    if(l >= r) return;
    int s = l, t = r;
   // debug(num[l]), debug(num[r]);
    int minCut = build(num[l], num[r]);
   // debug(minCut);
    add_edge(num[l], num[r], minCut);
    add_edge(num[r],num[l], minCut);
    int cnt1 = 0, cnt2 = 0;
    For(i,l,r){
        if(d[num[i]] != -1) a[++cnt1] = num[i];
        else b[++cnt2] = num[i];
    }
    int i = l, j = 1;
    while(j <= cnt1) num[i++] = a[j++];
    j = 1;
    while(j <= cnt2) num[i++] = b[j++];
    MinCutTree(l,l + cnt1 - 1);
    MinCutTree(l+cnt1,r);
}
#include <cctype>
int read(){
    char ch = getchar(); int f = 0,x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
int depth[N];
int fa[N][30], mi[N][30];
void bfs(int root){
    memset(mi, 0x3f, sizeof mi);
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0,depth[root] = 1;
    int hh = 0,tt = 0;
    q[0] = root;
    while(hh <= tt){
        int u = q[hh++];
        for(int i = h1[u]; ~i; i = ne[i]){
            int ver = e[i];
            if(depth[ver] > depth[u] + 1){
                q[++tt] = ver;
                depth[ver] = depth[u] + 1;
                fa[ver][0] = u;
                mi[ver][0] = f[i];
                for(int k = 1; k <= 15; k ++ ){
                    fa[ver][k] = fa[fa[ver][k-1]][k-1];
                    int anc = fa[ver][k-1];
                    mi[ver][k] = min(mi[ver][k-1],mi[anc][k-1]);
                }
            }
        }
    }
}
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    int res = INF;
    for(int k = 15; k>= 0; k -- )
        if(depth[fa[a][k]] >= depth[b]){
           // cout<<res<<endl;
            res = min(res, mi[a][k]), a = fa[a][k];
        }
    if(a == b) return res;
    for(int k = 15; k >= 0; k -- )
        if(fa[a][k] != fa[b][k]){
            res = min(res, mi[a][k]);
            res = min(res, mi[b][k]);
            a = fa[a][k];
            b = fa[b][k];
        }
    res = min(res, min(mi[a][0], mi[b][0]));
    return res;
}
int main(){
    memset(h,-1,sizeof h);
    memset(h1,-1,sizeof h1);
    n = read(), m = read(); n++;
    For(i,1,m){
        int a = read(), b = read(), c = read();
        w[i] = c;
        a++,b++;
        add(a,b,c);
    }
    For(i,1,n) num[i] = i;
    MinCutTree(1,n);
    bfs(1);
    int q = read();
    while(q--){
        int a = read(), b = read();
        a++,b++;
       // printf("%d:%d\n",q, lca(a,b));
        printf("%d\n", lca(a,b));
    }
    return 0;
}