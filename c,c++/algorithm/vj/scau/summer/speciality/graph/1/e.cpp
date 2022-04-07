#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int M = 1e5+10;
int fa[M];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
struct Edge{
    int u,v, w;
    bool operator < (const Edge& x)const{
        return w<x.w;
    }
}e[M];
int main(){
    int n, m;
    while(scanf("%d", &n) && n){
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++ ){
            int a, b, c;
            scanf("%d%d%d",&a,&b,&c);
            e[i] = (Edge){a,b,c};
        }
        int sum = 0;
        for(int i = 1; i <= n; i ++ ) fa[i] = i;
        sort(e+1,e+1+m);
        int cnt = 1;
        for(int i = 1; i <= m; i ++ ){
            int a = find(e[i].u), b = find(e[i].v);
            if(a == b) continue;
            fa[a] = b;
            cnt++;
            sum += e[i].w;
            if(cnt == n) break;
        }
        printf("%d\n", sum);
    }
    return 0;
}