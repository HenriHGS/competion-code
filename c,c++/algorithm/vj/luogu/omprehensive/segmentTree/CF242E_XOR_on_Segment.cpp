#include <cstdio>
#include <cstring>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
struct Node{
    int l, r;
    int lazy, sum;
} tr[22][N<<2];
int a[N];
#define ls u<<1
#define rs u<<1|1
void pushup(int x, int u){
    auto &t = tr[x][u];
    t.sum = tr[x][ls].sum + tr[x][rs].sum;
}
void pushdown(int x, int u){
    if(tr[x][u].lazy){
        auto&t = tr[x][u], &l = tr[x][ls], &r = tr[x][rs];
        l.lazy ^= t.lazy;
        r.lazy ^= t.lazy;
        int llen = l.r - l.l + 1;
        int rlen = r.r - r.l + 1;
        r.sum = rlen - r.sum;
        l.sum = llen - l.sum;
        //l.sum ^= t.lazy, r.sum ^= t.lazy;
        t.lazy = 0;
    }
}
void build(int x, int u, int l, int r){
    tr[x][u] = {l,r};
    if(l == r) tr[x][u].sum = (a[l]>>x & 1);
    else {
        int mid = l + r >> 1;
        build(x,ls,l,mid);
        build(x,rs,mid+1,r);
        pushup(x,u);
    }
}
void mody(int x, int u, int l, int r){
    auto& t = tr[x][u];
    if(l <= t.l && t.r <= r){
        int len = t.r - t.l + 1;
        t.sum = len - t.sum;
        t.lazy ^= 1;
    }else {
        int mid = t.l + t.r >> 1;
        pushdown(x,u);
        if(l <= mid) mody(x,ls,l,r);
        if(r > mid) mody(x,rs,l,r);
        pushup(x,u);
    }
}
int qury(int x, int u, int l, int r){
    auto & t = tr[x][u];
    if(l <= t.l && t.r <= r) return t.sum;
    else {
        int sum = 0;
        pushdown(x,u);
        int mid = t.l + t.r >>1;
        if(l <= mid) sum += qury(x,ls,l,r);
        if(r > mid) sum += qury(x,rs,l,r);
        return sum;
    }
}
int n, m;
int main(){
    scanf("%d", &n);
    For(i,1,n) scanf("%d",&a[i]);
    fori(i,0,20){
        build(i,1,1,n);
    }
    scanf("%d", &m);
    while(m--){
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if(op == 1){
            long long sum = 0;
            fori(i,0,20){
                sum += (1LL<<i)*qury(i,1,l,r);                 
            }
            printf("%lld\n", sum);
        }else {
            int x; scanf("%d", &x);
            fori(i,0,20){
                if(x>>i & 1) mody(i,1,l,r);
            }
        }
    }
    return 0;
}