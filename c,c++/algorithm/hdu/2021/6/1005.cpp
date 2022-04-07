#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
template<class T> using vc = vector<T>;
using vi = vector<int>;
const int N = 1e5+10;
//vi a(N);
int b[N];
void sol(){
    int n, m;
    scanf("%d%d",&n,&m);
    For(i,1,m)scanf("%d",b+i);
    b[m+1] = n + 1;
    sort(b+1,b+1+m+1);
    int tot = n - m;
    bool ok = true;
    int mx = 0;
    For(i,1,m+1)mx = max(mx,b[i]-b[i-1]-1);
    For(i,1,m+1){
        int cur = b[i] - b[i-1] - 1;
        int other = tot - cur;
        if(cur > other && mx == cur){
            ok &= (other + (i - 1) >= cur); 
        }
      //  if(mx == cur) break;
    }
    if(ok)puts("YES");
    else puts("NO");
}
int main(){
    int tt;
    scanf("%d",&tt);
    while(tt--)sol();
    return 0;
}