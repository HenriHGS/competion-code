/*
不用跑暴搜，写了个暴搜。。。。
直接枚举，之后check就可以了。。。。。
*/
# include <cstdio>
#include <iostream>
using namespace std;
int n;
int val[20], vis[10];
int ans = 0;
int check(int x){
    int res = 0;
    while(x){
        if(!vis[x%10]) return false;
        x /= 10;
        res++;
    }
    return res;
}
void dfs2(int cur, int y, int x){
    if(cur > 2){
        int z, w, m[2];
        int tmp = y, i = 0;
        while(tmp){
            m[i++] = tmp%10;
            tmp /= 10;
        }
        z = m[0]*x;
        w = m[1]*x;
        int ret = z + w*10;
        /*
        if(x==222){
            cout<<x<<endl;
           cout<<y<<endl;
           cout<<z<<endl;
            cout<<w<<endl;
            cout<<ret<<endl;
        }
        */
        if(check(z) == 3&&check(w) == 3&&check(ret) == 4){
            ans++;
           //cout<<x<<endl;
           // cout<<y<<endl;
           // cout<<z<<endl;
            //cout<<w<<endl;
           // cout<<ret<<endl;
        }
        return ;
    }
    for(int i = 0; i < n; i ++ ){
        dfs2(cur+1,y*10+val[i], x);
    }
    return ;
}
void dfs1(int cur, int x){
    if(cur > 3){
        dfs2(1,0,x);
        return ;
    }
    for(int i = 0; i < n; i ++ ){
        dfs1(cur+1, x*10 + val[i]);   
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i = 0; i < n; i ++ )cin>>val[i], vis[val[i]] = 1;
    dfs1(1,0);
    cout<<ans<<endl;
    return 0;
}