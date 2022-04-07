#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#define mp make_pair
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int> PII;
void sol(){
    priority_queue<PII> q;
    int n; cin>>n;
    For(i,1,n){
        int x; cin>>x;
        if(x)q.push({x,i});
    }
    vector<PII>ans;
    while(q.size() >= 2){
        auto fi = q.top(); q.pop();
        auto se = q.top(); q.pop();
        ans.pb({fi.second,se.second});
        fi.first--;
        if(fi.first > 0) q.push(fi);
        se.first--;
        if(se.first > 0) q.push(se);
    }
    cout<<ans.size()<<endl;
    fori(i,0,ans.size()) cout<<ans[i].first<<' '<<ans[i].second<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}