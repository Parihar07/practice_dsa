#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Problem: Generate All Valid Parentheses Combinations

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example:
Input: n = 3
Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]

Input: n = 2
Output: ["(())", "()()"]

Input: n = 1
Output: ["()"]

Constraints:
- 1 <= n <= 8
- The number of valid combinations is the nth Catalan number: C(n) = (2n)! / ((n+1)! * n!)
  C(1)=1, C(2)=2, C(3)=5, C(4)=14, C(5)=42, etc.

Approach: Backtracking
- At each step, we can add '(' if we have remaining open brackets
- We can add ')' only if close > open (ensures we don't close before opening)
- Base case: when all brackets are used (open=0, close=0)

Time Complexity: O(4^n / √n) - nth Catalan number is the exact count of valid combinations
Space Complexity: O(n) - recursion call stack depth is 2n, output string is 2n
*/

void printValidParenthesis(string &op, int open, int close)
{
    if (open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }
    if (open > 0)
    {
        op.push_back('(');
        printValidParenthesis(op, open - 1, close);
        op.pop_back(); // i have to remove when control pass to next phase when open 1 and close is 2 open will be inserted twice
    }
    if (close > 0 && close > open)
    {
        op.push_back(')');
        printValidParenthesis(op, open, close - 1);
        op.pop_back();
    }
}

int main()
{
    cout << "Hello printing valid parenthesis..\n";

    // Test Case 1: n = 1 (Catalan number C(1) = 1)
    cout << "\nTest 1: n = 1 (Expected: 1 combination)" << endl;
    string op1 = "";
    printValidParenthesis(op1, 1, 1);

    // Test Case 2: n = 2 (Catalan number C(2) = 2)
    cout << "\nTest 2: n = 2 (Expected: 2 combinations)" << endl;
    string op2 = "";
    printValidParenthesis(op2, 2, 2);

    // Test Case 3: n = 3 (Catalan number C(3) = 5)
    cout << "\nTest 3: n = 3 (Expected: 5 combinations)" << endl;
    string op3 = "";
    printValidParenthesis(op3, 3, 3);

    // Test Case 4: n = 4 (Catalan number C(4) = 14)
    cout << "\nTest 4: n = 4 (Expected: 14 combinations)" << endl;
    string op4 = "";
    printValidParenthesis(op4, 4, 4);

    // Test Case 5: Edge case n = 0 (should print nothing)
    cout << "\nTest 5: n = 0 (Expected: 1 empty combination)" << endl;
    string op5 = "";
    printValidParenthesis(op5, 0, 0);

    cout << "\nAll tests completed!" << endl;
    cout << "\nCatalan Numbers Reference:" << endl;
    cout << "C(1)=1, C(2)=2, C(3)=5, C(4)=14, C(5)=42, C(6)=132" << endl;

    return 0;
}