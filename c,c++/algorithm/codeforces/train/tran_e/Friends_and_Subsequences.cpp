#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <climits>
#include <cassert>
#include <iostream>
#include <vector>
#define pb push_back
#define sz(a) (int)a.size()
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int MX_LOG = 21;
int mx[N][MX_LOG+1], mi[N][MX_LOG+1];
int logn[N+1];
void init(){
    logn[1] = 0, logn[2] = 1;
    fori(i,3,N){
        logn[i] = logn[i/2] + 1;
    }
}
int n, a[N], b[N];
int get1(int x, int y){
    int s = logn[y-x+1];
    return max(mx[x][s], mx[y - (1<<s) + 1][s]);
}
int get2(int x, int y){
    int s = logn[y-x+1];
    return min(mi[x][s],mi[y-(1<<s)+1][s]);
}
int check(int l, int r){
    int mxa, mib;
    int s = logn[r - l + 1];
    mxa = max(mx[l][s], mx[r - (1<<s)+1][s]);
    mib = min(mi[l][s],mi[r - (1<<s)+1][s]);
    if(mxa > mib) return 1;
    else if(mxa < mib) return -1;
    else return 0;
}
int main(){
    init();
    scanf("%d", &n);
    For(i,1,n) scanf("%d", &a[i]);
    For(i,1,n) scanf("%d", &b[i]);
    For(i,1,n){
        mx[i][0] = a[i];
        mi[i][0] = b[i];
    }
    For(j,1,MX_LOG){
        for(int i = 1; i + (1<<j) - 1<= n; i++){
            mx[i][j] = max(mx[i][j-1], mx[i + (1<<(j-1))][j-1]);
            mi[i][j] = min(mi[i][j-1], mi[i + (1<<(j-1))][j-1]);
        }
    }
    ll ans = 0;
    For(i,1,n){
        int rmin = i - 1, rmax = n + 1;
        int l, r, mid;
        l = i, r = n;
        int cnt = 0;
        while(l <= r){
            mid = l + r >> 1;
            if(check(i,mid) == 1) rmax = mid, r = mid - 1;
            else l = mid + 1;
            cnt++;
            assert(cnt != 100);
        }
        l = i, r = n;
        cnt = 0;
        while(l <= r){
            mid = l + r >>1;
            if(check(i,mid) == -1) rmin = mid, l = mid+1;
            else r = mid - 1;
            assert(cnt != 100);
        }
       /*  cout<<"rmin:"<<rmin<<" rmax:"<<rmax<<endl;
        cout<<"mi: "<<get2(i,rmin)<<" "<<get2(i,rmax)<<endl;
        cout<<"mx: "<<get1(i,rmin)<<" "<<get1(i,rmax)<<endl; */
        ans += rmax - rmin - 1;
    }
    printf("%lld", ans);
    return 0;
}