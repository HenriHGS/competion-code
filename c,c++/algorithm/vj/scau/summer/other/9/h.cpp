#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    long long  n,k;
    long long zu, ans;
    scanf("%lld%lld", &n, &k);
    zu = n/(2*k);
    ans = zu*10;
    if(n%(2*k)){
        ans += 5;
        if(zu ==0 || n%(2*k)>k)ans+=5;
    }
    printf("%lld\n",ans);
    return 0;
}