#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define mst(x,a) memset(x,a,sizeof x)
using namespace std;
typedef long long ll;
const int N = 1e5+10, M = (1e5+10)*2*2;
int e[M], ne[M], idx;
int h1[N], h2[N];
void add(int a, int b, int h[]){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m;
int bcc_cnt, id[N], siz[N], sizE[N];
int dfn[N], low[N], dfs_clock;
bool in_stk[N];
int top, stk[N];

void tarjan(int x, int h[]){
    dfn[x] = low[x] = ++dfs_clock;
    in_stk[x] = true, stk[++top] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j,h);
            low[x] = min(low[x], low[j]);
        }else if(in_stk[j]) low[x] = min(low[x], dfn[j]);
    }
    if(low[x] == dfn[x]){
        int y;
        bcc_cnt++;
        do{
            siz[bcc_cnt]++;
            y = stk[top--];
            in_stk[y] = false;
            id[y] = bcc_cnt;
        }while(y != x);
    }
}
ll ans = 0;
int du[N], out[N];
void init(){
    ans = 0;
    For(i,0,n) h1[i] = h2[i] = -1;
    For(i,0,n) out[i] = du[i] = dfn[i] = 0;
    For(i,0,bcc_cnt) sizE[i] = siz[i] = 0;
    bcc_cnt = top = idx = dfs_clock = 0;
}
struct Edge{
    int a, b;
}edge[M];
void sol(){
    scanf("%d %d", &n, &m);
    For(i,1,m){
        int a, b; scanf("%d %d", &a, &b);
        edge[i] = {a,b};
        add(a,b,h1); //add(b,a,h1);
    }
    For(i,1,n) if(!dfn[i]) tarjan(i,h1);
    if(bcc_cnt == 1){
        puts("-1");
        return ;
    }
    for(int i = 1; i <= m; i ++){
        int ind1 = id[edge[i].a];
        int ind2 = id[edge[i].b];
        if(ind1 == ind2) {
            sizE[i]++;
            continue;
        }
        du[ind2]++;
        out[ind1]++;
    }
    ll tot = 1ll*n*(n-1)/2;
    For(i,1,bcc_cnt){
        if(du[i] == 0){
            ll oth = n - siz[i];
            ll add0 = oth*siz[i] - out[i] + (1ll*siz[i]*(siz[i]-1) - sizE[i]);
            //debug(add0);
            ll add1 = oth*(oth-1) - (m - out[i] - sizE[i]);
           // debug(oth*(oth-1));
            //debug(out[i]);
            //debug(add1);
            ans = max(ans,add0 + add1);
        }else if(out[i] == 0){
            //没考虑这个
            ll oth = n - siz[i];
            ll add0 = oth*siz[i] - du[i] + (1ll*siz[i]*(siz[i]-1) - sizE[i]);
            //debug(add0);
            ll add1 = oth*(oth-1) - (m - du[i] - sizE[i]);
           // debug(oth*(oth-1));
            //debug(out[i]);
            //debug(add1);
            ans = max(ans,add0 + add1);
        }
    }
    printf("%lld\n", ans);
}
int main(){
    mst(h2,-1); mst(h1,-1);
    int tt; scanf("%d", &tt);
    For(i,1,tt){
        printf("Case %d: ", i);
        sol();
        init();
    }
    return 0;
}
/*
1004
最终添加完边的图，肯定可以分成两个部X和Y，其中只有X到Y的边没有Y到X的边，
那么要使得边数尽可能的多，则X部肯定是一个完全图，Y部也是，
同时X部中每个点到Y部的每个点都有一条边，假设X部有x个点，Y部有y个点，有x+y=n，
同时边数F=x*y+x*(x-1)+y*(y-1)，整理得：F=N*N-N-x*y，当x+y为定值时，二者越接近，
x*y越大，所以要使得边数最多，那么X部和Y部的点数的个数差距就要越大，
所以首先对于给定的有向图缩点，对于缩点后的每个点，如果它的出度或者入度为0，
那么它才有可能成为X部或者Y部，所以只要求缩点之后的出度或者入度为0的点中，
包含节点数最少的那个点，令它为一个部，其它所有点加起来做另一个部，
就可以得到最多边数的图了

*/