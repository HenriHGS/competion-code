// 真っ白に透けた　羽根を閉じたまま
// AC自动机Fail树上DFS序建可持久化线段树
// 后缀自动机Next指针DAG图上求SG函数
#include <cstdio>
#include <cstring>
#include <numeric>
#include <queue>
#include <cmath>
#include <cassert>
#include <limits>
#include <iostream>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define forr(i,a) for(auto i:a)
#define rall(a) rbegin(a),rend(a)
#define all(a) begin(a),end(a)
#define pb emplace_back
using namespace std;
const int N = 620;
struct read
{
    static const int M = 1 << 21;
    char buf[M], * S = buf, * P = buf, c, l;
    inline int gc() { return (S == P && (P = (S = buf) + fread(buf, 1, 1 << 21, stdin), S == P) ? EOF : *S++); }
    template<typename T> read& operator>>(T& x)
    {
        for (c = 0;!isdigit(c);c = gc()) l = c;
        for (x = 0;isdigit(c);c = gc()) x = (x << 1) + (x << 3) + (c ^ 48);
        return x = (l ^ 45) ? x : -x, *this;
    }
}fin;
#define cin fin
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
            auto dual_ref = [&]() {
                std::fill(dist.begin(), dist.end(),
                    std::numeric_limits<Cost>::max());
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
                    vis[v] = true;
                    if (v == t) break;
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
                    return false;
                }
 
                for (int v = 0; v < _n; v++) {
                    if (!vis[v]) continue;
                    dual[v] -= dist[t] - dist[v];
                }
                return true;
            };
            Cap flow = 0;
            Cost cost = 0, prev_cost_per_flow = -1;
            std::vector<std::pair<Cap, Cost>> result;
            result.push_back({ flow, cost });
            while (flow < flow_limit) {
                if (!dual_ref()) break;
                Cap c = flow_limit - flow;
                for (int v = t; v != s; v = pv[v]) {
                    c = std::min(c, g[pv[v]][pe[v]].cap);
                }
                for (int v = t; v != s; v = pv[v]) {
                    auto& e = g[pv[v]][pe[v]];
                    e.cap -= c;
                    g[v][e.rev].cap += c;
                }
                Cost d = -dual[s];
                flow += c;
                cost += c * d;
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
mcf_graph<int, int> mc(N);
struct T { int x, y, z, v; };
#define int long long
signed main()
{
    cout.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    /* vector<T> a(n);for (auto& [x, y, z, v] : a) cin >> x >> y >> z >> v;
    int source = 0, sink = 2 * n + 1;
    rep(i, 1, n) mc.add_edge(source, i, 1, 0);
    rep(i, 1, n) mc.add_edge(n + i, sink, 1, 0);
    rep(i, 1, n) rep(j, n + 1, 2 * n)
    {
        int p = j - n - 1;
        auto [x, y, z, v] = a[p];
        mc.add_edge(i, j, 1, x * x + y * y + (z + (i - 1) * v) * (z + (i - 1) * v));
    }
    auto [cost, flow] = mc.flow(source, sink); */
    //return cout << flow, 0;
}