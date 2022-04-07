#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#define CF
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int  n, k;
int fa[N], dep[N];
vector<int> e[N];
int red[N], green[N];
bool vis[N];
void dfs(int x, int f, int st){
    st |= red[x];
    for(auto v:e[x]){
        if(v == f) continue;
        fa[v] = x; dep[v] = dep[x] + 1;
        if(st) red[v] = 0;
        dfs(v,x,st);
    }
    return ;
};
void sol(){
    cin>>n>>k;
    bool ok = true;
    For(i,0,n) green[i] = 0,fa[i] = 0,vis[i] = false, red[i] = false, e[i].clear();
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
    int cnt = 0;
    dfs(1,-1,0);
    queue<int>que2, que1, que22; 
    for(auto v: e[1]) if(!red[v])que1.push(v);
    else cnt++;
    set<int>ans;
    for(int i = 1; i <= n; i ++ ){
        if(red[i]){
            que2.push(fa[i]);
            que22.push(i);
            ans.insert(i);
            //cout<<"insert anc: "<<i<<endl;
        }
    }
    /* for(int i = 1; i <= n; i ++ ){
        if(red[i]) red[fa[i]] = true;
    } */
    int step = 2;
    green[1] = 1;
    while(!que1.empty() || !que2.empty()){
        bool ok = true;
        int u;

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
                green[u] = 1;
                //cout<<"ok  u1:"<<u<<endl;
                for(auto v : e[u]){
                    if(v == fa[u]) continue;
                    if(red[v])continue;
                    tmp.push(v);
                    //green[v] = 1;
                }
            }
            que1 = tmp;
        }else {
            queue<int> tmp, tmp2;
            while(!que2.empty()){
                u = que2.front(); que2.pop();
                int anc = que22.front();que22.pop();
                //cout<<"u2:"<<u<<", anc:"<<anc<<endl;
                int ind = fa[u];
                if(u == 1) continue;
                if(red[u] >= 1 && !green[u]){
                    //cout<<"delet:anc:"<<anc<<endl;
                    if(ans.find(anc)!=ans.end()){
                        auto it = ans.find(anc);
                        //cout<<(*it)<<endl;
                        ans.erase(it);
                    }
                    red[u]++;
                    continue;
                }
                red[u]++;
                //if(red[ind])continue;
                //red[ind]++; 
                if(ind && !green[ind]){
                    tmp.push(ind);
                    tmp2.push(anc);
                }
            }
            que2 = tmp;
            que22 = tmp2;
        }
        step++;
    }
    //cout<<max(1,max(cnt,(int)ans.size()))<<endl; 
    cout<<(int)ans.size()<<endl; 
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