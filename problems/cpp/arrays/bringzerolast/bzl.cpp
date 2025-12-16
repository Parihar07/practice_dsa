#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Move Zeros to End

Given an array of integers, move all zeros to the end while maintaining the
relative order of non-zero elements. Perform this operation in-place.

Example:
Input:  [7, 0, 3, 0, 5, 0, 9]
Output: [7, 3, 5, 9, 0, 0, 0]

Approach:
- Use two pointers: `j` tracks position for next non-zero, `i` scans array
- When A[i] is non-zero, swap with A[j] and increment j
- All zeros naturally accumulate at the end

Time Complexity: O(n) - single pass through array
Space Complexity: O(1) - in-place modification, constant extra space
*/

void bzlast(vector<int> &A)
{
    int j = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] != 0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
}

void bzlast2(vector<int> &A)
{
    int j = 0;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] != 0)
        {
            A[j] = A[i];
            j++;
        }
    }
    for (size_t i = j; i < A.size(); i++)
    {
        A[i] = 0;
    }
}

int main()
{
    cout << "Problem: Move Zeros to End\n\n";

    // Test case 1: Mixed zeros
    vector<int> A{7, 0, 3, 0, 5, 0, 9};
    cout << "Input:  ";
    for (auto i : A)
        cout << i << " ";
    cout << "\n";

    bzlast2(A);

    cout << "Output: ";
    for (auto i : A)
        cout << i << " ";
    cout << "\n\n";

    // Test case 2: All zeros
    vector<int> B{0, 0, 0, 0};
    cout << "Input:  ";
    for (auto i : B)
        cout << i << " ";
    cout << "\n";

    bzlast(B);

    cout << "Output: ";
    for (auto i : B)
        cout << i << " ";
    cout << "\n\n";

    // Test case 3: No zeros
    vector<int> C{1, 2, 3, 4};
    cout << "Input:  ";
    for (auto i : C)
        cout << i << " ";
    cout << "\n";

    bzlast(C);

    cout << "Output: ";
    for (auto i : C)
        cout << i << " ";
    cout << "\n";

    return 0;
}