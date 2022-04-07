#include <cstdio>
#include <cstring>
#include <map>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 3e5+10;
const int MX_LOG = 22;
int logn[N];
void init(){
    logn[1] = 0;
    fori(i,2,N) logn[i] = logn[i/2] + 1;
}
int n;
char s[N];
ll d[N][22];
ll find(int l, int r){
    int s = logn[r - l + 1];
    return d[l][s] | d[r - (1<<s) + 1][s];
}
int main(){
    scanf("%s", s + 1);
    init();
    n = strlen(s + 1);
    For(i,1,n) d[i][0] = 1ll<<(s[i] - 'a');
    fori(j,1,MX_LOG)
        for(int i = 1; i + (1<<j) - 1 <= n; i ++ )
            d[i][j] = d[i][j-1] | d[i + (1<<(j-1))][j-1];
    map<int,ll> ans;
    int mx = 0;
    For(i,1,n){
        int r2 = i, r1 = i, l = i;
        while(r1 <= n){
            int L = r1, R = n;
            while(L <= R){
                int mid = L + R >> 1;
                if(find(l,r1) == find(l,mid)) r2 = mid, L = mid + 1;
                else R = mid - 1;
            } 
            mx = max(mx,__builtin_popcountll(find(l,r2)));
            ans[__builtin_popcountll(find(l,r2))] += (r2 - r1 + 1);
            r1 = r2 + 1;
        }
    }
    printf("%d\n", mx);
    For(i,1,mx) printf("%lld\n", ans[i]);
    return 0;
}