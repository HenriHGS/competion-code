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

///@"/"
int n;
vector<vector<int> >pos(4);
bool check1(string s){
    ///pos(0)@
    ///pos(1)/
    ///pos(2)[
    ///pos(3)]
    fori(i,0,n){
        if(s[i] == '@')pos[0].pb(i);//cnt[0]++;
        else if(s[i] == '/')pos[1].pb(i);//cnt[1]++;
        else if(s[i] == '[')pos[2].pb(i);
        else if(s[i] == ']')pos[3].pb(i);
    }
    /*
    fori(i,0,4){
       // debug(sz(pos[i]));
        for(auto x: pos[i]) cout<<x<<' ';
        cout<<endl;
    }
    */
 ///   debug("check1111111111");
    fori(i,0,1){
        if(sz(pos[i])<=0)return false;
        if(sz(pos[i]) >1) return false;
    }
    ///debug("check222");
    if(sz(pos[1]) > 1) return false;
   // debug(1);
   /*
    if(sz(pos[1]) == 0 && (sz(pos[2]) || sz(pos[3]) ) )  return false;
 //   debug(2);
    if(sz(pos[2]) == 0  && sz(pos[3])) return false;
   // debug(3);
    if(sz(pos[2])  && sz(pos[3]) == 0) return false;
   // debug(4);
    if(sz(pos[2]) != sz(pos[3])) return false;
  //  debug(5);
    if(sz(pos[2]) > 1) return false;
    */
   // debug("check333");
    if(pos[0][0] == 0 )return false;
    /*
    if(sz(pos[2])){
            ///@ [
        if(pos[2][0] - pos[0][0] == 1)return false;
        /// [ and /
        if(pos[1][0]-pos[2][0]!=1)return false;
    /// / ]
        if(pos[3][0]-pos[1][0] == 1) return false;
        ///the last
        if(pos[3][0] != sz(s) - 1) return false;
    }else
    */
    if(sz(pos[1])){
        ///@ /
        if(pos[1][0] - pos[0][0] == 1)return false;
        /// the last
        if(pos[1][0] == sz(s) - 1) return false;
    }
    return true;
}
/*
mike@codeforces.com
*/
const string ans[]={"NO", "YES"};
void sol(){
    string s;
    getline(cin,s);
    n = sz(s);
    if(!check1(s)){
        cout<<ans[0]<<endl;
        return ;
    }
   // debug("waaaa1111111111");
    int i = 0;
    bool ok = true;
    ///@
    int tot = 0;
    for(i; i < n; i ++){
        if(s[i] == '@')break;
        ok &= (isdigit(s[i]) || isalpha(s[i]) || s[i] == '_');
        tot++;
    }
    if(!ok || tot >  16){
        cout<<ans[0]<<endl;
        return ;
    }
    /// [
    i++;
    bool fl = false;
    bool fl2 = false;
    if(sz(pos[1])) fl2 = true;
  //  if(sz(pos[2]))fl = true;
    int cnt = 0;
    tot = 0;
  //  debug("waaaa222");
    for(i; i < n ; i ++){
        if(s[i] == '/')break;
       // if(s[i] == '[' && fl)break;
        if(s[i] == '.'){
            if(cnt == 0 || cnt > 16){
                cout<<ans[0]<<endl;
                return ;
            }else {
                cnt = 0;
            }
        }else {
            cnt++;
            ok &= (isdigit(s[i]) || isalpha(s[i]) || s[i] == '_');
        }
        tot++;
        if(cnt>16){
            cout<<ans[0]<<endl;
            return ;
        }
    }
     if(!ok || tot >  32 || cnt == 0){
        cout<<ans[0]<<endl;
        return ;
    }
  //  debug("waaaa333");
    if(!fl2){
        cout<<ans[1]<<endl;
        return ;
    }
    /// i+1 = '\'
    i++;
    if(fl)i++;
    if(fl)n--;///the last is ']'
    tot = 0;
    for(i; i < n; i ++){
        ok &= (isdigit(s[i]) || isalpha(s[i]) || s[i] == '_');
        tot++;
    }
    if(!ok || tot >  16){
        cout<<ans[0]<<endl;
        return ;
    }
    cout<<ans[1]<<endl;
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