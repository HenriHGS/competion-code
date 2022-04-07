#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )

const int N = 1e3+10;
const int M = 2e6+10;
int a[2*N];//, dp[N][N];
int dp[N];
int n, v, c[2];
//int nxt1[2*N], nxt2[2*N];
int main(){
    /*
    a[3] = a[2] = a[1] = 1;
    int pos =lower_bound(a+1,a+1+3,2) - a;
    printf("%d\n", pos); pos = 4;
    */
    memset(dp,0x3f, sizeof dp);
    scanf("%d%d%d%d",&n,&v,&c[0],&c[1]);
    For(i,1,n){
        scanf("%d", a + i);
        a[n + i] = a[i] + v;
    }
    int ans = 2e9;
    fori(start,0,n){
        //memset(dp,-1);
        For(i,1,n)dp[i] = 2e9;
        dp[1] = 0;
        int end = start + n;
        For(i,1,n){
            if(dp[i] == 2e9) continue;
            int ii = start + i;
            int prff = a[ii];
            fori(k,0,2){
                int w1 = prff + c[k];
                //int w2 = prff + c2;
                int j1 = lower_bound(a + 1 + start, a + 1 + start + n, w1) - a;
                //printf("j1 = %d\n", j1);
                //int j2 = lower_bound(a + 1 + start, a + 1 + start + n, w2) - a;
                if(j1<=end){
                    if(a[j1] == w1){
                        j1++;
                        if(j1 > end)ans = min(ans,dp[i] + c[k]);
                        else {
                            dp[j1 - start] = min(dp[j1 - start], dp[i] + c[k]);
                            //ans = min(ans,dp[i] + c[k] + min(c[0],c[1]));
                        }
                    } 
                    else {
                        dp[j1 - start] = min(dp[j1 - start],dp[i] + c[k]);
                    }
                }else ans = min(ans,dp[i] + c[k]);
            }
            
        }
        /*
        printf("%d\n", 1 + start);
        for(int i = 1; i <= n; i ++ )printf("%d ", dp[i]);
        puts("");
        printf("ans = %d\n",ans)    ;
        */
    }
    printf("%d\n",ans);
    /*
    For(i,1,n){
        int w1 = a[i] + c1;
        int w2 = a[2] + c2;
        int to1 = lower_bound(a+1,a+1+2*n,w1) - a; 
        int to2 = lower_bound(a+1,a+1+2*n,w2) - a; 
        if(to1 <= 2*n){
            if(to1 >2*n) to1 -= n;
            nxt1[i] = to1;
        }
    }
    */
    return 0;
}/*
5 20 2 3
2 5 8 11 15 | 22 

4 20 12 9
1 2 3 13
*/