/*
旋转90度，可以看成关于两条对角线，对称。。。。
即先主变换，之后水平翻转
*/
# include <cstdio>
# include <cstring>
# include <iostream>
using namespace std;
char s[12][12], t[12][12], ss[12][12];
int n;
void init(){
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )s[i][j] = ss[i][j];
}
bool mody1(){
    char tmp[12][12];
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )
        tmp[i][j] = s[i][j];
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ )s[j][n - i + 1] = tmp[i][j];
    }
    bool ok = true;
    return ok;
}
bool mody2(){
    char tmp[12][12];
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )
        tmp[i][j] = s[i][j];
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )s[n - i + 1][n - j + 1] = tmp[i][j];
    bool ok = true;
    return ok;
}
bool mody3(){
    char tmp[12][12];
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )
        tmp[i][j] = s[i][j];
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ )s[n - j + 1][i] = tmp[i][j];
    }
    bool ok = true;
    return ok;
}
bool mody4(){
    char tmp[12][12];
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )
        tmp[i][j] = s[i][j];
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )s[i][j] = tmp[i][n - j + 1];
    bool ok = true;
    return ok;
}
bool equal(){
    bool ok = true;
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )
        ok &= t[i][j] == s[i][j];
    return ok;
}
int main(){
    cin>>n;
    for(int i = 1; i <= n; i++ ){
        cin>>(s[i]+1);
    }
    for(int i = 1; i <= n; i ++ ){
        cin>>(t[i]+1);
    }
    for(int i = 1; i <= n; i ++ )for(int j = 1; j <= n; j ++ )ss[i][j] = s[i][j];
    mody1();
    if(equal()){
        cout<<1<<endl;
        return 0;
    }
    init();
    mody2();
    if(equal()){
        cout<<2<<endl;
        return 0;
    }
    init();
    mody3();
    if(equal()){
        cout<<3<<endl;
        return 0;
    }
    init();
    mody4();
    if(equal()){
        cout<<4<<endl;
        return 0;
    }
    init();
    mody4(),mody1();
    if(equal()){
        cout<<5<<endl;
        return 0;
    }
    init();
    mody4(),mody2();
    if(equal()){
        cout<<5<<endl;
        return 0;
    }
    init();
    mody4(),mody3();
    if(equal()){
        cout<<5<<endl;
        return 0;
    }
    init();
    if(equal()){
        cout<<6<<endl;
        return 0;
    }
    cout<<7<<endl;
    return 0;
}