#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef pair<int,int> pa;
const int maxn = 1e3+10;
int pref[maxn][maxn], order[maxn][maxn], next[maxn];
int future_husband[maxn], future_wife[maxn];
queue<int>q;
void init(){

}
//match one
void engage(int man, int woman){
    int m = future_husband[woman];
    if(m){
        future_wife[m] = 0;
        q.push(m);
    }
    future_wife[man] = woman;
    future_husband[woman] = man;
}
int b[maxn];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++ )scanf("%d", b + i);
        For(i,1,n){
            vector<pa>v;
            For(j,1,n){
                v.pb(mp(abs(b[j]-i),j));//pref[i][j] = abs(b[j]-i);
            }
            sort(v.begin(),v.end());
            For(j,1,n){
                pref[i][j] = v[j-1].second;
                order[j][i]
            }
        }
    }
    return 0;
}
