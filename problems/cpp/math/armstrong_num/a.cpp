#include<iostream>
using namespace std;

int cube(int x)
{
    return x*x*x;
}

int armstrong(int A)
{
    int tmp = A;
    int rem=0;
    int sum=0;
    while(tmp)
    {
        rem=tmp%10;
        rem=cube(rem);
        sum+=rem;
        tmp/=10;
    }
    return (sum==A)?1:0;
}
int main()
{
    int N=0;
    cin>>N;
    cout<<"hello armstrong \n";
    for(int i=1;i<=N;i++)
    {
        if(armstrong(i))
        {
            cout<<i<<endl;
        } 
    }
    return 0;
}