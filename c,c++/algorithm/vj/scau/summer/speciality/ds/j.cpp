#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 5e5+10;
struct Node{
    int ch[2], p, v, cnt;
    int siz, flag;
    void init(int _v, int _p){
        v = _v, p = _p;
        siz = cnt = 1;
        ch[0] = ch[1] = 0;
    }
}tr[N];
int root, tot, fa[N], val[N],sz[N], cnt[N];
#define ls tr[x].ch[0]
#define rs tr[x].ch[1]
void pushup(int x){
    tr[x].siz = tr[ls].siz + tr[rs].siz + tr[x].cnt;//1;
}
bool get(int x){
    int y = tr[x].p;
    return x == tr[y].ch[1];
}
/*
void clear(int x){
    ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
}
*/
void rotate(int x){
    int y = tr[x].p, z = tr[y].p;
    int k = get(x);
    tr[z].ch[get(y)] = x, tr[x].p = z;
    tr[y].ch[k] = tr[x].ch[k^1], tr[tr[x].ch[k^1]].p = y;
    tr[x].ch[k^1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}
void splay(int x, int k){
    while(tr[x].p != k){
        int y = tr[x].p, z = tr[y].p;
        if(z != k)
            if( (tr[y].ch[1] == x) ^ (tr[z].ch[1] == y) ) rotate(x);
            else rotate(y);
        rotate(x);
    }
    if(!k) root = x;
}
//val - rank
void find(int x){
    int u = root;//, res = root;
    if(!u) return;
   /*
    while(x){
        cout<<"x:"<<x<<" tr[x].v = "<<tr[x].v<<endl;
        if(tr[x].v >= v) x = ls;//res = x, x = ls;
        else x = rs;
    }
    */
    while(tr[u].ch[x>tr[u].v]&&x!=tr[u].v)//当存在儿子并且当前位置的值不等于x
        u=tr[u].ch[x>tr[u].v];//跳转到儿子，查找x的父节点
    splay(u,0);
    return ;//res;
}
void insert(int v){
    int u = root, p = 0;
    while(u && tr[u].v != v){
        p = u;
        u = tr[u].ch[v > tr[u].v];
    }
    if(u) tr[u].cnt++;
    else {
        u = ++tot;
        if(p) tr[p].ch[v > tr[p].v] = u;
        tr[u].init(v,p);
    }
    splay(u,0);
}
int Next(int val, int f){
    find(val);
    //cout<<"ok1"<<endl;
    int x = root;
    if(tr[x].v > val && f) return x;
    //cout<<"ok"<<endl;
    if(tr[x].v < val && !f) return x;
    x = tr[x].ch[f];
    while(tr[x].ch[f^1]) x = tr[x].ch[f^1];
    return x;
}
int get_k(int k){
    int x = root;
    if(tr[x].siz < k) return 0;
    while(1){
        //pushdown(x);
        if(k > tr[ls].siz + tr[x].cnt){
            k -= tr[ls].siz + tr[x].cnt;
            x = rs;
        }else {
            if(tr[ls].siz >= k) x = ls;
            else return tr[x].v;
        }
        /*
        if(tr[ls].siz >= k) x = ls;
        else if(tr[ls].siz + 1 == k) return tr[x].v;
        else k -= tr[ls].siz + 1, x = rs;
        */
    }
    return -1;
}
void Delete(int x){
    int last = Next(x,0);
    int next = Next(x,1);
    splay(last,0), splay(next,last);

    int del = tr[next].ch[0];
    if(tr[del].cnt > 1){
        tr[del].cnt--;
        splay(del,0);
    }else  tr[next].ch[0] = 0;
}
int n;
void sol(){
    //init();
    scanf("%d", &n);
    insert(+2147483647);
    insert(-2147483647);//哨兵
    while(n--){
        int opt, x;
        scanf("%d %d", &opt, &x);
        if(opt == 1){
            insert(x);
        }else if(opt == 2){
            Delete(x);
        }else if(opt == 3){
            //cout<<"opt3:";
            find(x);
            x = root;
            printf("%d\n", tr[ls].siz);
        }else if(opt == 4){
           // cout<<"opt4:";
            printf("%d\n", get_k(x+1));
        }else if(opt == 5){
           // cout<<"opt5:";
           int pos = Next(x,0);
            printf("%d\n", tr[pos].v);
        }else {
          //  cout<<"opt6:";
          int pos = Next(x,1);
            printf("%d\n", tr[pos].v);
        }
    }
}
int main(){
    sol();
    return 0;
}