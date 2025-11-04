/*
Problem: Sum of Array Elements using Recursion

Given an array of integers, find the sum of all elements using recursion.

Example 1:
Input: A = [1, 4, 5, 6, 7]
Output: 23
Explanation: 1 + 4 + 5 + 6 + 7 = 23

Example 2:
Input: A = [10, 20, 30]
Output: 60

Example 3:
Input: A = []
Output: 0

Constraints:
- 0 <= A.length <= 10^4
- -10^9 <= A[i] <= 10^9

Approach:
- Base case: If index >= array size, return 0
- Recursive case: Return current element + sum of remaining elements
- Time Complexity: O(n)
- Space Complexity: O(n) due to recursion stack
*/

#include<iostream>
#include<vector>
using namespace std;

int getSum(const vector<int>& A, int ind){
    if(ind >= A.size())
        return 0;
    return A[ind] + getSum(A, ind + 1);
}

// Test helper function
void runTest(const string& testName, const vector<int>& arr, int expected) {
    int result = getSum(arr, 0);
    bool passed = (result == expected);
    cout << testName << ": ";
    cout << (passed ? "✓ PASSED" : "✗ FAILED");
    if (!passed) {
        cout << " (Expected: " << expected << ", Got: " << result << ")";
    }
    cout << endl;
}

int main()
{
    cout << "Running test cases for Array Sum (Recursion)\n";
    cout << "============================================\n\n";
    
    // Test 1: Normal case with positive numbers
    vector<int> test1{1, 4, 5, 6, 7};
    runTest("Test 1: Basic positive array", test1, 23);
    
    // Test 2: Single element
    vector<int> test2{42};
    runTest("Test 2: Single element", test2, 42);
    
    // Test 3: Empty array
    vector<int> test3{};
    runTest("Test 3: Empty array", test3, 0);
    
    // Test 4: Array with negative numbers
    vector<int> test4{-5, 10, -3, 8};
    runTest("Test 4: Mixed positive/negative", test4, 10);
    
    // Test 5: All negative numbers
    vector<int> test5{-1, -2, -3, -4};
    runTest("Test 5: All negatives", test5, -10);
    
    // Test 6: Array with zeros
    vector<int> test6{0, 5, 0, 10, 0};
    runTest("Test 6: Array with zeros", test6, 15);
    
    // Test 7: Large array
    vector<int> test7(100, 1); // 100 elements, all 1s
    runTest("Test 7: Large array (100 elements)", test7, 100);
    
    // Test 8: Two elements
    vector<int> test8{10, 20};
    runTest("Test 8: Two elements", test8, 30);
    
    cout << "\n============================================\n";
    cout << "All tests completed!\n";
    
    return 0;
}