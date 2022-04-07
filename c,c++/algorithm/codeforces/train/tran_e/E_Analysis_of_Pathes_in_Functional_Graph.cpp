#include <cstdio>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 1e5+10;
int fa[N][36];//35
ll w[N][36], mi[N][36];
ll n, m;
void bei(){
    For(k,1,35){
        fori(i,0,n){
            int anc = fa[i][k-1];
            fa[i][k] = fa[anc][k-1];
            mi[i][k] = min(mi[i][k-1], mi[anc][k-1]);
            w[i][k] = w[i][k-1] + w[anc][k-1];
        }
    }
}
void print(int x, ll k){
    ll ans1 = 0, ans2 = 1e9;
    for(int i = 35; i >= 0; i -- ){
        if(k>>i&1){
            ans1 += w[x][i];
            ans2 = min(ans2, mi[x][i]);
            x = fa[x][i];
        }
    }
    printf("%lld %lld\n", ans1,ans2);
}
int main(){
    scanf("%lld %lld", &n, &m);
    fori(i,0,n) scanf("%d", &fa[i][0]);
    fori(i,0,n){
        scanf("%lld", &w[i][0]);
        mi[i][0] = w[i][0];
    }
    bei();
    fori(i,0,n){
        print(i,m);
    }
    return 0;
}