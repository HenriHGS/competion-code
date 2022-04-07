#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define mp make_pair
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
//typedef pair<int,int> PII;
const int N = 2e5+10;
int n;
int p[N];
struct PII{
    int first, second;
    bool operator < (const PII&a) const{
        if(a.first != first) return first < a.first;
        return second > a.second;
    }
};
PII mi[N];

//int ans[N];
deque<int> ans;
void dfs(int l, int r){
    if(l > r) return ;
    auto x = mi[r];
    int midr = x.second + 1;
    int mid = x.second;
    //ans[mid] = x.first;
    dfs(l,mid-1);
    ans.push_front(x.first);
    For(i,midr,r) ans.push_back(p[i]);
}
void sol(){
    cin>>n;
    mi[0] = {(int)1e9,0};
    For(i,1,n) cin>>p[i], mi[i] = {p[i],i};
    For(i,1,n) mi[i] = min(mi[i], mi[i-1]); 
    dfs(1,n);
    //For(i,1,n) cout<<ans[i]<<' ';
    while(!ans.empty()){
        auto x = ans.front();
        cout<<x<<' ';
        ans.pop_front();
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}