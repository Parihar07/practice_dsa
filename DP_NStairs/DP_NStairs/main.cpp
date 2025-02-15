//
//  main.cpp
//  DP_NStairs
//
//  Created by CodeBreaker on 12/02/25.
//
/*
 tairs
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are climbing a staircase and it takes A steps to reach the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 Return the number of distinct ways modulo 1000000007


 Problem Constraints
 1 <= A <= 105


 Input Format
 The first and the only argument contains an integer A, the number of steps.


 Output Format
 Return an integer, representing the number of ways to reach the top.


 Example Input
 Input 1:
  A = 2
 Input 2:
  A = 3


 Example Output
 Output 1:
  2
 Output 2:
  3


 Example Explanation
 Explanation 1:
  Distinct ways to reach top: [1, 1], [2].
 Explanation 2:
  Distinct ways to reach top: [1 1 1], [1 2], [2 1].
 */
#include <iostream>
#include<vector>
using namespace std;

int stairWays(int A, vector<int> &dp)
{
    if(A<=1) return A;
    if(dp[A]==-1)
    {
        dp[A]=(stairWays(A-1, dp)+stairWays(A-2, dp))%1000000007;
    }
    return dp[A];
}

int climbStairs(int A)
{
    vector<int> dp(A+1,-1);
    stairWays(A, dp);
    return dp[A];
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Dynamic problem staircase problem!\n";
    cout<<"number of way : "<<climbStairs(5)<<endl;
    return 0;
}
