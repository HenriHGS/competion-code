#include <cstdio>
#include <cstring>
using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
const int N = 1e4+10;
int vis[N];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    For(i,1,m){
        int x;
        scanf("%d", &x); vis[x]++;
    }
    if(n == m){
        puts("*");
        return 0;
    }
    For(i,1,n)if(!vis[i]) printf("%d ", i);
    return 0;
}