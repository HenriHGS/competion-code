#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 1e5+10;
const int NM = 2;
const int mod = 1e9+7;

template<class T> using vc = vector<T>;
template<class T> using vvc = vc<vc<T>>;
using vi = vc<int>;
typedef long long ll;
ll a[N], n;
template<class T>
struct Matrix{
public:
    //vvc<T> m;
    int m[NM][NM];
    /*
    Matrix(){
       // m.resize(NM);
     //   fori(i,0,NM) m[i].resize(NM);
    }
    */
   /*
    Matrix(vvc<T> v){
      //  new(this) Matrix();
       // fori(i,0,v.size()) fori(j,0,v[i].size()) m[i][j] = v[i][j];
    }
    */
    Matrix(int x = 0){
        //new(this) Matrix();
        fori(i,0,NM)fori(j,0,NM) m[i][j] = i == j ? x:0;
    }
    Matrix operator * (const Matrix& b) const{
        Matrix res;
        auto&mt = res.m;
        auto&m1 = m, &m2 = b.m;
        fori(i,0,NM)fori(j,0,NM){
            fori(k,0,NM){
                res.m[i][j] = res.m[i][j] + 1LL*m1[i][k]*m2[k][j]%mod;
                res.m[i][j] %= mod;
            }
        }
        return res;
    }
    Matrix matrixQpow(Matrix& a, ll k){
        Matrix res(1);
      //  res.print();
        while(k){
            if(k&1ll) res = res*a;
            a = a*a;
            k >>= 1ll;
        }
       // a = res;
        return res;
    }
    void print(){
        fori(i,0,NM)fori(j,0,NM){
            cout<<m[i][j]<<' ';
            if(j == NM - 1)puts("");
        }
        puts("");
    }
};
int qpow(int a, ll k){
    int res = 1;
    while(k){
        if(k &1ll) res = 1LL*res*a%mod;
        a = 1LL*a*a%mod;
        k >>= 1ll;
    }
    return res;
}
int main(){
    scanf("%lld", &n);
    ll mx = 8e18, mi = 0;
    bool even = false;
    For(i,1,n) {
        scanf("%lld", &a[i]);
        even |= a[i]%2==0;
    }
    mx = *max_element(a+1,a+1+n);
    mi = *min_element(a+1,a+1+n);
    Matrix<int> ma, mb;
    int inv2 = qpow(2,mod-2);
   // debug(inv2);
    ma.m[0][0] = 2; ma.m[0][1] = 0;
    ma.m[1][0] = 2; ma.m[1][1] = -1;
    
    mb.m[0][0] = inv2;
    mb.m[1][0] = 0;
    int ansb = 2, ansa = 1;
     if(mx == mi && mx == 1){
        printf("0/1\n");
        return 0;
    } 

    //ma.print();

    // ansb
    For(i,1,n) ansb = qpow(ansb,a[i]);
    
    

    ansb = 1LL*ansb*inv2%mod;
    //ansa
    For(i,1,n) ma = ma.matrixQpow(ma, a[i]);//,debug(a[i]);
    
  //  ma.print();

    ma = ma*mb;
   // debug(ma.m[0][0]);
    ansa = (ma.m[1][0] + mod)%mod;
    //ansa = ansa*inv2;
   // debug(ansa);
    if(!even) ansa = 1LL*(ansa - 1 + mod)*inv2%mod;
    else ansa = 1LL*(ansa + 1)%mod*inv2%mod;
    printf("%d/%d",ansa,ansb);
    return 0;
}