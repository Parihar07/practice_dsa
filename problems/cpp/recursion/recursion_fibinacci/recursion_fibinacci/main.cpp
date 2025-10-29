//
//  main.cpp
//  recursion_fibinacci
//
//  Created by CodeBreaker on 24/05/25.
//

#include <iostream>
using namespace std;

int fib(int N)
{
    if(N<=1) return N;
    return fib(N-2) + fib(N-1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, fibaniacci using recursion!\n";
    cout<<"Fibonacci of 5th number is "<<fib(5)<<endl;
    return 0;
}
