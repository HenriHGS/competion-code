#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 51;
int sua[N][N][N][N];//存取一个平面的子矩阵和。 (高度)[x1][x2][y1][y2]
int a[N][N][N], aa[N][N][N][N];
int pre[N][N];
int main(){
    int m, n, p;
    scanf("%d %d %d", &m, &n, &p);
    for(int i = 1; i <= m; i ++ ) for(int j = 1; j <= n; j ++ ) for(int k = 1; k <= p; k ++ )
        scanf("%d", &a[i][j][k]);
    int ans = 0, sum = 0;
    for(int h = 1; h <= p; h ++ ){
        memset(pre,0,sizeof pre);
        
      //  puts("layer:");
        for(int i = 1; i <= m; i ++) 
        for(int j = 1; j <= n; j ++ ){
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + a[i][j][h];
          //  printf("%d ", pre[i][j]);
        }
       // puts("");
        for(int x1 = 1; x1 <= m; x1 ++ ) 
        for(int x2 = x1; x2 <= m; x2 ++ )
        for(int y1 = 1; y1 <= n; y1 ++ )
        for(int y2 = y1; y2 <= n; y2 ++ )
        {
            aa[x1][x2][y1][y2] = max(0, aa[x1][x2][y1][y2] + pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1]);
            ans = max(ans, aa[x1][x2][y1][y2]);
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
3 4 5
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
-1 -1 -1 -1 -1
*/