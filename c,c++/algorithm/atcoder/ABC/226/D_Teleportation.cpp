#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>
#include <cctype>
#include <map>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch - '0', ch = getchar();
    return f? -x : x;
}
typedef long long ll;
typedef pair<int,int>PII;

int x[N], y[N];

vector<PII> lx;
#define X first
#define Y second
int main(){
    int n = read();
    For(i,1,n){
        x[i] = read(), y[i] = read();
    }
    For(i,1,n)For(j,1,n){
        if(i != j){
            lx.push_back({x[j] - x[i], y[j] - y[i]});
        }
    }
    sort(lx.begin(),lx.end());
    lx.erase(unique(lx.begin(),lx.end()),lx.end());
    int ans = 0;
    for(auto u: lx) {
        bool ok = true;
        for(auto v: lx){
            if(u.X == 0 && v.X || u.X && v.X == 0 
            || u.Y == 0 && v.Y || u.Y && v.Y == 0) continue;
            if(u.Y == 0){
                if(u.Y * v.Y < 0) continue;
                else if(u.Y % v.Y == 0) {
                    ok = false;
                    break;
                }
            }

        }
        ans += (!ok);
    }
    cout<<ans<<endl;
    return 0;
}