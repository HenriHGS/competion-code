#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5+10, M = 2*N;
template<typename T> void read(T& x){
    x = 0;
    char ch = getchar(); int f = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    if(f) x = -x;
   // return f ? -x : x;
}
int f[N][20];
ll d[N][20];
int logn[N];
int n;
ll val[N];
int e[M], ne[M], h[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int q[N], dep[N];
const int mod = 1e9+7;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
void bfs(int u){
    memset(dep,0x3f, sizeof dep);
    q[0] = u;
    int hh = 0, tt = 0;
    dep[0] = 0, dep[u] = 1;
    while(hh <= tt){
        u = q[hh++];
        for(int i = h[u];~i; i = ne[i]){
            int ver = e[i];
            //cout<<"ver:"<<ver<<endl;
            if(dep[ver] > dep[u] + 1){
                dep[ver] = dep[u] + 1;
                q[++tt] = ver;
                f[ver][0] = u;
                d[ver][0] = gcd(val[ver], val[u]);
                for(int k = 1; k <= 19; k ++ ){
                    int anc = f[ver][k-1];
                    f[ver][k] = f[anc][k-1];
                    d[ver][k] = gcd(d[ver][k-1], d[anc][k-1]);
                }
            }
        }
    }
}
void init(){
    logn[1] = 0;
    for(int i = 2; i < N; i ++ )logn[i] = logn[i/2] + 1;
    memset(h,-1,sizeof h);
    read(n);
    for(int i = 1; i <= n; i ++ ) read(val[i]);
    for(int i = 1; i <= n - 1; i ++ ){
        int a, b;
        read(a), read(b);
        add(a,b); add(b,a);
    }
    bfs(1);
}
ll get(int x, int dist){
    //int dist = r - l;
    ll res = 0;
    for(int k = 19; k >= 0; k -- ){
        if( (1<<k) <= dist){
            dist -= (1<<k);
            res = gcd(res, d[x][k]);
            x = f[x][k];
        }
    } 
    return res;
}
int cal(int x){
    int res = 0;
    //int ed = dep[x], st;
    //if(ed == 1) return val[x]%mod;
   // st = ed;
    //cout<<"x:"<<x<<endl;
    /* auto check = [&](int x, int dist1, int dist2){
        return get(x,dist1) == get(x,dist2);
    }; */
    ll now = val[x];
    while(x){
        int pre = x;
        for(int k = 19; k >= 0; k -- ){
            if(gcd(now,d[x][k]) == now) x = f[x][k];
        }
        x = f[x][0];
        res = (res + 1ll*now%mod*(dep[pre] - dep[x]) %mod) %mod;
        now = gcd(now,val[x]);
    }
   /*  while(st >= 1){
        //cout<<"st:"<<st<<endl;
        int L = 1, R = st - 1, ans = 0;
        while(L <= R){
            int mid = L + R >> 1;
            if(check(x, ed - st, ed - st + mid)) ans = mid, L = mid + 1;
            else R = mid - 1;
        }
        res = (res +  1ll*get(x,ed - st)%mod*(ans +1)%mod ) % mod;
        st = st - (ans + 1);
        //st = - 1;
    }
    res = (res + val[x])%mod; */
    return res;
}
int main(){
    init();
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) ans = (ans + cal(i)) % mod;
    printf("%d\n", ans);
    return 0;
}
