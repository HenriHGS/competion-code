#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = x; i <= (y); i ++ )
using namespace std;
typedef long long ll;
const int mod = 998244353;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k&1) res = (ll)res*a%p;
        a = (ll)a*a%p;
        k >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    For(i,1,100)For(j,1,1000){
        int tmp = i;//i*i%mod;
        tmp = tmp*qpow(j,mod-2,mod)%mod;
        if(tmp == 499122190){
            //cout<<"i:"<<i<<"  i * i:"<<i*i<<"  j:"<<j<<endl;
            cout<<"i:"<<i<<"  j:"<<j<<endl;
            break;
        }
    }
    return 0;
}