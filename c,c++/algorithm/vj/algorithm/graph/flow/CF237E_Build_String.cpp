#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <assert.h>
#include <numeric>
#define pb emplace_back
#define rep(i,a,b) for(int i = (a); i <= (b); i ++ )
#define per(i,a,b) for(int i = (a); i >= (b); i -- )
#define forr(i,a) for(auto i:a)
#define rall(a) rbegin(a), rend(a)
#define all(a) begin(a), end(a)
using namespace std;
const int N = 300;

int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f?-x:x;
}
template<typename T> void print(T x){
    if(x < 0) putchar('-'), x = -x;
    if(x >= 10) print(x/10);
    putchar(x%10+'0');
}
template<typename T> void print(T x, char let){
    print(x), putchar(let);
}
typedef long long ll;
const ll INF = 1e18;
namespace atcoder{
    template<class Cap, class Cost> struct mcf_graph{
    public:
        mcf_graph(){}
        mcf_graph(int n): _n(n), g(n){}
        
        int add_edge(int from, int to, Cap cap, Cost cost){
            assert(0 <= from && from < _n);
            assert(0 <= to && to < _n);
            int m = int(pos.size());
            pos.push_back({from, int(g[from].size())});
            int from_id = int(g[from].size());
            int to_id = int(g[to].size());
            if(from == to) to_id++;
            g[from].push_back(_edge{to, to_id, cap, cost});
            g[to].push_back(_edge{from, from_id, 0, -cost});
            return m;
        }

        struct edge{
            int from, to;
            Cap cap, flow;
            Cost cost;
        };

        edge get_edge(int i ){
            int m = int(pos.size());
            assert(0 <= i && i < m);
            auto _e = g[pos[i].first][pos[i].second];
            auto _re = g[_e.to][_e.rev];
            return edge{
                pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost
            };
        }
        std::vector<edge> edges(){
            int m = int(pos.size());
            std::vector<edge> result(m);
            for(int i = 0; i < m ; i ++ ){
                result[i] = get_edge(i);
            }
            return result;
        }
        std::pair<Cap,Cost> flow(int s, int t){
            return flow(s,t, std::numeric_limits<Cap>::max());    
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
            std::vector<Cost> dual(_n, 0), dist(_n);
            std::vector<int> pv(_n), pe(_n);
            //std::vector<bool> vis(_n);
            auto dual_ref = [&](){
                std::fill(dist.begin(), dist.end(),
                INF);
                std::fill(pv.begin(),pv.end(),-1);
                std::fill(pe.begin(),pe.end(),-1);
                struct Q{
                    Cost key;
                    int to;
                    bool operator < (Q r) const {
                        return key > r.key;
                    } 
                };
                priority_queue<Q> que;
                que.push({0,s});
                dist[s] = 0;
                while(!que.empty()){
                    int u = que.top().to;
                    Cost d = que.top().key;
                    que.pop();
                    if(d > dist[u]) continue;
                    for(int i = 0; i < int(g[u].size()); i ++ ){
                        auto e = g[u][i];
                        if(!e.cap) continue;
                        Cost cost = e.cost - dual[e.to] + dual[u];
                        if(dist[e.to] - dist[u] > cost){
                            dist[e.to] = dist[u] + cost;
                            pv[e.to] = u;
                            pe[e.to] = i;
                            que.push(Q{dist[e.to], e.to});
                        }
                    }
                }
                if(dist[t] == INF) return false;
                for(int i = 0; i < _n; i ++ ){
                    if(dist[i] == INF) continue;
                    dual[i] -= dist[t] - dist[i];
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
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
mcf_graph<ll,ll> mc(N);
char s[N];
int a[N];
int k[N];
char t[N];
int n, S, T;

int main(){
    scanf("%s", t + 1);
    int ans[26]{};
    int len = strlen(t+1);
    For(i,1,len){
        ans[t[i] - 'a']++;
    }
    n = read();
    S = 0, T = n + 26 + 1;
    For(i,1,n){
        scanf("%s", s + 1);
        k[i] = read();
        int cnt[26]{};
        int len = strlen(s+1);
        For(j,1,len){
            char ch = s[j];
            cnt[ch - 'a']++;
        }
        mc.add_edge(S,i,k[i],0);
        fori(j,0,26) if(cnt[j])mc.add_edge(i,n+j+1,cnt[j],i);
    }
    fori(j,0,26)mc.add_edge(n+j+1,T,ans[j],0);
    auto res = mc.flow(S,T);
  //  print(mc.get_edge(1).flow,'\n');
   // print(mc.get_edge(2).flow,'\n');
   // print(mc.get_edge(4).flow,'\n');
   // print(mc.get_edge(4).flow,'\n');
    //print(res.first,'\n');
    if(res.first == len)print(res.second);
    else print(-1);
    return 0;
}