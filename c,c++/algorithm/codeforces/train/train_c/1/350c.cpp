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

struct Point {
    int x, y;
    int dis;
    void getdis(){
        dis = abs(x-0) + abs(y-0);
    }  
    bool operator < (const Point& a)const {
        return dis < a.dis;
    }
} p[maxn];
const char LR[] = "LR";
const char DU[] = "DU";
struct Qury{
    string dir;
    int op;
    int k;
};
void sol(){
    int n;
    cin>>n;
    For(i,1,n){
        cin>>p[i].x>>p[i].y;
        p[i].getdis();
        //debug(p[i].dis);
    }
    sort(p + 1, p + 1 + n);
    //cout<<n*6<<endl;
    vector<Qury>ans;
    For(i,1,n){
        int dis1 = p[i].x - 0;
        int dis2 = p[i].y - 0;
        int id1 = 0, id2 = 0;
        Qury tmp;
        if(dis1 > 0)id1 = 1;
        if(dis2 > 0) id2 = 1;
        if(dis1){
            tmp.dir = LR[id1];
            tmp.k = abs(dis1);
            tmp.op = 1;
            ans.pb(tmp);
        } 
        if(dis2){
            tmp.dir = DU[id2];
            tmp.k = abs(dis2);
            tmp.op = 1;
                ans.pb(tmp);
        }
        tmp.op = 2;
        ans.pb(tmp);
        id1 = 1 - id1; id2 = 1 - id2;
        if(dis1){
            tmp.dir = LR[id1];
            tmp.k = abs(dis1);
            tmp.op = 1;
            ans.pb(tmp);
        } 
        if(dis2){
            tmp.dir = DU[id2];
            tmp.k = abs(dis2);
            tmp.op = 1;
            ans.pb(tmp);
        }
        tmp.op = 3;
        ans.pb(tmp);
    }
    cout<<sz(ans)<<endl;
    fori(i,0,sz(ans)){
        if(ans[i].op == 1){
            cout<<ans[i].op<<' '<<ans[i].k<<' '<<ans[i].dir<<endl;
        }else cout<<ans[i].op<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}