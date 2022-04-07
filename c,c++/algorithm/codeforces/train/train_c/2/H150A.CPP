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

//质数，输出
//1
//0
//两个质因子
//2
void sol(){
    ll x;
    cin>>x;
    LL ans = 1, cot = 0, pre = x;
    vector<LL>pri, pri_num;
    for(int i = 2; i <= x/i; i ++ ){
        if(x % i == 0){
            int cnt = 0;
            pri.pb(i);
            //cot++;
            //if(cot <= 2)ans *= i;
            while(x%i==0){
                x /= i;
                cnt++;
            }
            pri_num.pb(cnt);
        }
    }
    if(x > 1){
        pri.pb(x);
        pri_num.pb(1);
    }
    int cnt = 0;
    fori(i,0,sz(pri)){
       // debug(pri_num[i]);
        for(int j = 0; cnt < 2 && j < pri_num[i]; j ++ ){
            ans *= pri[i];
            cnt++;
        }
    }  
    //cout<<ans<<endl;
    //debug(ans);
    if(pre == 1 || sz(pri) == 1 && cnt == 1)cout<<1<<'\n'<<0<<'\n';
    else if(cnt == 2 && ans != 1 && ans != pre)cout<<1<<'\n'<<ans<<'\n';
    else cout<<2<<'\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}