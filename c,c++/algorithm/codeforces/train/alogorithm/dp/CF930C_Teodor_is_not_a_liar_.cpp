#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 1e5+10;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
struct Node{
    int l, r;
    int sum, lazy;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r){
    tr[u] = {l,r};
    if(l == r) return ;
    else {
        int mid = l + r >> 1;
        build(ls,l,mid); build(rs, mid + 1, r);
    } 
}
void pushup(int u){
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}
void pushdown(int u){
    if(tr[u].lazy){
        tr[rs].sum += (tr[rs].r - tr[rs].l + 1) * tr[u].lazy;
        tr[ls].sum += (tr[ls].r - tr[ls].l + 1) * tr[u].lazy;
        tr[rs].lazy += tr[u].lazy;
        tr[ls].lazy += tr[u].lazy;
        tr[u].lazy = 0;
    }
}
void mody(int u, int l, int r, int val){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].sum += (tr[u].r - tr[u].l + 1)*val;
        tr[u].lazy++;
    }
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) mody(ls,l,r,val);
        if(r > mid) mody(rs,l,r,val);
        pushup(u);
    }
}
int qury(int u, int x){
    if(tr[u].l == tr[u].r && tr[u].l == x){
      //  printf("xxxx l == r\n");
       // printf("tr[u].l = %d, tr[u].r = %d\n", tr[u].l, tr[u].r);
        return tr[u].sum;
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) return qury(ls,x);
        else return qury(rs,x);
    }
}
int n, m;
int h[N];
int f1[N], dp[N], f2[N];
int getMax(int *f){
    int len = 0;
    dp[0] = -1e9;
    for(int i = 1; i <= n; i ++ ){
        if(dp[len] <= h[i]) dp[++len] = h[i], f[i] = len;
        else {
            int wz = upper_bound(dp + 1, dp + 1 + len, h[i]) - dp;
            dp[wz] = h[i];
            f[i] = wz;
        }
    }
    return len;
}
int main(){
    m = read(), n = read();
    build(1,1,n);
    For(i,1,m){
        int l = read(), r = read();
        mody(1,l,r,1);
    }
    int ans = 0;
    For(i,1,n){
        //printf("qury(1,%d) = %d\n", i , qury(1,i));
        h[i] = qury(1,i);
    }
    /* int dif = 0;
    ans = n;
    For(i,2,n) dif |= h[i] != h[i-1]; */
    getMax(f1);
    reverse(h + 1, h + 1 + n); 
    getMax(f2);
    For(i,1,n){
        ans = max(ans, f1[i] + f2[n - i + 1] - 1);
    }
    printf("%d\n", ans);
    return 0;
}