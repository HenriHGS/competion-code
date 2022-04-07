#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#define debug(a) cout<<#a<<": "<<a<<endl
#define sz(a) (int)a.size()
#define sz(a) (int)a.size()
using namespace std;
typedef long long LL;
vector<string>All;
void dfs(int x, int len, string s){
    if(x > len){
        string odd = s.substr(0,len-1);
        string even = s;
        reverse(s.begin(),s.end());
        odd += s;
        even += s;
       // if(len==5)cout<<odd<<' '<<even<<endl; 
        All.push_back(odd);
        All.push_back(even);
        //cout<<odd<<' '<<even<<endl;
        return ;
    }
    int add = 1;
    if(x==1)add++;
    int bg = 0;
    if(x==1)bg++;
    for(int i = bg; i <= 9;  i += add){
        dfs(x+1,len,s + (char)(i+'0'));
    }
}
bool check(string s){
    return s == string(s.rbegin(), s.rend());
}
vector<string> init(){
    string d;
    for(int len = 1; len <= 5; len++)dfs(1, len, d);
   // sort(all.begin(),all.end());
    vector<string>dmp;
    //cout<<sz(all)<<endl;
   // cout<<all.back()<<endl;
    for(int i = 0; i < sz(All); i ++ ){
        if(check(All[i])) dmp.push_back(All[i]);
    }
    return dmp;
}
bool check(LL x){
    int mid = sqrt(x);
    for(int i = 2; i <= mid; i ++ ){
        if(x%i==0)return false;
    }
    return true;
}
const int maxn = 8e7+10000;
bool st[maxn+1];
int primes[maxn/10+100000];
int cnt;
void sieve(){
    for(int i = 2; i <= maxn; i ++ ){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= maxn/i; j++){
            st[i*primes[j]] = 1;
            if(i%primes[j] == 0) break;
        }
    }
}
int main(){
    sieve();
    int a, b;
    cin>>a>>b;
    vector<string>smp = init();
  //  cout<<sz(smp)<<endl;
    vector<LL>dmp;
     smp.erase(unique(smp.begin(),smp.end()), smp.end());
     
    for(int i = 0; i < sz(smp); i ++ ){
        LL val = stoll(smp[i]);
      //  if(i>2000)cout<<val<<endl;
        //if(check(val))
        dmp.push_back(val);
    }
    sort(dmp.begin(),dmp.end());
   // for(int i = 0; i < 2; i ++ )cout<<dmp[i]<<endl;
   dmp.erase(unique(dmp.begin(),dmp.end()), dmp.end());
   
   int cnt = 0;
   for(int i = 0; i < sz(dmp); i ++ ){
       if(dmp[i]<a)continue;
       if(dmp[i]>b || dmp[i]>maxn)break;
      if(!st[dmp[i]]) {
          cout<<dmp[i]<<endl, cnt++;
        //if(cnt == 780)debug(dmp[i]);//cout<< #(dmp[i]) <<": "<<dmp[i]<<endl;
      }
   }
   
   /*
    int tot1 = lower_bound(dmp.begin(),dmp.end(),b) - dmp.begin();
   // if(dmp[tot1] > b) tot1--;
    int tot2 = lower_bound(dmp.begin(),dmp.end(),a-1) - dmp.begin();
    //if(dmp[tot2] > a-1)tot2--;
    cout<<tot1-tot2<<endl;
    */
    return 0;
}