#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <chrono>
#include <cstdint>
#include <queue>
#include <ctime>
#include <random>
#include <set>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

template<class T> using vc = vector<T>;
template<class T> using vvc = vc<vc<T>>;

using vi = vc<int>;

const int N = 2e5+10;
int c[11], n, m;
int a[11][N];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
set<vector<int>> ban, used;
vector<int>st;
void init(){
    scanf("%d", &n);
    st.resize(n+1,0);
    For(i,1,n){
        scanf("%d", &c[i]);
        For(j,1,c[i]) scanf("%d", &a[i][j]);
        st[0] += a[i][c[i]];
        st[i] = c[i];
    }
    scanf("%d", &m);
    For(i,1,m) {
        vector<int> tmp;
        For(j,1,n) {
            int x;
            scanf("%d", &x);
            tmp.pb(x);
        }
        ban.insert(tmp);
    }
}
//priority_queue<vector<int>> que;
set<vector<int>> que;
void sol(){
    que.insert(st);
    while(!st.empty()){
        auto it = prev(que.end());
        auto tp = *it;
        if(ban.find(vi(tp.begin() + 1,tp.end())) == ban.end()){
            bool first = true;
            for(int i = 1; i < tp.size(); i ++ ) {
                if(first) first = false;
                else printf(" ");
                printf("%d", tp[i]);
            }
            return ;
        }
        que.erase(it);
       // used.insert(tp);
        for(int i = 1; i <= n; i ++ ){
            if(tp[i] > 1){
                tp[i] --;
                int idx = tp[i];
                tp[0] += a[i][idx] - a[i][idx + 1];
             //   if(used.find(vi(tp.begin(), tp.end())) == used.end() ){
                    que.insert(tp);
              //  }
                tp[0] -= a[i][idx] - a[i][idx + 1];
                tp[i]++;
            }
        }
    }
}
int main(){
    init();
    sol();
    return 0;
}