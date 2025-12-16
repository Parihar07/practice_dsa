#include <iostream>
#include <vector>
using namespace std;

/*
Problem: Combination Sum (reuse allowed)

Given an array of distinct positive integers `candidates` and an integer `target`,
return all unique combinations of `candidates` where the chosen numbers sum to `target`.
You may use the same number an unlimited number of times. The order of numbers in a
combination does not matter (i.e., [2,3,2] and [2,2,3] are the same combination).

Assumptions:
- `candidates` are distinct and non-negative (typically positive) integers.
- `target` is a non-negative integer.
- Reusing a number is allowed; permutations of the same multiset are considered duplicates and must not be duplicated in output.

Approach (Backtracking):
- At index `idx`, we have two choices:
    1) Take `candidates[idx]` if it does not exceed the remaining `target`, and stay at `idx` (unlimited reuse).
    2) Skip `candidates[idx]` and move to `idx + 1`.
- When `target == 0` at a leaf, record the built path.
- Prune branches early when `target < 0`.

Time Complexity:
- Output-sensitive (exponential) in general; bounded by the total number of valid combinations.
- Commonly described as O(number_of_combinations × average_length). Worst case grows
    roughly exponential in `target / min(candidates)`.

Space Complexity:
- O(depth) auxiliary space for recursion where depth ≤ target / min(candidates).
- Plus O(total_output_size) to store the resulting combinations.
*/

/*
Given array of distinct elements of ineger type, target integer, return list of unique combinations os condiates, where chosen sum to target, combination in any order
same unmber unlimaited times
combination is unique id chosen sum is differnt
*/

// Backtracking helper
// candiate: list of distinct candidate numbers (modifiable copy acceptable)
// idx: current index in candidates to consider
// tv: current partial combination being built
// target: remaining sum to reach
// ans: accumulator of valid combinations
void targetSum(vector<int> &candiate, int idx, vector<int> &tv, int target, vector<vector<int>> &ans)
{
    // Early prune when target drops below zero (candidates assumed non-negative)
    if (target < 0)
        return;

    if (idx == candiate.size())
    {
        if (target == 0)
        {
            ans.push_back(tv); // target sum vector where sum is == target
        }
        return;
    }

    if (target >= candiate[idx])
    {
        tv.push_back(candiate[idx]);
        targetSum(candiate, idx, tv, target - candiate[idx], ans);
        tv.pop_back();
    }
    targetSum(candiate, idx + 1, tv, target, ans);
}

void runTest(const vector<int> &candidates, int target)
{
    vector<int> tv;
    vector<vector<int>> ans;
    vector<int> copy = candidates; // swap-based recursion needs a modifiable copy
    targetSum(copy, 0, tv, target, ans);

    cout << "Candidates: ";
    for (int v : candidates)
        cout << v << " ";
    cout << " Target: " << target << "\n";
    cout << "Combinations: " << ans.size() << "\n";
    for (auto &combo : ans)
    {
        for (int v : combo)
            cout << v << " ";
        cout << "\n";
    }
    cout << "-------------------------\n";
}

int main()
{
    cout << "Hello Target sum problem..\n\n";

    runTest({2, 3, 6, 7}, 7); // Expect [2 2 3], [7]
    runTest({2, 3, 5}, 8);    // Expect [2 2 2 2], [2 3 3], [3 5]
    runTest({2}, 1);          // Expect 0 combos
    runTest({1, 2}, 4);       // Expect [1 1 1 1], [1 1 2], [2 2]

    return 0;
}