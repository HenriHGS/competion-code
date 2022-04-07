#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x :x;
}
// 仙人掌 转化为 圆方树。
const int N = 12000 + 10, M = 3*N;
//圆方树 点数最多是: （M + 1 ）, 圆方树边 为有向边。
int n, m, q;
int e[M], h1[N], h2[N], idx, w[M], ne[M];
void add(int *h, int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}
int pe[N], pv[N];
int low[N], dfn[N], dfs_clock;
int preS[N], cSum[N];
int tot;
void buildCircle(int x, int y, int ww){
    int sum = ww;
    for(int i = y; i != x; i = pv[i]){
        preS[i] = sum;
        int eind = pe[i];
        sum += w[eind];
    }
    cSum[x] = preS[x] = sum;
    add(h2,x,++tot,0);
    for(int i = y; i != x; i = pv[i]){
        cSum[i] = sum;
        add(h2,tot,i, min(sum - preS[i], preS[i]));
    }
}
void tarjan(int x, int last){
    dfn[x] = low[x] = ++dfs_clock;
    for(int i = h1[x]; ~i; i = ne[i]){
        int ver = e[i];
        if(!dfn[ver]){
            pv[ver] = x, pe[ver] = i;
            tarjan(ver,i);
            low[x] = min(low[x], low[ver]);
            if(dfn[x] < low[ver]) //bridge
                add(h2,x,ver,w[i]);
        }else if((i^1) != last) low[x] = min(low[x],dfn[ver]);
    }
    for(int i = h1[x]; ~i; i = ne[i]){
        int ver = e[i];
        if(dfn[x] < dfn[ver] && pv[ver] != x) buildCircle(x,ver, w[i]);
    }
}
int fa[N][15], depth[N], d[N];
void dfs_lca(int x){
    depth[x] = depth[fa[x][0]] + 1;
    for(int k = 1; k <= 14; k ++ ){
        int anc = fa[x][k-1];
        fa[x][k] = fa[anc][k-1];
    }
    for(int i = h2[x]; ~i; i = ne[i]){
        int j = e[i];
        fa[j][0] = x;
        d[j] = d[x] + w[i];
        dfs_lca(j);
    }
}
int A, B;
int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);
    for(int k = 14; k >= 0; k -- ){
        if(depth[fa[a][k]] >= depth[b]) a = fa[a][k];
    }   
    if(a == b) return a;
    for(int k = 14; k >= 0; k -- ){
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    A = a, B = b;
    return fa[a][0];
}
int main(){
    memset(h1,-1,sizeof h1); 
    memset(h2,-1,sizeof h2); 
    cin>>n>>m>>q;//n = read(), m = read(), q = read();
    tot = n;
    For(i,1,m){
        int a,b,c;//int a = read(), b = read(), c = read();
        cin>>a>>b>>c;
        add(h1,a,b,c), add(h1,b,a,c);
    }
    tarjan(1,-1);
    dfs_lca(1);
    For(i,1,q){
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        if (p <= n) printf("%d\n", d[a] + d[b] - d[p] * 2);
        else
        {
            int da = d[a] - d[A], db = d[b] - d[B];
            //这里不能加abs。wa死。。。。。因为lca时，
            //可能是会交换a，b的所以求出的A,B并不是对应的。
            int l = abs(preS[A] - preS[B]);
            int dm = min(l, cSum[A] - l);
            printf("%d\n", da + dm + db);
        }
    }
    return 0;
}