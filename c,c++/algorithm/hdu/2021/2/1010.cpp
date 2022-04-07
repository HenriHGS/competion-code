#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef long long ll;
void sol(){
    ll a, p;
    cin>>a>>p;
    if(a&1)cout<<1<<endl;
    else cout<<0<<endl;
}

int table(ll a, ll p){
    vector<int>S;
    int res = 0;
    For(i,1,p-1){
        int val = a*i%p;
        S.push_back(val);
        sort(S.begin(),S.end());
        res += val - (lower_bound(S.begin(),S.end(),val) - S.begin() + 1);
    }  
    //cout<<res&1<<endl;
    return res&1;
}
const int N = 1e5+10;
bool st[N+1];
int primes[N+1], tot;
void sieve(){
    st[1] = 1;
    for(int i = 2; i <= N; i ++ ){
        if(!st[i])primes[tot++] = i;
        for(int j = 0; primes[j]<=N/i; j ++ ){
            st[i * primes[j]] = 1;
            if(i % primes[j] == 0) break;
        }  
    }
}
int main(){
    ios::sync_with_stdio(0);

    sieve();
    int down = 3, up = 9;
    for(int j = down; j <= up; j ++){
        cout<<"pr = "<<primes[j]<<endl;
        For(i,1,primes[j] - 1){
            if(table(i,primes[j]) %2 != i %2)cout<<"a: "<<i<<" ans:"<<table(i,primes[j])<<endl;
        }
        cout<<endl;
    }
    cout<<(3&1);
    /*
    int tt;
    cin>>tt;
    while(tt--)sol();
    */
    return 0;
}