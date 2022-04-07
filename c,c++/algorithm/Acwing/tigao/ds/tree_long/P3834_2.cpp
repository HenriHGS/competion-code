#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
const int M = N * 18 + 100;
struct node{
    int l, r;
    int cnt;
} tr[N*4 + M];
int root[N], idx;
int build(int l, int r){
    int p = ++idx;
    if(l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l,mid); tr[p].r = build(mid+1,r);
    return p; 
}
#define ls tr[u].l
#define rs tr[u].r
void pushup(int u){
    tr[u].cnt = tr[ls].cnt + tr[rs].cnt;
}
int insert(int p, int l, int r, int x){
    int q = ++idx;
    tr[q] = tr[p];
    if(l == r){
        tr[q].cnt++;
        return q;
    }
    int mid = l + r >> 1;
    if(x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
    else tr[q].r = insert(tr[p].r, mid + 1, r, x);
    pushup(q);
    return q;
}
int qury(int p, int q, int l, int r, int x){
    if(l == r){
        return r;
    }
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = l + r >> 1;
    if(cnt >= x) return qury(tr[p].l, tr[q].l, l, mid, x);
    else return qury(tr[p].r, tr[q].r, mid +1, r, x - cnt);
}
int n, m;
int a[N];
vector<int> lx;
inline int getID(int x){
    return lower_bound(lx.begin(), lx.end(), x) - lx.begin();
}
int main(){
    scanf("%d %d", &n, &m);
    For(i,1,n){
        scanf("%d", &a[i]);
        lx.pb(a[i]);
    }
    sort(lx.begin(),lx.end());
    lx.erase(unique(lx.begin(),lx.end()), lx.end());

    root[0] = build(0, lx.size() - 1);
    For(i,1,n){
        root[i] = insert(root[i-1], 0, lx.size() - 1, getID(a[i]));
    }
    For(i,1,m){
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", lx[qury(root[l-1], root[r],0,lx.size()-1,k)]);
    }
    return 0;
}