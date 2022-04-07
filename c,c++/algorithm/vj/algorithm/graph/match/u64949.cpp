#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 110;
int g[N][N];
int id[N][N], ban[N][N], cnt;
int n, m;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int match[N*N];
bool st[N*N];

typedef pair<int,int>PII;
PII p[N*N];
bool find(int u){
    int x = p[u].x, y = p[u].y; 
    fori(k,0,4){
        int tx = x + dx[k];
        int ty = y + dy[k];
        if(ban[tx][ty]) continue;
        //int u = id[x][y];
        int v = id[tx][ty];
        if(!st[v]){
            st[v] = true;
            if(!match[v] || find(match[v])){
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d", &n, &m);
    For(i,0,n+1) ban[i][0] = ban[i][n+1] = ban[0][i] = ban[n+1][i] = 1;
    For(i,1,m){
        int x, y;
        scanf("%d %d", &x, &y);
        ban[x][y] = 1;
    }
    For(i,1,n)For(j,1,n){
        if(ban[i][j]) continue;
        id[i][j] = ++cnt;
        p[cnt] = {i,j};
    }
    int mx = 0;
    For(i,1,n)For(j,1,n){
        int c = (i+j)&1;
        if(c || ban[i][j]) continue;
        memset(st,0,sizeof st);
        if(find(id[i][j])) mx++;
    }
    printf("%d\n", mx);
    return 0;
}