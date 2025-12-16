#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Problem: Combination Sum II (unique combinations)

Given a multiset of candidate integers (may contain duplicates) and a target,
return all unique combinations where each number can be used at most once and
the chosen numbers sum to the target. Order inside a combination does not
matter, and permutations of the same multiset are considered duplicates.

Approach:
- Sort the array to group duplicates.
- Backtrack from index idx, trying each candidate once.
- Skip duplicate values at the same depth (if C[i] == C[i-1] and i > idx).
- After picking C[i], recurse with i+1 (cannot reuse the same position).
- Stop when targ == 0 (record combo) or targ < 0 / idx == n (dead branch).

Time Complexity: O(number_of_combinations * n) — exponential in worst case.
Space Complexity: O(n) recursion depth + O(total_output_size) for results.
*/

void utargetsum(vector<int> &C, int idx, int targ, vector<int> tmp, vector<vector<int>> &ans)
{
    if (targ == 0)
    {
        ans.push_back(tmp);
        return;
    }
    if (idx == C.size() || targ < 0)
    {
        return;
    }

    for (int i = idx; i < C.size(); i++)
    {
        // Skip duplicates (array must be sorted)
        if (i > idx && C[i] == C[i - 1])
            continue;

        if (targ >= C[i])
        {
            tmp.push_back(C[i]);
            utargetsum(C, i + 1, targ - C[i], tmp, ans); // KEY FIX: i + 1, not idx + 1
            tmp.pop_back();
        }
    }
}

void runTest(vector<int> C, int target)
{
    sort(C.begin(), C.end());
    vector<int> tmp;
    vector<vector<int>> ans;
    utargetsum(C, 0, target, tmp, ans);

    cout << "Candidates: ";
    for (int v : C)
        cout << v << " ";
    cout << "  Target: " << target << "\n";
    cout << "Unique combinations: " << ans.size() << "\n";
    for (auto &combo : ans)
    {
        for (int v : combo)
            cout << v << " ";
        cout << "\n";
    }
    cout << "---------------------------\n";
}

int main()
{
    cout << "Combination Sum II (unique combinations)\n\n";
    runTest({10, 1, 2, 7, 6, 1, 5}, 8); // expect [1,7], [1,2,5], [2,6]
    runTest({2, 5, 2, 1, 2}, 5);        // expect [1,2,2], [5]
    runTest({1, 1, 2, 2, 4}, 6);        // expect [1,1,4], [1,2,3? nope], [2,4], [1,1,2,2]
    runTest({1}, 1);                    // expect [1]
    return 0;
}