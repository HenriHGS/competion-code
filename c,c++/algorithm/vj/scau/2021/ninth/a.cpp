#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <map>
#define For(i,x,y) for(int i=(x); i<=(y); i++)
#define fori(i,x,y) for(int i=(x); i<(y); i++)
#define rep(i,y,x) for(int i=(y); i>=(x); i--)
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define sz(a) (int)a.size()
#define ALL(x) x.begin(),x.end()
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

const db eps = 1e-8;
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

const int maxn = 1e4+10;
int dp[maxn][2];

void sol(){
    int a,tot,f,k;
    cin>>a>>tot>>f>>k;
    int st = 0, ed = a;
    int t = 0;
    mst(dp,-1);
    dp[0][0] = tot;
    int dis = a;
    For(i,1,k){
        t ^= 1;
        int dis_f = abs(f-st);
        int dis_ed = abs(f-ed);
        For(j,0,i+1)dp[j][t] = -1;
        For(j,0,i){
            int& d = dp[j][t];
            if(dp[j][t^1] != -1 && dp[j][t^1]>=dis){
                if(d==-1)d = dp[j][t^1] - dis;
                else d = max(d,dp[j][t^1] - dis);
            }
            int& d1 = dp[j+1][t];
            if(dp[j][t^1] != -1 && dp[j][t^1] >= dis_f && tot-dis_ed >= 0){
                if(d1 == -1) d1 = tot - dis_ed;
                else d1 = max(d1,tot - dis_ed);
            }
        }
        swap(st,ed);
    }
    int ans = k+1;
    For(i,0,k){
        int& d = dp[i][t];
        if(d == -1) continue;
        ans = min(ans,i);
    }
    if(ans == k+1)cout<<-1<<endl;
    else cout<<ans<<endl;
}

//#define LOCAL
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
freopen("in.txt", "r", stdin);
#endif // LOCAL
    sol();
    return 0;
}
/*
hack:
1000000 1 1 1
*/