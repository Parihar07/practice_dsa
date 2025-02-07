//
//  main.cpp
//  stack_largestRectHisto
//
//  Created by CodeBreaker on 19/01/25.
//
<<<<<<< HEAD

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
=======
/*
 Largest Rectangle in Histogram
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an array of integers A.
 A represents a histogram i.e A[i] denotes the height of the ith histogram's bar. Width of each bar is 1.
 Find the area of the largest rectangle formed by the histogram.


 Problem Constraints
 1 <= |A| <= 100000
 1 <= A[i] <= 10000


 Input Format
 The only argument given is the integer array A.


 Output Format
 Return the area of the largest rectangle in the histogram.


 Example Input
 Input 1:
  A = [2, 1, 5, 6, 2, 3]
 Input 2:
  A = [2]


 Example Output
 Output 1:
  10
 Output 2:
  2


 Example Explanation
 Explanation 1:
 The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
 Explanation 2:
 Largest rectangle has area 2.
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    static int largestRectangleAreaBF(vector<int> &A);
    static int largestRectangleArea(vector<int> &A);
};
int Solution::largestRectangleArea(vector<int> &A)
{
    size_t N = A.size();
    int ans=0;
    stack<int> stk;
    
    vector<int> SL(N,-1);
    for(int i=0;i<N;i++)
    {
        while(!stk.empty() && A[stk.top()]>=A[i])
        {
            stk.pop();
        }
        if(!stk.empty() && A[stk.top()]<A[i])
        {
            SL[i]=stk.top();
        }
        stk.push(i);
    }
    for(auto i:SL)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    stk = stack<int>();
    vector<int> SR(N,(int)N);
    for(int i=N-1;i>=0;i--)
    {
        while(!stk.empty() && A[stk.top()]>=A[i])
        {
            stk.pop();
        }
        if(!stk.empty() && A[stk.top()]<A[i])
        {
            SR[i]=stk.top();
        }
        stk.push(i);
    }
    
    for(auto i:SR)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<N;i++)
    {
        int area=0;
        area = A[i] * (SR[i]-SL[i]-1);
        ans=max(ans,area);
    }
    return ans;
}
int Solution::largestRectangleAreaBF(vector<int> &A) {
    size_t N = A.size();
    int left=0,right=0,ans=0;
    for(int i=0;i<N;i++)
    {
        left=0;right=0;
        for(int j=i-1;j>=0;j--)
        {
            if(A[j]>=A[i])
            {
                left+=A[i];
            } else {
                break;
            }
        }
        for(int k=i+1;k<N;k++)
        {
            if(A[k]>=A[i])
            {
                right+=A[i];
            } else {
                break;
            }
        }
        ans=max(ans,(left+right+A[i]));
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, largest rectangle in histogram!\n";
    vector<int> A{2, 1, 5, 6, 2, 3};
    cout<<"largest rect : " << Solution::largestRectangleArea(A)<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
