#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pll pair<long,long>
using namespace std;
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
const int maxn=305,MAXN=1e6+10,INF=0x3f3f3f3f;
map<int,ll> M[maxn];
int buf[maxn];
ll Mul[maxn];
ll DP(int len, ll now, int k, bool lim, bool zero) {
	if (len==0) return now<=k;
//	if (now>k&&!lim) return Mul[len];
	if (now>k) now=k+1;
	if (!zero&&!lim&&M[len].count(now)) return M[len][now];
	int pos=lim?buf[len]:9;
	ll res=0;
	for (int i=0; i<=pos; i++) {
		res+=DP(len-1,zero&&i==0?1:now*i,k,lim&&i==pos,zero&&i==0);
	}
    cout<<len<<' '<<now<<' '<<res<<' '<<buf[len]<<endl;
	if (!zero&&!lim) M[len][now]=res;
	return res;
}
int main() {
	ll n,k;
	int len=0;
	cin>>n>>k;//read(n),read(k);
	while (n) {
		buf[++len]=n%10;
		n/=10;
	}
   // for(int i = 1; i <= len; i ++ )cout<<buf[i];
   // cout<<endl;
	printf("%lld\n",DP(len,1,k,true,true)-1);
	return 0;
}