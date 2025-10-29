//
//  main.cpp
<<<<<<< HEAD
//  stack_greaterleft
//
//  Created by CodeBreaker on 19/01/25.
//

#include <iostream>
=======
//  stack-greaterright
//
//  Created by CodeBreaker on 19/01/25.
//
/*
 Next Greater
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A, find the next greater element G[i] for every element A[i] in the array.
 The next greater element for an element A[i] is the first greater element on the right side of A[i] in the array, A.
 More formally:
 G[i] for an element A[i] = an element A[j] such that
     j is minimum possible AND
     j > i AND
     A[j] > A[i]
 Elements for which no greater element exists, consider the next greater element as -1.


 Problem Constraints
 1 <= |A| <= 105
 1 <= A[i] <= 107


 Input Format
 The first and the only argument of input contains the integer array, A.


 Output Format
 Return an integer array representing the next greater element for each index in A.


 Example Input
 Input 1:
  A = [4, 5, 2, 10]
 Input 2:
  A = [3, 2, 1]


 Example Output
 Output 1:
  [5, 10, 10, -1]
 Output 2:
  [-1, -1, -1]


 Example Explanation
 Explanation 1:
 For 4, the next greater element towards its right is 5.
 For 5 and 2, the next greater element towards their right is 10.
 For 10, there is no next greater element towards its right.
 Explanation 2:
 As the array is in descending order, there is no next greater element for all the elements.
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    static vector<int> nextGreaterBF(vector<int> &A);
    static vector<int> nextGreater(vector<int> &A);
};

vector<int> Solution::nextGreaterBF(vector<int> &A) {
    size_t N=A.size();
    vector<int> ans(N,-1);
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(A[j]>A[i])
            {
                ans[i]=A[j]; break;
            }
        }
    }
    return ans;
}
vector<int> Solution::nextGreater(vector<int> &A) {
    vector<int> ans(A.size(),-1);
    stack<int> stk;
    for(int i=ans.size()-1;i>=0;i--)
    {
        while(!stk.empty()&&stk.top()<=A[i])
        {
            stk.pop();
        }
        if(!stk.empty()&&stk.top()>A[i])
        {
            ans[i]=stk.top();
        }
        stk.push(A[i]);
    }
    return ans;
}
>>>>>>> d61fd74 (treetraversals)

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
<<<<<<< HEAD
=======
    vector<int> A{4, 5, 2, 10};
    vector<int> ans = Solution::nextGreater(A);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
