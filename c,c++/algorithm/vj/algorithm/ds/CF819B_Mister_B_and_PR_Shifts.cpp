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

const int maxn = 1e6+10 + 6;

int p[maxn];
vector<int> dfn[maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    For(i,1,n) cin>>p[i];
    ll pos_cnt, pos_tot, neg_cnt, neg_tot;
    pos_cnt = pos_tot = neg_cnt = neg_tot = 0;
    // cal p[i] - i > 0 --- pos
    // cal p[i] - i <= 0 ---neg
    ll ans1 = 0, sum = 0, ans2 = 0;
    For(i,1,n){
        if(p[i] - i > 0){
            pos_cnt++;
            pos_tot += p[i] - i;
            int ctime = p[i] - i;
            dfn[ctime].push_back(i);
        }else {
            neg_cnt++;
            neg_tot += i - p[i];
            int ctime = n - i + p[i];
            dfn[ctime].push_back(i);
        }
    }
    ans1 = pos_tot + neg_tot;
    sum = ans1;
    //printf("pre: pos_cnt = %d, pos_tot = %d, neg_cnt = %d, neg_tot = %d\n", pos_cnt, pos_tot, neg_cnt, neg_tot);
    int dfs_clock = 0;
    for(int i = n; i >= 2; i -- ){
        
        dfs_clock++;
        //last to first, neg - 1
        {
            int cur = n - p[i];
            neg_cnt--;
            neg_tot -= cur;
            neg_tot += neg_cnt;
            if(p[i] != 1){
                pos_cnt++;
                pos_tot += p[i];
            }else neg_cnt++;
        }
        pos_tot -= pos_cnt;
        //others run back   
        {
            auto&v = dfn[dfs_clock];
            for(auto x : v) {
                if(p[x] == 1) continue;
                pos_cnt--;
                neg_cnt++;
                //and then the tot will add in all instead of this"neg_tot += 1"
                //pos_tot pre statues is zero
            }
        }
        
        //neg_tot += neg_cnt;
        sum = pos_tot + neg_tot;
        if(dfs_clock == 7){
            //printf("after: pos_cnt = %d, pos_tot = %d, neg_cnt = %d, neg_tot = %d\n", pos_cnt, pos_tot, neg_cnt, neg_tot);
        }
        if(ans1 > sum){
            ans1 = sum;
            ans2 = dfs_clock;
        }
        //printf("after: pos_cnt = %d, pos_tot = %d, neg_cnt = %d, neg_tot = %d\n", pos_cnt, pos_tot, neg_cnt, neg_tot);
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}