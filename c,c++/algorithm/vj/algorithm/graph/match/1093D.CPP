#include <cstdio>
#include <cstring>
using namespace std;
const int N = 3e5+10, M = N*2;
typedef long long ll;
typedef long long LL;
int e[M], ne[M], h[N], idx;
int cnt[3];
int color[N];
const int mod = 998244353 ;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (ll)res*a%p;
        a = 1LL*a*a%p;
        k >>= 1;
    }
    return res;
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] =  idx++;
}
bool dfs(int x, int c, int fa){
    color[x] = c;
    cnt[c]++;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        if(!color[j]) {
            if(!dfs(j,3-c,x)) return false;
        }else if(color[j] == c) return false;
    }
    return true;
}
void sol(){
    for(int i = 0 ; i < idx; i ++ ){
        int a = e[i];
        h[a] = -1;
    }
    cnt[1] = cnt[2] = 0;
    idx = 0;
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i ++ ) color[i] = 0;
    while(m -- ){
        int a, b;
        scanf("%d %d", &a, &b);
        add(a,b);add(b,a);
    }
    bool bg = true;
    int ans = 1;
    for(int i = 1; i <= n; i++ ){
        if(!color[i]){
            cnt[1] = cnt[2] = 0;
            bg &= dfs(i,1,-1);
            int mul = qpow(2,cnt[1],mod) + qpow(2,cnt[2],mod);
            mul %= mod;
            ans = 1LL*ans*mul%mod;
        }
    }
    if(!bg)printf("%d\n",0);
    else {
       // int ans = qpow(2,cnt[1],mod);
      //  ans = ans + qpow(2,cnt[2],mod);
        printf("%d\n", ans%mod);
    }
}
int main(){
    memset(h,-1,sizeof h);
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}