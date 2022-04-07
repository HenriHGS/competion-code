#include <cstdio>
#include <cstring>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    int a[6]{};
    ll ans = 0;
    fori(i,0,6)scanf("%d", a + i);
    int l1,l2,r1,r2,m;
    l1 = a[0]; l2 = a[5];
    m = a[1];
    r1 = a[2]; r2 = a[3];
    ll cnt = m*2+1;
    For(i,1,l1+l2){
        ans += cnt;
        //printf("debug:%d\n", cnt);
        if(i<l1)cnt++;  
        else if(i > l1)cnt--;
        if(i<r1)cnt++;
        else if(i > r1)cnt--;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
2 1 1 2 1 1
*/