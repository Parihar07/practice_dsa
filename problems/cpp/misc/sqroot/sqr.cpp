#include<iostream>
using namespace std;
// this function returns floor value of square root if not exact match
class math{
    private:
    int val;
    public:
    math(int v): val(v){}
    int getSquareRoot();
};

int math::getSquareRoot()
{
     {
        int res=0;
        for(int i=1;i*i<=val;i++)
        {
            res=i;
        }
        return res;
    }
}
int main()
{
    math om(1);
    cout<<"Square root of 45 : "<<om.getSquareRoot() <<endl;
    cout<<"hello square root\n";
    return 0;
}