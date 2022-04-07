#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define mp make_pair
#define X first
#define Y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int N  = 5e3+10;

typedef long long ll;
typedef pair<ll,ll>pa;//<vector>
pa p[N];

struct Edge{
    ll w;
    int a, b;
    bool operator<(const Edge& x)const{
        return w<x.w;
    }
}e[N*N];
int idx = 0;
int fa[N];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        idx = 0;
        int n;
        scanf("%d", &n);
        For(i,1,n) fa[i] = i;
        For(i,1,n){
            int x, y;
            scanf("%d%d",&x,&y);
            p[i] = {x,y};
        }
        ll ans = 0;
        For(i,1,n)For(j,i,n){
            if(p[i] == p[j])continue;
            ll dis = (p[i].X - p[j].X)*(p[i].X - p[j].X) + (p[i].Y - p[j].Y)*(p[i].Y - p[j].Y);
            //ans = max(ans,dis*4);
            e[idx++] = {dis,i,j};
        }
        sort(e,e+idx);
        int cnt = 1;
        //printf("debug: %d\n", idx);
        fori(i,0,idx){
            if(cnt == n) break;
            int a, b;
            a = e[i].a, b = e[i].b;
           // printf("debug: %d\n", e[i].w);
            a = find(a), b = find(b);
            if(a == b) continue;
            //ans += e[idx].w;
            
            fa[a] = b;
            cnt ++;
            ans = e[i].w;
        }
        printf("%lld\n", ans);
    }
    return 0;
}