#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 5000 + 10;
int a[N];
int ma[N];
vector<int>divsor;
int ans[N + 10];

const int maxn = 1e5;
bool st[maxn + 1];
int primes[maxn], tot;
void sieve(){
    for(int i = 2; i <= maxn; i ++ ){
        if(!st[i]) primes[tot++] = i;
        for(int j = 0; primes[j] <= maxn/i; j ++ ){
            int pr = primes[j];
            st[i * pr] = 1;
            if(i % pr == 0) break;
        }
    }
}
vector<int> lx;
int main(){
    ios::sync_with_stdio(0);
    sieve();
    int n; cin>>n;
    fori(i,0,n) cin>>a[i];
    fori(i,0,n){
       // for(int j = 2; j* j <= abs(a[i]); j ++ ) while(a[i] % (j*j) == 0) a[i] /= (j*j);
        int x = abs(a[i]), mid = sqrt(abs(a[i]));
        int f = a[i]<0;
        divsor.clear();
        for(int k = 0; k < tot && x >= primes[k]; k ++ ){
            int j = primes[k];
            if(x % j == 0){
                int cnt = 0;
                while(x % j == 0) x /= j, cnt++;
                if(cnt & 1)divsor.push_back(j);
            }
        }
        if(x > 1) divsor.push_back(x);
        int xa = 1;
        for(int j = 0; j < divsor.size(); j ++ ) xa *= divsor[j];
        if(f) xa = -xa;
        if(a[i] == 0) continue;
        a[i] = xa;
    }
    //fori(i,0,n) cout<<a[i]<<" \n"[i==n-1];
    fori(i,0,n) lx.push_back(a[i]);
    sort(lx.begin(), lx.end());
    lx.erase(unique(lx.begin(),lx.end()), lx.end());
    int posZero = -1;
    fori(i,0,n) {
        bool ok = false;
        if(a[i] == 0) ok = true;
        a[i] = lower_bound(lx.begin(), lx.end(), a[i]) - lx.begin();
        if(ok) posZero = a[i];
    }
    //fori(i,0,n) cout<<a[i]<<" \n"[i==n-1];
    fori(i,0,n){
        int zero = 0, cnt = 0, neg = 1;
        fori(i,0,N) ma[i] = 0;
        fori(j,i,n){
            if(a[j] == posZero){
             //   if(!zero && !cnt) cnt++;
             //   zero = 1;
            }else {
                if(!ma[a[j]]) cnt++;
                ma[a[j]]++;
            }
            ans[max(cnt,1)]++;
        }
    }
    For(i,1,n) cout<<ans[i]<<" \n"[i == n];
    return 0;
}