/*
PS: Find the first missing positive integer.
    Given an unsorted integer array, find the smallest positive integer that is missing.
    Return the first missing positive (1, 2, 3, ...).

Algo: Cyclic Sort approach
    - Place each positive integer i at index (i-1)
    - Only process elements in range [1, n]
    - After placement, scan array to find first position where A[i] != i+1

TC: O(n) - Each element is visited at most twice
SC: O(1) - In-place sorting
*/

#include <iostream>
#include <vector>
using namespace std;

int firstmissposnum(vector<int> &A)
{
    // Cyclic sort: place each element at its correct position
    for (int i = 0; i < A.size(); i++)
    {
        int ele = A[i];
        int rightIndex = ele - 1;
        if (ele > 0 && ele <= A.size())
        {
            if (A[rightIndex] != ele)
            {
                swap(A[i], A[rightIndex]);
                i--;
            }
        }
    }

    // Find first missing positive
    for (int i = 0; i < A.size(); i++)
    {
        if (i + 1 != A[i])
            return i + 1;
    }

    // All elements 1 to n are present
    return A.size() + 1;
}

int main()
{
    // TC1: Missing middle element
    cout << "TC1: [3,2,1,-3,8,2]\n";
    cout << "Expected: 4\n";
    vector<int> A1{3, 2, 1, -3, 8, 2};
    cout << "Result: " << firstmissposnum(A1) << "\n\n";

    // TC2: Missing 1
    cout << "TC2: [2,3,4]\n";
    cout << "Expected: 1\n";
    vector<int> A2{2, 3, 4};
    cout << "Result: " << firstmissposnum(A2) << "\n\n";

    // TC3: All consecutive from 1
    cout << "TC3: [1,2,3,4,5]\n";
    cout << "Expected: 6\n";
    vector<int> A3{1, 2, 3, 4, 5};
    cout << "Result: " << firstmissposnum(A3) << "\n\n";

    // TC4: All negative
    cout << "TC4: [-1,-2,-3]\n";
    cout << "Expected: 1\n";
    vector<int> A4{-1, -2, -3};
    cout << "Result: " << firstmissposnum(A4) << "\n\n";

    // TC5: With duplicates
    cout << "TC5: [1,1,1,1]\n";
    cout << "Expected: 2\n";
    vector<int> A5{1, 1, 1, 1};
    cout << "Result: " << firstmissposnum(A5) << "\n";

    return 0;
}