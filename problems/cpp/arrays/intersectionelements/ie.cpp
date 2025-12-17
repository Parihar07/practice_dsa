/*
 * PROBLEM STATEMENT:
 * Find the intersection of two arrays A and B.
 * Return all elements that are present in both arrays.
 * Each element in the result must appear as many times as it shows in both arrays.
 *
 * Example:
 * A = [1, 2, 3, 4, 5, 6]
 * B = [1, 2, 3]
 * Output = [1, 2, 3]
 *
 * TIME COMPLEXITY: O(m + n)
 * - Where m = size of array A, n = size of array B
 * - We iterate through A once: O(m)
 * - We iterate through B once: O(n)
 *
 * SPACE COMPLEXITY: O(min(m, n))
 * - Unordered set stores elements from A: O(m)
 * - Result vector in worst case contains all elements: O(min(m, n))
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersectionEle(vector<int> &A, vector<int> &B)
{
    unordered_set<int> us;
    vector<int> ans;

    // Insert all elements from A into the set
    for (int x : A)
    {
        us.insert(x);
    }

    // Find common elements from B that exist in A
    for (int x : B)
    {
        if (us.find(x) != us.end())
        {
            ans.push_back(x);
        }
    }

    return ans;
}

int main()
{
    // Test Case 1: Basic intersection
    cout << "Test Case 1: Basic intersection\n";
    vector<int> A1{1, 2, 3, 4, 5, 6}, B1{1, 2, 3};
    vector<int> ans1 = intersectionEle(A1, B1);
    cout << "A = [1, 2, 3, 4, 5, 6], B = [1, 2, 3]\n";
    cout << "Output: ";
    for (auto x : ans1)
        cout << x << " ";
    cout << "\nExpected: 1 2 3\n\n";

    // Test Case 2: No intersection
    cout << "Test Case 2: No intersection\n";
    vector<int> A2{1, 2, 3}, B2{4, 5, 6};
    vector<int> ans2 = intersectionEle(A2, B2);
    cout << "A = [1, 2, 3], B = [4, 5, 6]\n";
    cout << "Output: ";
    for (auto x : ans2)
        cout << x << " ";
    cout << "(empty)\nExpected: (empty)\n\n";

    // Test Case 3: Complete overlap
    cout << "Test Case 3: Complete overlap\n";
    vector<int> A3{1, 2, 3}, B3{1, 2, 3};
    vector<int> ans3 = intersectionEle(A3, B3);
    cout << "A = [1, 2, 3], B = [1, 2, 3]\n";
    cout << "Output: ";
    for (auto x : ans3)
        cout << x << " ";
    cout << "\nExpected: 1 2 3\n\n";

    // Test Case 4: Partial overlap
    cout << "Test Case 4: Partial overlap\n";
    vector<int> A4{1, 2, 3, 4, 5}, B4{3, 4, 5, 6, 7};
    vector<int> ans4 = intersectionEle(A4, B4);
    cout << "A = [1, 2, 3, 4, 5], B = [3, 4, 5, 6, 7]\n";
    cout << "Output: ";
    for (auto x : ans4)
        cout << x << " ";
    cout << "\nExpected: 3 4 5\n\n";

    // Test Case 5: Single element arrays
    cout << "Test Case 5: Single element arrays\n";
    vector<int> A5{5}, B5{5};
    vector<int> ans5 = intersectionEle(A5, B5);
    cout << "A = [5], B = [5]\n";
    cout << "Output: ";
    for (auto x : ans5)
        cout << x << " ";
    cout << "\nExpected: 5\n\n";

    return 0;
}