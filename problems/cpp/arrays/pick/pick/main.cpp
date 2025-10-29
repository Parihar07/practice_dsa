//
//  main.cpp
//  pick
//
//  Created by CodeBreaker on 06/08/1946 Saka.
//
/*
 Pick from both sides!
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an integer array A of size N.
 You have to perform B operations. In one operation, you can remove either the leftmost or the rightmost element of the array A.
 Find and return the maximum possible sum of the B elements that were removed after the B operations.
 NOTE: Suppose B = 3, and array A contains 10 elements, then you can:
 Remove 3 elements from front and 0 elements from the back, OR
 Remove 2 elements from front and 1 element from the back, OR
 Remove 1 element from front and 2 elements from the back, OR
 Remove 0 elements from front and 3 elements from the back.asdf


 Problem Constraints
 1 <= N <= 105
 1 <= B <= N
 -103 <= A[i] <= 103


 Input Format
 First argument is an integer array A.
 Second argument is an integer B.


 Output Format
 Return an integer denoting the maximum possible sum of elements you removed.


 Example Input
 Input 1:
  A = [5, -2, 3 , 1, 2]
  B = 3
 Input 2:
  A = [ 2, 3, -1, 4, 2, 1 ]
  B = 4


 Example Output
 Output 1:
  8
 Output 2:
  9


 Example Explanation
 Explanation 1:
  Remove element 5 from front and element (1, 2) from back so we get 5 + 1 + 2 = 8
 Explanation 2:
  Remove the first element and the last 3 elements. So we get 2 + 4 + 2 + 1 = 9
 */
#include <iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int solve(vector<int> &A, int B);
    int solveOptimum(vector<int> &A, int B);
};
int Solution::solveOptimum(vector<int> &A, int B)
{
    int maxSum=INT_MIN;
    int N=A.size();
    int ind=B;
    int i=1;
    vector<int> PFS(A.size());
    PFS[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        PFS[i]+=(PFS[i-1]+A[i]);
    }
    while(B)
    {
        if(ind==B)
        {
            maxSum=max(maxSum,PFS[ind-i]);
        } else {
            maxSum=max(maxSum,(PFS[ind-i] + PFS[N-1] - PFS[N-i]));
        }
        i++;B--;
    }
    return maxSum;
}
int Solution::solve(vector<int> &A, int B) {
    int maxSum=INT_MIN;
    int lSum=0,rSum=0;
    int N=A.size();
    int L=B,R=0;
    while(B>=0)
    {
        for(int i=0;i<L;i++)
        {
            lSum+=A[i];
        }
        for(int j=N-1;j>=N-R;j--)
        {
            rSum+=A[j];
        }
        maxSum = max(lSum+rSum,maxSum);
        L--;R++;
        lSum=rSum=0;B--;
    }
    return maxSum;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution so;
    vector<int> v{2, 3, -1, 4, 2, 1};
    cout<<"Max pick sum "<<so.solveOptimum(v, 4)<<endl;
    std::cout << "Hello, pick form both sides\n";
    return 0;
}
