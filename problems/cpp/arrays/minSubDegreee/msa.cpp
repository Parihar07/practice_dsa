#include <iostream>
#include <vector>
// NOTE: <string> is included but not used anywhere below — consider removing it.
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Degree of an Array
Description
An integer array arr is given.
The degree of the array is the highest frequency of any value in the array.
Your task is to determine the length of the shortest contiguous subarray whose degree is the same as the degree of the entire array.
Return that minimum length.
Example
arr = [1, 2, 1, 3, 2]
The array has a degree of 2 based on the occurrences of values 1 and 2. The subarray of degree 2 based on the 1's is [1, 2, 1] and based on 2's is [2, 1, 3, 2]. Their lengths are 3 and 4, so the shortest is length 3. Return the shortest length.

Function Description
Complete the function degreeOfArray in the editor with the following parameter(s):

    int arr[n]:  an array of integers indexed from 0 to n-1
Return
    int:  the minimum size of the subarrays that have a degree equal to the degree of the array
Constraints

2 ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/

/*
 Complexity / Test Cases

 - Time Complexity:
         * Naive (current two-pass + scanning per-degree-value): O(n * k) worst-case -> O(n^2)
             where k is number of values with max frequency (can be O(n) when degree==1).
         * Optimized (one-pass with count/first/last): O(n) time.

 - Space Complexity:
         * O(n) extra space for hash maps (counts, first, last indices) in the optimized solution.

 - Representative Test Cases (input -> expected output):
         * [] -> 0  (if empty input allowed)
         * [5] -> 1
         * [2,2,2,2] -> 4
         * [1,2,1,3,2] -> 3
         * [1,2,2,3,1] -> 2
         * [1,2,3,4] -> 1
         * [9,1,2,9,3,9] -> 6
         * [1,2,3,4,5,1,6,7,1] -> 9

 Notes:
 - Prefer the one-pass approach shown in the discussion: record counts and first/last indices
     while iterating once, then compute the minimal window among values whose count == degree.
 - The above test cases cover empty/singleton, all-equal, multiple-degree-values, distinct elements,
     and uneven distribution of frequent elements.
*/

int degreeArr(vector<int> &A, vector<int> &R)
{
    // Build frequency map: value -> count
    int degree = 0, N = A.size();
    unordered_map<int, int> um;
    for (int i = 0; i < N; i++)
    {
        um[A[i]]++;
    }

    // Find the maximum frequency (degree)
    for (const auto &p : um)
    {
        degree = max(degree, p.second);
    }

    // Collect all values that reach the degree
    for (const auto &p : um)
    {
        if (p.second == degree)
            R.push_back(p.first); // R contains the actual values (not indices)
    }
    return degree;
}

int minSubDeg(vector<int> &A)
{
    vector<int> R;
    int d = degreeArr(A, R);
    // WARNING: The approach below finds first/last positions by scanning
    // the full array for every value in R. If R is large (e.g., degree==1),
    // this becomes O(n * k) and can degrade to O(n^2) for n up to 1e5.
    // A linear alternative: record first/last indices while counting in one pass.
    int rn = R.size(), s = 0, e = 0, N = A.size();
    int ans = N;
    for (int i = 0; i < rn; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A[j] == R[i])
            {
                s = j;
                break;
            }
        }
        for (int j = N - 1; j >= 0; j--)
        {
            if (A[j] == R[i])
            {
                e = j;
                break;
            }
        }

        // Now we have first (s) and last (e) occurrence for value R[i]
        // and can compute the subarray length. This is correct but potentially
        // inefficient for large inputs; see the note above for a one-pass fix.
        ans = min(ans, e - s + 1);
    }
    return ans;
}

int optMinSubArr(vector<int> &A)
{
    int N = A.size();
    int ans = N, d = 0;
    unordered_map<int, int> first, last, degree;

    // Fill the aray and get index of first and last indeex of element and frequesncy in one pass
    for (int i = 0; i < N; i++)
    {
        if (degree.count(A[i]) == 0)
        {
            first[A[i]] = i;
        }
        last[A[i]] = i;
        degree[A[i]]++;
    }

    // Get degree of array
    for (auto i : degree)
    {
        d = max(i.second, d);
    }

    // calculate min sub array or windows e-s+1 logic
    for (auto i = degree.begin(); i != degree.end(); i++)
    {
        int key = i->first; // extract one to avoid multiple lookups
        if (d == degree[key])
            ans = min(ans, (last[key] - first[key] + 1));
    }

    return ans;
}

int main()
{
    // Test harness: list of {input, expected}
    vector<pair<vector<int>, int>> tests = {
        {{}, 0},
        {{5}, 1},
        {{2, 2, 2, 2}, 4},
        {{1, 2, 1, 3, 2}, 3},
        {{1, 2, 2, 3, 1}, 2},
        {{1, 2, 3, 4}, 1},
        {{9, 1, 2, 9, 3, 9}, 6},
        {{1, 2, 3, 4, 5, 1, 6, 7, 1}, 9}};

    auto printVec = [](const vector<int> &v)
    {
        cout << "[";
        for (size_t i = 0; i < v.size(); ++i)
        {
            if (i)
                cout << ", ";
            cout << v[i];
        }
        cout << "]";
    };

    int passed = 0;
    for (size_t i = 0; i < tests.size(); ++i)
    {
        const auto &inp = tests[i].first;
        int expect = tests[i].second;
        int got = optMinSubArr(const_cast<vector<int> &>(const_cast<vector<int> &>(inp)));
        cout << "Case " << i + 1 << ": ";
        printVec(inp);
        cout << " -> expected=" << expect << ", got=" << got;
        if (got == expect)
        {
            cout << " [PASS]";
            ++passed;
        }         else
            cout << " [FAIL]";
        cout << '\n';
    }
    cout << passed << " / " << tests.size() << " passed.\n";
    return 0;
}