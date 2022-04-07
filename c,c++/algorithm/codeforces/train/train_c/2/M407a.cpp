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

int getdis(pa p1, pa p2){
    return (p1.fi - p2.fi) * (p1.fi - p2.fi) + (p1.se - p2.se) * (p1.se - p2.se);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b;
    cin >> a >> b;
    bool ok = false;
    vector<pa>ans;
    ans.pb({0,0});
    For(x1,0,a){
        For(x2,-b,b){
            if(x1 == x2)continue;
            int yy1 = a*a - x1*x1; 
            int yy2 = b*b - x2*x2;
            int y1 = sqrt(yy1);
            if(y1*y1 != yy1)continue;
            int y2 = sqrt(yy2);
            if(y2 * y2 != yy2)continue;
            if(x1*y1 == 0 || x2*y2 == 0)continue;
            pa p1 = {x1,y1}, p2 = {x2,y2}, p3 = {x2,-y2};
            if(x1 * x2 + y1 * y2 == 0 && p1.se != p2.se){
                ok = true;
                ans.pb(p1);
                ans.pb(p2);
                break;
            }
            if(x1 * x2 - y1 * y2 == 0 && p1.se != p3.se){
                ok = true;
                ans.pb(p1);
                ans.pb(p3);
                break;
            }
        }
        if(ok)break;
    }
    if(!ok)cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        for(auto x:ans)cout<<x.fi<<' '<<x.se<<endl;
    }
    return 0;
}
