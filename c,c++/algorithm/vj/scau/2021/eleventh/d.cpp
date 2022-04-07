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
int cas  = 0;
void sol(){
    int n;
    cin>>n;
    vector<int>w(n),p(n);
    fori(i,0,n)cin>>w[i];
    fori(i,0,n)cin>>p[i];
    sort(ALL(w));
    sort(ALL(p));
    int ans = 1;
    cout<<"Case "<<++cas<<": ";
    fori(i,0,n){
        //int pos = 0;
        auto it = lower_bound(w.begin(),w.end(),p[i]);
        int cap = 0, pos;
        if(it==w.end()){
           // debug("no1");
            cap = n - i;
        }
        /*else if(it == w.begin()){
            cap = 1;
            if(*it>p[i] || i > 0){
                cout<<0<<endl;
                return ;
            }
        
        }
        */else {
            //debug("no2");
            if(*it == p[i]){
                it = upper_bound(w.begin(),w.end(),p[i]);
                //cout<<i<<' ';
               // debug(*it);
                if(it == w.end())it--;//都是相等的
            }
            pos = it-w.begin();
            if(*it > p[i])pos--;
            cap = pos - i + 1;
            if(cap<=0){
                cout<<0<<endl;
                return ;
            }
        }
        //cap = pos - i+1;
        ans = (LL)ans*cap%mod;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin>>tt;
    while(tt--)sol();
   /*
    vector<int>a(3,0);
    a[0] = a[1] = a[2] = 3;
    auto it = upper_bound(a.begin(),a.end(),4);
    //找不到输出0 and it->a.end();
     cout<<*it<<endl;
    if(it == a.end())cout<<"YES"<<endl;
    */
    return 0;
}
/*
hack:
1
3
7 7 7
7 7 7
hack2:
1
1
7
6
hack3:
1
3
7 7 8
7 7 8
*/