#include <cstdio>
#include <cstring>

using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
typedef long long ll;
const int N = 1e5+10;
int n;
ll x[N], y[N];
bool onLine(int a, int b, int c){
    return (y[b] - y[a]) * (x[c] - x[b]) == (y[c] - y[b]) * (x[b] - x[a]);
}
bool check(int a, int b){
    int p, q;
    p = q = -1;
    For(i,1,n){
        if(!onLine(a,b,i)){
            if(p == -1){
                p = i;
                continue;
            }else if(q == -1){
                q = i;
                continue;
            }else if(!onLine(p,q,i)) return false;
        }
    }
    return true;
}
void sol(){
    scanf("%d", &n);
    For(i,1,n) scanf("%lld %lld", x + i, y + i);
    if(check(1,2)||check(1,3)||check(2,3))puts("YES");
    else puts("NO");
}

int main(){
    sol();
    return 0;
}