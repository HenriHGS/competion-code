#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n' 
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 100000 + 6;
map<pa,int> vis, have;
struct Seg{
    int x, l, r;
};
int n;
int tot = 0;
vector<Seg>seg;
pa st, ed;
int st_id, ed_id;
vector<int>e[maxn];
int dx[]={1,-1,0,0,-1,-1,1,1};
int dy[]={0,0,1,-1,-1,1,-1,1};
void link(){
    fori(i,0,n){
        For(y,seg[i].l,seg[i].r){
            pa u = {seg[i].x,y};
            fori(k,0,8){
            pa v = {u.fi+dx[k], u.se+dy[k]};
                if(vis.count(v)){
                    e[vis[u]].pb(vis[v]);
                }
            }
        }
    }
}
int dis[maxn];
int dij(){
    st_id = vis[st], ed_id = vis[ed];
    priority_queue<pa>q;
    q.push({0,st_id});
    mst(dis,0x3f);
    dis[st_id] = 0;
    while(!q.empty()){
        int u = q.top().se, d = -q.top().fi;//pa u = q.top(); q.pop();
        q.pop();
        if(dis[u] != d) continue;
        //cout<<u<<endl;
        for(auto v: e[u]){
            if(dis[v] > dis[u] + 1){
                dis[v] = dis[u] + 1;
                q.push({-dis[v],v});
            }
        }
    }
    return 0;
}
void sol(){
    cin>>st.fi>>st.se;
    cin>>ed.fi>>ed.se;
    cin>>n;
    fori(i,0,n){
        int r, a, b;
        cin>>r>>a>>b;
        seg.pb({r,a,b});
    }
    fori(i,0,n){
        For(j,seg[i].l,seg[i].r){
            pa p = {seg[i].x,j};
            if(!vis.count(p)){
                vis[p] = ++tot;
            }
        }
    }
    link();
    dij();
    if(dis[ed_id] == inf)cout<<-1<<endl;
    else cout<<dis[ed_id]<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}