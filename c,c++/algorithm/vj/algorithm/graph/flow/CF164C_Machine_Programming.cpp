#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <assert.h>
#define debug(a) cout<<#a<<":"<<a<<endl;
#define rep(i,a,b) for(int i = (a); i <= (b); i ++ )
#define per(i,a,b) for(int i = (a); i >= (b); i -- )
#define forr(i,a) for(auto i:a)
#define rall(a) rbegin(a), rend(a)
#define all(a) begin(a),end(a)
#define pb emplace_back
using namespace std;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x / 10);
    putchar(x%10+'0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
const long long INF = 1e18;
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
                    INF);
                std::fill(pv.begin(), pv.end(), -1);
                std::fill(pe.begin(), pe.end(), -1);
                std::fill(vis.begin(), vis.end(), false);
                struct Q {
                    Cost key;
                    int to;
                    bool operator < (Q r) const{
                        if(key == r.key) return to > r.to;
                        return key > r.key;
                    }
                };
                std::priority_queue<Q> que;
                dist[s] = 0;
                que.push(Q{ 0, s });
                while (!que.empty()) {
                    int v = que.top().to;
                    Cost d = que.top().key;
                    que.pop();
                    if(dist[v] < d) continue;//if (vis[v]) continue;
                    vis[v] = true;
                  //  if (v == t) break;
                    //破案了，是这一句！！！！！！！！！！！！！！！！！！！！
                    for (int i = 0; i < int(g[v].size()); i++) {
                        auto e = g[v][i];
                        if (!e.cap) continue;
                        Cost cost = e.cost - dual[e.to] + dual[v];
                      //  cout<<e.to<<" "<<dist[e.to]<<" "<<dist[v]<<" "<<cost<<endl;
                        if (dist[e.to]  - cost > d) {
                            dist[e.to] = dist[v] + cost;
                            pv[e.to] = v;
                            pe[e.to] = i;
                            que.push(Q{ dist[e.to], e.to });
                        }
                    }
                }
                if (dist[t] == INF) {
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
               // debug(d);
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
typedef long long ll;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int N = 2200;
mcf_graph<ll,ll> mc(N);

int tot;
int n, S, T, k;
vector<int> time;
int t1[N], t2[N], w[N];
int main(){
    tot = read(), k = read();
// cout<<tot<<' '<<k<<endl;
    For(i,1,tot){
        t1[i] = read(), t2[i] = read(), w[i] = read();
        t2[i] = t1[i] + t2[i];
        time.push_back(t1[i]); time.push_back(t2[i]);
    }
    sort(all(time));
    time.erase(unique(all(time)), time.end());
    n = time.size();
    S = 0, T = n + 1;
   // debug(T);
    For(i,1,tot){
        int a = lower_bound(all(time), t1[i]) - time.begin() + 1;
        int b = lower_bound(all(time), t2[i]) - time.begin() + 1;
        if(b == 10){
          //  cout<<t1[i]<<' '<<t2[i]<<"  wawa!!!"<<endl;
        }
        mc.add_edge(a,b,1,-w[i]);
    }
    mc.add_edge(S,1,k,0);
    For(i,2,n) mc.add_edge(i-1,i,k,0);
    mc.add_edge(n,T,k,0);
    pair<ll,ll> ans = mc.flow(S,T);
    //print(ans.first,'\n');
   // print(ans.second,'\n');
    fori(i,0,tot){
        if(mc.get_edge(i).cap == mc.get_edge(i).flow) print(1," \n"[i==tot-1]);
        else  print(0," \n"[i==tot-1]);
    }
    return 0;
}
