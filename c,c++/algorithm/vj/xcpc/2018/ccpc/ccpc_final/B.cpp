#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int INF = 1e9+10;
typedef pair<int,int> PII;

struct Node{
    int mx[2], mi[2]; //0 l 1 r
}node[N];

struct Tree{
    int l, r, mi, sum;
} tr[N<<2];

#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r){
    tr[u] = {l,r,INF,0};
    if(l == r) return ;
    int mid = l + r >> 1;
    build(ls,l,mid), build(rs,mid+1,r);
}
void pushup(int u){
    tr[u].mi = min(tr[ls].mi, tr[rs].mi);
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void mody(int u, int pos,int x){
    if(tr[u].l == tr[u].r){
        tr[u].mi = x, tr[u].sum = 1;
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(pos <= mid) mody(ls,pos,x);
        else mody(rs,pos,x);
        pushup(u);
    }
}
int col[N];
int tot, idx;
int n, m;
int w[N][2];
vector<int> e[N];
void init(){
    idx = tot = 0;
    memset(col, -1, sizeof col);
    scanf("%d %d", &n, &m);
    For(i,1,n) e[i].clear();

    For(i,1,m) {
        int a, b; scanf("%d %d", &a, &b);
        e[a].pb(b);
        e[b].pb(a);
    }
    For(i,1,n) fori(k,0,2) scanf("%d", &w[i][k]);
    
}


bool dfs(int x, int color, vector<vector<int>> &v){
    if(color == 0) v[0].pb(x);
    else v[1].pb(x);
    col[x] = color;
    for(auto j : e[x]){
        if(col[j] == -1) {
            if(!dfs(j,color^1,v)) return false;
        }else if(col[x] == col[j]) return false;
    }
    return true;
}
PII aa[N<<1];
void sol(){
    init();
    For(i,1,n){
        if(col[i] != -1) continue;
        ++tot;
        auto& mx = node[tot].mx, &mi = node[tot].mi;
        vector<vector<int>> v(2);
        if(!dfs(i,0,v)){
            puts("IMPOSSIBLE");
            return;
        }
        fori(k,0,2){
            //l -- l
            mx[k] = 0;
            mi[k] = INF;
            for(auto j: v[0]){
                mx[k] = max(mx[k],w[j][k]);
                mi[k] = min(mi[k], w[j][k]);
            }
            //r -- r
            for(auto j: v[1]){
                mx[k] = max(mx[k], w[j][k^1]);
                mi[k] = min(mi[k], w[j][k^1]);
            }
        }
        aa[++idx] = {mx[0],tot};
        aa[++idx] = {mx[1],tot};
    }
    build(1,1,tot);
    int ans = INF;
    sort(aa + 1, aa + 1 + idx);
    For(i,1,idx){
        int ed = aa[i].fi;
        int pos = aa[i].se;
        int x = 0;
        if(node[pos].mx[0] <= ed) x = node[pos].mi[0];
        if(node[pos].mx[1] <= ed) x = max(x,node[pos].mi[1]);
        mody(1,pos,x);
        if(tr[1].sum == tot)ans = min(ans, ed - tr[1].mi);
    }
    printf("%d\n", ans);
}

int cas;
int main(){
    int tt; scanf("%d", &tt);
    while(tt--){
        printf("Case %d: ",++cas);
        sol();
    }
    return 0;
}