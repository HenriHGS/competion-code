#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include <queue>
#include<sstream>
#include <stack>
#include <set>
#include <bitset>
#include<vector>
#define FAST ios::sync_with_stdio(false)
#define abs(a) ((a)>=0?(a):-(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mem(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,n,a) for(int i=n;i>=a;--i)
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int maxn = 1e5+200;
const int inf=0x3f3f3f3f;
const double eps = 1e-7;
const double pi=acos(-1.0);
const int mod = 1e9+7;
inline int lowbit(int x){return x&(-x);}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y){if(!b){d=a,x=1,y=0;}else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}}//x=(x%(b/d)+(b/d))%(b/d);
inline ll qpow(ll a,ll b,ll MOD=mod){ll res=1;a%=MOD;while(b>0){if(b&1)res=res*a%MOD;a=a*a%MOD;b>>=1;}return res;}
inline ll inv(ll x,ll p){return qpow(x,p-2,p);}
inline ll Jos(ll n,ll k,ll s=1){ll res=0;rep(i,1,n+1) res=(res+k)%i;return (res+s)%n;}
inline ll read(){ ll f = 1; ll x = 0;char ch = getchar();while(ch>'9'||ch<'0') {if(ch=='-') f=-1; ch = getchar();}while(ch>='0'&&ch<='9') x = (x<<3) + (x<<1) + ch - '0',  ch = getchar();return x*f; }
int dir[4][2] = { {1,0}, {0,-1},{0,1},{-1,0} };

string L[50];
string R[50];
int n,m;
ll Map[500];


typedef struct Pos
{
    ll x1;
    ll y1;
    ll x2;
    ll y2;
    void init(int xx1, int yy1, int xx2, int yy2)
    {
        x1 = xx1, x2 = xx2, y1 = yy1, y2 = yy2;
    }
}P;
P d[30][30][30][30];
int f[30][30][30][30];
int vis[30][30][30][30];

bool check(int x, int y, string X[])
{
     if(x<1||x>20||y<1||y>20||X[x][y]=='#') return false;
     return true;
}

void bfs()
{
    queue<P> q;
    P tmp;
    tmp.x1 = 20, tmp.y1 = 20, tmp.x2 = 20, tmp.y2 = 20;
    vis[20][20][20][20] = 1;
    q.push(tmp);
    while(!q.empty())
    {
        P cur = q.front();
        q.pop();
        ll x1 = cur.x1, y1 = cur.y1, x2 = cur.x2, y2 = cur.y2;
        //q.pop();
        rep(i,0,3)
        {
            int xx1 = x1 + dir[i][0] ;
            int yy1 = y1 + dir[i][1];
            if(!check(xx1,yy1,L)) xx1 = x1, yy1 = y1;

            int xx2 = x2 + dir[i][0] ;
            int yy2 = y2 + dir[i][1];
            if(!check(xx2,yy2,R)) xx2 = x2, yy2 = y2;

            if(!vis[xx1][yy1][xx2][yy2])
            {
                tmp.x1 = xx1, tmp.y1 = yy1, tmp.x2 = xx2, tmp.y2 = yy2;
                q.push(tmp);
                d[xx1][yy1][xx2][yy2].init(x1,y1,x2,y2);
                vis[xx1][yy1][xx2][yy2] = 1;
                f[xx1][yy1][xx2][yy2] = i;
            }
        }
    }
}

int main()
{
    Map[0] = 'D';
    Map[1] = 'L';
    Map[2] = 'R';
    Map[3] = 'U';
    rep(i,1,20)
    {
        string s;
        cin>>s;
        L[i] = "?" + s;
        cin>>s;
        reverse(s.begin(),s.end());
        R[i] = "?" + s;
    }
   // d[20][20] = 1;
    bfs();
    int x1 = 1, y1 = 20, x2=1, y2 = 20;
    string ans;
    while(!((x1==20&&y1==20)&&(x2==20&&y2==20)))
    {
    //    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
        auto k = d[x1][y1][x2][y2];
        ans += Map[f[x1][y1][x2][y2]];
        x1 = k.x1;
        x2 = k.x2;
        y1 = k.y1;
        y2 = k.y2;
        cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    cout<<ans<<endl;

    return 0;
}