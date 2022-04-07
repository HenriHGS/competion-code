#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cctype>
#include <vector>
#include <climits>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e3+ 10, M = 3e4 * 2 + 10;

/* tarjan */
vector<int> ecc[N];
int ecc_cnt, id[N];
bool is_cut[N];
bool is_bridge[M];
int dfn[N], low[N], stk[N], top, dfs_clock;
int e[M], h[N], eid[M], ne[M], idx, w[M];
int pv[N], pe[N];
int pv1[N], pe1[N];

void init(int n){
    memset(is_bridge, 0, sizeof is_bridge);
    memset(h,-1,sizeof h);
    idx = 0;
    For(i,0,n) dfn[i] = 0;
    ecc_cnt = 0;
    For(i,0,n) ecc[i].clear();
}
void initdfs(int n){
    memset(is_bridge, 0, sizeof is_bridge);
    For(i,0,n) dfn[i] = 0;
    top = 0;
    ecc_cnt = 0;
    For(i,0,n) ecc[i].clear();
}
void add(int a, int b, int c, int _id){
    //printf("pre: h[a]: %d\n", h[a]);
    e[idx] = b, ne[idx] = h[a], eid[idx] = _id, w[idx] = c, h[a] = idx ++ ;
    // printf("debug: a = %d, b = %d, c = %d, idx = %d, h[a] = %d\n", a, b, c, idx, h[a]);
}


bool ban[M];
void dfs(int x, int last){
    low[x] = dfn[x] = ++ dfs_clock;
    stk[++top] = x;
    int child = last != -1;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(ban[i]) continue;
        if(!dfn[j]){
            pv[j] = x;
            pe[j] = i;
            child ++ ;
            dfs(j,i);
            low[x] = min(low[x],low[j]);
            if(dfn[x] < low[j]) is_bridge[i] = is_bridge[i^1] = true;
        }else if((i^1) != last && dfn[j] < dfn[x]) low[x] = min(low[x], dfn[j]);
    }
    if(child > 1) is_cut[x] = true;
    if(dfn[x] == low[x]){
        int y;
        ecc_cnt++;
        do{
            y = stk[top -- ];
            id[y] = ecc_cnt;
            ecc[ecc_cnt].push_back(y);
        }  while(y != x);
    }
}
/* tarjan */

int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
//tar1 存储原来的tar图，也方便求答案
//tar2 用来枚举删除一条边后，求的tarjan
int n, m, S, T;
#define x first
#define y second
//vector<pair<int,int>> e[N];

int main(){
    n = read(), m = read();
    S = read(), T = read();
    init(n);
    For(i,1,m){
        int a = read(), b = read(), c = read();
        add(a,b,c, i); add(b,a,c, i);
    }
    dfs(S, -1);
    if(!dfn[T]) {
        puts("0");
        puts("0");
        return 0;
    }
    //求只删除一条边时的，答案
    int ans2 = INT_MAX;
    vector<int> del_edge;
    
    /* for(int i = 0; i < idx; i += 2){
        int w = tar1.w[i];
        if( tar1.is_bridge[i]){
            if(w < ans2){
                ans2 = w;
                //printf("mi_edge is %d\n", w);
                del_edge.clear();
                del_edge.push_back(tar1.eid[i]);
            }
        }
    } */
    For(i,1,n) pv1[i] = pv[i], pe1[i] = pe[i];
    //dfs1(S, -1);
    for(int x = T; x != S; x = pv1[x]){
        //现在是枚举删除的是哪一条边

        int ind = pe1[x];
        int eid1 = eid[ind], eid2;
        ban[ind] = ban[ind^1] = 1;
        initdfs(n);
        dfs(S,-1);
        ban[ind] = ban[ind^1] = 0;
        if(!dfn[T]){
            if(ans2 > w[ind]){
                ans2 = w[ind];
                del_edge.clear();
                del_edge.push_back(eid1);
            }
            continue;
        }
        for(int y = T; y != S; y = pv[y]){
            int i = pe[y];
            if(is_bridge[i]){
                if(ans2 > w[ind] + w[i]){
                    ans2 = w[ind] + w[i];
                    eid2 = eid[i]; 
                    del_edge.clear();
                    del_edge.push_back(eid1);
                    del_edge.push_back(eid2);
                }
            }
        }
    }
    if(ans2 == INT_MAX){
        puts("-1");
        return 0;
    }
    printf("%d\n", ans2);
    printf("%d\n", del_edge.size());
    sort(del_edge.begin(), del_edge.end());
    for(auto x:del_edge) printf("%d ", x);
    return 0;
}
