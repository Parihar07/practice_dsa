#include<iostream>
using namespace std;

class math{
    private:
    int val;
    public:
    math(int n): val(n){}
    int getFactorCount();
};

int math::getFactorCount()
{
    int res=0;
    for(int i=1;i*i<=val;i++)
    {
        if(val%i==0)
        {
            if(i*i==val) res+=1;
            else res+=2;
        }
    }
    return res;
}

int main()
{
    math om(21);
    cout<<"Factors count : "<<om.getFactorCount()<<endl;
    cout<<"hello factor programe\n";
    return 0;
}