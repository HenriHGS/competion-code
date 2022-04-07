#include <string>
#include <iostream>
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
const string ans = "ABC";
int main(){
    int cnt[3]{};
    fori(i,0,3)cin>>cnt[i];
    int win = -1;
    fori(i,0,3){
        int j = (i+1)%3;
        int k = (i+2)%3;
        if(cnt[i] != cnt[j] && cnt[i] != cnt[k]){
            cout<<ans[i]<<endl;
            return 0;
        }
    }
    cout<<'*';
    return 0;
}