#include <cstdio>
#include <cstring>
#include <iostream>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
#define sz(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define mst(x,a) memset(x,a,sizeof(x))
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define db double
#define endl '\n'
#define debug(a) cout << #a << ": " << a << endl
#define maxn  (100000 + 6)
using namespace std;
char s1[maxn];
char t1[maxn];
int main(void) {
    FILE *fp1, *fp2;
    fp1 = fopen("D:\\codefield\\c,c++\\atcoder\\test\\in.txt", "r");
    fp2 = fopen("D:\\codefield\\c,c++\\atcoder\\test\\out.txt", "w");
    while(!feof(fp1)){
        fgets(s1,maxn,fp1);
        int len = strlen(s1);
        //cout<<s1<<endl;
        t1[0] = '\"';
        int len2 = 1;
        fori(i,0,len-1){
            if(s1[i] == '\"') t1[len2++] = '\\';
            t1[len2++] = s1[i];
        }
        //printf("%d\n", len);
        t1[len2++] = '\"';
        t1[len2++] = ',';
        t1[len2++] = '\n';
        t1[len2++] = '\0';
        fputs(t1,fp2);
    }
    return 0;
}
