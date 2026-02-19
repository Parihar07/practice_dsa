/*
 * Problem Statement (PS):
 * Given a sorted array of integers, find the first occurrence of a target element k.
 * If the element is not present, return -1.
 *
 * Time Complexity (TC): O(log n)
 * - Binary search halves the search space in each iteration
 *
 * Space Complexity (SC): O(1)
 * - Only using constant extra space for variables
 */

#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> &A, int k)
{
    if (A.empty())
        return -1;

    int ans = -1, s = 0, e = A.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (A[m] == k)
        {
            ans = m;       // Record this occurrence
            e = m - 1;     // Continue searching left for earlier occurrence
        }
        else if (A[m] < k)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int main()
{
    cout << "First Occurrence in Sorted Array\n\n";

    // Test Case 1: Element present multiple times
    vector<int> A1{2, 3, 4, 4, 4, 4, 4, 5, 8};
    cout << "Test 1: Array = {2,3,4,4,4,4,4,5,8}, k = 4\n";
    cout << "Expected: 2, Got: " << firstOccurance(A1, 4) << "\n\n";

    // Test Case 2: Element present once
    vector<int> A2{1, 2, 3, 4, 5};
    cout << "Test 2: Array = {1,2,3,4,5}, k = 3\n";
    cout << "Expected: 2, Got: " << firstOccurance(A2, 3) << "\n\n";

    // Test Case 3: Element not present
    vector<int> A3{1, 2, 3, 4, 5};
    cout << "Test 3: Array = {1,2,3,4,5}, k = 6\n";
    cout << "Expected: -1, Got: " << firstOccurance(A3, 6) << "\n\n";

    // Test Case 4: Empty array
    vector<int> A4;
    cout << "Test 4: Array = {}, k = 5\n";
    cout << "Expected: -1, Got: " << firstOccurance(A4, 5) << "\n\n";

    // Test Case 5: Single element - match
    vector<int> A5{5};
    cout << "Test 5: Array = {5}, k = 5\n";
    cout << "Expected: 0, Got: " << firstOccurance(A5, 5) << "\n\n";

    // Test Case 6: Single element - no match
    vector<int> A6{5};
    cout << "Test 6: Array = {5}, k = 3\n";
    cout << "Expected: -1, Got: " << firstOccurance(A6, 3) << "\n\n";

    // Test Case 7: First element is target
    vector<int> A7{1, 1, 1, 2, 3};
    cout << "Test 7: Array = {1,1,1,2,3}, k = 1\n";
    cout << "Expected: 0, Got: " << firstOccurance(A7, 1) << "\n\n";

    // Test Case 8: Last element is target
    vector<int> A8{1, 2, 3, 4, 5, 5, 5};
    cout << "Test 8: Array = {1,2,3,4,5,5,5}, k = 5\n";
    cout << "Expected: 4, Got: " << firstOccurance(A8, 5) << "\n";

    return 0;
}