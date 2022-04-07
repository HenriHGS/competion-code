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

const int maxn = 2e5 + 6;



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    int k; cin>>k;
    int n = s.size();
    s = " " + s;
    vector<int> pre(n+1), suf(n+2, n + 1);
    for(int i = 1; i <= n; i ++ ){
        if(s[i] == 'X') {
            if(pre[i-1] == 0) pre[i] = i;
            else pre[i] = pre[i-1];
        }
    }
    for(int i = n; i >= 1; i -- ){
        if(s[i] == 'X') {
            if(suf[i+1] == n + 1) suf[i] = i;
            else suf[i] = suf[i+1];
        }
    }
    pre[0] = 1, suf[n+1] = n;
    vector<int> pos;
    for(int i = 1; i<= n; i ++ ) if(s[i] != 'X') pos.push_back(i);
    if(k == 0){
        pos.push_back(0);
        pos.push_back(n+1);
        sort(ALL(pos));
        int ans = 0;
        for(int i = 1; i < pos.size(); i ++ ){
            ans = max(ans, pos[i] - pos[i-1] - 1);
        }
        cout<<ans<<endl;
        return 0;
    }
    if(pos.size() <= k){
        cout<<n<<endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i + k <= pos.size(); i ++ ){
        int l = pre[pos[i]-1], r = suf[pos[i + k - 1] + 1];
        if(l == 0 && r != n + 1) ans = max(ans, r - pos[i] + 1);
        if(r == n + 1 && l ) ans = max(ans, pos[i + k - 1] - l + 1);
        if(r == n + 1 && l == 0) ans = max(ans, pos[i + k - 1] - pos[i] + 1);
        if(l && r != n + 1) ans = max(ans, r - l + 1);
        /* if(ans == 12) cout<<"wa:"<<pos[i]<<endl;
        if(i == 3) {
            cout<<"l:"<<l<<", r:" <<r<<endl;
            //cout<<pos[i + k - 1]<<endl;
            //cout<<suf[10]<<endl;
        } */
    }
    cout<<ans<<endl;
    return 0;
}