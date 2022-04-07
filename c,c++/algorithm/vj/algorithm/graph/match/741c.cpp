#include <vector>
#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 2e5+10, M = 1e5*4;
int e[M], ne[M], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}
int color[N];
void dfs(int x, int c, int fa){
    color[x] = c;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        if(!color[j]) dfs(j,3-c,x);
    }
}
void sol(){
    int n;
    memset(h,-1,sizeof h);
    scanf("%d", &n);
    For(i,1,n){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b);
    }
    For(i,1,n)add(2*i-1,2*i);
    For(i,1,n*2){
        if(!color[i]) dfs(i,1,-1);
    }
    for(int i = 0; i < 2*n; i+=2 ){
        int a = e[i^1], b = e[i];
        printf("%d %d\n", color[a], color[b]);
    }
}
int main(){
    sol();
    return 0;
}