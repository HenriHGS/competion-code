#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 1e5+10;
int a[N];
int main(){
 //   map<int,int> ma;
   // ma[1] = 3;
   // for(auto [x,y] : ma) ;
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    int ans = 1;
    int i = n, j = n;
    for(i,j; j >= 1; j -- ){
        while(i >= 1 && a[i] <= abs(a[j])) i--;
        ans = max(ans,j - i);
    }
    printf("%d\n", ans);
    return 0;
}