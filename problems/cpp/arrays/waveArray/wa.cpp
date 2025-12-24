#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Statement: Wave Array
=============================
Arrange the array such that it forms a wave pattern.
For a wave array: A[0] >= A[1] <= A[2] >= A[3] <= A[4]...

Approach:
1. Sort the array first
2. Swap adjacent pairs: (0,1), (2,3), (4,5)...
   This ensures arr[i] >= arr[i+1] for even i
   and arr[i] <= arr[i+1] for odd i

Input:
- A: unsorted array of integers

Output:
- Modified array in wave pattern (sorted first, then adjacent elements swapped)

Example:
Input: [1, 2, 3, 4, 5, 7]
After sort: [1, 2, 3, 4, 5, 7]
After swap: [2, 1, 4, 3, 7, 5]
This satisfies: 2 >= 1 <= 4 >= 3 <= 7 >= 5

Time Complexity: O(N log N) for sorting + O(N) for swapping = O(N log N)
Space Complexity: O(1) - only swap operations (in-place)
*/

void waveArray(vector<int> &A){
    // Sort array first
    sort(A.begin(), A.end());
    
    // Swap adjacent elements to form wave pattern
    // Loop condition: i < A.size() - 1 prevents out-of-bounds access
    for (size_t i = 0; i < A.size() - 1; i+=2)
    {
        swap(A[i], A[i + 1]);
    }
}

void printArray(const vector<int>& arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

bool verifyWave(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        if (i % 2 == 0) {
            // Even index: should be >= next
            if (arr[i] < arr[i + 1]) return false;
        } else {
            // Odd index: should be <= next
            if (arr[i] > arr[i + 1]) return false;
        }
    }
    return true;
}

int main(){
    cout << "=== Wave Array Test Cases ===\n\n";
    
    // Test Case 1: Basic example
    cout << "Test Case 1: Basic example\n";
    vector<int> A1{1, 2, 3, 4, 5, 7};
    cout << "Input:  "; printArray(A1);
    waveArray(A1);
    cout << "Output: "; printArray(A1);
    cout << "Valid: " << (verifyWave(A1) ? "YES" : "NO") << "\n\n";
    
    // Test Case 2: Already sorted
    cout << "Test Case 2: Already sorted array\n";
    vector<int> A2{1, 2, 3, 4};
    cout << "Input:  "; printArray(A2);
    waveArray(A2);
    cout << "Output: "; printArray(A2);
    cout << "Valid: " << (verifyWave(A2) ? "YES" : "NO") << "\n\n";
    
    // Test Case 3: Reverse sorted
    cout << "Test Case 3: Reverse sorted array\n";
    vector<int> A3{5, 4, 3, 2, 1};
    cout << "Input:  "; printArray(A3);
    waveArray(A3);
    cout << "Output: "; printArray(A3);
    cout << "Valid: " << (verifyWave(A3) ? "YES" : "NO") << "\n\n";
    
    // Test Case 4: Odd length array
    cout << "Test Case 4: Odd length array\n";
    vector<int> A4{9, 1, 8, 2, 7};
    cout << "Input:  "; printArray(A4);
    waveArray(A4);
    cout << "Output: "; printArray(A4);
    cout << "Valid: " << (verifyWave(A4) ? "YES" : "NO") << "\n\n";
    
    // Test Case 5: Single element
    cout << "Test Case 5: Single element\n";
    vector<int> A5{5};
    cout << "Input:  "; printArray(A5);
    waveArray(A5);
    cout << "Output: "; printArray(A5);
    cout << "Valid: " << (verifyWave(A5) ? "YES" : "NO") << "\n\n";
    
    // Test Case 6: Two elements
    cout << "Test Case 6: Two elements\n";
    vector<int> A6{3, 1};
    cout << "Input:  "; printArray(A6);
    waveArray(A6);
    cout << "Output: "; printArray(A6);
    cout << "Valid: " << (verifyWave(A6) ? "YES" : "NO") << "\n\n";
    
    // Test Case 7: Duplicates
    cout << "Test Case 7: Array with duplicates\n";
    vector<int> A7{3, 1, 3, 2, 2, 1};
    cout << "Input:  "; printArray(A7);
    waveArray(A7);
    cout << "Output: "; printArray(A7);
    cout << "Valid: " << (verifyWave(A7) ? "YES" : "NO") << "\n\n";
    
    // Test Case 8: Negative numbers
    cout << "Test Case 8: With negative numbers\n";
    vector<int> A8{-1, 5, -3, 2, 4};
    cout << "Input:  "; printArray(A8);
    waveArray(A8);
    cout << "Output: "; printArray(A8);
    cout << "Valid: " << (verifyWave(A8) ? "YES" : "NO") << "\n\n";
    
    return 0;
}