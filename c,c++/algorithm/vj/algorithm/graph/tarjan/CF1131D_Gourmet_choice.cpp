#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e3+10;
const int M = N*N*4;
int e[M], ne[M], h[N], idx, w[M];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x / 10);
    putchar(x%10 + '0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
int n, m;
bool in_stk[N];
int scc_cnt, top, stk[N];
int id[N], fa[N], siz[N];
int low[N], dfn[N], dfs_clock;
void tarjan(int x){
    dfn[x] = low[x] = ++dfs_clock;
    in_stk[x] = true; stk[++top] = x;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[x] = min(low[x], low[j]);
        }else if(in_stk[j]) low[x] = min(low[x], dfn[j]); 
    }
    if(low[x] == dfn[x]){
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
int h2[N];
void add2(int a, int b,int c){
    e[idx] = b, ne[idx] = h2[a], w[idx] = c, h2[a] = idx++;
}
char s[N][N];
int dp[N], deg[N];
int ans_a[N];
int ans_b[N];
int main(){
    memset(h,-1,sizeof h);
    memset(h2,-1,sizeof h);
    n = read(), m = read();
    //n a, n + 1 b
    For(i,1,n) scanf("%s", s[i] + 1);
    For(i,1,n)For(j,1,m){
        int a = i, b = n + j;
        if(s[i][j] == '>') add(b,a,1);
        else if(s[i][j] == '=') add(a,b,0), add(b,a,0);
        else add(a,b,1);
    }
    For(i,1,n+m) if(!dfn[i]) tarjan(i);
    bool ok = true;
    For(i,1,n)For(j,1,m){
        int a = i, b = n + j;
        a = id[a], b = id[b];
        if(a == b){
            ok &= (s[i][j] == '=');
        }else {
            if(s[i][j] == '<') add2(a, b, 1), deg[b]++;
            else if(s[i][j] == '>')add2(b, a, 1), deg[a]++;
            else {
                if(a < b) swap(a, b);
                deg[b]++;
                add2(a,b,0);
            }
        }
    }
    //memset(dp,0x3f,sizeof dp);
    dp[scc_cnt] = 1;
    for(int k = scc_cnt; k >= 1; k -- ){
        if(deg[k] == 0) dp[k] = 1;
        for(int i = h2[k]; ~i; i = ne[i]){
            int j = e[i], val = w[i];
            dp[j] = max(dp[j], dp[k] + val);
        }
    }
    For(i,1,n+m){
        if(i <= n) ans_a[i] = dp[id[i]];
        else ans_b[i - n] = dp[id[i]];
    }
    if(ok){
        puts("Yes");
        For(i,1,n) print(ans_a[i], " \n"[i == n]);
        For(i,1,m) print(ans_b[i], " \n"[i == m]);
    }else puts("No");
    return 0;
}