#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int N = 1e6+10;
int color[N], siz[N];
int main(){
    ios::sync_with_stdio(0);
    string s; cin>>s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i ++ ){
        int c = s[i] - 'a' + 1;
        if(c != color[cnt]) color[++cnt] = c, siz[cnt] = 1;
        else if(c == color[cnt]) siz[cnt]++;
    }
    int ans = 0;
    while(cnt > 1){
        for(int i = 1; i <= cnt; i ++ ){
            if(i == 1 || i == cnt) siz[i] -= 1;
            else siz[i] -= 2;
        }
        int cur = 0;
        for(int i = 1; i <= cnt; i ++ ){
            if(siz[i] <= 0) continue;
            if(color[cur] != color[i]) color[++cur] = color[i], siz[cur] = siz[i];
            else siz[cur] += siz[i];
        }
        cnt = cur;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}