#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#define pb push_back
#define sz(a) (int)a.size()
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const int N = 3e5+10;
typedef long long ll;

int n;
void sol(){
    #define ldb long double
    scanf("%d", &n);
    vector<ldb> v;
    For(i,1,n){
        ldb a, b; scanf("%llf:%llf",&a,&b);
        v.pb((a/(a+b)));
    }
    int ans = 0;
    ldb sum = 0;
    sort(v.begin(),v.end());
    fori(i,0,sz(v)){
        sum += v[i];
        if(sum < 1.0)ans++;
    }
    printf("%d\n", ans);
}
int main(){
    int tt; scanf("%d", &tt);
    int cas = 0;
    while(tt--){
        printf("Case #%d: ", ++cas);
        sol();
    }
    return 0;
}
//https://vjudge.net/solution/11975480 二分答案
//https://blog.csdn.net/Mr_Kingk/article/details/105078255?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_utm_term~default-9.no_search_link&spm=1001.2101.3001.4242
//二分求后缀数组
//https://vjudge.net/solution/11836538 后缀数组