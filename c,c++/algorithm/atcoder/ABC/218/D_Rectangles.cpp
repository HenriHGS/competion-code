#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#define mp make_pair
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i <(y); i ++ )
using namespace std;
const int N = 2000+10;
int x[N], y[N];
typedef pair<int,int> pa;
map<pa,int>ma;
int main(){
    int n;
    int ans = 0;
    scanf("%d", &n);
    For(i,1,n){
        scanf("%d %d", &x[i], &y[i]);
        ma[mp(x[i],y[i])] = 1;
    }
    For(i,1,n){
        For(j,1,n){
            if(i == j) continue;
            if(x[i] >= x[j]) continue;
            if(y[i] >= y[j]) continue;
          /*   cout<<x[i]<<' '<<y[i]<<endl;
            cout<<x[j]<<' '<<y[j]<<endl; */
            int lx = x[i], rx = x[j];
            int ly = y[j], ry = y[i];
            if(ma.count(mp(lx,ly)) && ma.count(mp(rx,ry))) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}