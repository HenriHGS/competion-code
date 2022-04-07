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

const int maxn = 2e5 + 5;
set<int> gif;
vector<int> v[maxn];
void sol(){
    int n;
    cin>>n;
    For(i,1,n)v[i].clear();
    gif.clear();
    For(i,1,n)gif.insert(i);
    vector<int>col(n+1);
    vector<int>a(n+1);
    For(i,1,n){
        int x;
        cin>>x;
        a[i] = x;
        col[x]++;
       // cin>>x;
        v[x].pb(i);
        if(gif.find(x) != gif.end())gif.erase(gif.find(x));
    }
    vector<int>ans(n+1);
    int cnt = n - sz(gif);
    For(i,1,n){
        if(col[a[i]] == 1)ans[i] = a[i];
        else {
            col[a[i]]--;
            ans[i] = *gif.rbegin();
            int x = *gif.rbegin();
            gif.erase(gif.find(x));
        }
    }
    //check
    For(i,1,n){
        if(ans[i] == i){
            int co = a[i];
            fori(j,0,sz(v[co])){
                if(v[co][j] != i){
                    swap(ans[i],ans[v[co][j]]);
                    break;
                }
            }
        }
    }
    /*
    For(i,1,n){
        if(v[i].empty())continue;
        if(v[i].size() == 1)continue;
       // ans[v[i][0]] = i;
       // cnt++;
        auto& vt = v[i];
        for(int j = 0; j < sz(vt); j ++ ){
            ans[vt[j]] = *gif.begin();
            gif.erase(gif.begin());
        }
    }
    For(i,1,n){
        if(v[i].empty())continue;
        if(v[i].size() == 1)continue;
        ans[v[i][0]] = i;
        cnt++;
        auto& vt = v[i];
        for(int j = 1; j < sz(vt); j ++ ){
            ans[vt[j]] = *gif.begin();
            gif.erase(gif.begin());
        }
    }
    For(i,1,n)if(ans[i] == 0){
        ans[i] = *gif.begin();
        gif.erase(gif.begin());
    }*/
    cout<<cnt<<endl;
    For(i,1,n)cout<<ans[i]<<' ';
    cout<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}