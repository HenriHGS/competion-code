#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int N = 270;
bool g[N][N];
int path[N];
int n, b, d;
int h[N], e[N], ne[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void build(){
    fori(i,0,1<<b)fori(j,i,1<<b){
        if( __builtin_popcount(i^j) >= d){
            g[i][j] = g[j][i];
            add(i,j);
        }
    }
}
bool dfs(int x, int start){
    if(x == n){
        fori(i,0,n){
            printf("%d",path[i]);
            if((i+1)%10 == 0)puts("");
            else printf(" ");
        }
        return true;
    }
    fori(i,start,1<<b){
        bool ok = true;
        fori(j,0,x) ok &= __builtin_popcount(i^path[j]) >= d;
        if(ok){
            path[x] = i;
            if(dfs(x+1,i)) return true;
        }
    }
    return false;
}
int main(){
    memset(h,-1,sizeof h);
    //cout<<__builtin_ctz(2);
    scanf("%d%d%d", &n, &b, &d);
    build();
    dfs(0,0);
    return 0;
}