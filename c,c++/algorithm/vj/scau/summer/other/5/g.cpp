#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
int main(){
    int n, k; 
    scanf("%d%d", &n, &k);
    int sum = 0;
    For(i,1,n){
        int x;
        scanf("%d", &x);
        sum+= x;
    }
    printf("%d.", sum/n);
    sum = sum%n;
    sum *= 10;
    For(i,1,k){
        printf("%d",sum/n);
        sum = sum%n;
        sum*=10;
    }
}
//97.6666666666
//97.6666666666