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

const int maxn = 100 + 6;

int dp[maxn][maxn][maxn];
array<int,3> path[maxn][maxn][maxn];

int nxt[maxn];
void getnxt(string p){
    int m = p.size();
    int i = 0, j = -1;
    nxt[0] = -1;
    while(i < m){
        if(j == -1 || p[i] == p[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}
void ckmax(string& a, string b){
    if(a.size() < b.size()) a = b;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string A, B, C;
    cin>>A>>B>>C;
    getnxt(C);
    int len1 = A.size(), len2 = B.size(), len3 = C.size();
    For(i,1,len1)For(j,1,len2)For(k,0,len3-1){
        if(A[i - 1] == B[j - 1]){
            int t = k;
            char ch = A[i-1];
            while(t && ch != C[t])t = nxt[t];
            if(C[t] == ch)t++;
            auto& d1 = dp[i][j][t], & d2 = dp[i-1][j-1][k]; 
            if(d1 < d2 + 1){
                d1 = d2 + 1;
                path[i][j][t] = {i-1,j-1,k};
            }
        }
        auto& d1 = dp[i][j][k], & d2 = dp[i-1][j][k], & d3 = dp[i][j-1][k]; 
        if(d1 < d2){//ckmax(dp[i][j][k], dp[i-1][j][k]);
            d1 = d2;
            path[i][j][k] = {i-1,j,k};
        }
        if(d1 < d3){
            d1 = d3;
            path[i][j][k] = {i,j-1,k};
        }
        //ckmax(dp[i][j][k], dp[i][j-1][k]);
    }
    string ans = "";
    int ans_sz = 0;
    For(i,0,len3-1)ckmax(ans_sz,dp[len1][len2][i]);
    //debug(ans_sz);
    if(ans_sz == 0)cout<<0<<endl;//puts("0");
    else {//cout<<ans<<endl;
        int k = 0, i = len1, j = len2;
        For(i,0,len3-1)if(ans_sz == dp[len1][len2][i]){
            k = i;
            break;
        }
        auto pre = path[i][j][k];
        for(; dp[i][j][k]; ){
            pre = path[i][j][k];
            if(pre[0] + 1 == i && pre[1] + 1 == j) ans += A[i-1];
            i = pre[0], j = pre[1], k = pre[2];
        }
        reverse(ALL(ans));
        cout<<ans<<endl;
    }
    return 0;
}