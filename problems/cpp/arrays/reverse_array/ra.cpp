
/*
 Reverse the Array
Solved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
You are given a constant array A.
You are required to return another array which is the reversed form of the input array.


Problem Constraints
1 <= A.size() <= 10000
1 <= A[i] <= 10000


Input Format
First argument is a constant array A.


Output Format
Return an integer array.


Example Input
Input 1:
A = [1,2,3,2,1]
Input 2:
A = [1,1,10]


Example Output
Output 1:
 [1,2,3,2,1] 
Output 2:
 [10,1,1] 


Example Explanation
Explanation 1:
Reversed form of input array is same as original array
Explanation 2:
Clearly, Reverse of [1,1,10] is [10,1,1]
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> solve(const vector<int> &A);
};

vector<int> Solution::solve(const vector<int> &A) {
    int sz = A.size();
    int i=0;
    int j=sz-1;
    vector<int> ta(sz);
    for(int i=0;i<sz;i++)
    {
        ta[i]= A[i];
    }
    while(i<j)
    {
        int tmp=ta[i];
        ta[i]=ta[j];
        ta[j]=tmp;
        i++;j--;
    }
    return ta;
}

int main()
{
    Solution sol;
    vector<int> v{2,3,4,5,6};
    vector<int> rt = sol.solve(v);
    return 0;
    
}