#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )

const int maxn = 1e7+10;
const int N = 1e6+10;

int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}

int rac[maxn];
int a[N], b[N]; 
bool st[maxn+1];
int primes[maxn], idx;
int cnt[maxn];
void init(){
    for(int i = 2; i <= maxn; i ++ ){
        if(!st[i]) primes[idx++] = i, cnt[i] = 1;
        for(int j = 0; primes[j] <= maxn/i; j ++ ){
            st[i*primes[j]] = 1;
            cnt[i*primes[j]] = cnt[i] + cnt[primes[j]];
            if(i % primes[j] == 0) break;
        } 
    }
}
int main(){
    init();
    int tt;
    tt = read();//scanf("%d", &tt);
    while(tt--){
        int n;
        n = read();//scanf("%d", &n);
        For(i,1,n) b[i] = read();//scanf("%d", b+i);
        int ans = 0;
        For(i,1,n){
            /*
            int x = b[i], cnt1 = 0;
            for(int j = 0; primes[j] <= x/primes[j]; j ++ ){
                int pr = primes[j];
                while(x%pr==0)cnt1++,x/=pr;
            }
            if(x > 1)cnt1++;
            */
            //printf("debug: x:%d, cnt1 = %d, cnt0 = %d\n", b[i], cnt1, cnt[b[i]]);
            //ans ^= cnt1;
            ans ^= cnt[b[i]];
        }
        if(ans != 0)puts("Alice");
        else puts("Bob");   
    }
    return 0;
}