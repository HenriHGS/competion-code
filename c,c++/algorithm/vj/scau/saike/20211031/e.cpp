#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <numeric>
#include <map>
#include <iostream>
#define debug(a) cout<<#a<<":"<<a<<endl
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int mod = 425;
const int N = 1e5+10;

typedef long long ll;
int read(){
    char ch = getchar(); int f = 0, x = 0;
    while(!isdigit(ch)) f |= (ch=='-'), ch = getchar();
    while(isdigit(ch)) x = x*10 + ch-'0', ch = getchar();
    return f?(-x):x;
}
int a[N], b[N];
map<vector<int>, int> vis;
map<vector<int>, int> ansm;
queue<vector<int>> q;
int main(){
    int n = read();
    fori(i,0,n) b[i] = read();
    fori(i,0,n) a[i] = read();
    //printf("%d\n", n);
    vector<int> u(n);
    iota(u.begin(),u.end(),0);
    ansm[u] = 0;
    int ans = accumulate(a,a+n,0);
    while(u.size()){
        int siz = u.size();
        vector<int> nv;
        int mx = 0;
        bool ok = false;
        for(auto x: u) cout<<x<<' ';
        cout<<endl;
        int ban[100]{};
        fori(i,0,siz){
            int ind = u[i];
            int j =  (i + 1)%siz;
            if(b[ind] > siz) continue;
            int ed = (i + b[ind])%siz;
            int cnt = 1;
            for(j; cnt < b[ind]; cnt++, j = (j+1)%siz){
                int ind2 = u[j];
                int eed = (j + b[ind2]) % siz;
                if(eed <= ed && )
            }
        }
        fori(i,0,siz){
            int ind = u[i];
            vector<int>v;
            if(b[ind] > siz) continue;
            ok = true;
            int cnt = 0;
            int j = i;
            int sum = 0;
            for(j; cnt < b[ind]; j = (j + 1)%siz) {
                cnt++;
                sum += a[u[j]];
              //  debug(j);
            }
            cnt = 0;
            if(ans - (sum - a[ind]) > mx){
                for(j; cnt < siz - b[ind]; j = (j + 1)%siz,cnt++){ 
                    v.pb(u[j]);
                // debug(u[j]);
                }
                mx = ans - (sum - a[ind]);
                sort(v.begin(),v.end());
                nv = v;
            }
        }
        if(!ok) break;
        ans = mx;
        u = nv;
    }
    printf("%d\n", ans);
    return 0;
}