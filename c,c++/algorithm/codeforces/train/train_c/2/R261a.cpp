#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    int m;
    cin>>m;
    int mi = (int)1e5+10;
    for(int i = 1; i <= m; i ++ ){
        int x;
        cin>>x;
        mi = min(mi,x);
    }
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n; i ++ )cin>>a[i];
    sort(a.begin(),a.end());
    int sum = 0;
    int cnt = 0;
    for(int i = n-1; i >= 0; i -- ){
        cnt++;
        sum += a[i];
        if(cnt == mi){
            cnt = 0;
            i -= 2;
        }
    }
    cout<<sum<<endl;
    return 0;
}