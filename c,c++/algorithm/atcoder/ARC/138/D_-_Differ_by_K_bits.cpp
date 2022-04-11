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
#include <bitset>
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

// const int maxn = 100000 + 6;

const int maxn = 1<<20;
int n, k;
bool no(){
    if(k%2==0) {
        cout<<"No"<<endl;
        return true;
    }   
    if(n > 1 && n == k) {
        cout<<"No"<<endl;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if(no()) return 0;

    vector<int> a, t(n);
    for (int x = 0; x < (1 << n); x++) {
       if (__builtin_popcount(x) == k) {
            int y = x;
            for (int i = 0; i < n; i++) {
                if (y >> i & 1) {
                    if (t[i]) {
                        y ^= t[i];
                    } else {
                        t[i] = y;
                        a.push_back(x);
                        break;
                    }
                }
            }
       }
    }
    /* for(auto x: t) cout<<bitset<8>(x)<<endl;
    cout<<endl;
    for (int i= n - 1;i>=0;i--)
        for (int j=i-1;j>=0;j--)
            if (t[i]&(1LL<<j))
                t[i]^=t[j];
    // for(auto x: a) cout<<bitset<8>(x)<<endl;
    // cout<<endl;
    for(auto x: t) cout<<bitset<8>(x)<<endl;
    cout<<endl; */
    cout<<"Yes"<<endl;
    int s = 1<<n;
    for(int i = 0; i < s; i ++  ) {
        int v = i^(i>>1);
        int y = 0;
        for(int j = 0; j < n; j ++ ) 
            if(v&1<<j) y ^= a[j];
        cout<<y<<" \n"[ i == (1<<s)-1];
    }
    return 0;
}