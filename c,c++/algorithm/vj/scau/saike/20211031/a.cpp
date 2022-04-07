#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int mod = 425;
int main(){
    int t; scanf("%d", &t);
    int m = t/60;
    int ans = 0;
    if(m == 0) printf("%d\n",0);
    else if(m <= 3) printf("%d\n",1);
    else {
        int pre[3] = {1,1,1};
        For(i,4,m){
            int ans = 0;
            ans = (pre[0] + pre[1] + pre[2]) % mod;
            pre[0] = pre[1];
            pre[1] = pre[2];
            pre[2] = ans;
        }
        printf("%d\n",pre[2]);
    }
    return 0;
}