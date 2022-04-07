#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <map>
#define For(i,x,y) for(int i=(x); i<=(y); i++)
#define fori(i,x,y) for(int i=(x); i<(y); i++)
#define rep(i,y,x) for(int i=(y); i>=(x); i--)
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define sz(a) (int)a.size()
#define ALL(x) x.begin(),x.end()
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

const db eps = 1e-8;
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

int cal(LL x){
    if(x == 0) return 1;
    int res = 0;
    while(x){
        res++;
        x >>= 1;
    }
    return res;
}

int tot(LL x){
    if(x == 0) return 0;
    int res = 0;
    while(x){
        if(x%2)res++;
        x >>= 1;
    }
    return res;
}

void sol(){
    LL l, r;
    cin>>l>>r;
    int cnt1, cnt2;
    cnt1 = cal(l), cnt2 = cal(r);
   // debug(cnt1);
    //debug(cnt2);
    if(l == r) cout<<l<<endl;
    else if(cnt1 != cnt2){
        LL ans = 0;
        fori(i,0,cnt2-1){
            ans +=(LL)1<<i;
        }
        ll tmp = ans<<1;
        if(tmp+1 == r)ans = tmp+1;
        cout<<ans<<endl;
    }else {
        LL ans = 0;
        rep(i,cnt1-1,0){
            if( ((l>>i)&1)  == ((r>>i)&1)){
                if((l>>i)&1)ans += (LL)1<<i;
            }else {
              //  debug((int)(l>>i));
               // debug((int)(r>>i));
                ///出现不等
                LL b = 0;
                For(j,0,i){
                    b += (((LL)1<<j)&r);
                }
                //debug(i);
                //debug(b);
               int num = tot(b);
               if(num > i){
                    cout<<r<<endl;
                    return ;
               }else {
                   b = 0;
                   fori(j,0,i){
                        b+=(LL)1<<j;
                   }
                  // debug(b);
                    ans += b;
                    cout<<ans<<endl;
                return ;
               }
                break;
            }
        }
    }
}

//#define LOCAL
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
freopen("in.txt", "r", stdin);
#endif // LOCAL
    int tt;
    cin>>tt;
    while(tt--)sol();
    return 0;
}