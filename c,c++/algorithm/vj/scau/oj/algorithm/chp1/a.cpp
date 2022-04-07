#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch,  or input loop */

int power(int base,int exponent );
int main()
{
    int num;
    cin>>num;
    int impossible = 0;
    for(int i = 0 ; i<=num; i++)
    {
        int temp= power(5,5);
        if(!((i+4)%temp))
        {
            impossible = 1;
            cout<<i<<" ";
        }
    }
    if(!impossible)
    {
        cout<<"impossible";
    }
    return 0;
}

int power(int base,int exponent )
{
    int sum =1;
    for(int i =0;i<exponent;i++)
    {
        sum*=base;
    }
    return sum;
}