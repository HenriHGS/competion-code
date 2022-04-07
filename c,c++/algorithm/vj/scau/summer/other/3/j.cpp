#pragma GCC optimize(2,3,"Ofast")
#include <iostream>
#include <chrono>//随机化
#include <cstdint>//
#include <ctime>//
#include <random>//
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

const int maxn = 2e5 + 6;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int p, q;
int b1[200], b2[maxn];
int main() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    n = read(); //m = read(); p = read();
    LL mid = n/2;
    LL limi = pow(2,mid);
   // fori(i,0,n)scanf("%s", a[i]);
    //fori(i,0,n)fori(j,0,m)  a[i][j] -= '0';
    //int ans = 0;
    //string anss(m,'0');
    LL a[2];
    For(times, 1, 1000){
        bool ok = true;
        string anss = "";
        if(times%2){
            a[0] = rng()%limi;
        }else {
            a[1] = rng()%limi;
            LL sum1 = 0;
            LL sum2 = 0;
            For(i,0,min(63,n-1)){
                if(a[0]>>i&1)sum1 += b1[i+1], sum2 += b2[i+1];
            }
            For(i,0,min(n-64))
        }
        if(!ok){
            cout<<"NO"<<endl;
            cout<<anss;
        }
    }
    cout<<"YES"<<endl;
   // c//out<<anss<<endl;
    return 0;
}