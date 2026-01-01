#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

// Problem: Find the single element that occurs an odd number of times
// in an array where all other elements occur an even number of times.
// If the array is empty, return -1 as a sentinel. Assumes at most one
// odd-occurring value exists.

// TC: O(n)   SC: O(k) where k = distinct elements
int exceptionalOdd1(vector<int> &A){
    if (A.empty()) return -1;

    unordered_map<int, int> um;
    for (size_t i = 0; i < A.size(); i++) {
        um[A[i]] += 1;
    }

    int ans = -1;
    int oddCount = 0;
    for (auto i : um) {
        if (i.second % 2) {
            ans = i.first;
            oddCount += 1;
        }
    }

    // Enforce the contract: exactly one odd-occurring value; otherwise return sentinel -1.
    return (oddCount == 1) ? ans : -1;
}

// TC: O(n)   SC: O(1)
int exceptionalOdd2(vector<int> &A){
    if (A.empty()) return -1;

    int ans = A[0];
    for (int i = 1; i < static_cast<int>(A.size()); i++) {
        ans ^= A[i];
    }
    return ans;
}

int main(){
    cout << "Solving exceptional odd in given array\n";

    // Test cases: {array} -> expected (when single odd-occurring holds)
    vector<vector<int>> tests {
        {1, 2, 3, 2, 3, 1, 3},      // expected 3
        {4, 4, 4},                  // expected 4
        {7},                        // expected 7
        {},                         // expected -1 (sentinel for empty)
        {5, 6, 5, 6, 7, 7, 9, 9, 9} // violates single-odd rule; XOR still outputs a value
    };

    for (auto &tc : tests) {
        cout << exceptionalOdd2(tc) << "\n";
    }

    return 0;
}