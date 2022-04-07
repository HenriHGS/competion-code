#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
using vi = vector<int>;
int main(){
    int n;
    scanf("%d", &n);
    vi v(n),c(n);
    for(int i = 0; i < n; i ++ ){
        scanf("%d", &v[i]);
        c[i] = v[i];
    }
    sort(c.begin(),c.end());
    int ans = 0;
    for(int rot = 1; rot <= 3; rot++){
        for(int i = 0; i < n; i ++ ){
            if(v[i] == rot && v[i] != c[i]){
                for(int j = 0; j < n; j ++ ){
                    if(c[j] == rot && v[j] == c[i]){
                        swap(v[i],v[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i ++ ){
        if(c[i] != 1) break;
        if(v[i] != c[i])cnt++;
    }
    ans += cnt*2;
    printf("%d\n",ans);
    return 0;
}