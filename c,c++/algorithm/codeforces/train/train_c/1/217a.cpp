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

const int maxn = 1e3+2;
int n;
int vis[1000*1000+100];
int getId(int x, int y){
    return (x-1)*1000 + y;
}
struct Point{
    int x, y;
    int id;
}p[maxn];
//y
bool cmp1(Point&a, Point& b){
    if(a.x != b.x) return a.x < b.x;
    return a.y<b.y;
}
int fa[maxn*maxn];
void change(){
    For(i,1,n) swap(p[i].x,p[i].y);
}
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(){
    For(i,2,n){
        if(p[i-1].x == p[i].x){
            if(p[i-1].y == p[i].y)continue;
            int a = find(p[i-1].id), b = find(p[i].id);
            fa[a] = b;
        }
    }
}
void sol(){
    For(i,1,1000*1000) fa[i] = i;
    cin>>n;
    For(i,1,n){
        int x, y;
        cin>>x>>y;
        p[i] = {x,y,i};
    }
    sort(p+1, p + 1 + n, cmp1);
    merge();
    change();
    sort(p + 1, p + 1 + n,cmp1);
    merge();
    int ans = 0;
    For(i,1,n){
        int a = find(p[i].id);
        if(!vis[a])ans++;
        vis[a] = 1;
    }
    cout<<ans-1<<endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}