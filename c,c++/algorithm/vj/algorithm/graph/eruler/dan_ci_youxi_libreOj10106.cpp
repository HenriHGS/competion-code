#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e5+10;
int p[26];
char s[N];
int find(int x){
    if(x == p[x]) return x;
    return p[x] = find(p[x]);
}
bool have[26];
int din[26], dout[26];
void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 26; i ++ ) p[i] = i, din[i] = dout[i] = 0, have[i] = 0;
    for(int i = 1; i <= n; i ++ ){
        scanf("%s", s);
        int len = strlen(s);
        int a = s[0] - 'a', b  =s[len-1] - 'a';
        have[a] = have[b] = 1;
        din[b] ++, dout[a]++;
        a = find(a), b = find(b);
        if(a != b) p[a] = b;
    }
    bool success = true;
    int start = 0, end = 0;
    for(int i = 0; i < 26; i ++ ){
        if(din[i] - dout[i] == 1)end++;
        else if(dout[i] - din[i] == 1) start++;
        else if(din[i] == dout[i]) continue;
        else success = false;
    }
    if(!success || !(!start && !end || start == 1 && end == 1)){
        puts("The door cannot be opened.");
        return ;
    }
    int anc = -1;
    for(int i = 0; i < 26; i ++ ){
        p[i] = find(i);
        if(have[i]){
            if(anc == -1) anc = p[i];
            else if(p[i] != anc){
                success = false;
                break;
            }
        }
    }
    if(!success){
        puts("The door cannot be opened.");
        return ;
    }
    puts("Ordering is possible.");
}
int main(){
    int tt;
    scanf("%d", &tt);
    while(tt--)solve();
    return 0;
}