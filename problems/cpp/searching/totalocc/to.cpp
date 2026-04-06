/*
 * Problem: Count Total Occurrences in Sorted Array
 * 
 * Given a sorted array A[] with possibly duplicate elements, count the total
 * number of occurrences of a given key K.
 * 
 * Example:
 *   Input:  A[] = {2, 3, 4, 4, 4, 4, 6, 8}, K = 4
 *   Output: 4 (4 appears 4 times)
 * 
 *   Input:  A[] = {2, 3, 4, 4, 4, 4, 6, 8}, K = 5
 *   Output: 0 (element not found)
 * 
 * Time Complexity:  O(log n) - Two binary searches, each O(log n)
 * Space Complexity: O(1) - Only constant extra space used
 * 
 * Approach: Find first and last occurrence using binary search,
 *           then total = last - first + 1
 */

#include <iostream>
#include <vector>
using namespace std;

int firstOccurance(vector<int> &arr, int k)
{
    if (arr.empty())
        return -1;

    int ans = -1, s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == k)
        {
            ans = m;   // Record this occurrence
            e = m - 1; // Continue searching left for earlier occurrence
        }
        else if (arr[m] < k)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int lastOccurance(vector<int> &arr, int k)
{
    if (arr.empty())
        return -1;

    int ans = -1, s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == k)
        {
            ans = m;   // Record this occurrence
            s = m + 1; // Continue searching right for later occurrence
        }
        else if (arr[m] < k)
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}

int totalOccurance(vector<int> &arr, int k)
{
    int first = firstOccurance(arr, k);
    if (first == -1)
        return 0; // Element not found
    int last = lastOccurance(arr, k);
    return last - first + 1;
}

// ==================== TEST CASES ====================

void runTest(int testNum, vector<int> arr, int key, int expected)
{
    int result = totalOccurance(arr, key);
    bool passed = (result == expected);

    cout << "Test " << testNum << ": ";
    if (passed)
        cout << "PASSED";
    else
        cout << "FAILED (got " << result << ", expected " << expected << ")";

    cout << " | arr = [";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "], key = " << key << " -> count = " << result << endl;
}

void runAllTests()
{
    cout << "========== Running Test Cases ==========" << endl << endl;

    // Test 1: Element found with multiple occurrences
    runTest(1, {2, 3, 4, 4, 4, 4, 6, 8}, 4, 4);

    // Test 2: Element found at beginning (single occurrence)
    runTest(2, {2, 3, 4, 5, 6, 7, 8}, 2, 1);

    // Test 3: Element found at end (single occurrence)
    runTest(3, {2, 3, 4, 5, 6, 7, 8}, 8, 1);

    // Test 4: Element not found (smaller than all)
    runTest(4, {2, 3, 4, 5, 6, 7, 8}, 1, 0);

    // Test 5: Element not found (larger than all)
    runTest(5, {2, 3, 4, 5, 6, 7, 8}, 9, 0);

    // Test 6: Element not found (in range but absent)
    runTest(6, {2, 4, 6, 8, 10, 12}, 5, 0);

    // Test 7: Single element array (found)
    runTest(7, {7}, 7, 1);

    // Test 8: Single element array (not found)
    runTest(8, {7}, 3, 0);

    // Test 9: Empty array
    runTest(9, {}, 5, 0);

    // Test 10: All elements same (found)
    runTest(10, {5, 5, 5, 5, 5}, 5, 5);

    // Test 11: All elements same (not found)
    runTest(11, {5, 5, 5, 5, 5}, 3, 0);

    // Test 12: Duplicate at beginning
    runTest(12, {2, 2, 2, 3, 4, 5}, 2, 3);

    // Test 13: Duplicate at end
    runTest(13, {1, 2, 3, 5, 5, 5}, 5, 3);

    // Test 14: Negative numbers (found)
    runTest(14, {-10, -5, -3, -3, -3, 0, 2, 4}, -3, 3);

    // Test 15: Negative numbers (not found)
    runTest(15, {-10, -5, -3, 0, 2, 4}, -1, 0);

    // Test 16: Two elements (both same)
    runTest(16, {4, 4}, 4, 2);

    // Test 17: Large count
    runTest(17, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1, 10);

    cout << endl << "========================================" << endl;
}

int main()
{
    runAllTests();
    return 0;
}