//
//  main.cpp
//  oops_multilevelInheritance
//
//  Created by CodeBreaker on 15/03/25.
//

#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, public B, public C
{

    int val;
    public:
        //Initially val is 1
         D()
         {
             val = 1;
         }


         //Implement this function
         void update_val(int new_val)
         {
             while (val < new_val) {
                         if (new_val % val == 0) {
                             if ((new_val / val) % 2 == 0) { // If divisible by 2
                                 A::func(val); // Call A's func
                             } else if ((new_val / val) % 3 == 0) { // If divisible by 3
                                 B::func(val); // Call B's func
                             } else if ((new_val / val) % 5 == 0) { // If divisible by 5
                                 C::func(val); // Call C's func
                             }
                         }
                     }
             
             
         }
         //For Checking Purpose
         void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
