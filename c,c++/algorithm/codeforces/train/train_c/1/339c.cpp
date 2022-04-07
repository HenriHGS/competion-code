#include <cstdio>
#include <cstring>
#include <iostream>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define mst(x,a) memset(x,a,sizeof(x))
using namespace std;
const int N = 1010;
const int maxw = 11;
bool dp[N][11][11];
char have[11];
void print(int dep, int dif, int nxt){
    if(dep == 0) return ;
    dif = nxt - dif;
    //cout<<"dep = "<<dep<<" dif = "<<dif<<" nxt = "<<nxt<<endl;
    for(int k = 1; k <= 10; k ++ ){
        if(have[k] && dp[dep-1][dif][k] && k != nxt){
            print(dep-1,dif,k);
            //nxt = k;
            break;
        }
    } 
    printf("%d ",nxt);
}
int main(){
    dp[0][0][0] = 1;
    scanf("%s", have+1);
    For(i,1,10) have[i] -= '0';
    int m;
    scanf("%d", &m);
    fori(i,0,m)fori(j,0,maxw)fori(k,0,maxw)
        if(dp[i][j][k]){
            For(nxt,1,10){
                if(have[nxt] && nxt - j > 0 && nxt != k){
                    dp[i+1][nxt - j][nxt] = true;
                }
            }
        }
    int u = -1, v = -1;
    fori(j,1,maxw)fori(k,1,maxw){
        if(dp[m][j][k]){
            u = j, v = k;
            break;
        }
    }
    if(v == -1){
        puts("NO");
    }else {
        puts("YES");
        print(m,u,v);
    }
    return 0;
}