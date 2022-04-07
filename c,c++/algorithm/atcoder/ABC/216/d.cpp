#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <iostream>
#define x first
#define y second
#define pb push_back
#define sz(a) a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define mp make_pair
using namespace std;
const int N = 2e5+10, M = 2e5+10;
typedef pair<int,int>PII;
vector<int> cy[M];
PII pos1[N], pos2[N];
int main(){
    int n, m;
    bool ok = true;
    cin>>n>>m;
    vector<int> du(n+1,0);
    set<PII> s;
    For(i,1,m){
        int sz,x;
        cin>>sz;
        fori(j,0,sz){
            cin>>x;
            cy[i].pb(x);
            if(j) du[x]++;
            if(pos1[x].x == 0) pos1[x] = mp(i,j);
            else pos2[x] = mp(i,j);
        }
    }
    For(i,1,n) s.insert(mp(du[i],i));
    while(!s.empty()){
//        PII pp = *s.begin();
        auto it = s.begin();
        PII p = *it;
        int x = p.y, j1 = -1, j2 = -1;
        int i1 = pos1[x].x, i2 = pos2[x].x; 
        if(i1 == i2 || p.x != 0)break;
        int sz1 = sz(cy[i1]); 
        int sz2 = sz(cy[i2]);
        if(pos1[x].y  + 1 < sz1) j1 =  pos1[x].y  + 1;
        if(pos2[x].y + 1 < sz2) j2 = pos2[x].y + 1;
        if(j1 != -1){
            int x1 = cy[i1][j1];
            auto it1 = s.find(mp(du[x1],x1));
            du[x1]--;
            s.erase(it1);
            s.insert(mp(du[x1],x1));
        }
        if(j2 != -1){
            int x2 = cy[i2][j2];
            auto it2 = s.find(mp(du[x2],x2));
            du[x2]--;
            s.erase(it2);
            s.insert(mp(du[x2],x2));
        }
        s.erase(it);
    }
    if(!s.empty()) puts("No");
    else puts("Yes");
    return 0;
}