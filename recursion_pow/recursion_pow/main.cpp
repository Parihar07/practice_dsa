//
//  main.cpp
//  recursion_pow
//
//  Created by CodeBreaker on 28/05/25.
//

#include <iostream>
using namespace std;


/*
 This is naive approach but TC O(n) and time complexity SC O(n)
 */
int pow(int x, int n) //power of x to the n
{
    if(n==0) return 1;
    return pow(x,n-1)*x;
}

/*
 this is other way of recursive implementation eg: x to the power n then x^n/2*x^n/2 if its even other wise we can do same x^n/2*x^n/2*x
*/
int pow1(int x, int n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        return pow1(x,n/2)*pow1(x,n/2);
    } else {
        return x*pow1(x,n/2)*pow1(x,n/2);
    }
}
//optimizing pow1 ,, where time complxity will change to logn

int pow2(int x, int n)
{
    if(n==0) return 1;
    int p = pow2(x, n/2);
    if(n%2==0)
    {
        return p*p;
    } else {
        return x*p*p;
    }
}

// optimizing space complexity

int pow3(int x, int n)
{
    if(n==0) return 1;
    if(n<0){
        x=1.0/x;
        n=-n;
    }
    int p = pow3(x, n/2);
    if(n%2 == 1)
    {
        return x*p*p;
    }
    return p*p;
}

// Iterative appra\oach
int pow4(int x, int n)
{
    if(n==0) return 1;
    int ans =1;
    while(n>0)
    {
        if(n%2==1){
            ans*=x;
        }
        x*=x;
        n/=2;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Recursive appraoch for getting power of number!\n";
    cout<<" result of 2 to the poer of 5 : "<< pow4(2,5) <<endl;
    return 0;
}
