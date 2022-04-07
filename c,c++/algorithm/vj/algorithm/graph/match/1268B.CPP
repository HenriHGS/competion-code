#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    long long cnt[2]{};
    fori(i,0,n){
        int x;
        scanf("%d", &x);
        cnt[i&1] += (x + 1) /2;
        cnt[1 ^( i&1)] += x / 2;
    }
    printf("%lld\n", min(cnt[0],cnt[1]));
    return 0;
}