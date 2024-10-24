#include<iostream>
using namespace std;
int perfectSquare(int A)
{
    int ret=-1;
    for(int i=0;i*i<=A;i++)
    {
        ret =i;
    }
    // if(ret*ret==A) return ret;
    // else return -1;
    return (ret*ret==A)?ret:-1;
}

int main()
{
    int a=0;
    cin>>a;
    cout<<"hello perfect square\n";
    cout<<"If perfect square : "<< a << " : "<<perfectSquare(a)<<endl;
    return 0;
}