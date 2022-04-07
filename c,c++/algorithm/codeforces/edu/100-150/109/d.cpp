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

const int maxn = 100000 + 6;

void sol(){
    int n;
    cin>>n;
    vector<int>a(n);
    fori(i,0,n)cin>>a[i];
    vector<int>sea;
    set<int>emp;
    fori(i,0,n){
        if(a[i] == 0)emp.insert(i);
        else sea.pb(i);
    }
    int ans = 0;
    fori(i,0,sz(sea)){
        auto posi = emp.lower_bound(sea[i]);
        int dis1 = inf;
        int dis2 = inf;
        if(posi==emp.end()){
            posi--;
            int d = *posi;
            dis1 = abs(d-sea[i]);
            ans += dis1;
        }else {
            if(posi!=emp.begin()){
                dis1 = abs(sea[i]-*posi);
                posi--;
                dis2 = abs(sea[i]-*posi);
                if(dis2 < dis1){
                    emp.erase(posi);
                    ans += dis2;
                }else {
                    posi++;
                    emp.erase(posi);
                    ans += dis1;
                }
            }else {
                int dis1 = abs(sea[i]-*posi);
                ans += dis1;
                emp.erase(posi);
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}