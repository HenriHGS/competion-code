#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i =  (x); i <= (y); i ++ )
using namespace std;
const int N = 110;
int fa[N], vis[N];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    For(i,1,n)fa[i] = i;
    For(i,1,m){
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if(a!=b) fa[a] = fa[b];
    }
    int cnt = 0;
    For(i,1,n){
        int anc = find(i);
        if(vis[anc])continue;
        cnt++;
        vis[ans] = 1;
    }
    if(cnt%2) puts("Alice");
    else puts("Bob");
    return  0;
}