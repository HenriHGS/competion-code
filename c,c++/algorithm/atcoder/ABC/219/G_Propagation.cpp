#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
typedef pair<int,int> pii;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
using vi = vc<int>;

const int LIMIT = 500;
const int N = 2e5+10;
int du[N];
vi e[N], e2[N];
int n, m, q;
void init(){
    scanf("%d %d %d", &n, &m, &q);
    For(i,1,m) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].pb(b); e[b].pb(a);
        du[a]++; du[b]++;
    }
    For(i,1,n){
        //if(du[i] <= 500) continue;
        for(auto j : e[i]){
            if(du[j] <= 500) continue;
            e2[i].pb(j);
        }
    }
}
#define fi first
#define se second
void sol(){
    vc<pii> upd(n+1,pii(-1,0)), ans(n+1);
    For(i,1,n) ans[i] = {0,i};
    For(t,1,q){
        int x; scanf("%d", &x);
        for(auto j: e2[x]){
            if(upd[j].fi > ans[x].fi){
                ans[x] = upd[j];
            }
        }
        ans[x].fi = t;
        if(e[x].size() <= LIMIT){
            for(auto j: e[x]){
                ans[j] = {t,ans[x].se};
            }
        }else {
            upd[x] = {t,ans[x].se};
        }
    }
    For(i,1,n){
        for(auto j: e2[i]){
            if(ans[i].fi < upd[j].fi){
                ans[i] = upd[j];
            }
        }
    }
    bool first = true;
    For(i,1,n){
        if(first) first = false;
        else printf(" ");
        printf("%d", ans[i].se);
    }
}
int main(){
    init();
    sol();
    return 0;
}
