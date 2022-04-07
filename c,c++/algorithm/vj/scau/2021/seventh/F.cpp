/*
一开始以为读错题了，其实没读错。
是少了一个循环而已。
从一个点到其他点，可以借助中间点到达

*/
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

int ta[26][26];
void sol(){
    string s[2];
    //string t[2];
    int n;
    fori(i,0,2)cin>>s[i];
    cin>>n;
    fori(i,0,26)fori(j,0,26)ta[i][j] = i==j?0:inf;
    int w;
    For(i,1,n){
        char ch[2];
        fori(j,0,2)cin>>ch[j];
        // w;
        cin>>w;
        ckmin(ta[ch[0]-'a'][ch[1]-'a'],w);
    }
   // debug(w);
    if(sz(s[0]) != sz(s[1])){
        cout<<-1<<endl;
        return ;
    }
    fori(k,0,26)fori(i,0,26)fori(j,0,26) ta[i][j] = min(ta[i][j], ta[i][k] + ta[k][j]);
   // t[0] = t[1] = "";
    int len = sz(s[0]);
    LL ans = 0;
    string t ="";
    fori(i,0,len){
        if(s[0][i] != s[1][i]){
            int ch1 = s[0][i]-'a';
            int ch2 = s[1][i]-'a';
            bool ok = false;
            int add = inf;
            int opp = 0;
            fori(j,0,26){
                int op = j;
                int x1 = ta[ch1][op], x2 = ta[ch2][op];
                if(ta[ch1][op]== inf || ta[ch2][op] == inf) continue;
                //ckmin(add,x1+x2);
                if(add > x1+x2){
                    add = x1+x2;
                    opp = j;
                }
                ok = true;
            }
            if(!ok){
                cout<<-1<<endl;
                return ;
            }
            ans += add;
            t+=('a'+opp);
        }else t+=s[0][i];
    }
    cout<<ans<<endl;
    cout<<t<<endl;
}

//#define LOCAL
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
freopen("in.txt", "r", stdin);
#endif // LOCAL
    sol();
    return 0;
}
