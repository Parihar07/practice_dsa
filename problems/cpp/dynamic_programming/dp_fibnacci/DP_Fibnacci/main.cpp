//
//  main.cpp
//  DP_Fibnacci
//
//  Created by CodeBreaker on 13/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

int fib_dp(int A, vector<int> &dp)
{
    if(A<=1) return A;
    if(dp[A]==-1)
    {
        dp[A] = fib_dp(A-1, dp)+fib_dp(A-2, dp);
    }
    return dp[A];
}

int fib_recusrsive(int A)
{
    if(A<=1) return A;
    return fib_recusrsive(A-1)+fib_recusrsive(A-2);
}

int fib(int A)
{
    vector<int> dp(A+1,-1);
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=A;i++)
    {
        dp[i]= dp[i-1]+dp[i-2];
    }
    return dp[A];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Dynamic Programming Fibonacci.. !\n";
    int ip=0;
    
    cout<<"enter value : ";
    cin>>ip;
    vector<int> dp(ip+1,-1);
    if(ip<2)
    {
        return ip;
    } else {
        dp[0]=0;
        dp[1]=1;
    }
    cout<<"Fiboncaii : "<<fib_dp(ip, dp)<<endl;
    return 0;
}
