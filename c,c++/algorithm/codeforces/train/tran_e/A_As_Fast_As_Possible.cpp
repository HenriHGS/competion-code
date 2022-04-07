#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3+10;
#define db double
int n, l, v1, v2, k;
int main(){
    scanf("%d %d %d %d %d", &n, &l, &v1, &v2, &k);
 //   printf("%.6lf\n", func(n,l));
    db L = 0, R = 1.0*l/v1;
    db ans = 0;
    db x1, x2;
    n = (n + k - 1) / k;
    x2 = 1.0*l*(v1+v2) / (1.0*(n-1)*2*v1 + v1 + v2);
    ans = x2/v2 + (l - x2)/v1;
    printf("%.6lf\n", ans);
    return 0;
}