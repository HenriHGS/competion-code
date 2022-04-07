#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pa;
const int N = 2e6+10;
pa v[N];
int main(){
    int m, n;
    cin>>m>>n;
    for(int i = 1; i <= n; i ++ )cin>>v[i].first>>v[i].second;
    sort(v+1,v+1+n);
    int now = 0, ans = 0;
    for(int i = 1; i <= n; i ++ ){
        int add = min(v[i].second,m - now);
       // cout<<v[i].first<<' '<<v[i].second<<endl;
        ans += add*v[i].first;
        now += add;
        if(now == m)break;
    }
    cout<<ans<<endl;
}