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

const int maxnode = 1e5 + 10;
const int sigma_size = 2;
int ch[maxnode*34][sigma_size];
int val[maxnode*34];
int sz;
void init(){
    sz = 1; mst(ch[0],0);
}
//int idx()
void insert(LL x, int v){
    //debug("insert");
    int u = 0, len = 33;
    for(int i = len; i >= 0; i -- ){
        int c = (x>>i)&1;
       // cout<<c;
        if(!ch[u][c]){
            mst(ch[sz],0);
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
   // cout<<endl;
    val[u] += v;
}
LL find(LL x){
    int u = 0, len = 33;
    LL ans = 0;
    for(int i = len; i >= 0; i -- ){
        int c = (x>>i)&1;
       // cout<<c;
            if(ch[u][!c])u = ch[u][!c], ans |= ((LL)1<<i);
            else u = ch[u][c];//ans不动
    
        //debug(ans);
    }
   // cout<<endl;
   // debug(ans);
    return ans;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    LL ans = 0;
    init();
    int n;cin>>n;
    For(i,1,n){
        LL x;
        cin>>x;
        if(i >= 2){
            ckmax(ans,find(x));
        }
        insert(x,1);
    }
    cout<<ans<<endl;
    return 0;
}