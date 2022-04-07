#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
using namespace std;
const int N = 110;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
using vi = vc<int>;
typedef long long ll;
const int mod = 1e9+7;

#define debug(a) cout<<#a<<":"<<a<<endl;
class Martix{
public:
    Martix(){
        m.resize(N);
        fori(i,0,N) m[i].resize(N);
    }
    Martix(int x){
        m.resize(N);
        fori(i,0,N) m[i].resize(N);
        fori(i,0,N) m[i][i] = x;
    }
    Martix(vvc<int>& mt){
        //this();
        int n = mt.size();
        new(this) Martix();
       // m.resize(N);
       // fori(i,0,N) m[i].resize(N);
        fori(i,0,n) fori(j,0,n) {
            m[i][j] = mt[i][j];
        }
        /* debug(n);
        debug(m[0].size());
        fori(i,0,n) fori(j,0,n){
            cout<<m[i][j]<<' ';
            if(j == n -1) cout<<endl;
        }
        cout<<endl; */
    }
    Martix operator * (const Martix&b)const {
        Martix res;
        auto& mt = res.m;
        auto& m1 = m, &m2 = b.m; 
        fori(i,0,N){
            fori(j,0,N){
                fori(k,0,N) mt[i][j] =  (mt[i][j] + 1LL*m1[i][k]*m2[k][j]%mod)%mod;
            }
        }
        /* cout<<"a:"<<endl;
        print(6);
        cout<<endl;

        cout<<"b:"<<endl;
        b.print(6);
        cout<<endl; */

        /* debug(mt[0].size());
        fori(i,0,6) fori(j,0,6){
            cout<<mt[i][j]<<' ';
            if(j == 6 -1) cout<<endl;
        }
        cout<<endl; */
        return res;
    }
    Martix qpow(Martix a, ll k){
        Martix res(1);
        while(k){
            if(k&1) res = res*a;
            a = a*a;
            k>>=1;
        }
        return res;
    }
    int get(int i, int j){
        return m[i][j];
    }
    void print(int n){
        fori(i,0,n)fori(j,0,n){
            cout<<m[i][j]<<' ';
            if(j == n -1) cout<<endl;
        }
    }
private:
    vvc<int> m;
};
ll n, k;
ll a[N];
int main(){
    scanf("%lld %lld", &n, &k);
    For(i,1,n) scanf("%lld", &a[i]);
    vvc<int> ma(n+1,vi(n+1));
    vvc<int> mb(n+1,vi(n+1));
    For(i,1,n)For(j,1,n) {
        ll x = a[i]^a[j];
        int cnt = __builtin_popcountll(x);
        if(cnt%3==0) ma[i][j] = 1;
    }
  /*   fori(i,0,n+1) fori(j,0,n+1){
            if(j == n) cout<<endl;
            cout<<ma[i][j]<<' ';
        } */
    For(i,1,n) mb[i][1] = 1;
    Martix a(ma), b(mb);
    a = a.qpow(a,k-1);
    /* a.print(n+1);
    cout<<endl; */
    a = a*b;
    /* a.print(n+1); */
    int ans = 0;
    For(i,1,n)ans = (ans + a.get(i,1))%mod;
    printf("%d\n", ans);
    return 0;
}

