# include <bits/stdc++.h>

using namespace std;
int b;
string f(int x){
    string s;
    while(x){
        if(x%b>9) s+= (char)('A'+x%b-10);
        else s+=(char)('0'+x%b);
        x/=b;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    cin>>b;
    for(int i = 1; i <= 300; i++){
        string s = f(i*i);
        if(s == string(s.rbegin(),s.rend())){
            cout<<f(i)<<' '<<s<<endl;
        }
    }
    return 0;
}