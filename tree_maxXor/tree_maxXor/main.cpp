//
//  main.cpp
//  tree_maxXor
//
//  Created by CodeBreaker on 03/02/25.
//
/*
 Maximum XOR
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A, find and return the maximum result of A[i] XOR A[j], where i, j are the indexes of the array.


 Problem Constraints
 1 <= length of the array <= 100000
 0 <= A[i] <= 109


 Input Format
 The only argument given is the integer array A.


 Output Format
 Return an integer denoting the maximum result of A[i] XOR A[j].


 Example Input
 Input 1:
  A = [1, 2, 3, 4, 5]
 Input 2:
  A = [5, 17, 100, 11]


 Example Output
 Output 1:
  7
 Output 2:
  117


 Example Explanation
 Explanation 1:
  Maximum XOR occurs between element of indicies(0-based) 1 and 4 i.e. 2 ^ 5 = 7.
 Explanation 2:
  Maximum XOR occurs between element of indicies(0-based) 1 and 2 i.e. 17 ^ 100 = 117.
 */
#include <iostream>
#include <vector>
#include "xortrie.h"
using namespace std;

int solve(vector<int> &A) {
    int ans=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            ans = max(ans,A[i]^A[j]);
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Maximum XOR!\n";
    vector<int> A{22,61,38,27,21,34,42,37,43};
    MaxXorTrie mx;
    mx.insert(A);
    mx.parseTrie();
    return 0;
}
