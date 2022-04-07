#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
typedef long long LL;
typedef long long ll;
ll ans = 0;
bool st[N + 1];
int primes[N], tot;
vector<int> fpr[N+1];
void init(){
    for(int i = 2; i <= N; i ++){
        if(!st[i]) primes[tot++] = i;
        for(int j = 0; primes[j] <= N/i;j ++ ){
            st[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    fori(i,0,tot){
        int pr = primes[i];
        for(int j = pr; j <= N; j += pr) fpr[j].pb(pr);
    }
}
int n;
int a[N]; 
vector<int> pos[N];
void sol(){
    init();
    scanf("%d", &n);
    For(i,1,n){
        scanf("%d", &a[i]);
        //divide
        auto& p = fpr[a[i]];
        for(auto&x: p){
            pos[x].pb(i);
        }
    }
    fori(pr,0,tot){
        int i = primes[pr];
        if(pos[i].size() == 0) continue;
        for(int j = 1; j < pos[i].size(); j  ++ ){
            int cur = pos[i][j] - pos[i][j - 1];
            ans += 1LL*cur*pos[i][j-1];
        }
        if(pos[i].size() >= 1) ans += 1LL*(n - pos[i].back() + 1)*pos[i].back(); 
    }
    printf("%lld\n", ans);
}

int main(){
    sol();
    return 0;
}