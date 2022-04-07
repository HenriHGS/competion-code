#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
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
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
typedef pair<int,int>pa;
typedef pair<ll,ll>pai;
typedef pair<db,db> pdd;
const db eps = 1e-6;
const db pi = acos(-1.0);

template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= ch == '-', ch = getchar();
    while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
    return f ? -x : x;
}
template<typename T> void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) print(x / 10);
    putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
    print(x), putchar(let);
}
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1e6 + 6;

void sol(){
    int a[5];
    For(i,1,4)cin>>a[i];
    vector<string>v;
    bool fl = true;
    if(a[4] > min(a[1],a[2]) || a[3]==0&&a[4]==0&&a[1]&&a[2]){
        cout<<-1<<endl;
        return ;
    }
    For(i,1,a[4]){
        v.pb("74");
    }
    a[1] -= a[4], a[2] -= a[4];
    if(a[4])a[3] -= a[4] - 1;
    if(a[3] < 0 || a[3] > 2 && !v.empty() || a[3] >= 2 && v.empty() || a[1] < 0 || a[2] < 0){
        cout<<-1<<endl;
        return ;
    }
    /*
    for(auto s: v)cout<<s;
    cout<<endl;
    for(int i = 1; i <= 4; i ++ )debug(a[i]);
    */
    if(v.empty()){
        if(a[3] && a[1] && a[2]){
            v.pb("47");
            a[1]--;
            a[2]--;  
        }else if(a[3]){
            cout<<-1<<endl;
            return ;
        }
    }else if(a[3]){
        if(a[1]){
            v[0] = "4" + v[0];
            a[1]--;
            a[3]--;
        }
        if(a[3] && a[2]){
            v.back() = v.back() + "7";
            a[2]--;
            a[3]--;
        }
        if(a[3]){
            cout<<-1<<endl;
            return ;
        }
    }
    /*
    for(auto s: v)cout<<s;
    cout<<endl;
    */
    if(a[1]){
        if(v.empty())v.pb(string(a[1],'4'));
        else if(v[0][0] == '4')v[0] = string(a[1],'4') + v[0];
        else v[0] = v[0] + string(a[1],'4');
    }
    if(a[2]){
        if(v.empty())v.pb(string(a[2],'7'));
        else if(v.back().back() == '7') v.back() = v.back() + string(a[2],'7');
        else if(v.back()[0] == '4'){
            int pos = -1;
            string s = v.back();
            for(int i = 0; i < sz(s); i ++ ){
                if(s[i] == '7'){
                    pos = i;
                    break;
                }
            }
            if(pos == -1){
                cout<<-1<<endl;
                return ;
            }
            v.back() = s.substr(0,pos) + string(a[2],'7') + s.substr(pos) ; 
        }
        else v.back() = string(a[2],'7') + v.back();
    }
    for(auto s: v)cout<<s;
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sol();
    return 0;
}
/*
hack1: 4 3 3 3
4747474
hack2: 4 3 2 3
7447474
hack2: 7 2 0 0
-1
hack3: 7 2 0 1
774444444
hack4: 7 2 1 0
444444477
hack5: 4 3 4 3
4747474
*/