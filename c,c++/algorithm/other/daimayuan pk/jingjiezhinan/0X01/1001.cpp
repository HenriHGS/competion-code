#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int qpow(int a, int k, int p){
    int res = 1;
    while(k){
        if(k &1) res = res * 1ll* a % p;
        a = 1ll*a*a%p;
        k >>= 1;
    }
    return res % p;
}
int main(){
    int a, b, p;
    cin>>a>>b>>p;
    cout<<qpow(a,b,p);
    return 0;
}