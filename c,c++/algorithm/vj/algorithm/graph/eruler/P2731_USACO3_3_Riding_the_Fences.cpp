#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 501;
int g[N][N];
int m;
int du[N];
int ans[N*N], cnt;
void dfs(int x){
    fori(i,1,N){
        if(g[x][i]){
            g[x][i]--;
            g[i][x]--;
            dfs(i);
        }
    }
    ans[++cnt] = x;
}
int main(){
    scanf("%d", &m);
    For(i,1,m){
        int a, b;
        scanf("%d %d", &a, &b);
        du[a]++, du[b]++;
        g[a][b]++, g[b][a]++;
    }
    bool success = true;
    int start = 1;
    fori(i,1,N){
        if(du[i] & 1){
            start = i;
            break;
        }
    }
    dfs(start);
    for(int i = m+1; i ; i -- )printf("%d\n",ans[i]);
    return 0;
}