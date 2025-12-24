//
//  main.cpp
//  LeaderInArray
//
//  Created by CodeBreaker on 11/08/1946 Saka.
//
/*
 Leaders in an array
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer array A containing N distinct integers, you have to find all the leaders in array A. An element is a leader if it is strictly greater than all the elements to its right side.

 NOTE: The rightmost element is always a leader.


 Problem Constraints
 1 <= N <= 105
 1 <= A[i] <= 108


 Input Format
 There is a single input argument which a integer array A


 Output Format
 Return an integer array denoting all the leader elements of the array.


 Example Input
 Input 1:
  A = [16, 17, 4, 3, 5, 2]
 Input 2:
  A = [5, 4]


 Example Output
 Output 1:
 [17, 2, 5]
 Output 2:
 [5, 4]


 Example Explanation
 Explanation 1:
  Element 17 is strictly greater than all the elements on the right side to it.
  Element 2 is strictly greater than all the elements on the right side to it.
  Element 5 is strictly greater than all the elements on the right side to it.
  So we will return these three elements i.e [17, 2, 5], we can also return [2, 5, 17] or [5, 2, 17] or any other ordering.
 Explanation 2:
  Element 5 is strictly greater than all the elements on the right side to it.
  Element 4 is strictly greater than all the elements on the right side to it.
  So we will return these two elements i.e [5, 4], we can also any other ordering.
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> solveOpt(vector<int> &A)
{
    int N = A.size();
    int maxi = A[N - 1];
    vector<int> ans;
    ans.push_back(maxi);

    for (int i = N - 2; i >= 0; i--)
    {
        if (A[i] > maxi)
        {
            maxi = A[i];
            ans.push_back(maxi);
        }
    }

    return ans;
}
vector<int> solve(vector<int> &A)
{
    // Brute Force Approach: O(N^2)
    // For each element, check if it's greater than all elements to its right
    vector<int> ans;
    int N = A.size();

    for (int i = 0; i < N; i++)
    {
        bool isLeader = true;
        // Check if A[i] is strictly greater than all elements on right
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] <= A[j])
            {
                isLeader = false;
                break;
            }
        }
        if (isLeader)
        {
            ans.push_back(A[i]);
        }
    }
    return ans;
}

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

bool isLeader(const vector<int> &A, int idx)
{
    // Check if A[idx] is strictly greater than all elements to its right
    for (int i = idx + 1; i < A.size(); i++)
    {
        if (A[idx] <= A[i])
            return false;
    }
    return true;
}

bool verifyLeaders(const vector<int> &A, const vector<int> &leaders)
{
    // Each element in leaders should be a leader in A
    for (int leader : leaders)
    {
        bool found = false;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == leader && isLeader(A, i))
            {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    // All leaders in A should be in the result
    for (int i = 0; i < A.size(); i++)
    {
        if (isLeader(A, i))
        {
            bool found = false;
            for (int leader : leaders)
            {
                if (A[i] == leader)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
    }
    return true;
}

int main(int argc, const char *argv[])
{
    cout << "=== Leaders in Array - Test Cases ===\n\n";

    // Test Case 1: Example from problem
    cout << "Test Case 1: [16, 17, 4, 3, 5, 2]\n";
    vector<int> A1{16, 17, 4, 3, 5, 2};
    cout << "Input:  ";
    printArray(A1);
    vector<int> ans1_opt = solveOpt(A1);
    vector<int> ans1_brute = solve(A1);
    cout << "Optimal: ";
    printArray(ans1_opt);
    cout << "Brute:   ";
    printArray(ans1_brute);
    cout << "Valid (Optimal): " << (verifyLeaders(A1, ans1_opt) ? "YES" : "NO") << endl;
    cout << "Valid (Brute):   " << (verifyLeaders(A1, ans1_brute) ? "YES" : "NO") << "\n\n";

    // Test Case 2: Ascending order
    cout << "Test Case 2: [5, 4]\n";
    vector<int> A2{5, 4};
    cout << "Input:  ";
    printArray(A2);
    vector<int> ans2_opt = solveOpt(A2);
    vector<int> ans2_brute = solve(A2);
    cout << "Optimal: ";
    printArray(ans2_opt);
    cout << "Brute:   ";
    printArray(ans2_brute);
    cout << "Valid (Optimal): " << (verifyLeaders(A2, ans2_opt) ? "YES" : "NO") << endl;
    cout << "Valid (Brute):   " << (verifyLeaders(A2, ans2_brute) ? "YES" : "NO") << "\n\n";

    // Test Case 3: Descending order (all leaders)
    cout << "Test Case 3: [9, 8, 7, 6, 5]\n";
    vector<int> A3{9, 8, 7, 6, 5};
    cout << "Input:  ";
    printArray(A3);
    vector<int> ans3_opt = solveOpt(A3);
    vector<int> ans3_brute = solve(A3);
    cout << "Optimal: ";
    printArray(ans3_opt);
    cout << "Brute:   ";
    printArray(ans3_brute);
    cout << "Valid (Optimal): " << (verifyLeaders(A3, ans3_opt) ? "YES" : "NO") << endl;
    cout << "Valid (Brute):   " << (verifyLeaders(A3, ans3_brute) ? "YES" : "NO") << "\n\n";

    // Test Case 4: Single element (always a leader)
    cout << "Test Case 4: [5]\n";
    vector<int> A4{5};
    cout << "Input:  ";
    printArray(A4);
    vector<int> ans4_opt = solveOpt(A4);
    vector<int> ans4_brute = solve(A4);
    cout << "Optimal: ";
    printArray(ans4_opt);
    cout << "Brute:   ";
    printArray(ans4_brute);
    cout << "Valid (Optimal): " << (verifyLeaders(A4, ans4_opt) ? "YES" : "NO") << endl;
    cout << "Valid (Brute):   " << (verifyLeaders(A4, ans4_brute) ? "YES" : "NO") << "\n\n";

    // Test Case 5: Random order
    cout << "Test Case 5: [1, 100, 50, 200, 30]\n";
    vector<int> A5{1, 100, 50, 200, 30};
    cout << "Input:  ";
    printArray(A5);
    vector<int> ans5_opt = solveOpt(A5);
    vector<int> ans5_brute = solve(A5);
    cout << "Optimal: ";
    printArray(ans5_opt);
    cout << "Brute:   ";
    printArray(ans5_brute);
    cout << "Valid (Optimal): " << (verifyLeaders(A5, ans5_opt) ? "YES" : "NO") << endl;
    cout << "Valid (Brute):   " << (verifyLeaders(A5, ans5_brute) ? "YES" : "NO") << "\n\n";

    // Test Case 6: Large numbers
    cout << "Test Case 6: [100000000, 50000000, 75000000, 10000000]\n";
    vector<int> A6{100000000, 50000000, 75000000, 10000000};
    cout << "Input:  ";
    printArray(A6);
    vector<int> ans6_opt = solveOpt(A6);
    vector<int> ans6_brute = solve(A6);
    cout << "Optimal: ";
    printArray(ans6_opt);
    cout << "Brute:   ";
    printArray(ans6_brute);
    cout << "Valid (Optimal): " << (verifyLeaders(A6, ans6_opt) ? "YES" : "NO") << endl;
    cout << "Valid (Brute):   " << (verifyLeaders(A6, ans6_brute) ? "YES" : "NO") << "\n\n";

    cout << "\n=== Complexity Analysis ===\n";
    cout << "Brute Force (solve):     O(N^2) Time | O(N) Space\n";
    cout << "Optimal (solveOpt):      O(N) Time | O(N) Space\n";

    return 0;
}
