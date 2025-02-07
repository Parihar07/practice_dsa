//
//  main.cpp
//  stack_smallerleft
//
//  Created by CodeBreaker on 19/01/25.
//
<<<<<<< HEAD

#include <iostream>
=======
/*
 Nearest Smaller Element
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array A, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.
 More formally,
 G[i] for an element A[i] = an element A[j] such that
 j is maximum possible AND
 j < i AND
 A[j] < A[i]
 Elements for which no smaller element exist, consider the next smaller element as -1.


 Problem Constraints
 1 <= |A| <= 100000
 -109 <= A[i] <= 109


 Input Format
 The only argument given is integer array A.


 Output Format
 Return the integar array G such that G[i] contains the nearest smaller number than A[i]. If no such element occurs G[i] should be -1.


 Example Input
 Input 1:
  A = [4, 5, 2, 10, 8]
 Input 2:
  A = [3, 2, 1]


 Example Output
 Output 1:
  [-1, 4, -1, 2, 2]
 Output 2:
  [-1, -1, -1]


 Example Explanation
 Explanation 1:
 index 1: No element less than 4 in left of 4, G[1] = -1
 index 2: A[1] is only element less than A[2], G[2] = A[1]
 index 3: No element less than 2 in left of 2, G[3] = -1
 index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
 index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
 Explanation 2:
 index 1: No element less than 3 in left of 3, G[1] = -1
 index 2: No element less than 2 in left of 2, G[2] = -1
 index 3: No element less than 1 in left of 1, G[3] = -1


 Expected Output
 Provide sample input and click run to see the correct output for the provided input. Use this to improve your problem understanding and test edge cases
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    static vector<int> prevSmallerBF(vector<int> &A);
    static vector<int> prevSmaller(vector<int> &A);
};

vector<int> Solution::prevSmallerBF(vector<int> &A) {
    size_t N = A.size();
    vector<int> ans(N,-1);
    for(int i=0;i<N;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(A[j]<A[i])
            {
                ans[i]=A[j]; break;
            }
        }
    }
    return ans;
}

vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> ans(A.size(),-1);
    stack<int> stk;
    for(int i=0;i<A.size();i++)
    {
        while(!stk.empty() && stk.top()>=A[i])
        {
            stk.pop();
        }
        if(!stk.empty() && stk.top()<A[i])
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
    vector<int> A{4,5,8,2,10,8,8,11};
    vector<int> ans = Solution::prevSmaller(A);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
