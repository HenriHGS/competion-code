#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

struct Player{
    int score, id;
    bool operator < (const Player& a) const{
        if(score != a.score) return score > a.score;
        return id < a.id;
    } 
} play[110];
const char CGP[] = "CGP";
int st[110][110];
string s;
int main(){
    int n, m; cin>>n>>m;
    n*=2;
    For(i,1,n){
        play[i] = {0,i};
        cin>>s;
        fori(j,0,s.size())fori(k,0,3) if(CGP[k] == s[j])st[i][j+1] = k;
    }
    For(k,1,m){
        for(int i = 1; i <= n; i += 2){
            int a = play[i].id, b = play[i+1].id;
            int dis = st[a][k] - st[b][k];
            if(dis == 0) continue;
            if(abs(dis) == 2) dis *= -1;
            if(dis < 0) play[i+1].score++;
            else play[i].score++;
        }
        sort(play+1,play+n+1);
    }
    For(i,1,n) cout<<play[i].id<<endl;
    return 0;
}