#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--){
        double p, q;
        scanf("%lf%lf",&p,&q);
        int pp, qq;
        pp = p*10000+0.5;
        qq = q*10000+0.5;
        //cout<<pp<<' '<<qq<<endl;
        int dis = pp - qq;
       // cout<<dis<<endl;
        if(dis <= 0) puts("N0 M0R3 BL4CK 1CE TEA!");
        else puts("ENJ0Y YOURS3LF!");
    }
}