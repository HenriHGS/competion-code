/*
sol1：异或没看出来，干干！！！！！！！！

sol2: 由于一个串，只有两个元素组成，f(c,b)假如c和b中的1的奇偶性相同。
    对于同位的1，直接抵消，不对答案做贡献，抵消后，奇偶还是不变。

    假如不同位，还是抵消。因为c中的1在b中有0对应。
    假如不同位，还是抵消。因为b中1在c中有0对应。
    总体还是偶数

    对于0的情况，和1互逆。。。。。
*/
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

const int maxn = 1e6 + 6;



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin>>a>>b;
    int t = 0;
    int ch = '0';
    fori(i,0,sz(b)){
        t^=(a[i]-ch)^(b[i]-ch);
    }
    int ans = 0;
    if(!t) ans++;
    fori(i,sz(b), sz(a)){
        t^=(a[i]-ch)^(a[i-sz(b)] - ch);
        if(!t) ans++;
    }
    cout<<ans<<endl;
    return 0;
}