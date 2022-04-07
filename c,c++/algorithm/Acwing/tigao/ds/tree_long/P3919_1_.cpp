#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
struct node {
    int l, r;
    int val;
} tr[N*4 + N*20];
int root[N], idx;
int n, m;
int a[N];
int build(int l, int r){
    int p = ++idx;
    if(l == r){
        tr[p].val = a[l];
        return p;
    }
    int mid = l + r >> 1;
    tr[p].l = build(l,mid); tr[p].r = build(mid+1,r);
    return p; 
}
int mody(int p, int l, int r, int x, int val){
    int q = ++idx;
    tr[q] = tr[p];
    if(l == r){
        tr[q].val = val;
        return q;
    }
    int mid = l + r >> 1;
    if(x <= mid) tr[q].l = mody(tr[p].l, l, mid, x,val);
    else  tr[q].r = mody(tr[p].r, mid + 1, r, x,val);
    return q;
}
int qury(int p, int l, int r, int x){
    if(l == r){
        return tr[p].val;
    }
    int mid = l + r >> 1;
    if(x <= mid) return qury(tr[p].l,l,mid, x);
    else  return qury(tr[p].r,mid+1,r,x);
}
int main(){
    scanf("%d %d", &n, &m);
    For(i,1,n) scanf("%d", &a[i]);
    root[0] = build(1,n);
    For(i,1,m){
        int ver, op, x, v;
        scanf("%d %d %d", &ver, &op, &x);
        if(op == 1){
            //add
            scanf("%d", &v);
            root[i] = mody(root[ver],1,n,x,v);
        }else {
            printf("%d\n", qury(root[ver],1,n,x));
            root[i] = root[ver];
        }
        
    }
    return 0;
}