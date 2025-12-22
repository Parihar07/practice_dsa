#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Approach 1: Min Heap - Extract k times
// TC: O(n log n + k log n) = O(n log n)
// SC: O(n) - stores all elements in heap
int findkthsmallest(vector<int> &A, int k)
{
    if (k < 1 || k > A.size())
        return -1; // edge case

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (auto i : A)
        minHeap.push(i);
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        ans = minHeap.top();
        minHeap.pop();
    }
    return ans;
}

// Approach 2: Max Heap of size k (OPTIMIZED)
// TC: O(n log k) - much better when k << n
// SC: O(k) - only stores k elements
int findkthsmallestOptimized(vector<int> &A, int k)
{
    if (k < 1 || k > A.size())
        return -1; // edge case

    priority_queue<int> maxHeap; // max heap by default

    for (int num : A)
    {
        maxHeap.push(num);
        if (maxHeap.size() > k)
        {
            maxHeap.pop(); // remove largest element
        }
    }
    return maxHeap.top(); // kth smallest
}

int main()
{
    cout << "=== Kth Smallest Element Comparison ===\n\n";

    // Test Case 1
    vector<int> A1{10, 2, 30, 5, 6, 18};
    int k1 = 3;
    cout << "Test 1: [10, 2, 30, 5, 6, 18], k=" << k1 << endl;
    cout << "  Min Heap Approach: " << findkthsmallest(A1, k1) << endl;
    cout << "  Max Heap Optimized: " << findkthsmallestOptimized(A1, k1) << endl;
    cout << "  Expected: 6\n\n";

    // Test Case 2
    vector<int> A2{7, 10, 4, 3, 20, 15};
    int k2 = 3;
    cout << "Test 2: [7, 10, 4, 3, 20, 15], k=" << k2 << endl;
    cout << "  Min Heap Approach: " << findkthsmallest(A2, k2) << endl;
    cout << "  Max Heap Optimized: " << findkthsmallestOptimized(A2, k2) << endl;
    cout << "  Expected: 7\n\n";

    // Test Case 3
    vector<int> A3{1, 2, 3, 4, 5};
    int k3 = 1;
    cout << "Test 3: [1, 2, 3, 4, 5], k=" << k3 << endl;
    cout << "  Min Heap Approach: " << findkthsmallest(A3, k3) << endl;
    cout << "  Max Heap Optimized: " << findkthsmallestOptimized(A3, k3) << endl;
    cout << "  Expected: 1\n\n";

    // Test Case 4
    vector<int> A4{1, 2, 3, 4, 5};
    int k4 = 5;
    cout << "Test 4: [1, 2, 3, 4, 5], k=" << k4 << endl;
    cout << "  Min Heap Approach: " << findkthsmallest(A4, k4) << endl;
    cout << "  Max Heap Optimized: " << findkthsmallestOptimized(A4, k4) << endl;
    cout << "  Expected: 5\n\n";

    // Test Case 5: Large array with duplicates
    vector<int> A5{5, 3, 8, 3, 1, 9, 3, 7};
    int k5 = 4;
    cout << "Test 5: [5, 3, 8, 3, 1, 9, 3, 7], k=" << k5 << endl;
    cout << "  Min Heap Approach: " << findkthsmallest(A5, k5) << endl;
    cout << "  Max Heap Optimized: " << findkthsmallestOptimized(A5, k5) << endl;
    cout << "  Expected: 3\n\n";

    // Test Case 6: Edge case - invalid k
    vector<int> A6{1, 2, 3};
    int k6 = 10;
    cout << "Test 6: [1, 2, 3], k=" << k6 << " (invalid)" << endl;
    cout << "  Min Heap Approach: " << findkthsmallest(A6, k6) << endl;
    cout << "  Max Heap Optimized: " << findkthsmallestOptimized(A6, k6) << endl;
    cout << "  Expected: -1 (error)\n";

    return 0;
}