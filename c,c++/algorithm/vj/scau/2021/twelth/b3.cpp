#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;
#define ll long long
#define LL unsigned long long
ll read()
{
    ll ans=0,sign=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            sign=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        ans=(ans<<1)+(ans<<3)+(ch^48);
        ch=getchar();
    }
    return ans*sign;
}
const int N=1e7;
ll a[N];
ll b[N];
ll c[N];
int lenb=0,lena=0;
ll ans=0;
int main()
{
    int n;//int n=read();
    cin>>n;
    for(int i=0; i<n; i++)
     {
         cin>>c[i];
     }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(c[i]!=0)
                    a[lena++]=(c[k]+c[j])*c[i];
                b[lenb++]=(c[k]*c[j])+c[i];
            }
        }
    }
    sort(a,a+lena);
    sort(b,b+lenb);
    for(int i=0; i<lena; i++)
    {
        int cur1=lower_bound(b,b+lenb,a[i])-b;
        int cur2=upper_bound(b,b+lenb,a[i])-b;
        ans+=(ll)cur2-(ll)cur1;
    }
    cout<<ans<<'\n';
    return 0;
}