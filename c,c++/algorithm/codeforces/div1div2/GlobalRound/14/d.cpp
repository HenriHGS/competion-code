#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
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

const int maxn = 2e5 + 5;
int col_l[maxn], col_r[maxn];
void sol(){
    int n, l, r;
    cin>>n>>l>>r;
    For(i,1,n)col_l[i] = col_r[i] = 0;
    For(i,1,l){
        int col;
        cin>>col;
        col_l[col]++;
    }
    For(i,1,r){
        int col;
        cin>>col;
        col_r[col]++;
    }
    For(i,1,n){
        if(col_l[i] == 0 || col_r[i] == 0)continue;
        int mi = min(col_l[i], col_r[i]);
        col_l[i] -= mi;
        col_r[i] -= mi;
    }
    int cnt[2]{};
    For(i,1,n){
        cnt[0] += col_l[i];
        cnt[1] += col_r[i];
    }
    //debug(cnt[0]);
    //debug(cnt[1]);
    if(cnt[0]==cnt[1]){
        cout<<cnt[0]<<endl;
        return ;
    }
    if(cnt[0] < cnt[1]){
        swap(cnt[0],cnt[1]);
        For(i,1,n)swap(col_l[i],col_r[i]);
    }
    LL ans = 0;
    For(i,1,n){
        if(col_l[i] == 0) continue;
        if(col_l[i]>=2){
            int tmp = min(col_l[i]/2,(cnt[0]-cnt[1])/2);
            col_l[i] -= tmp*2;
            cnt[0] -= tmp*2;
            ans += tmp;
        }
    }
    if(cnt[0] != cnt[1])ans += (cnt[0]-cnt[1]);
    ans += cnt[1];
    cout<<ans<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}