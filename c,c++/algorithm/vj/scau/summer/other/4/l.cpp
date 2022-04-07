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

const int maxn = 100000 + 6;
int a[maxn], b[maxn];
void sol(){
    int n, x;
    cin>>n>>x;
    For(i,1,n)cin>>a[i]>>b[i];//, b[i] = a[i] + b[i];
    LL ans = INF;
    int ans_h = 0;
    For(h,0,480){
        LL tmp = 0;
        For(i,1,n){
            int st = a[i];
            if(h >= a[i]) st = h;
            else st = (a[i] - h + x - 1)/x * x + h;

            if(a[i] + b[i] < st)continue;
            else {
                int rem = b[i] - (st - a[i]);
                tmp += (rem)/x + 1;
            }
            /*
            int cnt1 = (a[i] - h)/x;
            if(a[i] < h) cnt1 = 0;
            else cnt1++;
            int cnt2 = (b[i] - h)/x;
            if(b[i] < h)cnt2 = 0;
            else cnt2++;
            tmp += (cnt2 - cnt1);
            if(h == 0){
                debug(cnt1);
                debug(cnt2);
            }
        
           
            if(b[i] >= h)cnt2--;
            if(cnt2*x + h == b[i])tmp++;
            */
        }
        if(tmp < ans) {
            ans = tmp;
            ans_h = h;
        }
    }
    cout<<ans_h<< ' '<< ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}