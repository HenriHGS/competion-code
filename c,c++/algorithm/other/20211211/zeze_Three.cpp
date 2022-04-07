#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
using namespace std;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
const int maxn = 100000 + 6;

int k[maxn], b[maxn];
int p[3];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    auto get = [&](string& a, int k, ll& res){
        res = 0;
        for(int i = 0; i < a.size(); i ++ ){
            res = res*k;
            if(a[i] >= '0' && a[i] <= '9') res += a[i] - '0';
            else res += a[i] - 'a' + 10;
            if(res > 1e5) return false;
        }
        return true;
    };
    auto check = [&](string&sa, string&sb, string&sc, int op, int k1, int k2, int k3){
        ll a, b, c;//= get(sa,k1), b = get(sb, k2), c = get(sc,k3);
        if(!get(sa,k1,a)) return false;
        if(!get(sb,k2,b)) return false;
        if(!get(sc,k3,c)) return false;
        if(a > 1e5 || b > 1e5 || c > 1e5) return false;
        if(op == '/') {
           // if(a < b || a < c || b == 0) return false;
           if(b == 0) return false;
           //cout<<b<<' '<<c<<' '<<a<<endl;
           //cout<<b*c<<endl; 
            return (b*c == a);
        }else if(op == '*'){
           // if(c < a && b || c < b && a) return false;
            return a * b == c;
        }else if(op == '+'){
            //if(c < a  || c < b ) return false;
            return a + b == c;
        }else {
            //if(a < b || a < c) return false;
            if((a - b == c)) {
                /*  cout<<a<<' '<<b<<' '<<c<<endl;
                cout<<k1<<' '<<k2<<' '<<k3<<endl;
                cout<<sa<<' '<<sb<<' '<<sc<<endl;
                cout<<endl;  */
            }
            return (a - b == c);
        }
        return false;
    };
    int tt; 
    cin>>tt;
    while(tt--){
        string a[3];
        /* fori(i,0,3) cout<<p[i]<<' ';
        cout<<endl; */
        int mi[3] = {1,1,1};
        fori(i,0,3) {
            cin>>a[i];
            for(auto x: a[i]) {
                if(x >= '0' && x <= '9') mi[i] = max(mi[i],x - '0');
                else mi[i] = max(mi[i], x - 'a' + 10);
            }
        }
        char op; cin>>op;
        bool ok = false;
        for(int i = max(1,mi[0]+1); i <= 36 && !ok; i ++ ) for(int j = max(1,mi[1]+1); j <= 36 && !ok; j ++ ) for(int k = max(1,mi[2]+1); k <= 36; k ++ ){
            p[0] = 0, p[1] = 1, p[2] = 2;
            do{
                int id1 = p[0], id2 = p[1], id3 = p[2];
                int ind[] = {i,j,k};
                if(check(a[id1], a[id2], a[id3], op, ind[id1], ind[id2], ind[id3])){
                    ok = true;
                    break;
                }
            }while(next_permutation(p,p+3));
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}