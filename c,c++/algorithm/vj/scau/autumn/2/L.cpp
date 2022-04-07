#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i  ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define mst(x,a) memset(x,a,sizeof x)
using namespace std;
const int N = 1e5+10, M = 2*N;
bool st[N];
int q[N];
int n, m, qq;
int e[M], ne[M], h[N], idx;
int dist[N][110];
int w[N];
vector<int> wp[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], h[b] = idx++;
}
void init(){
    mst(h,-1);
    mst(dist,0x3f);
    scanf("%d %d %d", &n, &m, &qq);
    For(i,1,n) {
        scanf("%d", w + i);
        wp[w[i]].pb(i);
    }
    For(i,1,m){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b);
    }
    For(ww,1,100){
        For(i,1,n) st[i] = false;
        int hh = 0, tt =  0;
        fori(i,0,wp[ww].size()){
            int a = wp[ww][i];
            dist[a][ww] = 0;
            q[tt++] = a;
        }
        while(hh != tt){
            int t = q[hh++];
            if(hh == N) hh = 0;
            for(int i = h[t]; ~i; i = ne[i]){
                int j = e[i];
                if(dist[j][ww] > dist[t][ww] + 1){
                    dist[j][ww] = dist[t][ww] + 1;
                    if(!st[j]){
                        q[tt++] = j;
                        if(tt == N) tt = 0;
                    }
                }
            }
        }
    }
}
const int INF = 0x3f3f3f3f;
void solve(){
    while(qq--){
        int p, x;
        scanf("%d %d", &p,&x);
        int ans = INF;
        For(i,1,x){
            ans = min(dist[p][i],ans);
        }
        //printf("ans = ");
        if(ans == INF) printf("-1\n");
        else printf("%d\n", ans);
    }
}
int main(){
    init();
    solve();
    return 0;
}