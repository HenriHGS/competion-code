#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
const int N = 1e5+10;
struct Dom{
    int x, h;
    int id;
} dom[N];
int n;
int px[N], mx[N];

struct node{
    int l, r;
    int mx;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
void build(int u, int l, int r){
    if(l == r) tr[u] = {l,r};
    else {
        int mid = l + r >> 1;
        tr[u] = {l,r};
        build(ls,l,mid);
        build(rs,mid+1,r);
    }
}
void pushup(int u){
    tr[u].mx = max(tr[ls].mx, tr[rs].mx);
}
void mody(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x,x,v};
    else {
        int mid = tr[u].l+tr[u].r>>1;
        if(x <= mid) mody(ls,x,v);
        else mody(rs,x,v);
        pushup(u);
    }
}
int qury(int u, int l, int r){
    if(l <= tr[u].l  && tr[u].r <= r) return tr[u].mx;
    else {
        int mx = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) mx = max(mx,qury(ls,l,r));
        if(r > mid) mx = max(mx,qury(rs,l,r));
        return mx;
    }
}
int main(){
    /* int a[] = {1,2,3,4,5,6};//5
    int r = lower_bound(a,a+6,7) - a;
    cout<<r<<endl; */
    
    scanf("%d", &n);
    For(i,1,n){
        int x, h;
        scanf("%d %d", &x, &h);
        dom[i] = {x,h,i};
    }
    sort(dom+1,dom+1+n,[&](Dom&a, Dom& b){
        return a.x < b.x;
    });
    build(1,1,n+1);
    For(i,1,n) px[i] = dom[i].x;
    mody(1,n+1,n+1);
    mx[n+1] = 0;
    for(int i = n; i ; i --){
        
        //mody(1,i, mx[i] + i);
        int l = i + 1;//lower_bound(px+1+i, px+1+n,px[i]) - px;
        //if(px[l] == px[i]) l++;
        int r = lower_bound(px+1+i,px+1+n,px[i] + dom[i].h -1) - px;
        if(r == n + 1);
        else if(dom[r].x > px[i] + dom[i].h-1)r--;
        if(l > r) {
            mx[dom[i].id] = 1;
            mody(1,i,1 + i);
            //continue;
        }else {
            int id = dom[i].id;
            mx[id] = qury(1,l,r) - i;
            mody(1,i,mx[id] + i);
        }
    }
    For(i,1,n){
        printf("%d ", mx[i]);
    }
    return 0;
}