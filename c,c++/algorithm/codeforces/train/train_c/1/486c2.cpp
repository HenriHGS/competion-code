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
int chg(char a, char b){
    int res = abs(a-b);
    return min(res,26-res);
}
void sol(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    s = " " + s;
    int mid = (n+1)/2;
    vector<int>pos, hal;
    LL ans1 = 0;
    vector<int> vis(n+1);
    For(i,1,mid){
        if(s[i]!=s[n-i+1]) {
            hal.pb(i);
            pos.pb(i);
            pos.pb(n-i+1);
            ans1 += chg(s[i], s[n-i+1]);
            vis[i] = vis[n-i+1] = 1;
        }
    }
    //debug(ans1);
    sort(ALL(pos));
    if(sz(hal) == 1){
        cout<<(ans1+min(abs(pos[0]-m), abs(pos[1] - m)))<<endl;
        return;
    }
    int ans2 = inf;
    for(int i = 0; i < sz(pos); i ++ ){
        int dis1 = 0, dis2 = 0;
        dis1 = abs(m-pos[i]);
        if(i == 0)dis1 += hal.back()-pos[0];
        else if(i == sz(pos)/2) dis1 += pos.back() - pos[i];
        else if(i < sz(pos)/2) dis1 += abs((n - pos[i-1] + 1) - pos[i]);
        dis2 = abs(m-pos[i]);
        if(i == sz(pos)/2-1) dis2 += pos[i] - pos[0];
        else if(i == sz(pos) - 1) dis2 += hal.back()-pos[0];
        else if(i < sz(pos)/2 - 1) dis2 += pos[i] + hal.back() - 1;
        else dis2 += pos[i] - pos[0];
        debug(dis1);
        debug(dis2);
        ckmin(ans2,dis1);
        ckmin(ans2,dis2);
    }
    ans1 += ans2;
    cout<<ans1<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}
