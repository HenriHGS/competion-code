#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int n, ans;
void build(int l, int r){
    ans++;
    if(l == r)return ;
    if(r - l == 1){
        build(l,l);
        build(r,r);
    }else{
        int b = l + (r-l+2)/3 - 1;
        int c = b + r>>1;
        build(l,b);
        build(b+1,c);
        build(c+1,r);
    }
}
void sol(){
    ans = 0;
    scanf("%d", &n);
    For(i,1,n){
        int x;
        scanf("%d", &x);
    }
    build(1,n);
    printf("%d\n", ans);
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--)sol();
    return 0;
}