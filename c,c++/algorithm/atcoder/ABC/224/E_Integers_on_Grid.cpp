#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#define x first
#define y second
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;

struct node{
    int x, y, a;
    int id;
    bool operator < (const node& x) const{
        return a < x.a;
    }
} p[N];
int dp[N];
int x[N], y[N];
int prex[N], prey[N];
int ans[N];
int main(){
    ios::sync_with_stdio(0);
    int h, w, n; cin>>h>>w>>n;
    For(i,1,n){
        cin>>p[i].x>>p[i].y>>p[i].a;
        p[i].id = i;
    }
    sort(p + 1, p + 1 +n);
    for(int i = n; i >= 1; i -- ){
        int j = i;
        while(j >= 1 && p[j].a == p[i].a){
            int ind = p[j].id;
            int cx = p[j].x, cy = p[j].y;
            int px = x[cx], py = y[cy];
            int mx = max(py + 1, px + 1);
            prex[cx] = x[cx], prey[cy] = y[cy];
          //  x[cx] = max(prex, mx);
          //  y[cy] = max(prey, mx);
            ans[ind] = mx;
            j--;
        }
        j = i;
        while(j >= 1 && p[j].a == p[i].a){
            int ind = p[j].id;
            int cx = p[j].x, cy = p[j].y;
            int px = x[cx], py = y[cy];
            int mx = max(prex[cx] + 1, prey[cy] + 1);
            x[cx] = max(x[cx], mx);
            y[cy] = max(y[cy], mx);
          //  x[cx] = max(prex, mx);
          //  y[cy] = max(prey, mx);
            j--;
        }
        i = j + 1;
    }
    For(i,1,n) cout<<ans[i]-1<<endl;
    return 0;
}