#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define pb push_back
using namespace std;
const int N = 510;
struct Time{
    int m, s;
    Time(){
        m = s = 0;
    }
    Time(int _m, int _s){
        m = _m;
        s = _s;
    }
    Time operator = (const Time x){
        this->m = x.m;
        this->s = x.s;
        return *this;
    }
    Time operator + (const Time x){
        Time c = *this;
        c.s += x.s;
        if(c.s>100)c.s = c.s%100, c.m++;
        c.m += x.m;
        return c;
    } 
    bool operator < (const Time&x)const{
        return m<x.m || m == x.m&&s<x.s;
    }
    void out(){
        printf("%d.%02d", m, s);
    }
};
struct Leg{
    Time t1,t2;
    int id;
    bool operator < (const Leg& x)const{
        return t2<x.t2;
    }
}leg[N];
int main(){
   // ios::sync_wiht_stdio(0);
    map<int,string>name;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i ++ ){
        string s;
        cin>>s;
        name[i] = s;
        cin>>s;
        string mi, sec;
        mi = s.substr(0,s.find('.'));
        sec = s.substr(s.find('.')+1);
        leg[i].t1 = Time(stoi(mi),stoi(sec));
        cin>>s;
    //    string mi, sec;
        mi = s.substr(0,s.find('.'));
        sec = s.substr(s.find('.')+1);
        leg[i].t2 = Time(stoi(mi),stoi(sec));
        leg[i].id = i;
        /*
        leg[i].t1.out();
        printf(" ");
        leg[i].t2.out();
        cout<<endl;
        */
    }   
    sort(leg+1,leg+1+n);
    vector<int>alp;
    Time ans = Time(1000000,100);
    for(int i = 1; i <= n; i ++ ){
        Time cur = leg[i].t1;
        int cnt = 1;
        vector<int>alp_tmp;
        alp_tmp.pb(leg[i].id);
        for(int j = 1; j <= n; j ++ ){
            if(i == j)continue;
            cnt++;
            alp_tmp.pb(leg[j].id);
            cur = cur + leg[j].t2; 
            if(cnt == 4)break;
        }
        if(cnt == 4){
            if(cur < ans){
                alp.assign(alp_tmp.begin(),alp_tmp.end());//alp = alp_tmp;//alp.clear();
               // alp.insert(alp_tmp.begin(),4);
                ans = cur;
                /*
                ans.out();
                puts("");
                for(int j = 0; j < alp.size(); j++) cout<<alp[j]<<' ';
                cout<<endl;
                */
            }
        }
    }
    ans.out();
    cout<<endl;
    for(int i = 0; i < alp.size(); i ++ )cout<<name[alp[i]]<<endl;
}
/*
6
ASHMEADE 9.90 8.85
BLAKE 9.69 8.72
BOLT 9.58 8.43
CARTER 9.78 8.93
FRATER 9.88 8.92
POWELL 9.72 8.61
*/