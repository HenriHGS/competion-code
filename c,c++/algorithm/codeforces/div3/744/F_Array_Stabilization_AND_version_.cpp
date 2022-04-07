#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#define debug(a) cout<<#a<<":"<<a<<endl
#define mp make_pair
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N = 1e6+10;
int n, d;
int in[N], a[N], vis[N];
bool bfs(vector<int>& v){
    int tot = v.size();
    queue<int> que;
    fori(i,0,tot){
        int id = v[i];
        vis[id] = -1;
        if(a[id] == 0) que.push(id), vis[id] = 0;
    }
    
    while(!que.empty()){
        int x = que.front();
        que.pop();
        int j = (x +  d)%n;
       // cout<<"que:"<<x<<' '<<j<<endl;
        if(a[j] == 1 && vis[j] == -1) vis[j] = vis[x] + 1, que.push(j);
    } 
    int res = 0;
    //debug(vis[0]);
    //debug(vis[1]);
    fori(i,0,tot) res += (vis[v[i]] != -1);
  //  debug(res);
   // debug(tot);
    return res == tot;
}
void sol(){
    cin>>n>>d;
    bool ok = true;
    fori(i,0,n)in[i] = 0, cin>>a[i];
    int ans = 0;
    fori(i,0,n){
        if(in[i]) continue;
        int st = i, j = i;
        vector<int> v; 
        while(!in[j]){
            v.pb(j);in[j] = 1;
            j = (j + d)%n;
        }
        ok &= bfs(v);
        if(!ok){
            cout<<-1<<endl;
            return;
        }
       // cout<<"x:";
       // for(auto x:v)cout<<x<<' ';
       // puts("");
        //int mx = *max_element(v.begin(),v.end());
        int mx = 0;
        for(auto x:v) mx = max(mx,vis[x]);
        ans = max(ans,mx);
    }
    cout<<ans<<endl;
   // debug(ans);
}
int main(){
    ios::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}