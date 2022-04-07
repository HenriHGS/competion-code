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

const int maxn = 100000 + 6;
const int N = 110;
int dp[N][N][12];
int path[N][N][12];
char s[N][N];
void sol(){
    int n, m, kk;
    cin>>n>>m>>kk;
   // vector<string> s(n);
    //mst(dp,-1);
    int mod = kk+1;
    for(int i = n; i >= 1; i --)cin>>(s[i]+1);
    mst(dp,-1);
   // cout<<endl;
    //For(i,1,n)cout<<(s[i]+1)<<endl;
    For(i,1,n)For(j,1,m) s[i][j] -= '0';
    For(i,1,n)For(j,1,m)For(k,0,mod){
        if( i == 1 ){
            int re = s[i][j] % mod;  
            dp[i][j][re] = s[i][j];
            break;
        }else {
            if(j != 1){
                //left
                if(dp[i-1][j-1][k] != -1){
                    int re = (k + s[i][j])%mod;
                    int& pre = dp[i-1][j-1][k]; 
                    int& dp1 = dp[i][j][re];
                    if(dp1 == -1){
                        dp1 = pre + s[i][j];
                        path[i][j][re] = 1; 
                    }else if(pre + s[i][j] > dp1){
                        dp1 = pre + s[i][j];
                        path[i][j][re] = 1;
                    }
                }
            }
            if(j != m){
                //right
                if(dp[i-1][j+1][k] != -1){
                    int re = (k + s[i][j])%mod;
                    int& pre = dp[i-1][j+1][k]; 
                    int& dp1 = dp[i][j][re];
                    if(dp1 == -1){
                        dp1 = pre + s[i][j];
                        path[i][j][re] = 2; 
                    }else if(pre + s[i][j] > dp1){
                        dp1 = pre + s[i][j];
                        path[i][j][re] = 2;
                    }
                }
            }
        }
    }
    int mx = -1, ed = -1, st;
    For(j,1,m){
        if(dp[n][j][0] > mx){
            mx = dp[n][j][0];
            ed = j;
        }
    }
    if(mx == -1)cout<<-1<<endl;
    else {
        cout<<mx<<endl;
        int cur_i = n, cur_j = ed;
        stack<string> ans;
         string stag = "";
         int cnt = 0;
         int now = dp[cur_i][cur_j][0];
         int re = now%mod;
        while(path[cur_i][cur_j][re]){
            now = now - s[cur_i][cur_j];
            if(path[cur_i][cur_j][re] == 1)stag += 'R', cur_j --;
            else if(path[cur_i][cur_j][re] == 2) stag += 'L', cur_j++;
             re = now%mod;
          //  cout<<(++cnt)<<": "<< cur_i << cur_j<<endl;
            cur_i --;
        }
        st = cur_j;
        reverse(ALL(stag));
        cout<<st<<endl;
        cout<<stag<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}