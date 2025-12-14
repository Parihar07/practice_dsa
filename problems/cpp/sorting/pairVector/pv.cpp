/*
Problem: Sort Vector of Pairs with Custom Comparator

Description:
Implement a sorting algorithm that can sort a vector of pairs of integers
using custom comparison functions. The sorting should work with:
1. Ascending order: Sort by first element ascending, then by second element ascending
2. Descending order: Sort by first element descending, then by second element descending

Example:
Input: {{5,1}, {1,3}, {1,6}, {1,2}, {1,4}, {3,5}, {2,2}, {2,7}}

Ascending Output: {{1,2}, {1,3}, {1,4}, {1,6}, {2,2}, {2,7}, {3,5}, {5,1}}
Descending Output: {{5,1}, {3,5}, {2,7}, {2,2}, {1,6}, {1,4}, {1,3}, {1,2}}

Constraints:
- 1 <= vector size <= 1000
- Pairs contain integer values

Time Complexity: O(n²)
- The sorting algorithm uses nested loops
- Outer loop runs n times
- Inner loop runs (n-1), (n-2), ..., 1 times
- Total comparisons: n*(n-1)/2 ≈ O(n²)
- Each comparison of pairs is O(1)

Space Complexity: O(1)
- In-place sorting algorithm
- Only uses a constant amount of extra space for loop variables and swap operations
- No additional data structures are created
- The input vector is modified in place
*/

#include <iostream>
#include <vector>
using namespace std;

bool ascending(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

bool descending(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

void sortt(vector<pair<int, int>> &A, bool (*comp)(const pair<int, int> &a, const pair<int, int> &b))
{
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = i + 1; j < A.size(); j++)
        {
            if (comp(A[i], A[j]))
            {
                swap(A[i], A[j]);
            }
        }
    }
}

void printVector(const vector<pair<int, int>> &A)
{
    for (const auto &i : A)
    {
        cout << "{" << i.first << "," << i.second << "} ";
    }
    cout << endl;
}

void testCase1()
{
    cout << "\n=== Test Case 1: Basic Ascending Sort ===\n";
    vector<pair<int, int>> A{{5, 1}, {1, 3}, {1, 6}, {1, 2}, {1, 4}, {3, 5}, {2, 2}, {2, 7}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {1,2} {1,3} {1,4} {1,6} {2,2} {2,7} {3,5} {5,1}\n";
}

void testCase2()
{
    cout << "\n=== Test Case 2: Basic Descending Sort ===\n";
    vector<pair<int, int>> A{{5, 1}, {1, 3}, {1, 6}, {1, 2}, {1, 4}, {3, 5}, {2, 2}, {2, 7}};
    cout << "Original: ";
    printVector(A);
    sortt(A, descending);
    cout << "Descending: ";
    printVector(A);
    cout << "Expected: {5,1} {3,5} {2,7} {2,2} {1,6} {1,4} {1,3} {1,2}\n";
}

void testCase3()
{
    cout << "\n=== Test Case 3: All Same First Element ===\n";
    vector<pair<int, int>> A{{5, 3}, {5, 1}, {5, 7}, {5, 2}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {5,1} {5,2} {5,3} {5,7}\n";
}

void testCase4()
{
    cout << "\n=== Test Case 4: Already Sorted ===\n";
    vector<pair<int, int>> A{{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {1,1} {2,2} {3,3} {4,4}\n";
}

void testCase5()
{
    cout << "\n=== Test Case 5: Reverse Sorted ===\n";
    vector<pair<int, int>> A{{4, 4}, {3, 3}, {2, 2}, {1, 1}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {1,1} {2,2} {3,3} {4,4}\n";
}

void testCase6()
{
    cout << "\n=== Test Case 6: Duplicate Pairs ===\n";
    vector<pair<int, int>> A{{2, 3}, {2, 3}, {1, 1}, {2, 3}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {1,1} {2,3} {2,3} {2,3}\n";
}

void testCase7()
{
    cout << "\n=== Test Case 7: Single Element ===\n";
    vector<pair<int, int>> A{{5, 10}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {5,10}\n";
}

void testCase8()
{
    cout << "\n=== Test Case 8: Negative Numbers ===\n";
    vector<pair<int, int>> A{{-1, 5}, {-3, 2}, {-1, 3}, {0, 0}, {-3, 4}};
    cout << "Original: ";
    printVector(A);
    sortt(A, ascending);
    cout << "Ascending: ";
    printVector(A);
    cout << "Expected: {-3,2} {-3,4} {-1,3} {-1,5} {0,0}\n";
}

int main()
{
    cout << "===== Sorting Pair Vector with Custom Comparator =====\n";

    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    testCase6();
    testCase7();
    testCase8();

    cout << "\n===== All Test Cases Completed =====\n";
    return 0;
}