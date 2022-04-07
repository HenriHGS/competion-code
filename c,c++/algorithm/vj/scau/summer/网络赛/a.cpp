#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T -- ) 
    {
        int n;
        scanf("%d", &n);
        int sum = 0;
        sum = n / 2;
        sum = n - sum;
        int l = 1, r = n;
        while (l < r) 
        {
            int mid = l + r >> 1;
            if (3ll * mid + 1 > n) r = mid;
            else l = mid + 1;
        }
        int cnt=0;
        cnt=n/2+n%2-(l-1)/2-(l-1)%2;
        sum = sum + cnt;
        printf("%d\n", sum);
    }
    
}