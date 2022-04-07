#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define pb push_back
#define sz(a) a.size()
using namespace std;
int n, m;
int num[5], p[4];
struct node{
    int num[4];
};
struct intop{
    int z, f;
};
vector<node>ans;
bool fl = false;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
bool check2(int x, intop sum, bool ok){
    if(fl) return true;
    int d = gcd(sum.z,sum.f);
    sum.z/=d;
    sum.f/=d;
    ok |= sum.f != 1;
    if(x >= n){
/*
        cout<<"p: ";
        fori(i,0,n)cout<<p[i]<<' ';
        cout<<endl<<"num: ";
        fori(i,0,n)cout<<num[p[i]]<<' ';
        cout<<endl;
        cout<<"sum.z = "<<sum.z<<" sum.f = "<<sum.f<<endl;
*/
        if(sum.f==1&&sum.z==m && ok){
            fl = true;
            return true;
        }else return false;
    }
    int val = num[p[x]];
    //+
    int mul = 1;
    if(sum.f != 1) mul = sum.f;
    if(check2(x+1, (intop){sum.z+val*mul,sum.f},ok)){
        fl = true;
        return true;
    }
    //-
    mul = 1;
    if(sum.f != 1) mul = sum.f;
    //if(x == 3)cout<<sum.z<<endl;
    if(check2(x+1, (intop){sum.z-val*mul,sum.f},ok)) {
        fl = true;
        return true;
    }
    //*
    d = 1;
    if(sum.f != 1) d = gcd(val,sum.f);
    int nval = val/d;
    if(check2(x+1, (intop){sum.z*nval,sum.f/d},ok)) {
        fl = true;
        return true;
    }
    // /
    d = 1;
    if(sum.z!=1) d = gcd(val,sum.z);
    nval = val/d;
    if(check2(x+1, (intop){sum.z/d,sum.f*nval}, ok)){
        fl = true;
        return true;
    }
    return false;
}
bool check(){
    iota(p,p+n,0);
    do{
        fl = false;
        if(check2(1, (intop){num[p[0]],1}, false)) return true;
    }while(next_permutation(p,p+n));
    //__next_permutation
    return false;
}
void dfs(int x, int pre){
    if(x >= n){
        node a;
        memcpy(a.num,num,n*sizeof(int));
        if(check())ans.pb(a);
        return;
    }
    for(int i = pre; i <= 13; i ++ ){
        num[x] = i;
        dfs(x+1,i);
    }
}
int main(){
   // iota(p,p+4,0);
   // for(int i = 0; i < 4; i ++ )cout<<p[i]<<' ';
    scanf("%d %d", &n, &m);
    dfs(0,1);
    cout<<sz(ans)<<endl;
    fori(i,0,sz(ans)){
        auto a = ans[i];
        fori(j,0,n)cout<<a.num[j]<<' ';
        cout<<endl;
    }
    return 0;
}
