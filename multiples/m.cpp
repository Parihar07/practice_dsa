#include<iostream>
using namespace std;

int printMultiples(int m, int cnt)
{
    for(int i=1;i<=cnt;i++)
    {
        cout<<m<< " * " <<i<< " = "<<m*i<<endl;
    }
    return 0;
}
int main()
{
    int ip=0;
    cin>>ip;
    printMultiples(ip,10);
    return 0;
}