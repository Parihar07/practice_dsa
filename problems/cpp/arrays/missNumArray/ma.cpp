#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Find the missing number in an array containing integers from 1..N with exactly one missing.
// Time: O(n), Space: O(1).
int missEleArray(const vector<int> &A){
    long long n = static_cast<long long>(A.size()) + 1; // array has n-1 elements from 1..n
    long long expectedSum = n * (n + 1) / 2;

    long long actualSum = 0;
    for (int v : A) {
        actualSum += v;
    }

    return static_cast<int>(expectedSum - actualSum);
}

int main(){
    cout<<"missing number in given n-1 array..\n";

    vector<vector<int>> tests{
        {1, 3, 4, 5, 6, 7},      // missing 2
        {2, 3, 4, 5},            // missing 1
        {1, 2, 3, 4, 5},         // missing 6
        {1},                     // missing 2
        {1, 2, 3, 5, 6, 7, 8}    // missing 4
    };

    for (const auto &t : tests) {
        cout << "missing number : " << missEleArray(t) << "\n";
    }
    return 0;
}