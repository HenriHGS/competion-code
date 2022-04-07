#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5e6+10;
char s[N];
int main(){
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    sort(s +1, s+1+n);
    int cnt = 1;
    do{
        printf("%d %s\n", cnt++, s+1);
    }while(next_permutation(s+1,s+1+n));
    return 0;
}