#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
   * RAIN WATER TRAPPING PROBLEM
 *
 * PS: Given an elevation map represented as an array where each element
 *     represents the height of a bar, calculate how much water can be trapped
 *     after raining.
 *
 * APPROACH: Two-pass technique with prefix/suffix arrays
 *          - Compute left maximum for each position
 *          - Compute right maximum for each position
 *          - Water trapped at position i = min(lMax[i], rMax[i]) - height[i]
 *
 * TC: O(N) - Three linear passes through array
 * SC: O(N) - Two auxiliary arrays for left and right maximums
 *
 * TEST CASES:
 *    1. [4,2,0,3,2,5] -> 7 (water trapped between bars)
 *    2. [0,1,0,2,1,0,1,3,2,1,2,1] -> 6
 *    3. [] or [5] -> 0 (edge cases: less than 3 elements)
 */
int waterTrapped(vector<int> &A)
{
    int ans = 0, N = A.size();
    if (N < 3)
        return 0; // check if we need min three elements to calculate rain trap water
    vector<int> lMax(N, 0), rMax(N, 0);
    lMax[0] = A[0];
    rMax[N - 1] = A[N - 1];
    for (int i = 1; i < N; i++)
    {
        lMax[i] = max(lMax[i - 1], A[i]);
    }
    for (int i = N - 2; i >= 0; i--)
    {
        rMax[i] = max(rMax[i + 1], A[i]);
    }

    for (int i = 1; i < N - 1; i++)
    {
        int m = min(rMax[i], lMax[i]);
        ans += max(0, m - A[i]);
    }
    return ans;
}

/*
 * TWO-POINTER APPROACH (Optimal Space)
 *
 * APPROACH: Use two pointers moving from both ends
 *          - Track leftMax and rightMax as we go
 *          - Process the side with smaller height
 *          - Accumulate water while iterating
 *
 * TC: O(N) - Single pass through array
 * SC: O(1) - Only constant extra space
 */
int waterTrappedTwoPointer(vector<int> &A)
{
    int N = A.size();
    if (N < 3)
        return 0;

    int left = 0, right = N - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;

    while (left < right)
    {
        if (A[left] < A[right])
        {
            // Left side is smaller, process left
            if (A[left] >= leftMax)
            {
                leftMax = A[left];
            }
            else
            {
                ans += leftMax - A[left];
            }
            left++;
        }
        else
        {
            // Right side is smaller or equal, process right
            if (A[right] >= rightMax)
            {
                rightMax = A[right];
            }
            else
            {
                ans += rightMax - A[right];
            }
            right--;
        }
    }

    return ans;
}

int main()
{
    cout << "Solving the rain water trapping problem..\n\n";

    vector<int> A{4, 2, 0, 3, 2, 5};
    cout << "Test Case 1: [4, 2, 0, 3, 2, 5]\n";
    cout << "Prefix-Suffix Array Approach: " << waterTrapped(A) << endl;
    cout << "Two-Pointer Approach: " << waterTrappedTwoPointer(A) << endl;

    vector<int> B{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "\nTest Case 2: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]\n";
    cout << "Prefix-Suffix Array Approach: " << waterTrapped(B) << endl;
    cout << "Two-Pointer Approach: " << waterTrappedTwoPointer(B) << endl;

    return 0;
}