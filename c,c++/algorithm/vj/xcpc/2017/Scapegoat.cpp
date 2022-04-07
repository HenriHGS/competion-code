#include <cstdio>
#include <cstring>
#include <queue>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;

struct Node{
    int cnt, num;
    bool operator < (const Node& a) const {
        return 1.0*cnt*cnt/num/(num+1) < 1.0*a.cnt*a.cnt/a.num/(a.num+1);
    }
};
const int N = 2e5+10;
#define db double
int a[N];
typedef long long ll;
int cas;
void sol(){ 
    int n, m; scanf("%d %d", &n, &m);
    db ans = 0;
    ll sum = 0;
    For(i,1,n) scanf("%d", &a[i]), sum += a[i];
    priority_queue<Node> q;
    For(i,1,n){
        q.push(Node{a[i],1});
    }
    int tot = m - n;
    while(tot--){
        auto tp = q.top();
        q.pop();
        tp.num++;
        q.push(tp);
    }
    db avg = 1.0*sum/m;
    while(!q.empty()){
        db add = 1.0*q.top().cnt/q.top().num;
        ans += q.top().num*(add - avg)*(add - avg);
        q.pop();
    }
    ans /= m;
    printf("Case #%d: %.8f\n",++cas, ans);
}

int main(){
    int tt; scanf("%d",&tt);
     while(tt--) sol();
}
