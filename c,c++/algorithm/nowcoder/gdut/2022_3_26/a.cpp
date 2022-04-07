#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
struct Node{
    int l, r;
    char charL, charR;
    int ans0, ans1;
    int lazy;
} tr[N<<2];
#define ls u<<1
#define rs u<<1|1
char s[N];
void pushup(int u){
    tr[u].ans0 = tr[ls].ans0 + tr[rs].ans0 
        - (tr[ls].charR == '1' && tr[ls].charR == tr[rs].charL);
    tr[u].ans1 = tr[ls].ans1 + tr[rs].ans1
        - (tr[ls].charR == '0' && tr[ls].charR == tr[rs].charL);
    tr[u].charL = tr[ls].charL, tr[u].charR = tr[rs].charR;
}
Node pushup(Node l, Node r){
    Node root;
    root.ans0 = l.ans0 + r.ans0 
        - (l.charR == '1' && l.charR == r.charL);
    root.ans1 = l.ans1 + r.ans1
        - (l.charR == '0' && l.charR == r.charL);
    root.charL = l.charL, root.charR = r.charR;
    return root;
}
void add2(int u){
    tr[u].lazy = (tr[u].lazy + 1) % 2;
}
void changeLR(int u){
    tr[u].charL = '1' - tr[u].charL + '0';
    tr[u].charR = '1' - tr[u].charR + '0';
    swap(tr[u].ans0,tr[u].ans1);
}
void pushdown(int u) {
    if(tr[u].lazy){
        add2(ls); add2(rs);
        changeLR(ls); changeLR(rs);
    }
}
void build(int u, int l, int r){
    if(l == r) {
        tr[u] = {l,r,s[l],s[r],0,0,0};
        if(s[l] == '1') tr[u].ans0 = 1;
        else tr[u].ans1 = 1;
    }else {
        tr[u] = {l,r,s[l],s[r],0,0,0};
        int mid = l + r >> 1;
        build(ls,l,mid); build(rs,mid+1,r);
        pushup(u);
        cout<<l<<' '<<r<<" tr[u].ans0:"<<tr[u].ans0<<", tr[u].ans1:"<<tr[u].ans1<<endl;
//         tr[u] = pushup(tr[ls], tr[rs]);
    }
}
void mody(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r){
        add2(u);//tr[u].lazy = (tr[u].lazy + 1)%2;
        changeLR(u);//tr[u].charL = '1' - tr[u].charL + '0';
        //tr[u].charR = '1' - tr[u].charR + '0';
        swap(tr[u].ans0,tr[u].ans1);
    }else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r>>1;
        if(l <= mid) mody(ls,l,r);
        if(r > mid) mody(rs,l,r);
        pushup(u);
    }
}
Node qury(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u];
    else {
        int mid = tr[u].l + tr[u].r>>1;
        Node ans;
        if(l <= mid) pushup(ans,qury(ls,l,mid));
        if(r > mid) pushup(ans,qury(rs,mid+1,r));
        return ans;
    }
}
int main(){
    ios::sync_with_stdio(0);
    int n, m; cin>>n>>m;
    cin>>(s+1);
    build(1,1,n);
    for(int i = 1; i <= m; i ++ ) {
        int op, l, r; cin>>op>>l>>r;
        if(op == 1) {
            Node ans = qury(1,l,r);
            cout<<min(ans.ans1,ans.ans0)<<endl;
            //cout<<1<<endl;
        }else mody(1,l,r);
    }
}