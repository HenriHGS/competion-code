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

const int maxn = 100000 + 6;

#define x first
#define y second

int fa[maxn], siz[maxn];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d; cin>>n>>d;
    vector<pa> e;
    For(i,1,n) fa[i] = i, siz[i] = 1;
    //vector<int> fa(n+1);
    //iota(ALL(fa), 0);
    For(i,1,d){
        int a, b; cin>>a>>b;
        e.push_back({a,b});
    }
    int add = 0;
    fori(k,0,d){
        int a = e[k].x, b = e[k].y;
        int anca = find(a), ancb = find(b);
        if(anca == ancb) add++;
        else {
            fa[anca] = ancb;
            siz[ancb] += siz[anca];
        }
        vector<int> S;
        For(i,1,n) if(i == find(i)){
            S.push_back(siz[i]);
        }
        sort(ALL(S));
        reverse(ALL(S));
        int ans = S[0];
        for(int i = 1, cnt = 1; i < S.size(); i ++, cnt++){
            if(cnt <= add) ans += S[i];
        }
        cout<<(ans-1)<<endl;
    }
    return 0;
}