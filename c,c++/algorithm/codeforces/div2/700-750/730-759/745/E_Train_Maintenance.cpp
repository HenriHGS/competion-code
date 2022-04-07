#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int LIMIT = 450;
int x[N], y[N];
int star[N];
int c[N], cm[LIMIT][LIMIT];
int n, m;
int main(){
    scanf("%d %d", &n, &m);
    For(i,1,n) scanf("%d %d", &x[i], &y[i]);
    int sum, sub;
    sum = sub = 0;
    fori(i,0,m){
        int op, k; scanf("%d %d", &op, &k);
        int add = 1;
        if(op == 1){
            star[k] = i;
        }else {
            add = -1;
            if( (i - 1 - star[k]) % (x[k] + y[k]) < x[k] ) sub--;
        }
        sum += add;
        if(x[k] + y[k] < LIMIT){
            int mod = x[k] + y[k];
            int st = star[k] % mod, mid = (star[k] + x[k]) %mod;
            cm[mod][st] += add, cm[mod][mid] -= add;
        }else {
            for(ll j = star[k]; j < m; j += x[k] + y[k] ) c[j] += add;
            for(ll j = star[k] + x[k]; j < m; j += x[k] + y[k] ) c[j] -= add;
        }
        sub += c[i];
        fori(mm,1,LIMIT) sub += cm[mm][i%mm];
        printf("%d\n", sum - sub);
    }
    return 0;
}