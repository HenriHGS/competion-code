#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;
int fa[N];
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
int a[N], n;
void init(){
    for(int i = 1; i <= n; i++ ) fa[i] = i;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    init();
    int cnt_root = 0, ans = 0, root = 0;
    for(int i = 1; i<= n; i ++ ) {
        cin>>a[i], cnt_root += a[i] == i;
        if(a[i] == i){
            root = i;
        }
    }
    if(cnt_root == 0){
        ans++;
        for(int i = 1; i <= n; i ++ ){
            int x = i, y = a[i];
            int fx = find(x), fy = find(y);
            //cout<<"i:"<<i<<", fx:"<<fx<<",fy:"<<fy<<endl;
            if(fx != fy){
                fa[fx] = fy;
            }else {
                //find the circle
                root = i;
                a[i] = i;
                break;
            }
        }
    }
    init();
    for(int i = 1; i <= n; i ++ ){
        int x = i, y = a[i];
       
        int fx = find(x), fy = find(y);
       // cout<<"i:"<<i<<", fx:"<<fx<<",fy:"<<fy<<endl;
        if(fx != fy){
            fa[fx] = fy;
        }else if(x != root){
            ans++;
            //find the circle
            a[i] = root;
           // break;
        }
    }
    cout<<ans<<endl;
    for(int i = 1; i <= n; i ++ ) cout<<a[i]<<" \n"[i==n];
    return 0;
}