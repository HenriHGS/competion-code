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

const int maxn = (1<<18) + 1;

int k, n;
LL dp[maxn];
int pw[maxn];
string s;
void add(int idx, LL val, int op){
    dp[idx] += op*val;
}
void mody(int x, int id){
    if(id != 1){
        int dow = pow(2,k-id+1);
        dow -= x - pw[id-1] - 1;
        if(s[x] == '1') dp[x] = dp[x-dow+1];
        else if(s[x] == '0') dp[x] = dp[x-dow];
        else dp[x] = (dp[x-dow+1] + dp[x-dow]);
    }else dp[x] = (s[x] == '?'?2:1);
}
void up(int x, int id){
    mody(x,id);
    if(x == n) return;
    int bu = pow(2,k-id);
    bu -= (x - pw[id-1])/2;
    up(x+bu,id+1);
}
int getId(int i){
    int id = lower_bound(pw+1,pw+1+k, i) - (pw);
    //if(pw[id] != i)id--;
    return id;
}
void sol(){
    cin>>k;
    cin>>s;
    n = pow(2,k)-1;
    s = " " + s;//!!!
   // For(i,1,tot)cout<<s[i];
    int bi = n + 1;
    for(int i = 1; i <= k; i ++ ){
        bi/=2;
        pw[i] = pw[i-1] + bi;
    }
    for(int i = 1; i <= n; i ++ ){
        int id = getId(i);
        mody(i,id);
    }
    int q;
    cin>>q;
   // debug(n);
    while(q--){
        int p;
        char ch;
        cin>>p>>ch;
        int id = getId(p);
      //  debug(id);
        s[p] = ch;
        up(p,id);
        cout<<dp[n]<<endl;
        //change to pre
        /*
        s[p] = pre;
        upsub(p, id);
        mody(p,id,1);
        upadd(p,id);
        */
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}