#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i <= (y); i ++ )
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef pair<int,int>PII;
const int N = 210, M = N*N;
int match[N];
//int g[N][N];
int e[M], ne[M], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
PII p[N];
int g[N][N];
int n, m, k;
bool st[N];
bool find(int x){
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]) {
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    memset(h, -1, sizeof h);
    scanf("%d %d %d", &n, &m, &k);
    For(i,1,k){
        int x, y; scanf("%d %d", &x, &y);
        g[x][y] = 1;
    }
    For(i,1,n)For(j,1,m){
        if(!g[i][j]) add(i,j);
    }
    int mx = 0;
    For(i,1,n){
        memset(st,0,sizeof st);
        if(find(i)) mx++;
    }
    printf("%d\n", mx);
    return 0;
}