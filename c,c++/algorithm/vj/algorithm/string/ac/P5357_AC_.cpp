#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10, maxn = 2e6+10;
int tr[N][26], fail[N], vis[N], idx; 
vector<string> T(N);
int n;
int tot;
int toAns[N];
int ans[N];
void extend(string& s, int id){
    int p = 0;
    for(int i = 0; i < s.size(); i ++ ){
        int c = s[i] - 'a';
        if(!tr[p][c]) tr[p][c] = ++idx;
        p = tr[p][c];
    }
    if(!vis[p]) {
        vis[p] = ++ tot;
        toAns[id] = vis[p];
    }else toAns[id] = vis[p];
}
int q[N];
int ed = 0;
void build(){
    int hh = 0, tt = -1;
    fori(i,0,26) if(tr[0][i]) q[++tt] = tr[0][i];
    while(hh <= tt){
        int t = q[hh++];
        fori(i,0,26){
            int p = tr[t][i];
            if(!p) tr[t][i] = tr[fail[t]][i];
            else {
                fail[p] = tr[fail[t]][i];
                q[++tt] = p;
            }
        }
    }
    ed = tt;
}
int cnt_times[N];
int cnt[N];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,1,n){
        cin>>T[i];
        extend(T[i], i);
    }
    build();
    string s;
    cin>>s;
    int p = 0;
    int mx = 0;
    for(int i = 0; i < s.size(); i ++ ){
        p = tr[p][s[i] - 'a'];
        cnt[p]++;
        /* int j  = p;
        while(j){
            if(vis[j]) {
                cnt_times[vis[j]]++;
                mx = max(mx, cnt_times[vis[j]]);
            } 
            j = fail[j];
        } */
    }
    //topo
    for(int i = ed; i >= 0; i -- ){
        int ind = q[i];
        ans[vis[ind]] = cnt[ind];
        cnt[fail[ind]] += cnt[ind];
    }
    For(i,1,n){
        int ind = toAns[i];
        cout<<ans[ind]<<endl;
    }
    return 0;
}