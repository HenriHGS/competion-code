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

void sol(){
    LL n, p;
    cin>>n>>p;
    vector<int>ans;
    auto check = [&](LL x,LL tot){
        LL cur = __builtin_popcountll(x);
        /*
         if(tot == 4) {
            debug(x);
            debug(cur);
        }
        */
        vector<LL>have(64,0);
        int i = 1;
        while(x){
            have[i] += x%2;
            x /= 2;
            i++;
        }
        if(cur > tot) return false;
        if(cur == tot) return true;
        for(i = 60; i >= 2; i -- ){
            LL add = min(tot - cur,have[i]);
            /*
            if(i == 5 && tot == 4){
                debug(add);
                debug(cur);
                debug(have[i]);
            }
            */
            have[i - 1] += add*2;
            cur += add;
            if(tot == cur) return true;
        }
        return false;
    };
    For(i,1,40){
        LL nn = n - i*p;
        if(nn < 0)continue;//
        //这里解释下为什么没特判都可以ac，因为我是开的longlong，所以
        //假如是负数的话，那么肯定很大。
        //而且在check里，%完之后还是负数。所以cur只会越来越小。
        if(check(nn,i)){
            cout<<i<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
  //  int cnt = __builtin_popcount(-1);
   // debug(cnt);
    //debug(-1%2);
   // debug(-2%2);
    return 0;
}