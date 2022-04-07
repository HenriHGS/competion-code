#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#define X first
#define Y second
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
using namespace std;
typedef long long LL;
typedef long long ll;
const int N = 1e5+10;
typedef pair<int,int>point;
map<int,int> ma;
vector<point> home;
point p[N];
int fa[N];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int n, m, k, idx;
int vis[N];
vector<point> S[N];
void init(){
    ma.clear(); home.clear();
    For(i,1,k){
        vis[i] = 0;
        fa[i] = i;
        S[i].clear();
    }
    idx = 0;
}
const int dx[]={-1,0,-1};
const int dy[]={1,1,0};
void sol(){
    scanf("%d%d%d", &n, &m, &k);
    init();
    LL ans = n*m;
    For(i,1,k){
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = mp(x,y);
        ma[p[i]] = idx++;
        home.pb(p[i]);
    }
    For(i,1,k){
        if(vis[i]) continue;
      //  queue<point> que;
      //  que.push({p[i].X, p[i].Y});
     //   while(!que.empty()){
           // auto po = que.front();
         //   que.pop();
            int x = p[i].X, y = p[i].Y;
            int ind1 = ma[p[i]];
          //  if(vis[id]) continue;
            fori(k,0,3){
                int xx = x + dx[k];
                int yy = y + dy[k];
                auto pv = mp(xx,yy);
                if(!ma.count(pv)) continue;
                int ind2 = ma[pv];
                int f_ind1 = find(ind1);
                int f_ind2 = find(ind2);
                if(f_ind1 == f_ind2)continue;
                f[_ind2] = f[_ind2];
            }
     //   }
    }
    For(i,1,k) find(i);
    For(i,1,k){
        int anc = find(i);
        S[anc].pb(home[i - 1]);
    }
    For(i,1,k)sort(S[i].begin(),S[i].end(), [&](point a, point b){
        if(a.x == b.x) return a.y<b.y;
        return a.x>b.x;
    });
    For(i,1,k){
        ans -= S[i].size();
        if(S[i].size == 0) continue;
        for(auto po: S[i]){
            int xx = po.X - 1;
            int 
        }
    }
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}