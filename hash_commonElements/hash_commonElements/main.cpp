//
//  main.cpp
//  hash_commonElements
//
//  Created by CodeBreaker on 29/11/24.
//
/*
 Common Elements
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given two integer arrays, A and B of size N and M, respectively. Your task is to find all the common elements in both the array.
 NOTE:
 Each element in the result should appear as many times as it appears in both arrays.
 The result can be in any order.


 Problem Constraints
 1 <= N, M <= 105
 1 <= A[i] <= 109


 Input Format
 First argument is an integer array A of size N.
 Second argument is an integer array B of size M.


 Output Format
 Return an integer array denoting the common elements.


 Example Input
 Input 1:
  A = [1, 2, 2, 1]
  B = [2, 3, 1, 2]
 Input 2:
  A = [2, 1, 4, 10]
  B = [3, 6, 2, 10, 10]


 Example Output
 Output 1:
  [1, 2, 2]
 Output 2:
  [2, 10]


 Example Explanation
 Explanation 1:
  Elements (1, 2, 2) appears in both the array. Note 2 appears twice in both the array.
 Explantion 2:
  Elements (2, 10) appears in both the array.
 */

#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Do not write code to include libraries, main() function or accept any input from the console.
// Initialization code is already written and hidden from you. Do not write code for it again.
vector<int> solve(vector<int> &A, vector<int> &B) {
    // Just write your code below to complete the function. Required input is available to you as the function arguments.
    // Do not print the result or any output. Just return the result via this function.
    vector<int> ans(0);
    unordered_map<int, int> um;
    size_t N = A.size(), M=B.size();
    for(int i=0;i<N;i++)
    {
        um[A[i]]+=1;
    }
    
    for(int i=0;i<M;i++)
    {
        if(um.find(B[i]) != um.end())
        {
            if(um[B[i]]>0)
            {
                ans.push_back(B[i]);
            }
            um[B[i]]--;
        }
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Common elements hashing!\n";
    cout<<"-----------------------\n";
    vector<int> A{1, 2, 2, 1};
    vector<int> B{2, 3, 1, 2,2};
    vector<int> ans = solve(A, B);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
