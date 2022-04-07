#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6+10;

int n, m;
char s[N];
int sa[N], x[N << 1], y[N << 1], c[N], rk[N];

bool cmp(int x1, int x2, int k){
    return y[x1] == y[x2] && y[x1 + k] == y[x2 + k];
}

void get_sa(){
    for(int i = 1; i <= n; i ++ ) c[x[i] = s[i]] ++ ;
    for(int i = 2; i <= m; i ++ ) c[i] += c[i - 1];
    for(int i = n; i ; i -- ) sa[c[x[i]] -- ] = i;
    for(int k = 1; k <= n; k <<= 1){
        int num = 0;
        for(int i = n - k + 1; i <= n; i ++ ) y[++num] = i;
        for(int i = 1; i <= n; i ++ )
            if(sa[i] > k) y[++num] = sa[i] - k;
        for(int i = 1; i <= m; i ++ ) c[i] = 0;
        for(int i = 1; i <= n; i ++ ) c[x[i]]++;
        for(int i = 2; i <= m; i ++ ) c[i] += c[i - 1];
        for(int i = n; i; i --) sa[c[x[y[i]]]--] = y[i], y[i] = 0;
        swap(x,y);
        x[sa[1]] = 1, num = 1;
        for(int i = 2; i <= n; i ++ )
            x[sa[i]] = cmp(sa[i],sa[i - 1],k) ? num: ++num;
        if(num == n) break;
        m = num;
    }
}

int main(){
    scanf("%s", s + 1);
    n = strlen(s + 1), m = 300;
    get_sa();
    for(int i = 1; i <= n; i ++ ) rk[sa[i]] = i;
    for(int i = 1; i <= n; i ++ )printf("%d ", sa[i]);
    puts("");
   // for(int i = 1; i <= n; i ++ )printf("%d ", rk[i]);
  //  puts("");
    return 0;
}