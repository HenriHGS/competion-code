#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
const ll mod=1e9+7;
int n;
char s[1000010];
ll num[1000010],inv[1000010];
inline ll pw(ll a,ll b) {
    ll res=1;
    while(b) {
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
inline void printstr(int l,int r) {
    for(int i=l;i<=r;i++)
        putchar(s[i]);
}
inline ll calc(int l,int r) {
    ll val=((num[l]-num[r+1])%mod+mod)%mod;
//  cout<<"interval :"<<l<<"->"<<r<<" get:"<<val<<endl;
    return (val*inv[n-r]%mod);
}
inline bool check(ll l1,ll l2,ll l3) {
//  cout<<"Now check three lengths:"<<l1<<" and "<<l2<<" and "<<l3<<endl;
    if(l1>l3||l2>l3||l1<1||l2<1||l3<1)
        return 0;
    int pl1=1,pl2=l1+1,pl3=l1+l2+1,pr1=l1,pr2=l1+l2,pr3=l1+l2+l3;
//  cout<<"Num one:"<<pl1<<" to "<<pr1<<" Num two:"<<pl2<<" to "<<pr2<<" Num three:"<<pl3<<" to "<<pr3<<endl;
    if(s[pl1]=='0'&&pr1-pl1+1!=1)
        return 0;
    if(s[pl2]=='0'&&pr2-pl2+1!=1)
        return 0;
    if(s[pl3]=='0'&&pr3-pl3+1!=1)
        return 0;
//  cout<<"First num:"<<calc(pl1,pr1)<<" Second num:"<<calc(pl2,pr2)<<" Third num:"<<calc(pl3,pr3)<<endl;
    if((calc(pl1,pr1)+calc(pl2,pr2))%mod==calc(pl3,pr3)) {
//      cout<<pl1<<" "<<pr1<<" "<<pl2<<" "<<pr2<<" "<<pl3<<" "<<pr3<<endl;
        printstr(pl1,pr1);
        putchar('+');
        printstr(pl2,pr2);
        putchar('=');
        printstr(pl3,pr3);
        cout<<calc(pl1,pr1)<<endl;
        cout<<calc(pl2,pr2)<<endl;
        cout<<calc(pl3,pr3)<<endl;
        return 1;
    }
    return 0;
}
int main() {
//  freopen("F.in","r",stdin);
    inv[1000000]=pw(10LL,1000000LL);
    inv[1000000]=pw(inv[1000000],mod-2);
    for(int i=999999;~i;i--)
        inv[i]=inv[i+1]*10%mod;
    scanf("%s",s+1);
//  for(int i=0;i<=10;i++)
//      cout<<inv[i]<<endl;
    n=strlen(s+1);
//  cout<<n<<endl;
//  for(int i=1;i<=n;i++)
//      putchar(s[i]);
    num[n+1]=0;
    for(int i=n;i;i--)
        num[i]=(num[i+1]+(s[i]-'0')*pw(10LL,n-i)%mod)%mod;
//  for(int i=n;i;i--)
//      cout<<num[i]<<" ";
//  cout<<endl;
    for(int div=1;div<=n;div++)
        if(check(div-1,n-div-(div-1),div)||check(div,n-div-div,div)||check(n-div-(div-1),div-1,div)||check(n-div-div,div,div))
            return 0;
    return 0;
}