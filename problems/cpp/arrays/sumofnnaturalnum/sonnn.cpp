#include<iostream>
using namespace std;

int nNaturalNo(int n)
{
    return n*(n+1)/2;
}
int main()
{
    int ip=0;
    cin>>ip;
    cout<<nNaturalNo(ip)<<endl;
    return 0;
}