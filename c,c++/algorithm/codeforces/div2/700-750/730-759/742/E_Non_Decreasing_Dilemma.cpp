#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
typedef long long ll;
struct node{
    int l, r;
    int alen, blen;
    int a, b;
    ll sum = 0;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
int n, q;
int a[N];

node pushup(node L, node R){
    node res;
    int lenl = L.r - L.l + 1;
    int lenr = R.r - R.l + 1;
    res.l = L.l, res.r = R.r;
    res.a = L.a, res.b = R.b;
    res.alen = lenl == L.alen && L.b <= R.a ? L.alen + R.alen : L.alen;
    res.blen = lenr == R.blen && L.b <= R.a ? R.blen + L.blen : R.blen;
    res.sum = L.sum + R.sum;
    if(L.b <= R.a) res.sum += 1LL*L.blen * R.alen;
    return res;
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l,r,1,1,a[l], a[l], 1};
    else {
        int mid = l + r >>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        tr[u] = pushup(tr[ls],tr[rs]);
    }
}
void mody(int u, int x, int v){
    if(x == tr[u].l && x == tr[u].r) tr[u] = {x,x,1,1,v, v, 1};
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) mody(ls,x,v);
        else mody(rs,x,v);
        tr[u] = pushup(tr[ls], tr[rs]);
    }
}
node qury(int u, int l, int r){
    if(l == tr[u].l && tr[u].r == r) return tr[u];
    else {
        ll sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return qury(ls,l,r);
        else if(mid + 1 <= l) return qury(rs,l,r);
        else return pushup(qury(ls,l,mid), qury(rs,mid+1,r)); 
    }
}
int main(){
    scanf("%d %d", &n, &q);
    For(i,1,n) scanf("%d", a + i);
    build(1,1,n);
    while(q--){
        int op, x,y;
        scanf("%d %d %d", &op, &x, &y);
        if(op == 1) mody(1,x,y);
        else printf("%lld\n", qury(1,x,y).sum);
    }
    return 0;
}