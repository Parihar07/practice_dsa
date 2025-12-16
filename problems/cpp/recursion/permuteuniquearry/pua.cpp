/*
 * PROBLEM STATEMENT:
 * Generate all unique permutations of an array that may contain duplicates.
 * Given an array of integers, return all distinct permutations without repetition.
 *
 * APPROACH:
 * - Use backtracking with swap technique
 * - At each position, use unordered_set to track values already used
 * - Skip swapping if the value has already been placed at this position
 * - This prevents duplicate permutations when array has repeated elements
 *
 * TIME COMPLEXITY: O(n! * n)
 *   - Generate at most n! permutations (fewer if duplicates exist)
 *   - Each permutation takes O(n) to store
 *   - Set operations are O(1) average
 *
 * SPACE COMPLEXITY: O(n! * n)
 *   - Store all unique permutations
 *   - O(n) recursion stack depth
 *   - O(n) for unordered_set at each level
 *
 * TEST CASES:
 * 1. Input: [1, 1, 2]
 *    Output: 3 unique permutations
 *    (1,1,2), (1,2,1), (2,1,1)
 *
 * 2. Input: [1, 2, 3]
 *    Output: 6 permutations (all unique since no duplicates)
 *    (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), (3,2,1)
 *
 * 3. Input: [2, 2, 2]
 *    Output: 1 permutation
 *    (2,2,2)
 *
 * 4. Input: [1]
 *    Output: 1 permutation (1)
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void permuteUnique(vector<int> &A, size_t idx, vector<vector<int>> &op)
{
    // Base case: all positions fixed, store this permutation
    if (idx == A.size())
    {
        op.push_back(A);
        return;
    }
    // Track values already used at this position to avoid duplicates
    unordered_set<int> dup;
    for (size_t i = idx; i < A.size(); i++)
    {
        // Skip if this value was already used at this position
        if (dup.find(A[i]) == dup.end())
        {
            dup.insert(A[i]);              // Mark value as used
            swap(A[i], A[idx]);            // Place A[i] at position idx
            permuteUnique(A, idx + 1, op); // Recurse for next position
            swap(A[i], A[idx]);            // Backtrack
        }
    }
}

int main()
{
    cout << "=== UNIQUE PERMUTATIONS ===\n\n";

    // Test case 1: [1, 1, 2] - 3 unique permutations (has duplicates)
    cout << "Test 1: [1, 1, 2] - Array with duplicates\n";
    vector<int> A{1, 1, 2};
    vector<vector<int>> op;
    permuteUnique(A, 0, op);
    cout << "Total unique permutations: " << op.size() << "\n";
    for (auto i : op)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // Test case 2: [1, 2, 3] - 6 permutations (all unique)
    cout << "\nTest 2: [1, 2, 3] - All distinct elements\n";
    vector<int> B{1, 2, 3};
    vector<vector<int>> op2;
    permuteUnique(B, 0, op2);
    cout << "Total unique permutations: " << op2.size() << "\n";
    for (auto i : op2)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // Test case 3: [2, 2, 2] - 1 permutation (all same)
    cout << "\nTest 3: [2, 2, 2] - All elements same\n";
    vector<int> C{2, 2, 2};
    vector<vector<int>> op3;
    permuteUnique(C, 0, op3);
    cout << "Total unique permutations: " << op3.size() << "\n";
    for (auto i : op3)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    // Test case 4: [1, 2, 1, 2] - Multiple duplicates
    cout << "\nTest 4: [1, 2, 1, 2] - Multiple pairs of duplicates\n";
    vector<int> D{1, 2, 1, 2};
    vector<vector<int>> op4;
    permuteUnique(D, 0, op4);
    cout << "Total unique permutations: " << op4.size() << "\n";
    for (auto i : op4)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}