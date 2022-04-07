#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
int st[26];
bool cmp(string& s, string& t){
    int len = min(s.size(),t.size());
    fori(i,0,len){
        int c1 = st[s[i]-'a'];
        int c2 = st[t[i]-'a'];
        if(c1 == c2) continue;
        if(c1 < c2) return true;
        else return false;
    }
    if(s.size() < t.size()) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    string t; cin>>t;
    fori(i,0,26){
        st[t[i] - 'a'] = i;
    }
    int n; cin>>n;
    vector<string> v(n);
    fori(i,0,n) cin>>v[i];
    sort(v.begin(),v.end(),cmp);
    fori(i,0,n) cout<<v[i]<<endl;
    return 0;
}