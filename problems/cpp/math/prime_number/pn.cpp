#include<iostream>
using namespace std;
int ifPrime(int a)
{
    int cnt=0;
    if(a>1)
    {
        for(int i=1;i<=a;i++)
        {
            if(a%i==0)
            {
                cnt++;
            }
        }
    }
    if(cnt==2)
    {
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
    return 0;
}
int main()
{
    int A=0;
    cin>>A;
    ifPrime(A);
    return 0;
}