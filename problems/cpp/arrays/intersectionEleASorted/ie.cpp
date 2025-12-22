/*
PS: Find intersection of two sorted arrays.
    Given two sorted arrays A and B, return all elements that appear in both arrays.
    Each element in the result must appear as many times as it shows in both arrays.

Algo: Two pointers approach
    - Use i for A, j for B
    - If A[i] == B[j], add to result and increment both
    - If A[i] < B[j], increment i (move in smaller array)
    - If A[i] > B[j], increment j (move in larger array)

TC: O(n + m) where n = A.size(), m = B.size()
SC: O(1) excluding output array
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> interElements(vector<int> &A, vector<int> &B)
{
    vector<int> ans;
    size_t i = 0, j = 0;

    // Two pointer approach
    while (i < A.size() && j < B.size())
    {
        if (A[i] == B[j])
        {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}

int main()
{
    // TC1: Partial intersection
    cout << "TC1: A{1,2,3,4,5}, B{1,2,5,6}\n";
    cout << "Expected: 1 2 5\n";
    vector<int> A{1, 2, 3, 4, 5}, B{1, 2, 5, 6};
    vector<int> ans = interElements(A, B);
    cout << "Result: ";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n\n";

    // TC2: Complete intersection
    cout << "TC2: A{1,2,3}, B{1,2,3}\n";
    cout << "Expected: 1 2 3\n";
    vector<int> A2{1, 2, 3}, B2{1, 2, 3};
    ans = interElements(A2, B2);
    cout << "Result: ";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n\n";

    // TC3: No intersection
    cout << "TC3: A{1,3}, B{2,4}\n";
    cout << "Expected: (empty)\n";
    vector<int> A3{1, 3}, B3{2, 4};
    ans = interElements(A3, B3);
    cout << "Result: ";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n\n";

    // TC4: Duplicates in intersection
    cout << "TC4: A{1,2,2,3}, B{2,2,3,4}\n";
    cout << "Expected: 2 2 3\n";
    vector<int> A4{1, 2, 2, 3}, B4{2, 2, 3, 4};
    ans = interElements(A4, B4);
    cout << "Result: ";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}