#include <cstdio>
#include <cstring>
#include <iostream>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
void sol(){
    int cnt[2][26]{};
    bool ok = false;
    string s;
    fori(i,0,2){
        cin>>s;
        fori(j,0,s.size()){
            int c = s[j] - 'a';
            cnt[i][c]++;
        }
    }
    fori(i,0,26) ok |= (cnt[0][i] && cnt[1][i]);
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(0);
    int tt; cin>>tt;
    while(tt--) sol();
    return 0;
}