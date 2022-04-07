#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define pb push_back
#define sz(a) (int)(a.size())
#define mst(x,a) memset(x,a,sizeof(x))
#define fzhead Edge(int u, int v, int c, int f)
#define fzbody from(u), to(v), cap(c), flow(f)
using namespace std;
const int maxn=1e2+10;
const int inf=0x3f3f3f3f;
struct Edge
{
    int from,to,cap,flow;
    Edge(){}
    fzhead:fzbody{}
};
struct Dinic{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>g[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    void init(int n){
        this->n=n;
        for(int i=0; i<n; i++)g[i].clear();
        edges.clear();
    }
    void add(int from, int to, int cap){
        edges.pb({from,to,cap,0});
        edges.pb({to,from,0,0});
        m=edges.size();
        g[from].pb(m-2);
        g[to].pb(m-1);
    }
    bool bfs(){
        mst(vis,0);mst(d,0);
        queue<int>q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int i=0; i<sz(g[x]); i++){
                Edge&e=edges[g[x][i]];
                if(!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x,int a){
        if(x==t||a==0)return a;
        int flow=0,f;
        for(int &i=cur[x]; i<sz(g[x]); i++){
            Edge&e=edges[g[x][i]];
            if(d[x]+1==d[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[g[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int maxflow(int s, int t){
        this->s=s,this->t=t;
        int flow=0;
        while(bfs()){
            mst(cur,0);
            flow+=dfs(s,inf);
        }
        return flow;
    }
} dinic;
int n,m,p,c;
int main()
{
    //while(~
    scanf("%d", &n);//){
        dinic.init(maxn);
        int s=n+1,t=n+2;
        dinic.add(s,1,inf);
        //dinic.add(1,t,inf);
        bool fl = false;
        For(i,1,n){
            string s;
            int v;
            cin>>s;
            if(s[0] == '*'){
                //type2
                cin>>v;
                dinic.add(i,v,inf);
                if(v == 1 && i == 1)dinic.add(v,t,inf);
                else if(v == 1)dinic.add(i,t,inf);
            }else {
                int num = stoi(s);
                For(j,1,num){
                    cin>>v;
                    dinic.add(i,v,1);
                    if(v == 1)dinic.add(i,t,1);
                    //if(v == 1)dinic.add(v,t,1);
                    //if(v == 1 && i == 1)fl = true;
                }
            }
          //  dinic.add(i,t,inf);
        }
       // cout<<"ok"<<endl;
       int ans = dinic.maxflow(s,t);
       if(ans == inf){
           puts("*");//cout<<"*"<<endl;
       }else printf("%d\n", ans+1);//cout<<ans+1<<endl<<endl;
    //}
    return 0;
}