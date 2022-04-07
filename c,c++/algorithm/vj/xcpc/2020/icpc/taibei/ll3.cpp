#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
#include <numeric>
#include <stack>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const ll mod = 1000000007;
const ll INF  = 1e18;
const double eps = 0.000000001;
#define dprint(v) cerr << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it,v) for(typeof(v.begin()) it=v.begin();it!=v.end();++it)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define fst first
#define snd second

class unionFindPC {
public:
    unionFindPC(int n);
    int find(int i); // pre, el nodo está
    void unite(int s, int t);
private:
    vector<int> set; //en la posición de cada elemento está su padre
    vector<int> peso; //peso
};

unionFindPC::unionFindPC(int n) {
    set = vector<int> (n);
    peso = vector<int> (n, 1);
    for(int i = 0; i< n; i++){
        set[i] = i; // al principio cada uno es su propio padre
    }
}

int unionFindPC::find(int i) {
    if(set[i] != i)
        set[i] = find(set[i]);
    return set[i];
}

void unionFindPC::unite(int s, int t) {
    int i = find(s);
    int j = find(t);
    if (i == j) return;
    if (peso[i] <= peso[j]) swap(i, j);
    set[j] = i;
    peso[i] += peso[j];
    peso[j] = 1;// técnicamente no hace falta ponerlo, por invariante el peso me importa solamente en las raíces
}

const int N = 1e5, M = 1e5;

vvpi g; //g[v] tiene pares {vecino, id de la arista}
vi prof,lo;
int bridges,artis;

unionFindPC uf(0);

void dfs(int v, int idp, int d){
    prof[v] = lo[v] = d;

    bool es_arti = false;
    int hijos = 0;
    int u,id;
    for(auto e : g[v]){
        tie(u,id) = e;
        if(id == idp) continue;
        if(prof[u] == -1) {
            dfs(u,id,d+1);
            mini(lo[v],lo[u]);
            if(idp != -1 and lo[u] < prof[v]) uf.unite(idp,id);
            if(lo[u] > prof[v]) bridges++;
            if(lo[u] >= prof[v]) es_arti = true;
            hijos++;
        }
        else {
            mini(lo[v],prof[u]);
            if(prof[u] < prof[v]) uf.unite(idp,id);
        }
    }
    if(es_arti) artis++;
    if(idp == -1 and hijos == 1) artis--;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

void i(){
    artis = bridges = 0;
    int n,m;
    cin>>n>>m;
    uf = unionFindPC(m);
    g = vvpi(n);
    prof = vi(n,-1);
    lo = prof;

    int u,v;
    F0(i,m){
        cin>>u>>v;
        u--, v--;
        g[u].pb({v,i});
        g[v].pb({u,i});
    }

    dfs(0,-1,0);

    map<int,int> dp;
    F0(i,m) dp[uf.find(i)]++;
    int p = dp.size();
    int q = 0;
    for(auto it : dp) maxi(q,it.second);

    int g = gcd(p,q);
    p /= g, q /= g;
    cout<<artis<<' '<<bridges<<' '<<p<<' '<<q<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) i();
    return 0;
}