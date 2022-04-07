#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <set>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
using namespace std;
const int N = 1e5+10;
const int M = 2e5+10;
vector<int> e[N];
int w[N], n;
int dp[N];

multiset<int> lef, rig;
void del(multiset<int>& s, int x){
    auto it = s.find(x);
    s.erase(it);
}
void del(int x){
    if(lef.size() > rig.size()){
        if(lef.find(x) != lef.end()) del(lef,x);
        else {
            auto lmx = *lef.rbegin();
            del(lef,lmx);
            del(rig,x); rig.insert(lmx);
        }
    }else {
        if(lef.find(x) != lef.end()){
            del(lef,x);
            auto rmi = *rig.begin();
            del(rig,rmi); lef.insert(rmi);
        }else {
            del(rig,x);
        }
    }
}
void add(int nval){
    if(lef.size() > rig.size()){
        auto lmx = *lef.rbegin();
        del(lef,lmx);
        if(lmx <= nval){
            lef.insert(lmx);
            rig.insert(nval);
        }else {
            lef.insert(nval);
            rig.insert(lmx);
        }
    }else {
        if(lef.size()){
            auto lmx = *lef.rbegin();
            auto rmi = *rig.begin();
            del(lef,lmx); del(rig,rmi);
            if(nval >= rmi){
                rig.insert(nval);
                lef.insert(lmx); lef.insert(rmi);
            }else {
                lef.insert(lmx), lef.insert(nval);
                rig.insert(rmi);
            }
        }else lef.insert(nval);
    }
}
int qury(){
    int res;
    if(lef.size() > rig.size()){
        res = *lef.rbegin();
    }else {
        int lres = *lef.rbegin();
        int rres = *rig.begin();
        res = lres + rres>>1;
    }
    return res;
}
// op == 0 max
int dfs(int x, int fa, int op){
    add(w[x]);
    if(e[x].size() == 1 && x != 1){
        dp[x] = qury();
       // cout<<x<<' '<<qury()<<endl;
        del(w[x]);
        return dp[x];
    }
    for(auto j: e[x]){
        if(j == fa) continue;
        dfs(j,x,op^1);
        if(op == 0) dp[x] = max(dp[x],dp[j]);
        else {
            if(dp[x])dp[x] = min(dp[x],dp[j]);
            else dp[x] = dp[j];
        }
    }
    del(w[x]);
    return dp[x];
}
void init(){
    scanf("%d", &n);For(i,1,n) scanf("%d", &w[i]);
    For(i,1,n-1){
        int a, b; scanf("%d %d", &a, &b);
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs(1,-1,0);
    printf("%d\n", dp[1]);
}
int main(){
    init();
    return 0;
}