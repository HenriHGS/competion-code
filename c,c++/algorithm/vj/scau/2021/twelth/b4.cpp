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
#include <unordered_map>
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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int maxn = 5e6+500;
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
inline ll read(){ ll x = 0;char ch = getchar();while(ch>'9'||ch<'0') ch = getchar();while(ch>='0'&&ch<='9') x = (x<<3) + (x<<1) + ch - '0',  ch = getchar();return x; }
int dir[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };

ll p[maxn];
unordered_map<ll,ll> Map;

int main()
{
    ll n = read();
    rep(i,1,n) scanf("%lld",&p[i]);
    ll cnt = 0;
    rep(a,1,n) rep(b,1,n) rep(c,1,n) rep(d,1,n) rep(e,1,n) rep(f,1,n)
    {
        if(p[d]&& (p[a]*p[b]+p[c])/p[d] - p[e] == p[f]&& (p[a]*p[b]+p[c])%abs(p[d])==0) cnt++;
    }
    cout<<cnt<<endl;
    /*
    cnt = 0;
    rep(i,1,n) rep(j,1,n) Map[p[i]+p[j]] ++;
    rep(a,1,n) rep(b,1,n) rep(c,1,n) rep(d,1,n)
    {
        if(p[d]&&((p[a]*p[b]+p[c])%abs(p[d])==0)&&Map[(p[a]*p[b]+p[c])/p[d]]) cnt+=Map[(p[a]*p[b]+p[c])/p[d]];
    }
    cout<<cnt<<endl;*/
    return 0;
}