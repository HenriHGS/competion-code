#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
void sol(){
    int c, d;
    scanf("%d %d", &c, &d);int dis = abs(c-d);
    if(c == d){
        if(c == 0)puts("0");
        else puts("1");
    }else if(dis&1)puts("-1");
    else puts("2");
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}