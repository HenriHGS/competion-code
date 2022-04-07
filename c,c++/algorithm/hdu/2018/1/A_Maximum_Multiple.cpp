#include <cstdio>
#include <cstring>
#include <cctype>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e6+10;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f ? -x : x;
}
int main(){
    int tt = read();
    while(tt--) {
        int n = read();
        if(n % 3 == 0){
            printf("%d %d %d\n", n/3, n/3, n/3);
        }else if(n % 4 == 0){
            printf("%d %d %d\n", n/2, n/4, n/4);
        }else puts("-1");
    }
    return 0;
}