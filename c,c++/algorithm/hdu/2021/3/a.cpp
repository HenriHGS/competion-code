#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define rep(i,y,x) for(int i = (y); i >= (x); i -- )
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define sz(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define mp make_pair
#define l first
#define r second
#define db double
#define endl '\n'
#define debug(a) cout<<#a<<": "<< a<<endl
using namespace std;
typedef long long LL;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int>pa;
const int N = 1e5+10, M = 2e5+10;
int h[N], e[M], ne[M], w[M], idx;
int val[N], e_id[M];
int dpt[N], fa[N], siz[N], son[N], seq[N], dfn[N], dfs_clock, top[N];
int n, s, q;
ll pre[N], suf[N];
void init(){
    mst(h,-1);
    idx = 0;
    dfs_clock = 0;
    For(i,1,n)dfn[i] = seq[i] = dpt[i] = son[i] = siz[i] = top[i] = fa[i] = 0;
}
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs1(int x){
    int i;
    dpt[x] = dpt[fa[x]] + 1;
    siz[x] = 1;
    for(i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x]) continue;
        fa[v] = x;
        dfs1(v);
        siz[x] += siz[v];
        if(siz[v] > siz[son[x]]) son[x] = v;
    }
}
void dfs2(int x){
    int i;
    seq[dfn[x] = ++ dfs_clock] = x;
    if(son[fa[x]] == x) top[x] = top[fa[x]];
    else top[x] = x;
    if(son[x]) dfs2(son[x]);
    for(int i = h[x]; ~i; i = ne[i]){
        int v = e[i];
        if(v == fa[x] || v == son[x]) continue;
        dfs2(v);
    }
}
int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dpt[top[x]] < dpt[top[y]]) swap(x,y);
        x = fa[top[x]];
    }
    if(dpt[x] > dpt[y]) swap(x,y);
    return x;
}
void getPreSum(){
    pre[0] = suf[n+1] = 0;
    For(i,1,n) pre[i] = pre[i - 1] + val[seq[i]];
    rep(i,n,1) suf[i] = suf[i+1] + val[seq[i]];
}
LL getSum(int x, int y, LL tot, bool& ok){
    LL sum = pre[y] - pre[x - 1];
    if(sum <= tot) {
        return sum;
    }
    int L = x, R = y;
    LL res = 0;
    while(L <= R){
        int mid = L + R>>1;
        LL tmpsum = suf[mid] - suf[y+1];
        if(tmpsum <= tot)res = tmpsum, R = mid - 1;
        else  L = mid+1;
    }
    return tmpsum;
}
LL Tquery(int x, int y, LL tot){
    LL res = 0;
    int op = 1;//现在看的是x节点
    stack<pa> stk;
    while(top[x] != top[y]){
        if(dpt[top[x]] < dpt[top[y]]) swap(x,y), op^=1;
        if(op == 0){
            //y半部分的区间可以先存起来
            stk.push({dfn[top[x]],dfn[x]});
        }else {
            bool ok = false
            LL add = getSum(dfn[top[x]], dfn[x], tot - res);
            res += add;
        }
        //res += getSum(1,dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if(x == y) return res;
}
void sol(){
    init();
    scanf("%d%d", &n, &q);
    //vector<pa>adj;
    For(i,1,n)scanf("%d", val+i);
    fori(i,0,n-1){
        int a, b, c;
        scanf("%d%d%d", &a,&b);
        add(a,b);add(b,a);
    }
    getPreSum();
    while(q--){
        int x, y, p;
        scanf("%d%d%d", &x,&y,&p);
        //int anc = LCA(x,y);
        LL rem = p - Tquery(x,y,p);
    }
}
int main(){
    int tt;scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}