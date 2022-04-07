# include  <bits/stdc++.h>
#define debug(a) cout<<#a<<":" << a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
typedef long long LL;
using namespace std;
const int N  =2e5+10;
int n, w;
int a[N];
struct Node{
    int l, r;
    int mx;
} tr[N<<2];
void pushup(int u){
    tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
}
void build(int u, int l, int r){
    if(l==r)tr[u]={l,r};
    else {
        tr[u]={l,r};
        int mid = l + r >> 1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
int quary(int u, int l, int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].mx;
    else {
        int mid = tr[u].l+tr[u].r>>1;
        int mx = 0;
        if(l<=mid) mx = quary(u<<1,l,r);
        if(r>mid) mx=max(mx,quary(u<<1|1,l,r));
        return mx;
    }
}
void mody(int u, int x, int c){
    if(tr[u].l==x&&tr[u].r==x) tr[u]={x,x,c};
    else {
        int mid = tr[u].l+tr[u].r>>1;
        if(x<=mid)mody(u<<1,x,c);
        else mody(u<<1|1,x,c);
        pushup(u);
    }
}
int main(){
   // int m,p;
    scanf("%d%d", &n, &w);
  //  scanf("%d%d", &m, &p);
    build(1,1,n);
    For(i,1,n) scanf("%d", a+i);
  //  For(i,1,n) cout<<a[i]<<' ';
 //   cout<<endl;
    For(i,1,n)mody(1,i,a[i]);
    int ans = 1;
    //debug("ok");
    //cout<<quary(1,1,n);
    For(len,1,n){
        bool ok = true;
        LL sum = 0;
        for(int i = 1; i <= n; i += len){
            sum += quary(1,i, min(i+len-1,n)) + 1;
        }
        //debug(len);
       //debug(sum);
        sum --;
        //ans += sum <= w;
        if(sum <= w){
            printf("%d\n", len);
            return 0;
        }
    }
    printf("%d\n", ans);//cout<<ans<<endl;
    //int last=0, n = 0;
    /*
    while(m--){
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op=='A'){
           // n++;
           // mody(1,n,(x+last)%p);
        }else {
            last = quary(1,n-x+1,n);
            printf("%d\n",last);
            //last = 
        }
    }
    */
    return 0;
}