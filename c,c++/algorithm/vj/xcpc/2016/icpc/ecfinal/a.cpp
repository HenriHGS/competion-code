#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
void sol(){
    int n; scanf("%d", &n);
    printf("%d\n", n/3);
}
int main(){
    int tt; scanf("%d", &tt);
    int cas = 0;
    while(tt--){
        printf("Case #%d: ", ++cas);
        sol();
    }
    return 0;
}