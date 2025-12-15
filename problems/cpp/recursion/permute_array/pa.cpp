/*
 * PROBLEM STATEMENT:
 * Generate all permutations of an array.
 * Given an array of integers, return all possible permutations.
 *
 * APPROACH:
 * - Use backtracking with swap technique
 * - Fix one position at a time and swap all remaining elements
 * - Recursively generate permutations for remaining positions
 *
 * TIME COMPLEXITY: O(n! * n)
 *   - Generate n! permutations
 *   - Each permutation takes O(n) to store/print
 *
 * SPACE COMPLEXITY: O(n! * n)
 *   - Store all n! permutations with n elements each
 *   - O(n) recursion stack depth
 *
 * TEST CASES:
 * 1. Input: [1, 2, 3]
 *    Output: 6 permutations
 *    (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,2,1), (3,1,2)
 *
 * 2. Input: [1, 1, 2]
 *    Output: 6 permutations (including duplicates)
 *    (1,1,2), (1,2,1), (1,1,2), (1,2,1), (2,1,1), (2,1,1)
 *
 * 3. Input: [1]
 *    Output: 1 permutation (1)
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permute(vector<int> &A, int ind, vector<vector<int>> &op)
{
    // Base case: all positions fixed, store this permutation
    if (ind == A.size())
    {
        op.push_back(A);
        return;
    }
    // Try each element from position ind onwards
    for (size_t i = ind; i < A.size(); i++)
    {
        // Swap: place A[i] at position ind
        swap(A[i], A[ind]);
        // Recurse: generate permutations for remaining positions
        permute(A, ind + 1, op);
        // Backtrack: restore original arrangement
        swap(A[i], A[ind]);
    }
}



int main()
{
    // Test case 1: [1, 2, 3] - 6 permutations
    cout << "Test 1: [1, 2, 3]\n";
    vector<int> A{1, 2, 3};
    vector<vector<int>> op;
    permute(A, 0, op);
    cout << "Total permutations: " << op.size() << "\n";
    for (auto i : op)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // Test case 2: [1, 2] - 2 permutations
    cout << "\nTest 2: [1, 2]\n";
    vector<int> B{1, 2};
    vector<vector<int>> op2;
    permute(B, 0, op2);
    cout << "Total permutations: " << op2.size() << "\n";
    for (auto i : op2)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // Test case 3: [1] - 1 permutation
    cout << "\nTest 3: [1]\n";
    vector<int> C{1};
    vector<vector<int>> op3;
    permute(C, 0, op3);
    cout << "Total permutations: " << op3.size() << "\n";
    for (auto i : op3)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}