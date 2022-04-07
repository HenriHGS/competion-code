#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#define fi first
#define se second
#define debug(a) cout<<#a<<": "<<a<<endl
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
using namespace std;
typedef pair<char,int>word;
int main(){
    string s;
    int cnt = 0;
    char pre = '\0';
    cin>>s;
    string t;
    vector<word>pos;
    for(auto x: s){
        if(x != pre){
            //t += x;
            cnt = 1;
            pos.pb({x,cnt});
        }else if(cnt < 2){
            cnt++;
            pos.pop_back();
            pos.pb({x,cnt});
            //t += x;
        }else cnt++;
        pre = x;
    }
    t = "";
    /*
    fori(i,0,sz(pos)){
        debug(pos[i].fi);
        debug(pos[i].se);
    }
    */
    fori(i,0,sz(pos)){
        word& now = pos[i];
        if(now.se == 1) t += now.first;
        else {
            int j = i;
           // debug(j);
            while(j < sz(pos) && pos[j].se == 2)j ++ ;
            //debug(j);
            //if(i)word& pre = pos[i-1];
            //if(i + 1 < sz(pos)) word&nxt = pos[i+1];
            if(j - i >= 3){
                int rot = 1;
                while(i < j){
                    if(rot == 1) t += string(2,pos[i].first);
                    else t += string(1,pos[i].first);
                    //debug(t);
                    //debug(rot);
                    i++;
                    rot ^= 1;
                }
            }else {
                int rot = 1;
                while(i < j){
                    if(rot == 1) t += string(2,pos[i].first);
                    else t += string(1,pos[i].first);
                    i++;
                    rot ^= 1;
                }
            }
            i--;
        }
    }
    cout<<t<<endl;
    return 0;
}