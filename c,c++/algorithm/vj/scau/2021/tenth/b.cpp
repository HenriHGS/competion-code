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
#define rep(i,y,x) for(int i = (y); i >= (x); i -- )
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

const int maxn = 2000 + 6;

//内存会超
void table(){
    int l = 1, r = 2000;
    LL sum = 0;
    For(i,1,r){
        For(j,i,r){
            sum += (j-i+1);
        }
    }
    cout<<sum<<endl;
}
/*
void test(){
    set<int>a;
    set<int>b;
    set<int>c;
    a.insert(1);
    a.insert(2);
    b.insert(3);
    b.insert(4);
    set_union(ALL(a),ALL(b),back_inserter(c));
    for(auto x: c)cout<<x<<' ';
    cout<<endl;
}
*/
set<int> pre[maxn], suf[maxn];
int a[maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //table();
    int n;
    cin>>n;
    For(i,1,n)cin>>a[i];
    int ans = n;
   // set<int>b;
    //For(i,1,n)b.insert(a[i]);
    //if(sz(b) == n)ans = 0;
    For(i,1,n){
        set<int>s;
        fori(j,1,i)s.insert(a[j]);//手都打断！！！！！！！！！！！、
        //写成了i，干干！！！！！！！！！
        rep(j,n,i){
            int sum1 = i-1;
            int sum2 = n - j;
           // debug(sz(s));
          // cout<<"i = "<<i << " j = "<<j <<endl;
            if(sz(s) == sum1+sum2){
                ans = min(ans,n - sum1 - sum2);
            }else break;
            s.insert(a[j]);
            //debug(a[j]);
        }
        if(sz(s) == n)ans = 0;
    }
    cout<<ans<<endl;
    return 0;
}
/*
hack:
4
1 2 2 3
*/