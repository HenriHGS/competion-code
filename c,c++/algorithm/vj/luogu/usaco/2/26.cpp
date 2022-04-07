#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
const int p[] = {0,1,5,10,50,100,500,1000};
const char ans[] = "AIVXLCDM";
int cnt[8]{};
/*
char c[4][10][100]={
            {"","I\0","II\0","III\0","IV\0","V\0","VI\0","VII\0","VIII\0","IX\0"},
            {"","X\0","XX\0","XXX\0","XL\0","L\0","LX\0","LXX\0","LXXX\0","XC\0"},
            {"","C\0","CC\0","CCC\0","CD\0","D\0","DC\0","DCC\0","DCCC\0","CM\0"},
            {"","M\0","MM\0","MMM\0"}
};
*/
 char c[4][10][100]={
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
        };
void cal(int x){
    int q = 1;
    fori(k,0,4){
        char* s = c[k][x/q%10];
      //  int len = strlen(s);
       // if(x/q%10)printf("%s\n",s);
        fori(i,0,100)For(j,1,7)if(ans[j] == s[i])cnt[j]++;
        q *= 10;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++ ) cal(i);
    For(i,1,7){
        if(cnt[i]){
            printf("%c %d\n", ans[i], cnt[i]);
        }
    }
    return 0;
}