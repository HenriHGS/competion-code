#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
int l[N], r[N];
int n, lx[N*2], tot;
void init(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) {
        scanf("%d %d",&l[i], &r[i]);
        lx[++tot] = l[i]; lx[++tot] = r[i];
    }
    sort(lx + 1, lx + 1 + tot);
    tot = unique(lx + 1, lx + 1 + tot) - (lx + 1);
    For(i,1,n){
        l[i] = lower_bound(lx +1, lx + 1 + tot, l[i]) - lx;
        r[i] = lower_bound(lx + 1, lx +1+tot, r[i]) - lx;
    }
}
int main(){
    init();
    return 0;
}