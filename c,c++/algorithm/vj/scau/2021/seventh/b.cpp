/*
这题写歪了。。。。。。。
不该加判环的。（判环写歪了xxx）
直接拓扑不香吗！！！！！！！！！！
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

const int maxn = 1e5+10;
int vis[maxn];
int n, k, sp[maxn];
int in[maxn];
vector<int>e[maxn];
vector<int>ans;
bool ok = true;
int cnt = 1;
void dfs(int x){
    //if(vis[x] == 0)ans.pb(x);
    vis[x] = cnt;
    for(auto v: e[x]){
        if(!vis[v])dfs(v);
       // else if(vis[v] == cnt){
         //   ok = false;
          //  return;
        //}
    }
}
void sol(){
    cin>>n>>k;
    For(i,1,k){
        int x;
        cin>>x;
        sp[x]++;
    }
    For(i,1,n){
        int num,x;
        cin>>num;
        in[i] += num;
        For(j,1,num){
            cin>>x;
           // in[x]++;

            e[i].pb(x);
            //e[x].pb(i);
        }
    }
    For(i,1,n){
        if(sp[i] && !vis[i])dfs(i),cnt++;
        if(!ok){
            cout<<-1<<endl;
            return ;
        }
    }
   // For(i,1,n)debug(vis[i]);
    For(i,1,n){
        for(auto v:e[i]){
            e[v].pb(i);
        }
    }
   //debug("o1");
    queue<int>que;
    For(i,1,n){
        if(vis[i]&&in[i] == 0){
           // debug(i);
            que.push(i);
        }
    }
    while(!que.empty()){
        int x = que.front();
        //debug(x);
        que.pop();
        ans.pb(x);
        if(sp[x])k--;
        for(auto v:e[x]){
            if(in[v]==0)continue;
            in[v]--;
            if(in[v]==0&&vis[v]){
                que.push(v);
            }
        }
    }
    //debug("ok");
   // debug(k);
    if(k){
        cout<<-1<<endl;
        return;
    }
   // reverse(ALL(ans));
    cout<<sz(ans)<<endl;
    for(auto x:ans)cout<<x<<' ';
    cout<<endl;
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
/*
4 1
4
1 2
1 3
1 1
1 1

4 1
4
1 2
1 3
1 1
0
*/
/*
hack
6 6
5 4 3 2 6 1
1 4
0
2 2 6
2 3 6
3 3 4 6
0
*/