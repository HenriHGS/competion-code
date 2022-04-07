#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define debug(a) cout<<#a<<":"<<a<<endl
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;
struct node{
    int a, b;
    bool operator < (const node& x) const{
        return a < x.a;
    }
}a[N], b[N], bb[N];
int n, m, mm;
int cnt[N], ca;
ll ans = 0;
void sol(){
    mm =  0;
    scanf("%d %d", &m, &n);
    For(i,1,m){
        int v;
        char s[20];
        scanf("%s%d", s,&v);
        if(s[0] == 'A') b[i].a = v;
        else b[i].b = v;
    }
    For(i,1,n) {
        int v;
        scanf("%d", &v); a[i].a = v;
    }
    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + m);
    For(i,1,m) cnt[i] = cnt[i-1] + b[i].b;
    int rem = m - cnt[m];
    if(n <= rem){
        bool ok = true;
        ans = 0;
        int i = 1, pre = 0, j = 1;
        ll sum_b = 0;int cnt1 = 0;
        for(j = 1; j <= m; j ++ ){
            if(b[j].b == 1) continue;
            while(i <= n && a[i].a < b[j].a)i++;
            if(i == n + 1) {
                ok = false;
                break;
            }
            if(b[j].b == 0){
                ans += a[i].a - b[j].a;
                sum_b += b[j].a;
            }else cnt1++;
            pre = ++i;
        }
        j -- ; //怪物数
            int st = max(n - j + cnt1 + 1, pre + cnt1);
            if(st <= n){
                ans = 0;
                for(int i = st; i <= n; i ++ ) ans +=  a[i].a;
                ans -= sum_b;
                       }
    }else if(n > rem && n <= m){
        For(i,1,m){
            if(b[i].b == 0) bb[++mm] = b[i];
        }
        bool ok = true;
        ans = 0;
        int i = 1, pre = 0, j = 1;
        ll sum_b = 0;
        for(j = 1; j <= mm; j ++ ){
            while(i <= n && a[i].a < bb[j].a)i++;
            if(i == n + 1) {
                ok = false;
                break;
            }
            ans += a[i].a - bb[j].a;
            sum_b += bb[j].a;
            pre = ++i;
        }
        j -- ; //怪物数
            //ans += 
            int st = max(n - j + 1, pre);
            if(st <= n){
                ans = 0;
                for(int i = st; i <= n; i ++ ) ans +=  a[i].a;
                ans -= sum_b;
                       }
    }else if(n > m){
        bool ok = true;
        ans = 0;
        int i = 1, pre = 0, j = 1;
        ll sum_b = 0;int cnt1 = 0;
        ll sum_a = 0;
        for(j = 1; j <= m; j ++ ){
            while(i <= n && a[i].a < b[j].a)sum_a += a[i].a, i ++ ;
            if(i == n + 1) {
                ok = false;
                break;
            }
            if(b[j].b == 0){
                ans += a[i].a - b[j].a;
                sum_b += b[j].a;
            }else cnt1++;
            pre = ++i;
        }
        j -- ; //怪物数
        if(!ok) {
            //ans += 
            ans = 0;
            int st = max(n - j + cnt1 + 1, pre + cnt1);
            if(st <= n){
                ans = 0;
                for(int i = st; i <= n; i ++ ) ans +=  a[i].a;
                ans -= sum_b;
                       }
        }else ans += sum_a;
    }
    //printf("Case %d: %lld\n", ++ca,ans);
    printf("%lld\n",ans);
}
/*
1
4 2
3 3 3 4
4 4
1 0
*/
int main(){
    //int tt; scanf("%d", &tt);
   // while(tt--) sol();
   sol();
    return 0;
}
