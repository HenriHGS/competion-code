#include <cstdio>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
using namespace std;
const int N = 2e3+10;
int a[N][N], mx_col[N][N];
int Left[N][N], Right[N][N];
typedef long long LL;
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++ )for(int j = 1; j <= m; j ++ ) {
            scanf("%d", a[i] + j);
            Left[i][j] = 1;
            Right[i][j] = m + 1;
        }
        for(int i = 0; i <= n + 1; i ++ ){
            for(int j = 0; j <= m + 1; j ++ ){
                if(i == 0 || i == n + 1 || j == 0 || j == m + 1) mx_col[i][j] = 1;
                Left[i][j] = 1;
                Right[i][j] = m;
            }
        }
        for(int i = 1; i <= n; i ++ )for(int j = 1; j <= m; j ++ ){
            mx_col[i][j] = 1;
            if(a[i][j] >= a[i-1][j] && i != 1) mx_col[i][j] = mx_col[i-1][j] + 1;
        }
        /*
        cout<<"mx_col:"<<endl;
        for(int i = 0; i <= n + 1; i ++ ){
            for(int j = 0; j <= m + 1; j ++ ){
                cout<<mx_col[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        LL ans = m;
        for(int i = 1; i <= n; i ++ ){
            int lo = 0, ro = m + 1;
            for(int j = 1; j <= m; j ++ ){
               if(mx_col[i][j] != mx_col[i-1][j]) Left[i][j] = max(Left[i][j], Left[i-1][j]);//要继承前面的计算结果
            }
            for(int j = m; j >= 1; j -- ){
                if(mx_col[i][j] != mx_col[i-1][j]) Right[i][j] = min(Right[i][j], Right[i-1][j]);//要继承前面的计算结果
                /*
                if(ans < (LL)mx_col[i][j] * (Right[i][j] - Left[i][j] + 1)){
                    cout<<"debug: "<<i<<' '<<j<<endl;
                    cout<<mx_col[i][j]<<' '<<Right[i][j]<<' '<<Left[i][j]<<endl;
                }
                */
                ans = max(ans, (LL)mx_col[i][j] * (Right[i][j] - Left[i][j] + 1));
                //更新right数组
                if(mx_col[i+1][j] == 1) {//出现断点
                    ro = j;
                }else {
                    Right[i][j] = min(Right[i][j],ro - 1);
                }
            }
            for(int j = 1; j <= m; j ++ ){
                 if(mx_col[i+1][j] == 1) {//出现断点
                    lo = j;
                }else {
                    Left[i][j] = max(Left[i][j],lo + 1);
                }
            }
        }

        /*
        cout<<"left:"<<endl;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= m; j ++ ){
                cout<<Left[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<"right:"<<endl;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= m; j ++ ){
                cout<<Right[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        cout<<ans<<endl;
    }
    return 0;
}

/*
hack:
1 
3 3
1 4 1 
2 1 2
1 2 1
ans:3
hack2:
1
3 3
2 1 2
1 2 1
2 3 2
ans:6
*/