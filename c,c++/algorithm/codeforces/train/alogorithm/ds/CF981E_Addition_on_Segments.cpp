#include <cstdio>
#include <cstring>
#include <bitset>
#include <vector>
using namespace std;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f? -x : x;
}
const int maxn = 1e4 + 10;
using bs = bitset<maxn>;
using vi = vector<int>;
bs ans;

#define ls u<<1
#define rs u<<1|1
struct Node{
    int l, r;
    bs cur;
    vi v;
}tr[maxn<<2];
void build(int u, int l, int r){
    tr[u] = {l,r};
    if(l == r) return ;
    else {
        int mid = l + r >> 1;
        build(ls,l,mid); build(rs,mid + 1, r);
    }
}
void mody(int u, int l, int r, int k){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].v.push_back(k);
    }else {
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) mody(ls,l,r,k);
        if(r > mid) mody(rs,l,r,k);
    }
}
void dfs(int u, bs pre){
    bs cur = pre;
    for(auto x: tr[u].v) cur |= (cur<<x);
    if(tr[u].l == tr[u].r) {
        ans |= cur;
        return ;
    }
    dfs(ls,cur); dfs(rs,cur);
}
int n, q;
int main(){
    n = read(); q = read();
    build(1,1,n);
    while(q-- ){
        int l = read(), r = read(), k = read();
        mody(1,l,r,k);
    }
    bs cur;
    cur[0] = 1;
    //bs cur[0] = 1;
    dfs(1,cur);
    int ansc = 0;
    for(int i = 1; i <= n; i ++ ) if(ans[i]) ansc++;
    printf("%d\n", ansc);
    for(int i = 1; i<= n; i ++ ) if(ans[i]) printf("%d ", i);
    return 0;
}