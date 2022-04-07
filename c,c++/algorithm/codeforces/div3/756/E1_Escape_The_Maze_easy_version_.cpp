#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define CF
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int  n, k;
int fa[N], dep[N];
vector<int> e[N];
bool red[N];
bool vis[N];
void dfs(int x, int f){
    for(auto v:e[x]){
        if(v == f) continue;
        fa[v] = x; dep[v] = dep[x] + 1;
        dfs(v,x);
    }
    return ;
};
void sol(){
    cin>>n>>k;
    bool ok = true;
    For(i,1,n) fa[i] = 0,vis[i] = false, red[i] = false, e[i].clear();
    For(i,1,k){
        int x; cin>>x;
        red[x] = true;
    }
    For(i,1,n-1){
        int a, b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
   
    dep[1] = 1;
    dfs(1,-1);
    queue<int>que2, que1, que22; 
    for(auto v: e[1]) if(!red[v])que1.push(v);
    set<int>ans;
    for(int i = 1; i <= n; i ++ ){
        if(red[i]){
            red[fa[i]] = true;
            que2.push(fa[i]);
            que22.push(i);
            ans.insert(i);
        }
    }
    int step = 1;
    
    while(!que1.empty() || !que2.empty()){
        bool ok = true;
        int u;
        //if(step == 3) break;
        if(step & 1){
            queue<int> tmp;
            while(!que1.empty()){
                u = que1.front(); que1.pop();
                //cout<<"u1:"<<u<<endl;
                if(red[u]) continue;
                if(e[u].size() == 1){
                    cout<<"-1"<<endl;
                    return ;
                }
                //cout<<"ok  u1:"<<u<<endl;
                for(auto v : e[u]){
                    if(v == fa[u]) continue;
                    if(red[v])continue;
                    tmp.push(v);
                }
            }
            que1 = tmp;
        }else {
            queue<int> tmp, tmp2;
            while(!que2.empty()){
                u = que2.front(); que2.pop();
                int anc = que22.front();que22.pop();
                //cout<<"u2:"<<u<<endl;
                int ind = fa[u];
                if(red[ind]) {
                    if(ans.find(anc)!=ans.end()){
                        auto it = ans.find(anc);
                        ans.erase(it);
                    }
                    continue;
                }
                red[ind] = true; 
                if(ind){
                    tmp.push(ind);

                }
            }
            que2 = tmp;
        }
        step++;
    }
    cout<<ans.size()<<endl; 
}
int main(){
    #ifdef CF
    ios::sync_with_stdio(0);
    #endif
    int tt;
    cin>>tt;
    while(tt--) sol();
    return 0;
}