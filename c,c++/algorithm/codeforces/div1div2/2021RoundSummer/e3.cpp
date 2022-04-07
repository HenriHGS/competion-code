#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
typedef long long ll;
typedef long long LL;
const LL INF = 1e18;
struct node{
    int l, r;
    ll mx;
} tr1[N<<2], tr2[N<<2];
//1 pos, 2 neg
#define ls u<<1
#define rs u<<1|1
void pushup(int u, node tr[]){
    tr[u].mx = max(tr[ls].mx, tr[rs].mx);
}
//pos INF*-1
void build(int u, int l, int r, node tr[], int op){
    if(l == r) tr[u] = {l,r,INF*op};
    else {
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(ls,l,mid,tr,op);
        build(rs,mid+1,r,tr,op);
        pushup(u,tr);
    }
}
//pos INF*-1
ll qury(int u, int l, int r, node tr[], int op){
    if( l <= tr[u].l && tr[u].r <= r){
        return tr[u].mx;
    }else {
        ll mx = INF*op;
        int mid = tr[u].l + tr[u].r>>1;
        if(l <= mid) mx = max(mx,qury(ls,l,r,tr,op));
        if(r > mid) mx = max(mx,qury(rs,l,r,tr,op));
        return mx;
    }
}
void mody(int u,int x, ll c, node tr[]){
    if(x == tr[u].l && x == tr[u].r) tr[u] = {x,x,c};
    else {
        int mid = tr[u].l + tr[u].r >>1;
        if(x <= mid) mody(ls,x,c,tr);
        else mody(rs,x,c,tr);
        pushup(u,tr);
    }
}
ll pre[N];
int a[N], b[N];
int n, q;
int main(){
    scanf("%d%d", &n, &q);
    For(i,1,n) scanf("%d", a+i);
    build(1,1,n,tr1,-1);//pos
    build(1,1,n,tr2,-1);//neg
    For(i,1,n) {
        scanf("%d", b+i);
        pre[i] = a[i] - b[i] + pre[i-1];
        mody(1,i,pre[i],tr1);
        mody(1,i,-pre[i],tr2);
    }
    while(q--){
        int l,r ;
        scanf("%d %d", &l, &r);
        if(pre[r] != pre[l-1] || qury(1,l,r,tr1,-1) > pre[l-1]){
            puts("-1");
        }else {
            printf("%lld\n", abs(-qury(1,l,r,tr2,-1) - pre[l-1]));
        }
    }
    return 0;
}