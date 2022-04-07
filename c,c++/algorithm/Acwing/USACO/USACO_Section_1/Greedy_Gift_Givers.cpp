# include <string>
# include <iostream>
# include <map>
# include <vector>
using namespace std;
vector<string> idc;
map<string,int> ma;
int cid(string s){
    if(ma.count(s))return ma[s];
    idc.push_back(s);
    ma[s] = idc.size()-1;
    return ma[s];
}
int main(){
    int n;
    int flag = false;
    while(cin>>n){
        /*
        if(flag){
            cout<<endl;
        }
        */
        string s;
        int ans[20][2]{};
        ma.clear(), idc.clear();
        for(int i = 1; i <= n;  i++ ){
            cin>>s;
            cid(s);
        }
    //  cout<<s<<endl;
        for(int i = 1; i <= n; i ++ ){
            cin>>s;
            int tot, num;
            cin>>tot>>num;
            string t;
        // cout<<s<<endl;
            if(num == 0){
               // ans[cid(s)][0]+=tot;
                //ans[cid(s)][1] = 0;
                continue;
            }
            int add = tot/num;
            for(int j = 1; j <= num; j ++ ){
                cin>>t;
                int idx = cid(t);
                ans[idx][0]+=add;
            }
        //  ans[cid(s)][0]+=tot%num;
            ans[cid(s)][1] = tot - tot%num;
        }
        //for(int i = 0; i < n; i ++ ) cout<<ans[i][0]<<endl;
        for(int i = 0; i < n; i ++ )cout<<idc[i]<<' '<<(ans[i][0] -ans[i][1])<<endl;
        cout<<endl;
        //flag = true;
    }
    return 0;
}