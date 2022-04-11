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

const int maxn = 4e5 + 6;

int a[maxn];
int mi[maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin>>n>>k;
    vector<int> lx;
    for(int i = 1; i <= n; i++ ) {
        cin>>a[i];
        lx.push_back(a[i]);
    }
    sort(lx.begin(), lx.end());
    lx.erase(unique(lx.begin(), lx.end()), lx.end());

    for(int i = 1; i <= n; i ++ ) {
        a[i] = lower_bound(lx.begin(), lx.end(), a[i]) - lx.begin() + 1;
        // cout<<a[i]<<endl;
    }
    
    mst(mi,0x3f);
    for(int i = n; i > k; i -- ) {
        mi[a[i]] = min(mi[a[i]], i);
    }
    //cout<<lx.back()<<endl;
    for(int i = lx.size(); i >= 0; i -- ) {
        mi[i] = min(mi[i],mi[i+1]);
    }
    int ans = -1;
    for(int i = 1; i <= k; i ++ ) {
       // auto it = home.upper_bound({a[i],10000000});
       // if(it == home.end() || (it->first) == a[i]) continue;
        // printf("i:%d, home->second:%d\n", i, it->second);
        // cout<<it->first<<endl;
        //1 2 3 | 4 5 
        if(mi[a[i] + 1] == inf) continue;
        if(ans != -1) {
            if(ans > (k-i) + (mi[a[i] + 1]) - k ) 
                ans =  (k-i) + (mi[a[i] + 1]) - k ;
        } else ans = (k-i) + (mi[a[i] + 1]) - k ;
    }
    
    cout<<ans<<endl;
   
    return 0;
}
/* 
20 13
90699850 344821203 373822335 437633059 534203117 523743511 568996900 694866636 683864672 836230375 751240939 942020833 865334948
142779837 22252499 197049878 303376519 366683358 545670804 580980054

 */