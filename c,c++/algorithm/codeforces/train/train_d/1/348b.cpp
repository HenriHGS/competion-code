#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define pb push_back
#define sz(a) (int)a.size()
#define debug(a) cout<<#a<<": " <<a<<endl
#define mst(x,a) memset(x,a,sizeof(x))
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10;
int n;
vector<int>e[maxn];
LL msum[maxn], a[maxn], d[maxn];
LL gcd(LL a, LL b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a, LL b){
    return a/gcd(a,b)*b;
}
LL ans;
void out(){
    cout<<ans<<endl;
    exit(0);
}
void dfs1(int u, int fa){
    if(sz(e[u]) == 1 && u != 1) {
        d[u] = 1;
        msum[u] = a[u];
        return ;//msum[u] = a[u];
    }
    msum[u] = 0;
    d[u] = 1;
    for(auto v: e[u]){
        if(fa == v) continue;
        dfs1(v, u);
        msum[u] +=  msum[v];//dfs1(v);
        d[u] = lcm(d[u],d[v]);
        if(d[u] > ans)out();
    }
    int k = sz(e[u]);
    if(u != 1)k--;
    d[u] = k*d[u];
    return ;//msum[u];
}
void dfs2(int u, int fa){
    LL mi = INF;
    LL sum = 0;
    if(sz(e[u]) == 1 && u != 1) return;
    for(auto v: e[u]){
        if(fa == v) continue;
        dfs2(v,u);
        mi = min(mi,msum[v]);
        sum += msum[v];
    }
    int k = sz(e[u]);
    if(u != 1) k--;
    LL t = d[u]/k;
    t = mi/t*t;
    ans += sum - t*k;
    /*
    if(sum - t*k > 0) {
        cout<<"u = "<<u<<endl;
        cout<<"sum - t*k = "<<sum-t*k<<endl;
        cout<<"d[u] = "<<d[u]<<endl;
        debug(t);
        debug(k);
    }
    */
    msum[u] = t*k;
}
void sol(){
    cin>>n;
    For(i,1,n)cin>>a[i], ans += a[i];
    fori(i,1,n){
        int x, y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs1(1,-1);
    ans = 0;
    dfs2(1,-1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    sol();
    return 0;
}