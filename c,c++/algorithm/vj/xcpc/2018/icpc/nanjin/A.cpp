#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;

void sol(){
    int n, k;
    scanf("%d %d", &n, &k);
    if(n == 0) puts("Austin");
    else if(k == 1){
        if(n % 2) puts("Adrien");
        else puts("Austin");
    }else puts("Adrien");
}

int main(){
    sol();
    return 0;
}