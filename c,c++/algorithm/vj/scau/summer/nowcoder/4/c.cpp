#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define pb push_back
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i <(y); i ++ )
using namespace std;
struct node{
    int id;
    int cnt;
    bool operator < (const node& x)const{
        return cnt < x.cnt;
    }
};
int main(){
    ios::sync_with_stdio(0);
    int a, b, c, n;
    cin>>a>>b>>c>>n;
    vector<node> arr(3);
    arr[0] = {0,a}; arr[1] = {1,b}; arr[2] = {2,c};
    sort(arr.begin(),arr.end());
    if(arr[2].cnt + arr[1].cnt -  arr[0].cnt*2 >= n){
        cout<<"NO"<<endl;
        return 0;
    }
    vector<string>s(3);
    int ch = 0;
    int fir = arr[0].cnt;
    fori(i,0,3){
        int ind1 = arr[i].id;
        int ind2 = (ind1+1)%3;
        int ind3 = (ind1+2)%3;
        if(i == 0){
            fori(k,0,3)fori(j,0,arr[i].cnt) s[k] += (ch+'a');
        } else {
            fori(j,0,arr[i].cnt - fir) s[ind1] += (ch+'a'), s[ind2] += (ch + 'a'), s[ind3] += (ch+1+'a');
            ch++;
        }
        if(s[ind1].size() > n || s[ind1].size() > n || s[ind1].size() > n){
            cout<<"NO"<<endl;
            return 0;
        }
        ch++;
    }
    fori(k,0,3){
        int need = n - s[k].size();
        if(need == 0) continue;
        fori(i,0,need) s[k] += (ch+'a');
        ch++;
    }
    fori(k,0,3)cout<<s[k]<<endl;
    return 0;
}
