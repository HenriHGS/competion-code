#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 6e5+10, M = N*25;
int tr[M][2], root[M];
int mx[M], idx;
#define nlson tr[now][0]
#define nrson tr[now][1]
#define plson tr[pre][0]
#define prson tr[pre][1]
#define nson tr[now][ch]
#define pson tr[pre][ch]
int sum[N];
int n, m;
void insert(int pre, int now, int i, int k){
    if(k < 0){
        mx[now] = i;
        return;
    }
    int ch = sum[i]>>k & 1;
    if(pre) tr[now][ch^1] = tr[pre][ch^1];
    tr[now][ch] = ++idx;
    insert(pson, nson, i, k - 1);
    mx[now] = max(mx[nlson], mx[nrson]); 
}
int qury(int now, int l, int x){
    int res = 0;
    for(int i = 24; i >= 0; i -- ){
        int ch = x>>i & 1;
        if(mx[tr[now][ch^1]] >= l) now = tr[now][ch^1];
        else now = tr[now][ch];
    }
    return sum[mx[now]]^x;
}
void init(){
    idx = 0;
    root[0] = ++idx;
    mx[0] = -1; 
    insert(0, root[0], 0, 24);
}
int main(){
    init();
    scanf("%d %d", &n, &m);
    For(i,1,n){
        int x; scanf("%d", &x);
        root[i] = ++idx; sum[i] = sum[i-1]^x;
        insert(root[i-1],root[i],i,24);
    }
    while(m--){
        char s[2]; scanf("%s", s);
        if(s[0] == 'A'){
            int x; scanf("%d", &x);
            n++;
            root[n] = ++idx;
            sum[n] = sum[n-1]^x;
            insert(root[n-1],root[n],n,24);
        }else {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            printf("%d\n", qury(root[r-1],l-1, sum[n]^x));
        }
    }
    return 0;
}