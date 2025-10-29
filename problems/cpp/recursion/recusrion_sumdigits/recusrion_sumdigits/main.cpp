//
//  main.cpp
//  recusrion_sumdigits
//
//  Created by CodeBreaker on 25/05/25.
//

#include <iostream>
using namespace std;

int sumDigits(int N)
{
    int sum = 0;
    while(N)
    {
        sum+=N%10;
        N/=10;
    }
    return sum;
}

//Tail recursion, avaoid return computation of the stack
// TCO(Tail call optimization) internally code is converted to iterative hence Space complexity is O(1) (if compiler it supports TCO)
// in ordinary return computation is required hence space copmplexity will be also O(logN)
int sumHelper1(int N, int acc=0)
{
    if(N==0) return acc;
    return sumHelper1(N/10, acc+(N%10));
}

int sumDigit1(int N)
{
    return sumHelper1(N,0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, sum of digits of given number!\n";
    cout<<"sum of digits : "<<sumDigit1(64)<<endl;
    return 0;
}
