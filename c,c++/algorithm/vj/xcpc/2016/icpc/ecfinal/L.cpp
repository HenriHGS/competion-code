#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#define pb push_back
#define debug(a) cout<<#a<<':'<<a<<endl
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5+10;
const int INF = 1e9+10;
vector<int> e[N];
int col[N];

int cur[10];
map<vector<int>,int> ma;
void check(){
    //cur[1]
    vector<int>a(4,0);
    if(cur[1] == 1)a[0]+=3;
    else if(cur[1] == 2) a[1] += 3;
    else a[0]++, a[1]++;
    
    if(cur[2] == 1)a[0]+=3;
    else if(cur[2] == 2) a[2] += 3;
    else a[0]++, a[2]++;
    
    if(cur[3] == 1)a[0]+=3;
    else if(cur[3] == 2) a[3] += 3;
    else a[0]++, a[3]++;
    
    if(cur[4] == 1)a[1]+=3;
    else if(cur[4] == 2) a[2] += 3;
    else a[1]++, a[2]++;
    
    if(cur[5] == 1)a[1]+=3;
    else if(cur[5] == 2) a[3] += 3;
    else a[1]++, a[3]++;
    
    if(cur[6] == 1)a[2]+=3;
    else if(cur[6] == 2) a[3] += 3;
    else a[2]++, a[3]++;
    ma[a]++;
}
void dfs(int x){
    if(x > 6){
        check();
        return ;
    }
    cur[x] = 0;
    dfs(x+1);
    cur[x] = 1;
    dfs(x+1);
    cur[x] = 2;
    dfs(x+1);
}

int main(){
    dfs(1);
    int tt; scanf("%d", &tt);
    For(i,1,tt){
        vector<int>a(4);
        fori(j,0,4) scanf("%d", &a[j]);
        printf("Case #%d: ", i);
        if(ma.count(a)== 0)puts("Wrong Scoreboard");
        else if(ma.count(a)==1 && ma[a] == 1)puts("Yes");
        else puts("No");
       // cout << n / 3 << endl;
        
    }
    return 0;
}