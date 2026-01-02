#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
PS:
Distribute the chocolates to given students m , where in given array each element is packets with number of chocholates.
Distribute choclates among m students and each students get 1 packet
differnc ebetween max no of choco and min number of chocos should be min

TC: Time Complexity
SC: Space Complexity
*/

int minDiff(vector<int> &A, int m)
{
    // Brute Force Approach
    // TC: O(n * m) - where n is array size, m is number of students
    // SC: O(1) - only using constant extra space

    int ans = INT_MAX;
    /*
    number of ele in between given a nd b is b-a+1 here b-a+1=m; b = m+a-1;
    */
    for (int i = 0; (m + i - 1) < static_cast<int>(A.size()); i++)
    {
        int mi = A[i], ma = A[i];
        for (int j = i; j < (i + m); j++)
        {
            mi = min(mi, A[j]);
            ma = max(ma, A[j]);
        }
        ans = min(ans, (ma - mi));
    }
    return ans;
}

int minDiffOpt(vector<int> &A, int m)
{
    // Optimal Approach - Sorting based
    // TC: O(n log n) - due to sorting, then O(n) for single pass
    // SC: O(1) - only using constant extra space (sort is in-place)

    sort(A.begin(), A.end());
    int ans = INT_MAX;
    for (int i = 0; (m + i - 1) < static_cast<int>(A.size()); i++)
    {
        ans = min(A[m + i - 1] - A[i], ans);
    }
    return ans;
}
int main()
{
    cout << "Solving chocolate distribution problem..\n\n";

    // Test Case 1
    cout << "TC 1: Basic case\n";
    vector<int> A1{3, 4, 1, 9, 56, 7, 9, 12};
    cout << "Array: [3, 4, 1, 9, 56, 7, 9, 12], m=5\n";
    cout << "Min Diff (Optimal): " << minDiffOpt(A1, 5) << endl;

    // Test Case 2
    cout << "\nTC 2: Smaller array\n";
    vector<int> A2{7, 3, 2, 4, 9};
    cout << "Array: [7, 3, 2, 4, 9], m=3\n";
    cout << "Min Diff (Optimal): " << minDiffOpt(A2, 3) << endl;

    // Test Case 3
    cout << "\nTC 3: All same elements\n";
    vector<int> A3{5, 5, 5, 5};
    cout << "Array: [5, 5, 5, 5], m=2\n";
    cout << "Min Diff (Optimal): " << minDiffOpt(A3, 2) << endl;

    return 0;
}