#include <cstdio>
#include <algorithm>
#include <cstring>
#define mst(x,a) memset(x,a,sizeof(x))
using namespace std;
const int N = 250000+10, M = 2*N;
int n, m;
int k;
struct Node{
    int a, b, c, s, res;
    int id;
    int sign;
    bool operator < (const Node & x)const {
        if(a != x.a) return a < x.a;
        if(b != x.b) return b < x.b;
        return c < x.c;
    }
    bool operator == (const Node&x)const {
        return a==x.a && b==x.b && c==x.c&&sign==x.sign&&id==x.id;
    }
}q[N], w[N];

int lowbit(int x){
    return x & -x;
}
int tr[M], ans[N];
void add(int x, int v){
    for(int i = x; i < M; i += lowbit(i))   tr[i] += x;
}
int sum(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
void merge_sort(int l, int r){
    if(l >= r) return ;
    int mid = l + r >>1;
    merge_sort(l,mid); merge_sort(mid+1,r);
    int i = l, j = mid + 1, k = 0;
    int sum  = 0;
    while(i <= mid && j <= r){
        if(q[i].b <= q[j].b) sum += !q[i].c, w[k++] = q[i++];
        else q[j].res += sum, w[k++] = q[j++];  
    }
    while(i <= mid) sum += !q[i].c, w[k++] = q[i++];
    while(j <= r) q[j].res += sum, w[k++] = q[j++];  
    for(int i = l, j =0; j < k; j++, i ++ )q[i] = w[j];
}
int cas;
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        scanf("%d%d", &n, &m);
        int k = n;
        for(int i = 1; i <= n; i ++ ){
            int x, y;
            scanf("%d%d", &x, &y);
            q[i] = {x,y,0,1,0,0};
        }
        for(int i = 1; i <= m; i ++ ){
            ans[i] = 0;
            int x1, y1, x2, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            q[++k] = {x2,y2,1,1,0,i,1};
            q[++k] = {x1-1,y2,1,1,0,i,-1};
            q[++k] = {x2,y1-1,1,1,0,i,-1};
            q[++k] = {x1-1,y1-1,1,1,0,i,1};
        }
        sort(q+1,q+1+k);
        n = k;
        k = 2;
        for(int i = 2; i <= n; i ++ ){
            if(q[i] == q[k-1]) q[k-1].s++;
            else q[k++] = q[i];
        }
        k--;
        merge_sort(1,k);
        for(int i = 1; i <= k; i ++ ){
            if(q[i].c)ans[q[i].id] += (q[i].res)*q[i].sign;
        }
        printf("Case %d:\n",++cas);
        for(int i = 1; i <= m; i ++ )printf("%d\n", ans[i]);
    }
    return 0;
}