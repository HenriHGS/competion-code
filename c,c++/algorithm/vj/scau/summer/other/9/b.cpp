#include <cstdio>
#include <cstring>
using namespace std;
void sol(){
    int n,k;
    bool ok = true;
    scanf("%d%d",&n,&k);
    if(n <= k + 1){
        ok &= (n&1);
    }
    if(ok)puts("Kilani");
    else puts("Ayoub");
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}