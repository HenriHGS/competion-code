#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#define For(i,x,y) for(int i = (x); i <= (y); i ++ )
#define fori(i,x,y) for(int i = (x); i < (y); i ++ )
using  namespace std;
int main(){
    bool so = false;
    int q;
    queue<int>que;
    scanf("%d", &q);
    multiset<int>s;
    while(q--){
        int op, x;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            que.push(x); 
        }else if(op == 2){
            //printf("ans = ");
            if(so){
                auto it = s.begin();
                printf("%d\n", *it);
                s.erase(it);
                if(s.empty()) so = false;
            }else {
                printf("%d\n", que.front());
                int v = que.front();
                que.pop();
              //  auto it = s.find(v);
               // if(it != s.end())s.erase(it);
            }
        }else {
            while(!que.empty()) {
                int v = que.front();
                que.pop();
                s.insert(v);
            }
            if(!s.empty())so = true;
        }
    }
    return 0;
}