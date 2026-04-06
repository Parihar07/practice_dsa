/*
 * Problem: Find Last Occurrence in Sorted Array
 * 
 * Given a sorted array A[] with possibly duplicate elements, find the index
 * of the last occurrence of a given key K.
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

int lastOccurance(vector<int> &arr, int k)
{
    if (arr.empty())
        return -1;
    int ans = -1, s = 0, e = arr.size() - 1, m = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[m] == k)
        {
            ans = m;   // update the recent found key value
            s = m + 1; // move towards the last occurance
        }
        else if (arr[m] < k)
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

// ==================== TEST CASES ====================

void runTest(int testNum, vector<int> arr, int key, int expected)
{
    int result = lastOccurance(arr, key);
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
    cout << "], key = " << key << endl;
}

void runAllTests()
{
    cout << "========== Running Test Cases ==========" << endl << endl;

    // Test 1: Element found with multiple occurrences
    runTest(1, {2, 3, 4, 4, 4, 4, 6, 8}, 4, 5);

    // Test 2: Element found at beginning (single occurrence)
    runTest(2, {2, 3, 4, 5, 6, 7, 8}, 2, 0);

    // Test 3: Element found at end (single occurrence)
    runTest(3, {2, 3, 4, 5, 6, 7, 8}, 8, 6);

    // Test 4: Element not found (smaller than all)
    runTest(4, {2, 3, 4, 5, 6, 7, 8}, 1, -1);

    // Test 5: Element not found (larger than all)
    runTest(5, {2, 3, 4, 5, 6, 7, 8}, 9, -1);

    // Test 6: Element not found (in range but absent)
    runTest(6, {2, 4, 6, 8, 10, 12}, 5, -1);

    // Test 7: Single element array (found)
    runTest(7, {7}, 7, 0);

    // Test 8: Single element array (not found)
    runTest(8, {7}, 3, -1);

    // Test 9: Empty array
    runTest(9, {}, 5, -1);

    // Test 10: All elements same (found)
    runTest(10, {5, 5, 5, 5, 5}, 5, 4);

    // Test 11: All elements same (not found)
    runTest(11, {5, 5, 5, 5, 5}, 3, -1);

    // Test 12: Duplicate at beginning
    runTest(12, {2, 2, 2, 3, 4, 5}, 2, 2);

    // Test 13: Duplicate at end
    runTest(13, {1, 2, 3, 5, 5, 5}, 5, 5);

    // Test 14: Negative numbers (found)
    runTest(14, {-10, -5, -3, -3, -3, 0, 2, 4}, -3, 4);

    // Test 15: Negative numbers (not found)
    runTest(15, {-10, -5, -3, 0, 2, 4}, -1, -1);

    cout << endl << "========================================" << endl;
}

int main()
{
    runAllTests();
    return 0;
}