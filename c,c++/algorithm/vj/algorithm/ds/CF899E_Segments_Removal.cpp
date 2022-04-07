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
#define eb emplace_back
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

const int maxn = 2e5 + 10;

int a[maxn];
int fa[maxn], siz[maxn], lef[maxn], rig[maxn];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
struct Node{
    int siz, x;
    bool operator < (const Node& t) const {
        if(siz == t.siz) return x > t.x;
        return siz < t.siz;
    }
};
int lx[maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    For(i,1,n) siz[i] = 1, fa[i] = i, lef[i] = i - 1, rig[i] = i + 1;
    For(i,1,n) cin>>a[i], lx[i] = a[i];
    /* sort(lx + 1, lx + 1 + n);
    int tot = unique(lx+1, lx + 1 + n) - (lx + 1);
    For(i,1,n) {
        a[i] = 
    } */
    int ans = 0;
    For(i,2,n){
        if(a[i] == a[i - 1]){
            //merge(i-1,i);
            int u = i - 1, v = i;
            int fu = find(u), fv = find(v);
            fa[fv] = fu;
            siz[fu] += siz[fv];
            rig[fu] = max(rig[fu], rig[fv]);
        }
    }
    set<Node> que;
    For(i,1,n) if(i == find(i)){
        que.insert(Node{siz[i], i});
    }
    
    while(!que.empty()){
        auto top = *que.rbegin();
        int x = top.x;
        que.erase(que.find(top));
        ans++;
        int l = lef[x], r = rig[x];
        if(l == 0){
            if(r <= n){
                lef[r] = 0; 
            }
        }else if(r == n+1){
            if(l > 0){
                rig[find(l)] = n + 1; 
            }
        }else {
            int fl = find(l), fr = find(r);
            if(a[l] == a[r]){
                auto ri = que.find(Node{siz[fr], r});
                que.erase(ri);
                auto le = que.find(Node{siz[fl], fl});
                que.erase(le);
                fa[fr] = fl;
                siz[fl] += siz[fr];
                rig[fl] = max(rig[fl], rig[fr]);
                que.insert(Node{siz[fl], fl});
            }else {
                rig[fl] = r;
                lef[fr] = l;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}