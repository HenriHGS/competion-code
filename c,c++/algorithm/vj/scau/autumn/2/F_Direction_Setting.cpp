#include <cstdio>
#include <cstring>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <assert.h>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
#define sz(a) (int)a.size()
#define mst(x,a) memset(x,a,sizeof x)
using namespace std;
const int N = 610, M = 2*(301 + 310*2 + 301*2);

namespace atcoder{

    template<class Cap, class Cost> struct mcf_graph{
    public:
        mcf_graph() {}
        mcf_graph(int n): _n(n), g(n){};

        int add_edge(int from, int to, Cap cap, Cost cost){
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            int m = sz(pos);
            pos.pb({from, sz(g[from])});
            int from_id = sz(g[from]);
            int to_id = sz(g[to]);
            if(from == to) to_id++;
            g[from].pb(_edge{ to, to_id, cap, cost});
            g[to].pb(_edge{from, from_id, 0, -cost});
            return m;
        }

        struct edge{
            int from, to;
            Cap cap, flow;
            Cost cost;
        };
        int print(int i){
            int m = sz(pos);
            if(0 <= i && i <= m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            int have = _re.cap;
            if(have == 0) return 0;
            else return 1;
        }
        edge get_edge(int i){
            int m = sz(pos);
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{
                pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.csot
            };
        }
        std::vector<edge> edges(){
            int m = sz(pos);
            std::vector<edge> result(m);
            for(int i = 0; i < m; i ++ ){
                result[i] = get_edge[i];
            }
            return result;
        }
        std::pair<Cap,Cost> flow(int s, int t){
            return flow(s,t, std::numeric_limits<Cap>::max());
        }
        std::pair<Cap,Cost> flow(int s, int t, Cap flow_limit){
            return slope(s,t,flow_limit).back();
        }
        std::vector<std::pair<Cap,Cost>> slope(int s,int t){
            return slope(s,t,std::numeric_limits<Cap>::max());
        }
         std::vector<std::pair<Cap,Cost>> slope(int s,int t, Cap flow_limit){
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            assert(s!= t);
            std::vector<Cost> dual(_n,0), dist(_n);
            std::vector<int> pv(_n), pe(_n);
            std::vector<int> vis(_n);
            auto dual_ref = [&](){
                std::fill(dist.begin(),dist.end(),
                    std::numeric_limits<Cost>::max());
                std::fill(pv.begin(), pv.end(),-1);
                std::fill(pe.begin(), pe.end(),-1);
                std::fill(vis.begin(), vis.end(),false);
                struct Q{
                    Cost key;
                    int to;
                    bool operator < (const Q& r) const {return key > r.key;}
                };
                std::priority_queue<Q>que;
                dist[s] = 0;
                que.push(Q{0,s});
                while(!que.empty()){
                    int v = que.top().to;
                    que.pop();
                    if(vis[v]) continue;
                    vis[v] = true;
                    if(v == t) break;
                    for(int i = 0; i < sz(g[v]); i ++ ){
                        auto e = g[v][i];
                        if(vis[e.to] || !e.cap) continue;
                        Cost cost = e.cost - dual[e.to] + dual[v];
                        if(dist[e.to] - dist[v] > cost){
                            dist[e.to] = dist[v] + cost;
                            pv[e.to] = v;
                            pe[e.to] = i;
                            que.push(Q{dist[e.to], e.to});
                        }
                    }
                }
                if(!vis[t]) return false;
                for(int v = 0; v < _n; v++){
                    if(!vis[v]) continue;
                    dual[v] -= dist[t] - dist[v];
                }
                return true;
            };
            Cap flow = 0;
            Cost cost = 0, prev_cost_per_flow = -1;
            std::vector<std::pair<Cap,Cost>> result;
            result.pb({flow,cost});
            while(flow < flow_limit){
                if(!dual_ref()) break;
                Cap c = flow_limit - flow;
                for(int v = t; v!=s; v = pv[v]){
                    c = std::min(c,g[pv[v]][pe[v]].cap);
                }
                for(int v = t; v != s; v = pv[v]){
                    auto& e = g[pv[v]][pe[v]];
                    e.cap -= c;
                    g[v][e.rev].cap += c;
                }
                Cost d = -dual[s];
                flow += c;
                cost += c*d;
                if(prev_cost_per_flow == d){
                    result.pop_back();
                }
                result.pb({flow,cost});
                prev_cost_per_flow = d;
            }
            return result;
        }
    private:
        int _n;

        struct _edge{
            int to, rev;
            Cap cap;
            Cost cost;
        };
        std::vector<std::pair<int,int>> pos;
        std::vector<std::vector<_edge>> g;
    };
};
using namespace atcoder;
const int INF = 1e9+10;
int a[N];
void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    mcf_graph<int,int> mc(n+m+10);
    int S = 0, T = n + m + 1;
    For(i,1,n){
        int w; scanf("%d", &w);
        mc.add_edge(i,T,w,0);
        mc.add_edge(i,T,INF,1);
    }
    For(i,1,m){
        int a, b; scanf("%d %d", &a, &b);
        mc.add_edge(S, n + i, 1, 0);
        mc.add_edge(n+i, a, 1, 0);
        mc.add_edge(n+i, b, 1, 0);
    }
    printf("%d\n",mc.flow(S,T).second);
    int st = 2*n;
    fori(i,0,m){
       // int have1 = mc.get_edge(i+1<<1).cap;
        printf("%d",mc.print(st + (i*3+1)));
    }
    puts("");
}

int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--) solve();
    return 0;
}