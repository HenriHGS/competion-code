#include <cstdio>
#include <cstring>
using namespace std;
void sol(){
    long long n, k;
    scanf("%lld%lld",&n,&k);
    long long  mid = n - 1;//n/2+1;
    if(k>=mid)puts("Yes");
    else puts("No");
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}