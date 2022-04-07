#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int du[N];
int n, m;
vector<int> e[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,1,m){
        int a, b; cin>>a>>b;
        e[a].pb(b);
        du[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> ans;
    For(i,1,n){
        if(du[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int u = q.top(); q.pop();
        ans.pb(u);
        for(auto j : e[u]){
            du[j]--;
            if(du[j] == 0){
                q.push(j);
            }
        }
    }
    if(ans.size() != n) cout<<-1<<endl;
    else for(auto x: ans) cout<<x<<' ';
    return 0;
}