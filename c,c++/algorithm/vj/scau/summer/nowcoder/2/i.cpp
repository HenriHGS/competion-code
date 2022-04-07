#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <stack>
#define mst(x,a) memset(x,a,sizeof(x))
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 21;
int dp[N][N][N][N][4];
const int inf = 0x3f3f3f3f;
//fir sec dir(fir)
char g[2][N][N], gans[2][N][N];
bool ok(int x, int y, int k){
    if(x >= 1 && x <= 20 && y >= 1 && y <= 20 && g[k][x][y] == '.') return true;
    return false;
}
void init(){
    For(i,1,20){
        fori(k,0,2){
            scanf("%s", (g[k][i] + 1) ) ;
        }
        fori(k,0,2)For(j,1,20) gans[k][i][j] = g[k][i][j];
    }
}
const char sans[] = "DLRU";
const int dx[]={1,0,0,-1};
const int dy[]={0,-1,1,0};
struct Two{
    int dis,x1, y1;
    int x2, y2;
    int dir;
    bool operator < (const Two a)const{
        return dis != a.dis ? dis > a.dis: dir > a.dir; 
    }
    bool operator == (const Two a) const{
        return dis == a.dis && x1 == a.x1 && x2 == a.x2 && y1 == a.y1 && y2 == a.y2 && dir == a.dir;
    }
} ;
Two pre[N][N][N][N][4];
//bool fl = false;
void bfs(int x1, int y1, int x2, int y2, int dir, int dis){
    Two now = {0,x1,y1,x2,y2,0};
    dp[x1][y1][x2][y2][0] = 0;
    priority_queue<Two> que;
    que.push(now);
    while(!que.empty()){
        now = que.top();que.pop();
        int & res =  dp[now.x1][now.y1][now.x2][now.y2][now.dir];
        if(now.x1 == 1 && now.y1 == 20 && now.x2 == 1 && now.y2 == 1){
            continue;
        }
        if(res != now.dis) continue;
        //res = dis;
        x1 = now.x1, x2 = now.x2, y1 = now.y1, y2 = now.y2;
        //cout<<now.x1<<' '<<now.y1<<' '<<now.x2<<' '<<now.y2<<' '<<now.dis<<' '<<sans[now.dir]<<endl;
        fori(k,0,4){
            int tx1 = now.x1 + dx[k];
            int tx2 = x2 + dx[k];
           // if(k == 1 || k == 2)tx2 = x2 + dx[3-k];
            int ty1 = y1 + dy[k];
            int ty2 = y2 + dy[k];
            if(k == 1 || k == 2)ty2 = y2 + dy[3-k];
           // cout<<tx1<<' '<<ty1<<' '<<tx2<<' '<<ty2<<' '<<endl;
            if(!ok(tx1,ty1,0) && !ok(tx2,ty2,1)) continue;
            if(!ok(tx1,ty1,0)) {
                Two fa = pre[x1][y1][tx2][ty2][k];
                int &nxt = dp[x1][y1][tx2][ty2][k];
                if(nxt > res + 1){
                    nxt = res + 1;
                    Two v = {-nxt, x1,y1,tx2,ty2,k};
                    que.push(v);
                    pre[x1][y1][tx2][ty2][k] = now;
                }else if(fa.dir > now.dir){
                    fa = now;
                }
            }
            if(!ok(tx2,ty2,1)){
                Two fa = pre[tx1][ty1][x2][y2][k];
                int &nxt = dp[tx1][ty1][x2][y2][k];
                if(nxt > res + 1){
                    nxt = res + 1;
                    Two v = {nxt, tx1,ty1,x2,y2,k};
                    que.push(v);
                    pre[tx1][ty1][x2][y2][k] = now;
                }else if(fa.dir > now.dir){
                    fa = now;
                }
            }
            if(ok(tx1,ty1,0) && ok(tx2,ty2,1)){
               // cout<<tx1<<' '<<ty1<<' '<<tx2<<' '<<ty2<<' '<<endl;
                Two fa = pre[tx1][ty1][tx2][ty2][k];
                int &nxt = dp[tx1][ty1][tx2][ty2][k];
                if(nxt > res + 1){
                    nxt = res + 1;
                    Two v = {nxt, tx1,ty1,tx2,ty2,k};
                    que.push(v);
                    pre[tx1][ty1][tx2][ty2][k] = now;
                }else if(fa.dir > now.dir){
                    fa = now;
                }
            }
        }
    }
}
void sol(){
    init();
    mst(dp,0x3f);
    bfs(20,20,20,1,0,0);
    int dir = 0, dis = inf;
    fori(i,0,4){
        if(dis > dp[1][20][1][1][i])//cout<<dp[1][20][1][1][i]<<endl;
        {
            dis = dp[1][20][1][1][i];
            dir = i;
        }
    }
    stack<char> trac;
    Two fir = {0,20,20,20,1,0};
    Two now = {dis,1,20,1,1,dir};
    while(1){
        if(now == {dis,1,20,1,1,dir}){
            ;
        }else {
            gans[0][now.x1][now.y1] = 'A';
            gans[0][now.x2][now.y2] = 'A';
        }
        if(now == fir){
            break;
        }
        trac.push(sans[now.dir]);
    }
}
int main(){
    sol();
    return 0;
}