#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using namespace std;
void toBi(int x){
    bool c;
    for(int i = 1<<2; i; i>>=1){
        c = x&i;
        if(c)putchar('1');
        else putchar('0');
    }
}
int main(){
    fori(i,0,1<<3){
        cout<<"i:";//<<i<<endl;
        toBi(i);
        cout<<"(j-1)&i:";
        for(int j = i; j; j = (j-1)&i){
            toBi(j);
            putchar(' ');
        }
        puts("");
    }
    return 0;
}