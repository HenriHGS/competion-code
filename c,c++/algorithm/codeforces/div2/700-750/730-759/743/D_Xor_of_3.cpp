#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 2e5+10;
int n, a[N];
void get1(vector<int>& ans,int l, int r){
    int i = l;
    vector<int> tmp;
    for(i; i <= r; i += 2){
        if(i + 2 == r){
            ans.pb(i);
            break;
        }
        ans.pb(i); tmp.pb(i);
    }
    reverse(tmp.begin(),tmp.end());
    for(auto x: tmp) ans.pb(x);
}
void sol(){
    scanf("%d", &n);
    int res = 0, oddZero = -1;
    For(i,1,n) {
        scanf("%d", &a[i]);
        res ^= a[i];
        if(res == 0 && i & 1 && oddZero < 0) oddZero = i;
    }
    if(res & 1 || oddZero < 0) {
        printf("NO");
        return ;
    }
    bool ok = true;
    vector<int> pos, ans;
    vector<int> odd, even;
    For(i,1,n){
        if(a[i] == 1) {
            if(pos.size() & 1){
                int len = i - pos.back() - 1;
                if(len&1) {
                    get1(ans, pos.back(), i);
                    pos.pop_back();   
                }
                else pos.pb(i);
            } else pos.pb(i);
        }
    }
    for(int i = 0; i < pos.size(); i += 2){

    }
    if(!ok) printf("NO");
    else {
        printf("YES");

    }
}
int main(){
    int tt; scanf("%d", &tt);
    while(tt--){
        sol();
    }
    return 0;
} 