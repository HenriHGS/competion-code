#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#define mp makr_pair
#define  ss first
#define  num second
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int>pa;
const int maxn = 1e5+10;
int c[maxn];
struct parti{
    int cnt, s;
}par[3];
int main(){
    ios::sync_with_stdio(0);   
    fori(i,0,3)cin>>par[i].cnt;
    fori(i,0,3)cin>>par[i].s;
    sort(par,par+3,[&](parti a, parti b){
        return a.s < b.s;
    });
    int m  = 0;//= acculmulate(par,par+3,0) / 2;
    fori(i,0,3) m += par[i].cnt;
    m /= 2;
    For(i,1,m)cin>>c[i];
    sort(c+1,c+m+1);
    int L = 2, R = 1e9+10;
    while(L<=R){
        int mid = L + R>>1;
        if(check(mid))
    }
    cout<<mx<<endl;
    return 0;
}
/*
3 1 0
40 60 90
18 20
*/
/*
7 0 7
5 10 500
1 1 1 1 1 1 1

0 0 2
10 10 10
10
*/