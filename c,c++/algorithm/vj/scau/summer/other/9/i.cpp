#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 3e5+10;
int v[N];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) scanf("%d", v + i);
    sort(v+1,v+1+n);
    int len = 1;
    int i = 1, j = n;
    long long pre = 0, bu = v[n] - v[1];
    i++, j --;
    long long ans = bu, pre_bu = bu;
    printf("%lld ",ans);
    while(1){
        long long cur = v[j] - v[i];
        //odd
        len++;
        if(len == n) break; 
        //ans = pre + bu*len; 
        ans = ans + pre_bu;
        printf("%lld ",ans);
        i++;
        //even
        len++;
        if(len == n) break;
        pre_bu += cur;
        ans = ans + pre_bu;
        printf("%lld ",ans);
        j--;
      //  pre_bu = cur;
       // pre = cur;
    }
    return 0;
}
