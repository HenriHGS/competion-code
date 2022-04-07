#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <numeric>
#include <cctype>
#include <climits>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define rep(i,a,b) for(int i = (a); i <= (b); i ++ )
#define forr(i,a) for(auto i: a)
#define rall(a) rbegin(a), rend(a)
#define all(a) begin(a), end(a)
#define pb emplace_back
const int N = 620;
using namespace std;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x: x;
}
namespace atcoder{
    template<class Cap, class Cost> struct mcf_graph{
    public: 
        mcf_graph() {}
        mcf_graph(int n): _n(n), g(n){}

        int add_edge(int a, int b, Cap c, Cost d){
            assert(a >= 0 && a < _n);
            assert(b >= 0 && b < _n);
            int m = int(pos.size());
            pos.push_back({a,int(g[a].size())});
            int from_id = int(g[a].size());
            int to_id = int(g[b].size());
            if(a == b) to_id++;
            g[a].push_back(_edge{b, to_id, c, d});
            g[b].push_back(_edge{a, from_id, 0, - d});
            return m;
        } 
        struct edge{
            int from, to;
            Cap cap, flow;
            Cost cost;
        };

        edge get_edge(int i){
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{
                pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cot
            };
        }
        std::vector<edge> edges(){
            int m = int(pos.size());
            std::vector<edge> result(m);
            for(int i = 0; i < m; i ++ ){
                result[i] = get_edge(i);
            }
            return result;
        }

        std::pair<Cap, Cost> flow(int s, int t){
            return flow(s,t,std::numeric_limits<Cap>::max());
        }
        std::pair<Cap,Cost> flow(int s, int t, Cap flow_limit){
            return slope(s,t,flow_limit).back();
        }
        std::vector<std::pair<Cap,Cost>> slope(int s, int t){
            return slope(s,t,std::numeric_limits<Cap>::max());
        }
        std::vector<std::pair<Cap,Cost>> slope(int s, int t, Cap flow_limit){
            assert(0 <= s && s < _n);
            assert(0 <= t && t < _n);
            assert(s != t);
            std::vector<Cost> dual(_n,0), dist(_n);
            std::vector<int> pv(_n), pe(_n);
            std::vector<bool> vis(_n);
            auto dual_ref = [&](){
                std::fill(dist.begin(), dist.end(), 
                    std::numeric_limits<Cost>::max());
                std::fill(pv.begin(), pv.end(), -1);
                std::fill(pe.begin(), pe.end(), -1);
                std::fill(vis.begin(), vis.end(), 0);
                struct Q{
                    Cost key;
                    int to;
                    bool operator < (Q r) const{
                        return key > r.key;
                    }
                };
                std::priority_queue<Q> que;
                dist[s] = 0;
                que.push(Q{0,s});
                while(!que.empty()){
                    int v = que.top().to;
                    que.pop();
                    if(vis[v]) continue;
                    vis[v] = true;
                    if(v == t) break;
                    for(int i = 0; i < int(g[v].size()); i ++ ){
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
                for(int v = 0; v < _n; v ++ ){
                    if(!vis[v]) continue;
                    dual[v] -= dist[t] - dist[v];
                }
                return true;
            };
            Cap flow = 0;
            Cost cost = 0, prev_cost_per_flow = -1;
            std::vector<std::pair<Cap,Cost>> result;
            result.push_back({flow, cost});
            while(flow < flow_limit){
                if(!dual_ref()) break;
                Cap c = flow_limit - flow;
                for(int v = t; v != s; v = pv[v]){
                    c = std::min(c, g[pv[v]][pe[v]].cap);
                }
                for(int v=  t; v != s; v = pv[v]){
                    auto &e = g[pv[v]][pe[v]];
                    e.cap -= c;
                    g[v][e.rev].cap += c;
                }
                Cost d = -dual[s];
                flow += c;
                cost += c*d;
                if(prev_cost_per_flow == d){
                    result.pop_back();
                }
                result.push_back({flow,cost});
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
}
using namespace atcoder;
mcf_graph<int,int> mc(N);
const int INF = numeric_limits<int>::max() / 1000;
int n, m;
char type[N][N];
int a[N], b[N];
int c[N];
int S, T;
int main(){
    n = read(), m = read();
    For(i,1,n) scanf("%s %d", type[i], a + i);
    int sum = 0;
    For(i,1,m) b[i] = read(), sum += b[i];

    S = 0, T = n + m + 1;
    For(i,1,m) mc.add_edge(S,i+n,1,0);
    For(i,1,n) mc.add_edge(i,T,1,0);
    For(i,1,m)For(j,1,n){
        if(type[j][0] == 'A' ){
            if(b[i] >= a[j]) mc.add_edge(n + i, j, 1, a[j]);
            else mc.add_edge(i+n,j,1,INF);
        }else {
            if(b[i] > a[j]) mc.add_edge(n+i,j,1,b[i]);
            else mc.add_edge(i+n,j,1,INF);
        }
    }
    int ans1 = sum - mc.flow(S,T).second;

    int ans2 = 0;
    For(i,1,n){
        if(type[i][0] == 'A') c[++*c] = a[i];
    }
    sort(b+1,b+1+m, greater<int>());
    sort(c + 1, c + 1 + *c);
    For(i,1,min(m,*c)) ans2 += max(0, b[i] - c[i]);
    printf("%d\n", max(ans1,ans2));
    return 0;
}