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

const int maxn = 1e5 + 6;
int du[maxn];
int n,k;
vector<int>di[maxn];
void sol(){
    cin>>n>>k;
    int root = 0, mi = inf;
    For(i,1,n)cin>>du[i];
    bool ok = true;
    int mx = 0;
    For(i,1,n){
        if(du[i] < mi){
            mi = du[i];
            root = i;
        }    
        if(du[i] >= n){
            ok = false;
            cout<<-1<<endl;
            return ;
        }
        ckmax(mx,du[i]);
        di[du[i]].pb(i);
    }
    if(sz(di[0])<=0 || sz(di[0]) > 1){
        cout<<-1<<endl;
        return ;
    }
    int cnt = 0;
    queue<int>q;
    q.push(root);
   // debug(root);
    vector<pa>ans;
    For(i,1,mx){
       // debug(sz(di[i]));
       // debug(i);
        if(q.empty()||sz(di[i]) == 0){
            cout<<-1<<endl;
            return ;
        }
        vector<int>tmp;
        while(!q.empty())tmp.pb(q.front()), q.pop();
        int tot = sz(tmp);
        int cnt = 0, pt = 0;
        const vector<int> dmp = di[i];
        if(i!=1)cnt++;
        fori(j,0,sz(dmp)){
            if(cnt >= k){
                pt++;
                if(pt == tot){
                    cout<<-1<<endl;
                    return ;
                }
                cnt = 0;
                if(i!=1)cnt++;
            }
            ans.pb({tmp[pt],dmp[j]});
            q.push(dmp[j]);
            cnt ++ ;
        }
    }
    cout<<sz(ans)<<endl;
    fori(i,0,sz(ans))cout<<ans[i].fi<<' '<<ans[i].se<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}