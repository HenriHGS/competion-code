#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <assert.h>
#include <numeric>
#include <vector>
#include <queue>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 100+10, M = 2*N*N*2;
typedef long long ll;

#include <cctype>
template<typename T> void read(T& x){
    char ch = getchar(); int f = 0;x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    if(f) x = -x;
    //return f ? -x : x;
}
int n, k;
namespace atcoder {
 
    template <class Cap, class Cost> struct mcf_graph {
    public:
        mcf_graph() {}
        mcf_graph(int n) : _n(n), g(n) {}
 
        int add_edge(int from, int to, Cap cap, Cost cost) {
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            int m = int(pos.size());
            pos.push_back({ from, int(g[from].size()) });
            int from_id = int(g[from].size());
            int to_id = int(g[to].size());
            if (from == to) to_id++;
            g[from].push_back(_edge{ to, to_id, cap, cost });
            g[to].push_back(_edge{ from, from_id, 0, -cost });
            return m;
        }
 
        struct edge {
            int from, to;
            Cap cap, flow;
            Cost cost;
        };
 
        edge get_edge(int i) {
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{
                pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
            };
        }
        std::vector<edge> edges() {
            int m = int(pos.size());
            std::vector<edge> result(m);
            for (int i = 0; i < m; i++) {
                result[i] = get_edge(i);
            }
            return result;
        }
 
        std::pair<Cap, Cost> flow(int s, int t) {
            return flow(s, t, std::numeric_limits<Cap>::max());
        }
        std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
            return slope(s, t, flow_limit).back();
        }
        std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
            return slope(s, t, std::numeric_limits<Cap>::max());
        }
        std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            assert(s != t);
            std::vector<Cost> dual(_n, 0), dist(_n);
            std::vector<int> pv(_n), pe(_n);
            std::vector<bool> vis(_n);
            auto dual_ref = [&](Cost cost) {
                std::fill(dist.begin(), dist.end(),
                    std::numeric_limits<Cost>::max());
                //这里条件变成INF！！！！！！！！！！！！！！！！！！！！！
                std::fill(pv.begin(), pv.end(), -1);
                std::fill(pe.begin(), pe.end(), -1);
                std::fill(vis.begin(), vis.end(), false);
                struct Q {
                    Cost key;
                    int to;
                    bool operator<(Q r) const { return key > r.key; }
                };
                std::priority_queue<Q> que;
                dist[s] = 0;
                que.push(Q{ 0, s });
                while (!que.empty()) {
                    int v = que.top().to;
                    que.pop();
                    if (vis[v]) continue;
                    vis[v] = true;//不加这一句！！！！！！！！！！！！时
                  //  if (v == t) break;
                    //破案了，是这一句！！！！！！！！！！！！！！！！！！！！
                    for (int i = 0; i < int(g[v].size()); i++) {
                        auto e = g[v][i];
                        if (vis[e.to] || !e.cap) continue;
                        Cost cost = e.cost - dual[e.to] + dual[v];
                        if (dist[e.to] - dist[v] > cost) {
                            dist[e.to] = dist[v] + cost;
                            pv[e.to] = v;
                            pe[e.to] = i;
                            que.push(Q{ dist[e.to], e.to });
                        }
                    }
                }
                if (!vis[t]) {
                    //这里条件变成 dist[t] == INF!!!!!!!!!!
                    return false;
                }
                for (int v = 0; v < _n; v++) {
                    if (!vis[v]) continue;
                    dual[v] -= dist[t] - dist[v];
                }
                return cost + (-dual[s]) <= k;
            };
            Cap flow = 0;
            Cost cost = 0, prev_cost_per_flow = -1;
            std::vector<std::pair<Cap, Cost>> result;
            result.push_back({ flow, cost });
            while (flow < flow_limit) {
                if (!dual_ref(cost)) break;
                Cap c = flow_limit - flow;
                for (int v = t; v != s; v = pv[v]) {
                    c = std::min(c, g[pv[v]][pe[v]].cap);
                }
                Cost d = -dual[s];
                if(cost + d*c > k){ 
                    c = (k - cost)/d;
                    cost += c * d;
                    flow += c;
                    result.push_back({ flow, cost });
                  //  break;
                }else {
                    flow += c;
                    cost += c * d;
                }
                for (int v = t; v != s; v = pv[v]) {
                    auto& e = g[pv[v]][pe[v]];
                    e.cap -= c;
                    g[v][e.rev].cap += c;
                }
                if (prev_cost_per_flow == d) {
                    result.pop_back();
                }
                result.push_back({ flow, cost });
                prev_cost_per_flow = d;
            }
            return result;
        }
 
    private:
        int _n;
 
        struct _edge {
            int to, rev;
            Cap cap;
            Cost cost;
        };
 
        std::vector<std::pair<int, int>> pos;
        std::vector<std::vector<_edge>> g;
    };
 
}
using namespace atcoder;
mcf_graph<ll,ll> mc(N);
int S, T;
int g[N][N];
int main(){
    read(n), read(k);
    For(i,1,n)For(j,1,n){
        int x; read(x);
        g[i][j] = x;
        if(i == j) continue;
        if(x) mc.add_edge(i,j,x,0);
    }
    S = 1, T = n;
    ll ans = mc.flow(S,T).first;
   // printf("%lld\n", ans);
    For(i,1,n)For(j,1,n){
        if(g[i][j]) mc.add_edge(i,j,k,1);
    }
    ans += mc.flow(S,T).first;
    printf("%lld\n", ans);
    return 0;
}