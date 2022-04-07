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

const int maxnode = 3e5+10;
const int sigma_size = 2;
const int maxn = 3e5 + 10;
int n, m;
int vis[maxn];

int ch[maxnode*30][sigma_size], o;
int s[maxnode*30];
void init(){
    o = 1; mst(ch[0], 0);
}
void insert(int x){
    int u = 0;
    for(int i = 19; i >= 0; i -- ){
        int c = x >> i & 1;
        if(!ch[u][c]){
            //mst()
            ch[u][c] = o++;
        }
        u = ch[u][c];
        s[u]++;
    }
}
int mex(int x){
    int ans = 0, u = 0;
    for(int i = 19; i >= 0; i -- ){
        int c = x >> i & 1;
        if(s[ch[u][c]] == 1 << i) ans|=1<<i, u = ch[u][c^1];
        else u = ch[u][c];
    }
    return ans;
}
void sol(){
    init();
    cin>>n>>m;
    For(i,1,n){
        int x;
        cin>>x;
        if(!vis[x]) vis[x] = 1, insert(x);
    }
    int xx = 0;
    For(i,1,m){
        int x;
        cin>>x;
        xx ^= x;
        cout<<mex(xx)<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}