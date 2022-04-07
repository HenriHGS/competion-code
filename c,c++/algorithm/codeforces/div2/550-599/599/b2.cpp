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

void sol(){
    int n;
    string s, t;
    cin>>n>>s>>t;
    vector<pa>ans;
    bool ok = true;
    fori(i,0,n){
        if(s[i] != t[i]){
            int sp = -1;
            fori(j,i+1,n){
                if(s[j] == s[i]) {
                    sp = j;
                    ans.pb({j,i});
                    swap(t[i],s[j]);
                }else if(t[j] == t[i]){
                    sp = j;
                    ans.pb({i,j});
                    swap(s[i],t[j]);
                }else if(s[i] == t[j]){
                    sp = j;
                    ans.pb({j,j});
                    swap(s[j],t[j]);
                    ans.pb({j,i});
                    swap(t[i],s[j]);
                }else if(t[i] == s[j]){
                    sp = j;
                    ans.pb({j,j});
                    swap(s[j],t[j]);
                    ans.pb({i,j});
                    swap(s[i],t[j]);
                }
                if(sp != -1) break;
            }
            if(sp == -1){
                cout<<"No"<<endl;
                return ;
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<sz(ans)<<endl;
    for(auto x: ans)cout<<x.fi+1<<' '<<x.se+1<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}