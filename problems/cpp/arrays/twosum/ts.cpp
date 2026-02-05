/*
PROBLEM STATEMENT:
Given an array of integers and a target sum, find two distinct indices i and j
such that A[i] + A[j] = target. Return the indices of the two numbers.

TIME COMPLEXITY: O(n) - Single pass through array with hash map operations
SPACE COMPLEXITY: O(n) - Hash map to store elements

TEST CASES:
1. A = [2, 7, 11, 15], target = 9 => (0, 1) [2 + 7 = 9]
2. A = [3, 2, 4], target = 6 => (1, 2) [2 + 4 = 6]
3. A = [1, 5], target = 6 => (0, 1) [1 + 5 = 6]
4. A = [1, 2, 3], target = 10 => (-1, -1) [No pair found]
5. A = [5, 5], target = 10 => (0, 1) [5 + 5 = 10]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

pair<int, int> twoSum(vector<int> &A, int k)
{
    unordered_map<int, int> um;
    for (int i = 0; i < A.size(); i++)
    {
        int complement = k - A[i];

        // Check if complement exists in map
        if (um.find(complement) != um.end())
        {
            return make_pair(um[complement], i);
        }

        // Store current element with its index
        um[A[i]] = i;
    }

    // No pair found
    return make_pair(-1, -1);
}

int main()
{
    cout << "two sum problem..\n\n";

    // TC1
    vector<int> A1{2, 7, 11, 15};
    int target1 = 9;
    pair<int, int> result1 = twoSum(A1, target1);
    cout << "TC1: A = [2, 7, 11, 15], target = 9" << endl;
    cout << "Result: (" << result1.first << ", " << result1.second << ")" << endl
         << endl;

    // TC2
    vector<int> A2{3, 2, 4};
    int target2 = 6;
    pair<int, int> result2 = twoSum(A2, target2);
    cout << "TC2: A = [3, 2, 4], target = 6" << endl;
    cout << "Result: (" << result2.first << ", " << result2.second << ")" << endl
         << endl;

    // TC3
    vector<int> A3{1, 5};
    int target3 = 6;
    pair<int, int> result3 = twoSum(A3, target3);
    cout << "TC3: A = [1, 5], target = 6" << endl;
    cout << "Result: (" << result3.first << ", " << result3.second << ")" << endl
         << endl;

    // TC4 - No pair exists
    vector<int> A4{1, 2, 3};
    int target4 = 10;
    pair<int, int> result4 = twoSum(A4, target4);
    cout << "TC4: A = [1, 2, 3], target = 10" << endl;
    cout << "Result: (" << result4.first << ", " << result4.second << ")" << endl
         << endl;

    // TC5 - Duplicate elements
    vector<int> A5{5, 5};
    int target5 = 10;
    pair<int, int> result5 = twoSum(A5, target5);
    cout << "TC5: A = [5, 5], target = 10" << endl;
    cout << "Result: (" << result5.first << ", " << result5.second << ")" << endl;

    return 0;
}