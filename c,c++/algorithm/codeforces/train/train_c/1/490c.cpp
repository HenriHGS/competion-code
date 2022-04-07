#include <iostream>
#include <string>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define rep(i,y,x) for(int i = (y); i >= (x); i -- )
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;
int pre[maxn], suf[maxn];
int main(){
    ios::sync_with_stdio(0);
    string s;
    int a, b;
    cin>>s;
    cin>>a>>b;
    int n = s.size();
    s = " " + s;

    For(i,1,n){
        pre[i] = (LL)pre[i-1]*10 % a + (s[i] - '0');
        pre[i] %= a; 
    }
    
    int base = 1;
    rep(i,n,1){
        suf[i] = (LL)suf[i+1] + (LL)(s[i] - '0') * base % b;
        suf[i] %= b;
        base = (LL)base*10%b; 
    }
    int pos = 0;
    For(i,1,n-1){
        if(pre[i] == 0 && suf[i+1] == 0 && s[i+1] != '0'){
            pos = i;
            break;
        }
    }
    if(!pos){
        cout<<"NO"<<endl;
    }else {
        cout<<"YES"<<endl;
        For(i,1,pos)cout<<s[i];
        cout<<endl;
        For(i,pos+1,n)cout<<s[i];
    }
    return 0;
}