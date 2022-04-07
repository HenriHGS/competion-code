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

const int maxn = 100000 + 5;
int a[maxn];
void sol(){
    int n; cin>>n;
    For(i,1,n) cin>>a[i];
    int even = 0, odd3 = 0;
    vector<pa> b;
    ll ans = 0, sum_even = 0;
    set<pa> left, right;
    For(i,2,n - 1) {
        if(a[i] % 2 == 0) {
            even++, sum_even += a[i]/2, ans += a[i]/2;
            left.insert({i,a[i]/2});
            right.insert({i,a[i]/2});
        }
        else if(a[i] > 1) odd3++, b.push_back({a[i],i});
        else b.push_back({a[i],i});
    }
    int one = n - 2 - even - odd3;
    sort(ALL(b));
    int p = 0, q = (int)b.size() - 1;
    bool ok = true;
    if(p <= q) {
        for(p, q; q >= 0; q -- ){
            int pos = b[q].second, val = b[q].first;
            bool fl = false;
            if(right.size()){
                auto it = right.lower_bound({pos,0});
                if(it == right.end()) it--;
                if(it == right.begin()) {
                    //fl = false;
                }else {
                    fl = true;
                    auto x = *it;
                    right.erase(it);
                    x.second--;
                    if(x.second) right.insert({x});
                    ans += (val + 1)/2;
                    left.insert({pos, (val + 1) / 2});
                    right.insert({pos, (val + 1)/ 2});
                }
            }
            if(fl) continue;
            if(left.size()){
                auto it = left.lower_bound({pos,0});
                if(it == right.end()) {
                    // fl = false
                }else {
                    fl = true;
                    auto x = *it;
                    right.erase(it);
                    x.second--;
                    if(x.second) right.insert({x});
                    ans += (val + 1)/2;
                    left.insert({pos, (val + 1) / 2});
                    right.insert({pos, (val + 1)/ 2});
                }
                //
            }
            if(fl) continue;

            while(p < q && a[p] != 1)p++;
            if(p < q){
                ans += (val + 1)/2;
                left.insert({pos, (val + 1) / 2});
                right.insert({pos, (val + 1)/ 2});
                a[p] -= 2;
            }
        }
    }   
    cout<<ans<<endl;
}

// 1 3 3 3

// 1 5 5 6
//2 3 6 6
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}