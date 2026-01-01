#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

// Kadane's algorithm (handles all-negative by picking the max element)
// TC: O(n)   SC: O(1)
int kadaneAlgo(const vector<int> &A){
    if (A.empty()) return INT_MIN; // sentinel for empty input

    int best = A[0];
    int cur  = A[0];
    for (size_t i = 1; i < A.size(); i++) {
        cur = max(A[i], cur + A[i]);
        best = max(best, cur);
    }
    return best;
}

int main(){
    cout << "solving greatest subarray in array..\n";

    vector<vector<int>> tests{
        {5, 4, -3, -15, 5, 6}, // mixed
        {-5, -1, -8},          // all negative -> -1
        {2, 3, -2, 4},         // standard
        {}                     // empty -> INT_MIN sentinel
    };

    for (auto &tc : tests) {
        cout << kadaneAlgo(tc) << "\n";
    }

    return 0;
}