//
//  main.cpp
//  DP_perfectsquares
//
//  Created by CodeBreaker on 12/02/25.
//
/*
 Minimum Number of Squares
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer A. Return minimum count of numbers, sum of whose squares is equal to A.


 Problem Constraints
 1 <= A <= 105


 Input Format
 First and only argument is an integer A.


 Output Format
 Return an integer denoting the minimum count.


 Example Input
 Input 1:
  A = 6
 Input 2:
  A = 5


 Example Output
 Output 1:
  3
 Output 2:
  2


 Example Explanation
 Explanation 1:
  Possible combinations are : (12 + 12 + 12 + 12 + 12 + 12) and (12 + 12 + 22).
  Minimum count of numbers, sum of whose squares is 6 is 3.
 Explanation 2:
  We can represent 5 using only 2 numbers i.e. 12 + 22 = 5
 */
#include <iostream>
#include <vector>
using namespace std;

int minPerfectSquaresDp(int A, vector<int> &dp)
{
    if(A==0) return 0;
    
    if(dp[A]==-1){
        int ans = INT_MAX;
        for(int i=1;i*i<=A;i++)
        {
            int t = minPerfectSquaresDp(A-(i*i), dp);
            ans=min(ans,t);
        }
        dp[A]=1+ans;
    }
    return dp[A];
}

int countMinSquares(int A) {
    vector<int> dp(A+1, -1);
    minPerfectSquaresDp(A, dp);
    return dp[A];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Hello Dynamic programming !\n";
    
    cout<<countMinSquares(5)<<endl;
    
    return 0;
}
