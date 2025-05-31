//
//  main.cpp
//  recursion_sumN
//
//  Created by CodeBreaker on 23/05/25.
//

#include <iostream>
using namespace std;

int sum(int N)
{
    if(N==1) return 1;
    return sum(N-1)+N; // sum of n number is 1+2+3+4+.....(n-1)+n
}

int tailRecusrionSum(int N, int accum=0)
{
    if(N==0) return accum;
    return tailRecusrionSum(N-1, (accum+N));
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cout << "Hello, sum of N natural number in recursion!\n";
    
    cout<<"sum of N natural numbers is : "<<tailRecusrionSum(7)<<endl;
    return 0;
}
