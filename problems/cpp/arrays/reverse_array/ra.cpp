
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
    cout << "Testing Reverse Array\n";
    cout << "=====================\n\n";
    
    // Test 1: Normal case
    vector<int> test1{2,3,4,5,6};
    vector<int> result1 = sol.solve(test1);
    cout << "Test 1 - [2,3,4,5,6]: ";
    for(auto i:result1) cout << i << " ";
    cout << (result1 == vector<int>{6,5,4,3,2} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: Palindrome (example from problem)
    vector<int> test2{1,2,3,2,1};
    vector<int> result2 = sol.solve(test2);
    cout << "Test 2 - [1,2,3,2,1]: ";
    for(auto i:result2) cout << i << " ";
    cout << (result2 == vector<int>{1,2,3,2,1} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: From problem example
    vector<int> test3{1,1,10};
    vector<int> result3 = sol.solve(test3);
    cout << "Test 3 - [1,1,10]: ";
    for(auto i:result3) cout << i << " ";
    cout << (result3 == vector<int>{10,1,1} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: Single element
    vector<int> test4{42};
    vector<int> result4 = sol.solve(test4);
    cout << "Test 4 - [42]: ";
    for(auto i:result4) cout << i << " ";
    cout << (result4 == vector<int>{42} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Two elements
    vector<int> test5{10,20};
    vector<int> result5 = sol.solve(test5);
    cout << "Test 5 - [10,20]: ";
    for(auto i:result5) cout << i << " ";
    cout << (result5 == vector<int>{20,10} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: All same elements
    vector<int> test6{5,5,5,5};
    vector<int> result6 = sol.solve(test6);
    cout << "Test 6 - [5,5,5,5]: ";
    for(auto i:result6) cout << i << " ";
    cout << (result6 == vector<int>{5,5,5,5} ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n=====================\n";
    return 0;
}