#include <cstring>
#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
const int N = 2e5+10;
typedef long long ll;
ll pre[N], a[N];
int main(){
    int n;
    scanf("%d", &n);
    For(i,1,n){
        scanf("%d", a + i);
        pre[i] = pre[i - 1] + a[i];
    }
    int sum = pre[n];
    if(sum % 3){
        printf("0\n");
        return 0;
    }
    int m3 = sum / 3;
    For(i,n+1,2*n){
        pre[i] = pre[i - 1] + a[i - n]; 
    }
    int ans = 0;
    For(i,1,n){
        ll prff = pre[i - 1];
        int p = lower_bound(pre + 1, pre + 1 + 2*n, prff + m3) - (pre);
        if(pre[p] - prff == m3){
            int q = lower_bound(pre+1,pre+1+2*n,prff+m3*2) - (pre);
            if(pre[q] == 2*m3+prff)ans++;
        }
    }
    printf("%d\n", ans/3);
    return 0;
}