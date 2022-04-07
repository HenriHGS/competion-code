#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <numeric>
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

const int maxn = 1e6 + 5;

void sol(){
    int n;
    cin>>n;
    vector<int>a(n), b(n);
    fori(i,0,n) cin>>a[i];
    fori(i,0,n) cin>>b[i];
    int ed = n - n/4;
    sort(ALL(a));
    sort(ALL(b));
    reverse(ALL(a));
    reverse(ALL(b));
    int sum1 = accumulate(a.begin(),a.begin()+ed,0);
    int sum2 = accumulate(b.begin(),b.begin()+ed,0);
    if(sum1>=sum2){
        cout<<0<<endl;
        return ;
    }
    int p = ed - 1, q = ed;
    int ans = 0;
    while(sum1 < sum2){
        ans++;
        int ned = n + ans - (n + ans)/4;
        if(ned > ed){
            sum1 += 100;
            //b
            if(q < n)sum2 += b[q],q++;
            ed = ned;
            continue;
        }
        if(p >= 0){
            sum1 -= a[p];
            p--;
            sum1 += 100; 
            //b
           // if(q < n)sum2 += b[q],q++;
        }
        /*
        else {
            sum1 += 100;
            if(q < n)sum2 += b[q],q++;
        }
        */
    }
    cout<<ans<<endl;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)
        sol();
    return 0;
}
/*
int sum = accumulate(ALL(b),0);
    int d = (sum2 - sum1 + 99)/100;
    int cnt = 0;
    debug(sum1);
    debug(sum2);
    int sed = ed;
    while(ed < n){
        cnt++;
        int nn = n + cnt;
        int ned = nn - nn/4;
        if(ned == ed){
            if(sed >= 0) sum1 -= a[sed], sed--;
            sum1 += 100;
            continue;
        } 
        sum2 += b[ed];
        ed = ned;
        sum1 += 100;
        if(sum1 >= sum2){
            cout<<cnt<<endl;
            return;
        }
    }
    debug(cnt);
    cout<<"after: sum1:"<<sum1<<"  sum2:"<<sum2<<endl;
    debug(d);
    n = n + cnt, d = (sum2 - sum1 + 99)/100;
    debug(d);
    int delt = -d + n/4;
    int L = 0, R = maxn, ans;
    while(L <= R){
        int mid = L + R>>1;
        int cur = mid + delt;
        int ch = (n + mid)/4;
        cout<<L<<' '<<R<<endl;
        if(cur >= ch) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    debug(ans);
    debug(n);
    cout<<ans + cnt<<endl;
*/