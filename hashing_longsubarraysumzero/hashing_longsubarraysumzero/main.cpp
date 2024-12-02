//
//  main.cpp
//  hashing_longsubarraysumzero
//
//  Created by CodeBreaker on 02/12/24.
//
/*
 Longest Subarray Zero Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A of N integers.
 Find the length of the longest subarray in the array which sums to zero.
 If there is no subarray which sums to zero then return 0.


 Problem Constraints
 1 <= N <= 105
 -109 <= A[i] <= 109


 Input Format
 Single argument which is an integer array A.


 Output Format
 Return an integer.


 Example Input
 Input 1:
  A = [1, -2, 1, 2]
 Input 2:
  A = [3, 2, -1]


 Example Output
 Output 1:
 3
 Output 2:
 0


 Example Explanation
 Explanation 1:
  [1, -2, 1] is the largest subarray which sums up to 0.
 Explanation 2:
  No subarray sums up to 0.
 */
#include <iostream>
#include<iostream>
#include<unordered_map>
using namespace std;

int solve(vector<int> &A) {
//    int ans=0;
    size_t N = A.size();
    long t=0;
    int len=INT_MIN;
    unordered_map<long,int> UM;
    
    for(int i=0;i<N;i++)
    {
        t+=A[i];
        if(t==0)
        {
            len=max(len,(i-0+1));
        }
        if(UM.find(t)!=UM.end())
        {
            len=max((i-UM[t]),len);
        }
        UM[t]=i;
    }
    return len==INT_MIN ? 0: len;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Longest subarray sum zero!\n";
    vector<int> A{0};
    cout<<"Longest sub arrray od sum Zero "<<solve(A)<<endl;
    return 0;
}
