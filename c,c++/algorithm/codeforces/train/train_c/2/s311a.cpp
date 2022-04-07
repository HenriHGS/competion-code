#include <iostream>
#include <string>
using namespace std;
string no = "no solution";
int main(){
    ios::sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    int sum = n*(n-1)/2;
    if(sum<=k)cout<<no<<'\n';
    else {
        for(int i = 1; i <= n; i ++ )cout<<0<<' '<<i<<endl;
    }
    return 0;
}
