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
#define rep(i,y,x) for(int i = (y); i >= (x); i -- )
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

const int maxn = 100000 + 5;
int tr[maxn];
int n;
int lowbit(int x){
    return x & -x;
}
void add(int x, int v){
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += x;
}
int qury(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
}
LL sum[maxn][4];
int rac(int x){
    if(x==0) return 'A';
    else if(x == 1) return 'T';
    else if (x == 2) return 'O';
    else return 'N';
}
void sol(){
    string s;
    cin>>s;
    n = s.size();
    //int p[4] = {'A','T','O','N'};
    int p[4] = {0, 1, 2, 3};
    s = " " + s;
    fori(i,0,4)sum[n+1][i] = 0;
    rep(i,n,1){
        fori(j,0,4) {
            int x = rac(p[j]);
            sum[i][j] = sum[i+1][j] + (s[i]==x);
        }
    }
    LL ans, mx;
    ans = mx = -1;
    string anss;
    int cnt = 0;
    do{
        //For(i,0,n) tr[i] = 0;
        ans = 0;
        For(i,1,n){
            for(int j = 0; rac(p[j]) != s[i]; j ++ ){
                int pp = p[j];
                ans += sum[i][pp];
            }
        }
        if(ans > mx){
            mx = ans;
            anss = "";
            fori(i,0,4){
                int pp = p[i];
                anss += string(sum[1][pp], (char)rac(pp));
            }
        }
       // cnt++;
    }while(next_permutation(p, p + 4));
  // debug(cnt);
    cout<<anss<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}