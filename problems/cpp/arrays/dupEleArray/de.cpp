#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Problem Statement: Find Duplicate Element in Array
===================================================
Given an array A containing N integers where 1 <= A[i] <= N,
find if there are any duplicate elements in the array.
Return true if duplicates exist, false otherwise.

Input:
- A: vector of integers

Output:
- true if any duplicate element exists, false otherwise

Example:
Input: [1, 2, 3, 4, 4, 5]
Output: true (4 appears twice)

Input: [1, 2, 3, 4, 5]
Output: false (no duplicates)

Time Complexity Comparison:
- Method 1 (Brute Force):  O(N²)
- Method 2 (Sorting):      O(N log N)
- Method 3 (Hash Set):     O(N)

Space Complexity:
- Method 1: O(1)
- Method 2: O(1) if using built-in sort, else O(N)
- Method 3: O(N)
*/

// Brute Force: O(N^2) Time | O(1) Space
bool finddup1(vector<int> &A)
{
    // Compare each element with all elements after it
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] == A[j]) // Found duplicate
                return true;
        }
    }
    return false; // No duplicates found
}

// Sorting: O(N log N) Time | O(1) Space
bool finddup2(vector<int> &A)
{
    if (A.size() <= 1)
        return false;

    sort(A.begin(), A.end());
    // After sorting, duplicates will be adjacent
    for (int i = 0; i < A.size() - 1; i++)
    { // Loop to size-1 to avoid out-of-bounds
        if (A[i] == A[i + 1])
        {
            return true; // Found duplicate
        }
    }
    return false; // No duplicates found
}

// Hash Set: O(N) Time | O(N) Space
bool finddup3(vector<int> &A)
{
    unordered_set<int> US;
    for (auto i : A)
    {
        // If element already in set, it's a duplicate
        if (US.find(i) != US.end())
            return true;
        US.insert(i);
    }
    return false; // No duplicates found
}

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    cout << "=== Find Duplicate Element in Array - Test Cases ===\n\n";

    // Test Case 1: Array with obvious duplicates
    cout << "Test Case 1: Array with duplicates\n";
    vector<int> A1 = {1, 2, 3, 4, 4, 5};
    cout << "Input: ";
    printArray(A1);
    cout << "Method 1 (Brute Force): " << (finddup1(A1) ? "YES" : "NO") << endl;

    vector<int> A1_copy = {1, 2, 3, 4, 4, 5};
    cout << "Method 2 (Sorting):      " << (finddup2(A1_copy) ? "YES" : "NO") << endl;

    vector<int> A1_copy2 = {1, 2, 3, 4, 4, 5};
    cout << "Method 3 (Hash Set):     " << (finddup3(A1_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: YES\n\n";

    // Test Case 2: Array without duplicates
    cout << "Test Case 2: Array without duplicates\n";
    vector<int> A2 = {1, 2, 3, 4, 5};
    cout << "Input: ";
    printArray(A2);
    cout << "Method 1 (Brute Force): " << (finddup1(A2) ? "YES" : "NO") << endl;

    vector<int> A2_copy = {1, 2, 3, 4, 5};
    cout << "Method 2 (Sorting):      " << (finddup2(A2_copy) ? "YES" : "NO") << endl;

    vector<int> A2_copy2 = {1, 2, 3, 4, 5};
    cout << "Method 3 (Hash Set):     " << (finddup3(A2_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: NO\n\n";

    // Test Case 3: Single element (no duplicates)
    cout << "Test Case 3: Single element\n";
    vector<int> A3 = {5};
    cout << "Input: ";
    printArray(A3);
    cout << "Method 1 (Brute Force): " << (finddup1(A3) ? "YES" : "NO") << endl;

    vector<int> A3_copy = {5};
    cout << "Method 2 (Sorting):      " << (finddup2(A3_copy) ? "YES" : "NO") << endl;

    vector<int> A3_copy2 = {5};
    cout << "Method 3 (Hash Set):     " << (finddup3(A3_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: NO\n\n";

    // Test Case 4: Two identical elements
    cout << "Test Case 4: Two identical elements\n";
    vector<int> A4 = {3, 3};
    cout << "Input: ";
    printArray(A4);
    cout << "Method 1 (Brute Force): " << (finddup1(A4) ? "YES" : "NO") << endl;

    vector<int> A4_copy = {3, 3};
    cout << "Method 2 (Sorting):      " << (finddup2(A4_copy) ? "YES" : "NO") << endl;

    vector<int> A4_copy2 = {3, 3};
    cout << "Method 3 (Hash Set):     " << (finddup3(A4_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: YES\n\n";

    // Test Case 5: Duplicate at beginning
    cout << "Test Case 5: Duplicate at beginning\n";
    vector<int> A5 = {1, 1, 2, 3, 4};
    cout << "Input: ";
    printArray(A5);
    cout << "Method 1 (Brute Force): " << (finddup1(A5) ? "YES" : "NO") << endl;

    vector<int> A5_copy = {1, 1, 2, 3, 4};
    cout << "Method 2 (Sorting):      " << (finddup2(A5_copy) ? "YES" : "NO") << endl;

    vector<int> A5_copy2 = {1, 1, 2, 3, 4};
    cout << "Method 3 (Hash Set):     " << (finddup3(A5_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: YES\n\n";

    // Test Case 6: Duplicate at end
    cout << "Test Case 6: Duplicate at end\n";
    vector<int> A6 = {1, 2, 3, 4, 4};
    cout << "Input: ";
    printArray(A6);
    cout << "Method 1 (Brute Force): " << (finddup1(A6) ? "YES" : "NO") << endl;

    vector<int> A6_copy = {1, 2, 3, 4, 4};
    cout << "Method 2 (Sorting):      " << (finddup2(A6_copy) ? "YES" : "NO") << endl;

    vector<int> A6_copy2 = {1, 2, 3, 4, 4};
    cout << "Method 3 (Hash Set):     " << (finddup3(A6_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: YES\n\n";

    // Test Case 7: Multiple duplicates
    cout << "Test Case 7: Multiple duplicates\n";
    vector<int> A7 = {5, 2, 5, 3, 2, 4};
    cout << "Input: ";
    printArray(A7);
    cout << "Method 1 (Brute Force): " << (finddup1(A7) ? "YES" : "NO") << endl;

    vector<int> A7_copy = {5, 2, 5, 3, 2, 4};
    cout << "Method 2 (Sorting):      " << (finddup2(A7_copy) ? "YES" : "NO") << endl;

    vector<int> A7_copy2 = {5, 2, 5, 3, 2, 4};
    cout << "Method 3 (Hash Set):     " << (finddup3(A7_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: YES\n\n";

    // Test Case 8: Large array
    cout << "Test Case 8: Larger array\n";
    vector<int> A8 = {10, 20, 30, 40, 50, 60, 70, 80, 50, 90};
    cout << "Input: ";
    printArray(A8);
    cout << "Method 1 (Brute Force): " << (finddup1(A8) ? "YES" : "NO") << endl;

    vector<int> A8_copy = {10, 20, 30, 40, 50, 60, 70, 80, 50, 90};
    cout << "Method 2 (Sorting):      " << (finddup2(A8_copy) ? "YES" : "NO") << endl;

    vector<int> A8_copy2 = {10, 20, 30, 40, 50, 60, 70, 80, 50, 90};
    cout << "Method 3 (Hash Set):     " << (finddup3(A8_copy2) ? "YES" : "NO") << endl;
    cout << "Expected: YES\n\n";

    cout << "\n=== Complexity Summary ===\n";
    cout << "Method 1 (Brute Force): O(N²) Time | O(1) Space\n";
    cout << "Method 2 (Sorting):     O(N log N) Time | O(1) Space\n";
    cout << "Method 3 (Hash Set):    O(N) Time | O(N) Space - OPTIMAL\n";

    return 0;
}