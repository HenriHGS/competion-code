#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 1e5+10, M = 2e6+10;
int e[M], ne[M], h[N], hs[N], idx;
int dfn[N], low[N], dfs_clock;
int stk[N], top;
bool in_stk[N];
void add(int h[], int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int siz[N], id[N], scc_cnt;
void tarjan(int x){
    dfn[x] = low[x] = ++dfs_clock;
    in_stk[x] = true, stk[++top] = x;

    for(int i = h[x]; ~i; i =  ne[i]){
        int j = e[i];
        if(!dfn[j]) {
            tarjan(j);
            low[x] = min(low[x], low[j]);
        }else if(in_stk[j]) low[x] = min(low[x], dfn[j]);
    }

    if(dfn[x] == low[x]){
        int y;
        scc_cnt++;
        do{
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt]++;
        }while(y != x);
    }
}
int f[N], g[N];
int n, m, mod;
unordered_set<ll> s;
int main(){
    memset(h,-1,sizeof h);
    memset(hs,-1,sizeof hs);
    scanf("%d %d %d", &n, &m, &mod);
    For(i,1,m){
        int a, b;
        scanf("%d %d", &a, &b);
        add(h,a,b);
    }
    For(i,1,n) if(!dfn[i]) tarjan(i);
    For(x,1,n)
        for(int i = h[x]; ~i; i = ne[i]){
            int a = id[x], b = id[e[i]];
            ll hash = a*1000000LL+b;
            if(a != b){
                if(!s.count(hash)){
                    add(hs,a,b);
                    s.insert(hash);
                }
            }
        } 
    for(int i = scc_cnt; i ; i -- ){
        if(!f[i]){
            f[i] = siz[i];
            g[i] = 1;
        }
        for(int j = hs[i]; ~j; j = ne[j]){
            int a = i, b = e[j];
            if(f[a] + siz[b] > f[b]){
                f[b] = f[a] + siz[b];
                g[b] = g[a];
            }else if(f[a] + siz[b] == f[b]){
                g[b] = (g[b] + g[a])%mod;
            }
        }
    }
    int max_len = 0, max_tra = 0;
    For(i,1,scc_cnt){
        if(max_len < f[i]){
            max_len = f[i];
            max_tra = g[i];
        }else if(max_len == f[i]){
            max_tra += g[i];
            max_tra %= mod;
        }
    }
    printf("%d\n%d\n",max_len,max_tra);
    return 0;
}