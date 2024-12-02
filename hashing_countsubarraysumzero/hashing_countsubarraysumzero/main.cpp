//
//  main.cpp
//  hashing_countsubarraysumzero
//
//  Created by CodeBreaker on 01/12/24.
//
/*
 Count Subarray Zero Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A of N integers.

 Find the count of the subarrays in the array which sums to zero. Since the answer can be very large, return the remainder on dividing the result with 109+7


 Problem Constraints
 1 <= N <= 105
 -109 <= A[i] <= 109


 Input Format
 Single argument which is an integer array A.


 Output Format
 Return an integer.


 Example Input
 Input 1:
  A = [1, -1, -2, 2]
 Input 2:
  A = [-1, 2, -1]


 Example Output
 Output 1:
 3
 Output 2:
 1


 Example Explanation
 Explanation 1:
  The subarrays with zero sum are [1, -1], [-2, 2] and [1, -1, -2, 2].
 Explanation 2:
  The subarray with zero sum is [-1, 2, -1].
 */
#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int solve(vector<int> &A) {
    long ans=0;
    size_t N = A.size();
    unordered_map<int, long> UM;
    int t=0;
    for(int i=0;i<N;i++)
    {
        t+=A[i];
        if(t==0) ans+=1;
        if(UM.find(t)!=UM.end())
        {
            ans+=UM[t];
        }
        UM[t]+=1;
    }
    return (int)ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> A{-1,2,-1};
    cout<<"Count of subbarrays sum xero : "<<solve(A)<<endl;
    return 0;
}
