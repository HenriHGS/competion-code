#include <cstdio>
#include <cstring>
#include <queue>
#define mst(x,a) memset(x,a,sizeof x)
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long LL;
typedef long long ll;
const int N = 4e5+10;
ll dist[N], mi[N], mx[N];
int e[N], w[N], ne[N], idx, h[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
struct node{
    int x;
    ll dis;
    bool operator < (const node&x)const{
        return dis>x.dis;
    }
};
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    For(i,1,m){
        int a, b, c;
        scanf("%d%d%d", &a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    auto dij = [&](int st){
        priority_queue<node> que;
        que.push({st,0});
        mst(dist,0x3f);
        dist[0] = 0;
        mx[0] = mi[0] = 0;
        while(!que.empty()){
            auto nod = que.top(); que.pop();
            int x = nod.x;
            ll dis = nod.dis;
            if(dis > dist[x]) continue;
            for(int i = h[x]; ~i; i = ne[i]){
                int v = e[i];
                if(dist[v] > dist[x] )
            }
        }
    }
    return 0;
}