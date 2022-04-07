#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
const int MAX_LOG = 20;
int logn[N], d[N][MAX_LOG];
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
void init(){
    logn[1] = 0;
    fori(i,2,N) logn[i] = logn[i/2] + 1;
}
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int find(int l, int r){
    int s = logn[r - l + 1];
    return gcd(d[l][s], d[r - (1<<s) + 1][s]);
}
typedef long long ll;
int n;
map<int,ll> ans;
int main(){
    n = read();
    init();
    For(i,1,n) d[i][0] = read();
    fori(j,1,MAX_LOG){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++ ){
            d[i][j] = gcd(d[i][j-1], d[i + (1<<(j - 1))][j-1]);
        }
    }
    For(i,1,n){
        int l = i;
        int r1 = i, r2 = i;
        int gd = d[i][0];
        while(r1 <= n){
            int L = r1, R = n;
            while(L <= R){
                int mid = L + R >> 1;
                if(find(l,r1) == find(l, mid)) r2 = mid, L = mid + 1;
                else R = mid - 1;
            }
            gd = find(l,r1);
            ans[gd] += (r2 - r1 + 1);
            r1 = r2 + 1;
        }
    }
    int q = read();
    while(q--){
        int x = read();
        printf("%lld\n", ans[x]);
    }
    return 0;
}