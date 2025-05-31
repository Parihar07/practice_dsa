//
//  main.cpp
//  dp_fib_lambda
//
//  Created by CodeBreaker on 01/06/25.
//

#include <iostream>
#include <vector>
using namespace std;

int fib(int n)
{
    vector<int> dp(n+1,-1);
    // Declare std::function first, then assign the lambda.
    // This is a common pattern for recursive lambdas.
    function<int(int)> l_fib = [&dp, &l_fib](int n){
        if(n<=1){
            dp[n]=n;
            return dp[n];
        }
        if(dp[n]==-1)
        {
            dp[n]=l_fib(n-1)+l_fib(n-2);
        }
        return dp[n];
    };
    l_fib(n);
    return dp[n];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Using lambda function to get the fibonacci of n!\n";
    
    cout<<"fibonaaci of at 5 is "<<fib(5)<<endl;
    return 0;
}
