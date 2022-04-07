#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
const int maxn = 100000 + 5;

int main() {
    int t, s, n;
    cin>>t>>s>>n;
    int pre = 0, up = 0,  dow = 7;
    For(i,1,n){
        int a;
        cin>>a;
        dow = min(dow+a-pre,s);
        up = s - dow;
        swap(up,dow);
        pre = a;
    }
    int ans = 0;
    if(up) up = max(0,up-(t-pre));
    if(up) ans += up;
    cout<<ans<<endl;
    return 0;
}