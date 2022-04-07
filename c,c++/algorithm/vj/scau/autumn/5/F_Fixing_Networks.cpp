#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
vector<int> e[N];
int n, c, d;
void solve1(int n){
    int k = d/2;
    For(rot,1,k){
        fori(i,0,n){
            int v = (i - rot + n) % n;
            e[i].pb(v);
            e[v].pb(i);
        }
    }
    int add = n / 2;
    if(d & 1){
        fori(i,0,n){
            int v = (i + add) % n;
            e[i].pb(v);
           // e[v].pb(i);
        }
    }
}
void solve2(int start, int tot){
    while(tot--){
        For(id1,1,d+1){
            int u = id1 + start - 1;
            For(id2,id1+1,d+1){
                int v = id2 + start - 1;
                e[u].pb(v);
                e[v].pb(u);
            }
        }
        start += d + 1;
    }
}
int main(){
    scanf("%d %d %d", &n, &d, &c);
    int x = n / c;
    if(d == 0){
        if(c == n){
            puts("Yes");
            For(i,1,n)printf("\n");
        }else puts("No");
        return 0;
    }
    if(d == 1){
        if(c*2 == n){
            puts("Yes");
            For(i,1,n)printf("%d\n", (i&1)?(i+1):(i-1));
        }else puts("No");
        return 0;
    }
    if(n & 1 && d&1 || x < d + 1){
        puts("No");
        return 0;
    }
    int cnt = n - (d+1)*(c-1);
    solve1(cnt);
    solve2(cnt,c-1);
    puts("Yes");
    fori(i,0,n){
        sort(e[i].begin(),e[i].end());
        auto & v = e[i];
        fori(j,0,sz(v)) printf("%d ", v[j]+1);
        puts("");
    }
    return 0;
}