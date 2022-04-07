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

const int maxn = 100000 + 5;

void sol(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    fori(i,0,n)cin>>a[i], b[i] = a[i];
    sort(ALL(b));
    int ans = 0;
    bool ok = true;
    fori(i,0,n) ok &= a[i] == b[i];
    if(ok) cout<<0<<endl;
    else {
        int cnt = 0;
        if(a[0] != 1){
            if(a[0] == n){
                if(a[n-1] == 1)cout<<3<<endl;
                else cout<<2<<endl;
            }else {
                if(a[n-1] == n)cout<<1<<endl;
                else cout<<2<<endl;
            }
        }else cout<<1<<endl;
    }
    /*
    else if(n == 3){
        if(a[0] == 3 && a[2] == 1)cout<<3<<endl;
        else if(a[0] == b[0] || a[2] == b[2]) cout<<1<<endl;
        else cout<<2<<endl;
    }else {
        int cnt = 0;
        if(a[0] != b[0])cnt++;
        if(a[n-1] != b[n-1])cnt++;
        ans += cnt;
        if(!ans)ans++;
        cout<<ans<<endl;
    }
    */
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}