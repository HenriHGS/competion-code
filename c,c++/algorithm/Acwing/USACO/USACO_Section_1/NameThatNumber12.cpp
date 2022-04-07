/*
这题的突破口：
字典很小。枚举字典，之后去比较编号即可。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
using namespace std;
typedef double db;
typedef long long LL;
typedef pair<int,int> pa;
const int maxn = 100000 + 5;
const db eps = 1e-6;

int st[26] = {
    2,2,2,
    3,3,3,
    4,4,4,
    5,5,5,
    6,6,6,
    7,-1,7,
    7,8,8,
    8,9,9,
    9,-1
};

int main() {
    string num;
    cin>>num;
    vector<string> vii;
    string s;
    while(cin>>s)vii.pb(s);
    bool fl = false;
    fori(i,0,sz(vii)){
        string s = vii[i];
        if(sz(s) != sz(num))continue;
        bool ok = true;
        fori(j,0,sz(num)){
            char now = st[s[j]-'A']+'0';
            ok &= now == num[j];
        }
        if(!ok)continue;
        cout<<s<<endl;
        fl = true;
    }
    if(!fl) cout<<"NONE"<<endl;
    return 0;
}