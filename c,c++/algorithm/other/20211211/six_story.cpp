#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n' 
#define debug(a) cout << #a << ": " << a << endl
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const int maxn = 100000 + 6;

bool cmp(const string& a,const string& b){
    if(a.size() != b.size()) return a.size()<b.size();
    for(int i = 0; i < a.size(); i ++ ){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return 0;
}
void mody(string &s){
    bool zero = true;
    int i = 0;
    while(zero && i + 1 < s.size()){
        zero = !(s[i] != '0') && zero;
        if(!zero)break;
        i++;
    }
    s = s.substr(i);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; 
    cin>>tt;
    while(tt--){
        int n; cin>>n;
        string s; cin>>s;
        s = " " + s;
        vector<string> ans;
        bool zero = true;
        //cout<<s<<endl;
        For(i,1,n){
            int j = i;
            string add = "";
            for(j; j <= n; j ++ ){
                if(s[j] == '6') break;
                add += s[j];
            }
            mody(add);
            if(add.size())ans.pb(add);
            zero = false;
            while(j <= n && s[j] == '6')j++;
            i = j - 1;
        }
        sort(ans.begin(),ans.end(), cmp);
        cout<<ans.size()<<endl;
        for(auto x:ans) cout<<x<<endl;
    }
    return 0;
}
/*

*/