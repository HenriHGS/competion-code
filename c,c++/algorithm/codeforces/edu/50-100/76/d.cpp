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

const int maxn = 2e5 + 5;

void sol(){
    int n, m;
    cin>>n;
    vector<int>a(n);
    fori(i,0,n)cin>>a[i];
    cin>>m;
    vector<pa>b(m);
    fori(i,0,m)cin>>b[i].fi>>b[i].se;
    sort(ALL(b));
    for(int i = m - 2; i >= 0; i --) ckmax(b[i].se,b[i+1].se);
    int res = 0;
    auto Get = [&](int mx){
        int ind = lower_bound(b.begin(),b.end(), mp(mx,0)) - b.begin();
       // if(lower_bound(ALL(b),mp(mx,0)) == b.end()) cout<<ind<<endl;
        if(ind == m)return 0;
        return b[ind].se;
    };
    for(int i = 0, j; i < n; i = j){
        j = i;
        int mx = a[i];
        while(j < n){
            ckmax(mx,a[j]);
            if(Get(mx) >= j - i + 1) j ++;
            else break;
        }
      //  debug(mx);
      //  debug(i);
      //  debug(j);
        if(i == j){
            cout<<-1<<endl;
            return ;
        }
        res++;
    }
    cout<<res<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}