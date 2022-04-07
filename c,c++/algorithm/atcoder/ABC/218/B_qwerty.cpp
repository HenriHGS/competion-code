#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    for(int i = 0; i < 26; i ++ ){
        int x; scanf("%d", &x);
        printf("%c", char('a' + x-1));
    }
    return 0;
}