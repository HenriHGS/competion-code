#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <numeric>
#include <queue>
#define x first
#define y second
#define pb push_back
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int N = 2e5+10;
const int INF = 1e9+10;
int g[10][10];
int main(){
    ios::sync_with_stdio(0);
    int m; cin>>m;
    For(i,1,m){
        int x, y; cin>>x>>y;
        x--, y--;
        g[x][y] = g[y][x] = 1;
    }
    vector<int> st(9,9), p(9);
    iota(p.begin(),p.end(),1);
    //fori(i,0,9) cout<<p[i]<<" \n"[i == 9-1];
    map<vector<int>,int> count;
    do{
        count[p] = INF;
    }while(next_permutation(p.begin(),p.end()));
    
    For(i,1,8) {
        int x;cin>>x;
        st[x-1] = i;
    }
    count[st] = 0; 
    queue<vector<int>> q;
    q.push(st); count[st] = 0;
    map<vector<int>,int> vis;
    while(!q.empty()){
        auto u = q.front(); q.pop();
       // for(int i = 0; i < 9; i ++ ) cout<<u[i]<<" \n"[i == 8];
        vis[u] = false;
        for(int i = 0; i < 9; i ++ ){
            if(u[i] == 9){
                for(int j = 0; j < 9; j ++ ){
                    if(g[i][j]){
                        auto v = u;
                        swap(v[i], v[j]); 
                        if(count[v] > count[u] + 1){
                            count[v] = count[u] + 1;
                            if(!vis.count(v) || vis[v] == 0){
                                q.push(v);
                                vis[v] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    iota(p.begin(),p.end(),1);
    if(count[p] == INF) cout<<-1<<endl;
    else cout<<count[p]<<endl;
    return 0;
}