#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 210, M = 5e4+10;
typedef long long ll;
struct Edge{
    int a, b, g, s;
    bool operator < (const Edge& x) const{
        return g < x.g;
    }
}e[M], T[M];
int n, m;
struct DSU{
    int fa[N];
    void init(){
        For(i,1,n) fa[i] = i;
    }
    int find(int a){
        if(fa[a] == a) return a;
        return fa[a] = find(fa[a]);
    }
    void merge(int a, int b){
        fa[a] = b;
    }
}dsu;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int G, S;
#include <iostream>
int main(){
    n = read(), m =read();
    G = read(), S = read();
    For(i,1,m){
        int a = read(), b = read(), g = read(),s = read();
        e[i] = {a,b,g,s};
    }
    int cnte = 0;
    sort(e + 1, e + 1 + m);
    ll ans = 2e18;
    For(j,1,m){
        cnte++;
        T[cnte] = e[j];
        for(int i = cnte; i >= 2; i -- ) if(T[i].s < T[i-1].s) swap(T[i],T[i-1]);
        int cntv = 0;
        dsu.init();
        auto& f = dsu.fa;
        int maxs = 0;
        For(i,1,cnte){
            int a = T[i].a, b = T[i].b;
            int fa = dsu.find(a), fb = dsu.find(b);
            if(fa != fb){
                dsu.merge(fa,fb);
                maxs = max(maxs, T[i].s);
                T[++cntv] = T[i];
            } 
        }
        if(cntv == n - 1) ans = min(ans, 1ll*S*maxs + 1ll*G*e[j].g);
        cnte = cntv;
    }
    if(ans == (ll)2e18) ans = -1;
    printf("%lld\n", ans);
    return 0;
}