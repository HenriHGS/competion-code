/*
区间的交集。经典题目
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> pa;
const int maxn = 5000 + 5;
const db eps = 1e-6;

struct Seg{
    int l, r;
    bool operator < (const Seg& x) const{
        return l<x.l;
    }
}seg[maxn];

int main() {
    int n;
    cin>>n;
    For(i,1,n){
        int l, r;
        cin>>l>>r;
        seg[i] = {l,r};
    }
    sort(seg+1,seg+1+n);
    int ans1 = 0, ans2 = 0;
    int l, r;
    for(int i = 1; i <= n; i ++ ){
        if(i!=1)ans2 = max(ans2,seg[i].l-r);
        int j = i;
        l = seg[i].l;
        r = seg[i].r;
        while(j <= n && seg[j].l<=r){
            r = max(r,seg[j].r);
            j++;
        }
        i = j-1;
        ans1 = max(ans1,r-l);
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}