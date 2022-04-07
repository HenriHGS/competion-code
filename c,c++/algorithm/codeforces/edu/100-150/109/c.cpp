#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
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

const int maxn = 300000 + 5;

struct Robot{
    int x, id;
    char dir;
    bool operator < (const Robot& a) const{
        return x < a.x;
    }
} rob[maxn];

void sol(){
    int n, m;
    cin>>n>>m;
    For(i,1,n)cin>>rob[i].x;
    For(i,1,n)rob[i].id = i;
    For(i,1,n)cin>>rob[i].dir;
    sort(rob+1,rob+1+n);
    int pre = 0;
    vector<int>ans(n,-1);
    //cal between
    stack<int>odd,even;
    For(i,1,n){
        if(rob[i].dir == 'L'){
            int idx = 0;
            if(rob[i].x%2==0){
                if(even.empty())continue;
                idx = even.top();
                even.pop();
            }else {
                if(odd.empty())continue;
                idx = odd.top();
                odd.pop();
            }
            int d = rob[i].x - rob[idx].x;
            ans[rob[i].id] = d;
            ans[rob[idx].id] = d;
        }else {
            if(rob[i].x%2==0)even.push(i);
            else odd.push(i);
        }
    }
    //cal LL && RR
    queue<Robot> qL,qR;
    For(i,1,n){
        int id = rob[i].id;
        if(ans[id] == -1){
            if(rob[i].dir == 'L')qL.push(rob[i]);
            else qR.push(rob[i]);
        }
    }
    while(!qL.empty()){
        auto fir = qL.front(); qL.pop();
        if(qL.empty())break;
        auto sec = qL.front();qL.pop();
        int id1 = fir.id, id2 = sec.id;
        ans[id1] = sec.x - fir.x;
    }
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}