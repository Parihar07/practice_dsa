/*
Problem Statement:
Given an array A of integers, return a new array B where B[i] is the product of
all elements in A except A[i]. You must solve this problem WITHOUT using division.

Example:
Input: [1, 2, 3, 4]
Output: [24, 12, 8, 6]

Approach:
Use prefix and suffix product arrays.
Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> productArray(vector<int> &A)
{
    size_t N = A.size();
    if (N == 0)
        return {};
    if (N == 1)
        return {1};

    vector<int> prefixProd(N, 1), suffixProd(N, 1);
    prefixProd[0] = A[0];
    suffixProd[N - 1] = A[N - 1];

    for (int i = 1; i < N; i++)
    {
        prefixProd[i] = prefixProd[i - 1] * A[i];
    }
    for (int i = N - 2; i >= 0; i--)
    {
        suffixProd[i] = suffixProd[i + 1] * A[i];
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            ans[i] = suffixProd[i + 1];
        }
        else if (i == N - 1)
        {
            ans[i] = prefixProd[i - 1];
        }
        else
        {
            ans[i] = prefixProd[i - 1] * suffixProd[i + 1];
        }
    }
    return ans;
}

int main()
{
    cout << "=== Product Array Problem ===\n\n";

    cout << "Test Case 1: [1, 2, 3, 4]\n";
    vector<int> A1{1, 2, 3, 4};
    auto ans1 = productArray(A1);
    cout << "Output: ";
    for (auto i : ans1)
        cout << i << " ";
    cout << "\nExpected: 24 12 8 6\n\n";

    cout << "Test Case 2: [2, 3, 4, 5]\n";
    vector<int> A2{2, 3, 4, 5};
    auto ans2 = productArray(A2);
    cout << "Output: ";
    for (auto i : ans2)
        cout << i << " ";
    cout << "\nExpected: 60 40 30 24\n\n";

    cout << "Test Case 3: [-1, 2, -3, 4]\n";
    vector<int> A3{-1, 2, -3, 4};
    auto ans3 = productArray(A3);
    cout << "Output: ";
    for (auto i : ans3)
        cout << i << " ";
    cout << "\nExpected: -24 12 -8 6\n\n";

    cout << "Test Case 4: [5, 7]\n";
    vector<int> A4{5, 7};
    auto ans4 = productArray(A4);
    cout << "Output: ";
    for (auto i : ans4)
        cout << i << " ";
    cout << "\nExpected: 7 5\n\n";

    return 0;
}