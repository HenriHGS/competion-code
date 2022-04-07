#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
#include <numeric>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()

const ll infLL = LLONG_MAX/3;

#ifdef int
const int inf = infLL;
#else 
const int inf = INT_MAX/2-100;
#endif


template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

using vi=vc<int>;

template<class E, class D>
struct hungarian{
    int n, m;
    const vvc<E>&g;
    vc<D> l,r,q;
    vi to, ot, p;
    vc<char> lu,ru;
    int sz = 0;
    D ans = 0;
    void L(int i){
        lu[i] = 1;
        for(auto e:g[i])if(!ru[e.to]){
            D w = l[i] + r[e.to] - e.cost;
            if(q[e.to] > w){
                p[e.to] = i;
                q[e.to] = w;
            }
        }
    }
    bool arg(){
        fill(all(p),-1);
        fill(all(q),inf);
        fill(all(lu),0);
        fill(all(ru),0);
        for(int i = 0; i < n; i ++ ) if(to[i] == -1)L(i);
        while(1){
            int x = -1;
            for(int i = 0; i < m; i ++ ) if(!ru[i] && p[i]!=-1 && (x==-1||q[x]>q[i])) x=i;
            if(x==-1)return false;
            D w = q[x];
            for(int i = 0; i < n; i ++ )if(lu[i])l[i]-=w;
            for(int i = 0; i < m; i ++ )if(ru[i])r[i]+=w;else if(p[i]!=-1)q[i]-=w;
            if(ot[x]==-1){
                while(x!=-1){
                    ot[x]=p[x];
                    swap(to[ot[x]],x);
                }
                sz++;
                return true;
            }
            ru[x] = 1;
            L(ot[x]);
        }
    }
    hungarian(int nn, int mm, const vvc<E>&gg):n(nn),m(mm),g(gg),l(n),r(m)
    ,q(m),to(n,-1),ot(m,-1),p(m),lu(n),ru(m){
        D mx = -inf;
        for(int i = 0; i < n; i ++ )for(auto e:g[i])mx = max(mx,e.cost);
        fill(all(l),mx);
        while(arg())ans = max(ans,get());
    }
    D get(){
        D mn = *min_element(all(l));
        return accumulate(all(l),accumulate(all(r),(-n+sz)*mn));
    }
};
int main(){
    return 0;
}