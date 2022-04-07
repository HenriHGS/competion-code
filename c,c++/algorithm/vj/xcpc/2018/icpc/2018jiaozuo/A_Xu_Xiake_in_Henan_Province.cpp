#include <bits/stdc++.h>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++)
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int N = 2e5+10;
#define db double
int a[N], cas;
int c[4];
const string ans[5] = {"Typically Otaku","Eye-opener","Young Traveller","Excellent Traveller",
"Contemporary Xu Xiake"};
void sol(){
    fori(i,0,4) scanf("%d", &c[i]);
    int cnt = 0;
    fori(i,0,4){
        cnt += (c[i] > 0);
    }
    //printf("%s", ans[cnt]);
    cout<<ans[cnt]<<endl;
}

int main(){
    int tt; scanf("%d", &tt);
    while(tt--) sol();
    return 0;
}