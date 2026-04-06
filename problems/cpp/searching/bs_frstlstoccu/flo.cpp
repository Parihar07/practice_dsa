/*
 * Problem: Find First and Last Occurrence in Sorted Array
 * 
 * Given a sorted array A[] with possibly duplicate elements, find the indices
 * of the first and last occurrence of a given key K.
 * 
 * Example:
 *   Input:  A[] = {2, 3, 4, 4, 4, 4, 6, 8}, K = 4
 *   Output: First = 2, Last = 5
 * 
 *   Input:  A[] = {2, 3, 4, 4, 4, 4, 6, 8}, K = 5
 *   Output: First = -1, Last = -1 (element not found)
 * 
 * Time Complexity:  O(log n) - Two binary searches, each O(log n)
 * Space Complexity: O(1) - Only constant extra space used
 * 
 * Approach: 
 *   - First occurrence: Modified binary search - when found, search left half
 *   - Last occurrence: Modified binary search - when found, search right half
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

// ==================== TEST CASES ====================

void runTest(int testNum, vector<int> arr, int key, int expectedFirst, int expectedLast)
{
    int first = firstOccurance(arr, key);
    int last = lastOccurance(arr, key);
    bool passed = (first == expectedFirst && last == expectedLast);

    cout << "Test " << testNum << ": ";
    if (passed)
        cout << "PASSED";
    else
        cout << "FAILED (got first=" << first << ", last=" << last 
              << ", expected first=" << expectedFirst << ", last=" << expectedLast << ")";

    cout << " | arr = [";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "], key = " << key << endl;
}

void runAllTests()
{
    cout << "========== Running Test Cases ==========" << endl << endl;

    // Test 1: Element found with multiple occurrences
    runTest(1, {2, 3, 4, 4, 4, 4, 6, 8}, 4, 2, 5);

    // Test 2: Element found at beginning (single occurrence)
    runTest(2, {2, 3, 4, 5, 6, 7, 8}, 2, 0, 0);

    // Test 3: Element found at end (single occurrence)
    runTest(3, {2, 3, 4, 5, 6, 7, 8}, 8, 6, 6);

    // Test 4: Element not found (smaller than all)
    runTest(4, {2, 3, 4, 5, 6, 7, 8}, 1, -1, -1);

    // Test 5: Element not found (larger than all)
    runTest(5, {2, 3, 4, 5, 6, 7, 8}, 9, -1, -1);

    // Test 6: Element not found (in range but absent)
    runTest(6, {2, 4, 6, 8, 10, 12}, 5, -1, -1);

    // Test 7: Single element array (found)
    runTest(7, {7}, 7, 0, 0);

    // Test 8: Single element array (not found)
    runTest(8, {7}, 3, -1, -1);

    // Test 9: Empty array
    runTest(9, {}, 5, -1, -1);

    // Test 10: All elements same (found)
    runTest(10, {5, 5, 5, 5, 5}, 5, 0, 4);

    // Test 11: All elements same (not found)
    runTest(11, {5, 5, 5, 5, 5}, 3, -1, -1);

    // Test 12: Duplicate at beginning
    runTest(12, {2, 2, 2, 3, 4, 5}, 2, 0, 2);

    // Test 13: Duplicate at end
    runTest(13, {1, 2, 3, 5, 5, 5}, 5, 3, 5);

    // Test 14: Negative numbers (found)
    runTest(14, {-10, -5, -3, -3, -3, 0, 2, 4}, -3, 2, 4);

    // Test 15: Negative numbers (not found)
    runTest(15, {-10, -5, -3, 0, 2, 4}, -1, -1, -1);

    // Test 16: Two elements (both same)
    runTest(16, {4, 4}, 4, 0, 1);

    // Test 17: Two elements (first only)
    runTest(17, {3, 5}, 3, 0, 0);

    // Test 18: Two elements (second only)
    runTest(18, {3, 5}, 5, 1, 1);

    cout << endl << "========================================" << endl;
}

int main()
{
    runAllTests();
    return 0;
}