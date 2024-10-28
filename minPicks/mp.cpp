/*
MINIMUM PICKS
Unsolved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
You are given an array of integers A of size N.
Return the difference between the maximum among all even numbers of A and the minimum among all odd numbers in A.


Problem Constraints
2 <= N <= 1e5
-1e9 <= A[i] <= 1e9
There is atleast 1 odd and 1 even number in A


Input Format
The first argument given is the integer array, A.


Output Format
Return maximum among all even numbers of A - minimum among all odd numbers in A.


Example Input
Input 1:
 A = [0, 2, 9]
Input 2:
 A = [5, 17, 100, 1]


Example Output
Output 1:
-7
Output 2:
99


Example Explanation
Explanation 1:
Maximum of all even numbers = 2
Minimum of all odd numbers = 9
ans = 2 - 9 = -7
Explanation 2:
Maximum of all even numbers = 100
Minimum of all odd numbers = 1
ans = 100 - 1 = 99
*/
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Solution {
    public:
    int solve(vector < int > &A);
};

int main()
{
    vector<int> v{0, 2, 9};
    Solution so;
    cout<<so.solve(v)<<endl;
    return 0;
}

// Do not write code to include libraries, main() function or accept any input from the console.
// Initialization code is already written and hidden from you. Do not write code for it again.
int Solution::solve(vector < int > &A) {
    // Just write your code below to complete the function. Required input is available to you as the function arguments.
    // Do not print the result or any output. Just return the result via this function.
    int N=A.size();
    int maxEven=INT_MIN;
    int minOdd=INT_MAX;
    for(int i=0;i<N;i++)
    {
        if(A[i]%2==0)
        {
            maxEven=max(maxEven,A[i]);
        } else {
            minOdd=min(minOdd,A[i]);
        }
        cout<<maxEven<<" "<<minOdd<<endl;
    }
    return maxEven-minOdd;
}
