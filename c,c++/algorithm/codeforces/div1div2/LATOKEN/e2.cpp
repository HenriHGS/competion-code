#include <iostream>
#include <numeric>
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

const int maxn = 100000 + 6;



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    auto query = [&](vector<int>v1, vector<int>v2){
        cout<<"? ";
        for(auto x:v1)cout<<x<<' ';
        for(auto x:v2)cout<<x<<' ';
        cout<<endl; cout.flush();
        //cout.flush
        //or 
        //
    };
    int n, k;
    cin>>n>>k;
    vector<int>dis(2000,inf);
    vector<int>par(2000);
    //bfs
    auto BFS = [&](){
        queue<int>q;
        q.push(0);
        par[0] = -1;
        dis[0] = 0;
        while(!q.empty()){
            int c = q.front(); q.pop();
            For(i,0,k){//num numbers will add
                if(c + i <= n && k - i <= c){
                    int to = c + i - (k - i);//add and del same
                    if(dis[to] == inf){
                        dis[to] = dis[c] + 1;
                        par[to] = c;
                        q.push(to);
                    }
                }
            }
        }
    };
    BFS();
    if(dis[n] == inf){
        cout<<-1<<endl;cout.flush();
        return 0;
    }
    vector<int>sel, nosel(n);
    iota(ALL(nosel),1);//increase fuzhi to nosel

    vector<int>path;
    for(int c = n; c != -1; c = par[c]){
        path.pb(c);
        //debug(c);
    }
    reverse(ALL(path));
    int res = 0;
    fori(i,0,sz(path)-1){
        int c1 = path[i], c2 = path[i+1], add = c2 - c1, nsel = (add + k) / 2, nnosel = k - nsel;
        vector<int>csel, cnosel;
        fori(j,0,nsel){
            csel.push_back(nosel.back());
            nosel.pop_back();
        }
        fori(j,0,nnosel){
            cnosel.push_back(sel.back());
            sel.pop_back();
        }
        query(csel,cnosel);
        nosel.insert(nosel.end(), cnosel.begin(), cnosel.end());
        sel.insert(sel.end(), csel.begin(), csel.end());

        int cur; cin>>cur;
        res ^= cur;
    }
    cout<<"! "<<res<<endl; cout.flush();
    return 0;
}