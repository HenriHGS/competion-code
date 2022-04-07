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

const int maxn = 2e5 + 6;
const int LOGN = 21;
int G[maxn][LOGN];
int logn[maxn];
int n;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
void init(){
    for(int i = 2; i < maxn; i ++ ) logn[i] = logn[i/2] + 1;
    cin>>n;
    for(int i = 1; i <= n; i ++ ) cin>>G[i][0];
    for(int j = 1; j < LOGN; j ++ )
        for(int i = 1; i + (1<<j) - 1 <= n; i ++ ){
            G[i][j] = gcd(G[i][j-1], G[i + (1<<(j - 1))][j-1]);
        }
}
int get(int l, int r){
    int s = logn[r- l + 1];
    return gcd(G[l][s], G[r - (1<<s)+1][s]);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int last = 0, l = 1, cnt = 0;
    for(int i = 1; i <= n; i ++ ){
        while(l <= i && get(l,i) < i - l + 1)l++;
        if(get(l,i) == i - l + 1 && last < l){
            last = i, cnt++;
        }
        cout<<cnt<<' ';
    }
    return 0;
}