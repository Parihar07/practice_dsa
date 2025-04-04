//
//  main.cpp
//  arrays_maxabsdiff
//
//  Created by CodeBreaker on 02/01/25.
//
/*
 Maximum Absolute Difference
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an array of N integers, A1, A2, .... AN.

 Return the maximum value of f(i, j) for all 1 ≤ i, j ≤ N. f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.


 Problem Constraints
 1 <= N <= 100000
 -109 <= A[i] <= 109


 Input Format
 First argument is an integer array A of size N.


 Output Format
 Return an integer denoting the maximum value of f(i, j).


 Example Input
 Input 1:
 A = [1, 3, -1]
 Input 2:
  
 A = [2]


 Example Output
 Output 1:
 5
 Output 2:
 0


 Example Explanation
 Explanation 1:
 f(1, 1) = f(2, 2) = f(3, 3) = 0
 f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
 f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
 f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

 So, we return 5.
 Explanation 2:
 Only possibility is i = 1 and j = 1. That gives answer = 0.
 */

#include <iostream>
#include <vector>
using namespace std;
int func(int Ai, int Aj, int i, int j)
{
    return (abs(Ai-Aj) + abs(i-j));
}
int maxArr(vector<int> &A) {
    int ans=0;
    size_t N = A.size();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            ans = max(ans, func(A[i], A[j], i,j));
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, MAx absolute difference!\n";
    vector<int> A{2};
    cout<<"max absolute diff : "<<maxArr(A)<<endl;
    return 0;
}
