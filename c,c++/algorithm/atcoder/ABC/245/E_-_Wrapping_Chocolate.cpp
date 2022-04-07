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
#include <numeric>
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

const int maxn = 2e5 + 6;

int a[maxn], b[maxn], c[maxn], d[maxn];
int id1[maxn], id2[maxn];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; i ++ ) cin>>a[i];
    for(int i = 1; i <= n; i ++ ) cin>>b[i];
    for(int i = 1; i <= m; i ++ ) cin>>c[i];
    for(int i = 1; i <= m; i ++ ) cin>>d[i];
    bool ok = true;
    iota(id1+1,id1+1+n,1);
    iota(id2+1,id2+1+m,1);
    //for(int i = 1; i<= m; i++) cout<<id2[i]<<endl;

    sort(id1 + 1, id1 +1 + n, [&](int x, int y) {
        if(a[x] != a[y]) return a[x] > a[y];
        return b[x] > b[y];
    });
    sort(id2 + 1, id2 +1 + m, [&](int x, int y) {
        if(c[x] != c[y]) return c[x] > c[y];
        return d[x] > d[y];
    });
    // for(int i = 1; i <= n; i ++ ) cout<<a[id1[i]] <<' ';
    // cout<<endl;
    // for(int i = 1; i <= n; i ++ ) cout<<b[id1[i]] <<' ';
    // cout<<endl;
    // for(int i = 1; i <= m; i ++ ) cout<<c[id2[i]]<<' ';
    // cout<<endl;
    // for(int i = 1; i <= m; i ++ ) cout<<d[id2[i]]<<' ';
    // cout<<endl;
    multiset<int> home;
    int i = 1, j = 1;
    for(i, j; i <= n; i ++ ) {
        while(j <= m && c[id2[j]] >= a[id1[i]]) {
            home.insert(d[id2[j]]);
            j++;
        }
        auto it = home.lower_bound(b[id1[i]]);
        if(it == home.end()) {
            cout<<"No"<<endl;
            return 0;
        }
        home.erase(it);
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*
iota(id1+1,id1+1+n,1);
    iota(id2+1,id2+1+m,1);
    //for(int i = 1; i<= m; i++) cout<<id2[i]<<endl;
    sort(id1 + 1, id1 +1 + n, [&](int x, int y) {
        if(a[x] < a[y]) return true;
        return b[x] < b[y];
    });
    sort(id2 + 1, id2 +1 + m, [&](int x, int y) {
        if(c[x] < c[y]) return true;
        return d[x] < d[y];
    });
    bool ok = true;
    int i = 1, j = 1;
    for(i,j; i <= n; i ++ ) {
        while(j <= m && (a[id1[i]] > c[id2[j]] || b[id1[i]] > d[id2[j]])) j++;
        if(j <= m) j++;
        else ok = false;
    }
    if(ok) cout<<"Yes"<<endl;
*/
/*
set<pair<int,int>> home;//
    vector<multiset<pair<int,int>>> col(m+1);// [len,id]
    vector<int> lx;
    for(int i = 1; i <= m; i ++ ) {
        home.insert({c[i],d[i]});
        lx.push_back(d[i]);
    }
    //lx
    sort(lx.begin(), lx.end());
    lx.erase(unique(lx.begin(), lx.end()), lx.end());
    for(int i = 1; i <= m; i ++ ) {
        d[i] = lower_bound(lx.begin(), lx.end(), d[i]) - lx.begin();
    }

    //insert
    for(int i = 1; i <= m; i ++ ){
        int dd = lx[d[i]];
        pair<int,int> xx = make_pair(c[i],0);// [c[i],dd];

        auto it = home.lower_bound(xx);
        if(it == home.end()) home.insert(make_pair(c[i],dd));
        else {
            if(it->first == c[i]) home.erase(it);
            home.insert(make_pair(c[i],dd));
        }
        col[c[i]].insert(make_pair(dd,i));
    }

    iota(id1+1,id1+1+n,1);
    iota(id2+1,id2+1+m,1);
    //for(int i = 1; i<= m; i++) cout<<id2[i]<<endl;
    sort(id1 + 1, id1 +1 + n, [&](int x, int y) {
        if(a[x] < a[y]) return true;
        return b[x] < b[y];
    });
    for(int i = 1; i <= n; i ++ ) {
        int idx = id1[i];
        pair<int,int> x = make_pair(a[idx], b[idx]);
        auto it = home.lower_bound(x);
        
    }
*/