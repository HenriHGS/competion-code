#include <iostream>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>
#include <assert.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define forr(i,a) for(auto i:a)
#define rall(a) rbegin(a),rend(a)
#define all(a) begin(a),end(a)
#define pb emplace_back
using namespace std;
const int N = 80*80 + 4;
typedef long long ll;
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
const int maxn = 100;
int a[maxn][maxn], id[maxn][maxn];
int S, T;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x){
    if(x < 0) x = -x, putchar('-');
    if(x >= 10) print(x/10);
    putchar(x%10 + '0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
int main()
{
  //  cout.tie(0)->sync_with_stdio(0);
    int n, m; 
    n = read(), m = read();//cin>>n>>m;
    int idx = 0;
    For(i,1,n)For(j,1,m) {
        //cin>>a[i][j], 
        a[i][j] = read();
        id[i][j] = ++idx;
    }
    T = n*m + 1;
    For(i,1,n)For(j,1,m){
       
        int u = id[i][j];
        if(i+j&1){
            fori(k,0,4){
                int tx = i + dx[k];
                int ty = j + dy[k];
                if(a[tx][ty]){
                    int v = id[tx][ty];
                    mc.add_edge(u,v,1, a[tx][ty] != a[i][j]);
                }
            }
            mc.add_edge(S,u,1,0);
        }else mc.add_edge(u,T,1,0);
    }
    print(mc.flow(S,T).second);//printf("%lld\n", mc.flow(S,T).second);
    return 0;
}