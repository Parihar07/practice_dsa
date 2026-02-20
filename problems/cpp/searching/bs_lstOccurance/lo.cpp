/*
 * Problem: Find Last Occurrence in Sorted Array
 *
 * Given a sorted array A[] with possibly duplicate elements, find the index
 * of the last occurrence of a given key K.
 *
 * Example:
 *   Input:  A[] = {2, 3, 4, 4, 4, 4, 6, 8}, K = 4
 *   Output: 5 (index of last occurrence of 4)
 *
 *   Input:  A[] = {2, 3, 4, 4, 4, 4, 6, 8}, K = 5
 *   Output: -1 (element not found)
 *
 * Time Complexity:  O(log n) - Binary search halves the search space each iteration
 * Space Complexity: O(1) - Only constant extra space used
 *
 * Approach: Modified binary search - when element is found, store the index
 *           and continue searching in the right half to find the last occurrence.
 */
#include <iostream>
#include <vector>
using namespace std;

int lastOccurance(vector<int> &A, int k)
{
    if (A.empty())
        return -1;
    int ans = -1, s = 0, e = A.size() - 1, m = s + (e - s) / 2;
    while (s <= e)
    {
        if (A[m] == k)
        {
            ans = m;   // update the recent found key value
            s = m + 1; // move towards the last occurance
        }
        else if (A[m] < k)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    vector<int> A{2, 3, 4, 4, 4, 4, 6, 8};
    cout << "binary search problem for last occcurance..\n";
    cout << "last occurance : " << lastOccurance(A, 4) << endl;
    return 0;
}