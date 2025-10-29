#include<iostream>
using namespace std;
int perfectNum(int A)
{
    int sum =0;
    for(int i=1;i<A;i++)
    {
        if(A%i==0)
        {
            sum+=i;
        }
    }
    
    if(sum==A)
    {
        cout<<"YES\n";
    } else{
        cout<<"NO\n";
    }
    return 0;
}

int main()
{
    int *ar;
    int cnt =0;
    cin>>cnt;

    ar = new int[cnt];
    for(int i=0;i<cnt;i++)
    {
        cin>>ar[i];
    }

    for(int i=0;i<cnt;i++)
    {
       perfectNum(ar[i]);
    }
    return 0;
}