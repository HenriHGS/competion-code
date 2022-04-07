#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10, M = 4e5+10;
int e[M], w[M], ne[M], idx, h[N];
typedef long long ll;
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
int n, m;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'),ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int sze[N];
int low[N], dfn[N], dfs_clock;
bool is_bridge[M];
void tarjan(int x, int last){
    low[x] = dfn[x] = ++dfs_clock;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            sze[x]++;
            tarjan(j,i);
            sze[x] += sze[j];
            low[x] = min(low[x], low[j]);
            if(dfn[x] < low[j]) is_bridge[i] = is_bridge[i^1] = 1;
        }else if(i != (last^1)){
            low[x] = min(low[x], dfn[j]);
            if(dfn[x] < dfn[j]){
                sze[x]++;
            }
        }
    }
}
int main(){
    memset(h,-1,sizeof h);
    ll sum = 0;
    n = read(), m = read();
    For(i,1,m) {
        int a = read(), b = read(), c = read();
        add(a,b,c); add(b,a,c);
        sum += c;
    }
    tarjan(1,-1);
    ll ans = 0;
    fori(i,0,idx){
        int a = e[i], b = e[i^1];
        if(is_bridge[i] && dfn[a] < dfn[b] && sze[b]%2==0 || !is_bridge[i]){
            //printf("i = %d\n", i);
            ans = max(ans, sum - w[i]);
        }
    }
    if(m%2 == 0){
        ans = sum;
    }
    printf("%lld\n", ans);
    return 0;
}