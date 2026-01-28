/*
Problem Statement:
Given an array of size N (initially all zeros) and Q queries of the form [L, R, V],
where each query adds value V to all elements in the range [L, R] (inclusive).
Find the maximum element in the array after processing all queries.

Approach:
- Use difference array technique for efficient range updates
- For each query [L, R, V]: add V at index L and subtract V at index R+1
- Compute prefix sum to get actual values
- Return maximum value

Time Complexity: O(Q + N) where Q is number of queries and N is array size
Space Complexity: O(N) for the difference array
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int maxProductQuery(vector<vector<int>> &Q, int size)
{
    vector<int> diffArray(size + 1, 0);
    
    // Apply difference array technique for range updates
    for (auto &query : Q)
    {
        int L = query[0];
        int R = query[1];
        int V = query[2];
        
        diffArray[L] += V;
        if (R + 1 <= size) {
            diffArray[R + 1] -= V;
        }
    }
    
    // Compute prefix sum to get actual values and find maximum
    int ans = INT_MIN;
    int currentSum = 0;
    
    for (int i = 0; i <= size; i++)
    {
        currentSum += diffArray[i];
        ans = max(ans, currentSum);
    }

    return ans;
}

int main()
{
    cout << "=== Prefix Sum Product Query Array Problem ===\n\n";
    
    // Test Case 1: Basic case
    cout << "Test Case 1:\n";
    vector<vector<int>> Q1{{1, 5, 3}, {4, 8, 7}, {6, 9, 1}};
    cout << "Queries: [1,5,3], [4,8,7], [6,9,1]\n";
    cout << "Array size: 10\n";
    cout << "Max element: " << maxProductQuery(Q1, 10) << endl;
    cout << "Expected: 10 (at indices 6-8)\n\n";
    
    // Test Case 2: Single query
    cout << "Test Case 2:\n";
    vector<vector<int>> Q2{{2, 7, 5}};
    cout << "Queries: [2,7,5]\n";
    cout << "Array size: 10\n";
    cout << "Max element: " << maxProductQuery(Q2, 10) << endl;
    cout << "Expected: 5\n\n";
    
    // Test Case 3: Overlapping ranges
    cout << "Test Case 3:\n";
    vector<vector<int>> Q3{{1, 3, 2}, {2, 4, 3}, {3, 5, 1}};
    cout << "Queries: [1,3,2], [2,4,3], [3,5,1]\n";
    cout << "Array size: 6\n";
    cout << "Max element: " << maxProductQuery(Q3, 6) << endl;
    cout << "Expected: 6 (at index 3)\n\n";
    
    // Test Case 4: Non-overlapping ranges
    cout << "Test Case 4:\n";
    vector<vector<int>> Q4{{1, 2, 10}, {5, 6, 8}, {8, 9, 12}};
    cout << "Queries: [1,2,10], [5,6,8], [8,9,12]\n";
    cout << "Array size: 10\n";
    cout << "Max element: " << maxProductQuery(Q4, 10) << endl;
    cout << "Expected: 12\n\n";
    
    return 0;
}