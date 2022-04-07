/*
一开始的写法不是很优雅。这个是改过的。。。。。
*/
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 210;
int reg[N];
int seg[N];
int cnt;
int main(){
    int m, s, c;
    cin>>m>>s>>c;
    for(int i = 0; i < c; i ++ )cin>>reg[i];
    sort(reg,reg+c);
    for(int i = 1; i < c; i ++ )seg[cnt++] = reg[i] - reg[i-1] - (reg[i] == reg[i-1]? 0 :1);
    sort(seg,seg+cnt);
    int ans = c, cur = c, j = 0;
    while(c > m){
        ans += seg[j++];
        c--;
    }
    cout<<ans<<endl;
    return 0;
}