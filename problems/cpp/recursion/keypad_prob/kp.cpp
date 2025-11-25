#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Problem: Keypad Letter Combinations (Phone Number)

Given a string of digits, print all possible letter combinations that the number could represent using the mapping of a classic phone keypad.

Example:
Input: "23"
Output:
  ad
  ae
  af
  bd
  be
  bf
  cd
  ce
  cf

Input: "234"
Output: (27 combinations)
  adg, adh, adi, aeg, ... cfi

Approach:
- Use recursion and backtracking.
- For each digit, loop through all possible letters and recurse for the next digit.
- Base case: when idx == ip.size(), print the current combination.

Time Complexity: O(3^n * 4^m), where n is the number of digits mapping to 3 letters (2-6,8) and m is the number mapping to 4 letters (7,9).
Space Complexity: O(n) (call stack and output string)
*/

void keyCombi(vector<string> &kp, string &ip, string &op, int idx)
{
    if (idx == ip.size())
    {
        cout << op << "\n";
        return;
    }
    for (size_t i = 0; i < kp[ip[idx] - '0'].size(); i++)
    {
        op.push_back(kp[ip[idx] - '0'][i]);
        keyCombi(kp, ip, op, idx + 1);
        op.pop_back();    
    }
}

// v2: Improved version with const correctness and enhanced readability
void keyCombi_v2(const vector<string> &kp, const string &ip, string &op, int idx)
{
    // Base case: if we've processed all digits, print the combination
    if (idx == ip.size())
    {
        cout << op << "\n";
        return;
    }

    // Get the string of letters for the current digit
    const string &letters = kp[ip[idx] - '0'];
    // Use a range-based for loop for better readability
    for (char letter : letters)
    {
        op.push_back(letter);
        keyCombi_v2(kp, ip, op, idx + 1); // Recurse for the next digit
        op.pop_back();                   // Backtrack
    }
}

int main()
{
    cout << "Hello solving keypad problem\n";
    // creating the keypad
    vector<string> keypad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cout << "=============\n";
    string op;
    // Test Case 1: "234"
    cout << "Test 1: 234" << endl;
    string ip1 = "234";
    keyCombi(keypad, ip1, op, 0);
    // Test Case 2: "23"
    cout << "\nTest 2: 23" << endl;
    string ip2 = "23";
    keyCombi(keypad, ip2, op, 0);
    // Test Case 3: "7" (4 letters)
    cout << "\nTest 3: 7" << endl;
    string ip3 = "7";
    keyCombi(keypad, ip3, op, 0);
    // Test Case 4: "9" (4 letters)
    cout << "\nTest 4: 9" << endl;
    string ip4 = "9";
    keyCombi(keypad, ip4, op, 0);
    // Test Case 5: "" (empty input)
    cout << "\nTest 5: (empty input)" << endl;
    string ip5 = "";
    keyCombi(keypad, ip5, op, 0);

    // --- Using the improved version (v2) ---
    cout << "\n\n=====================================\n";
    cout << "Running tests with improved version\n";
    cout << "=====================================\n";

    // Test Case 1: "234"
    cout << "Test 1: 234" << endl;
    string ip1_v2 = "234";
    string op1_v2; // Using a separate output string for each test
    keyCombi_v2(keypad, ip1_v2, op1_v2, 0);

    // Test Case 2: "23"
    cout << "\nTest 2: 23" << endl;
    string ip2_v2 = "23";
    string op2_v2;
    keyCombi_v2(keypad, ip2_v2, op2_v2, 0);

    // Test Case 3: "7"
    cout << "\nTest 3: 7" << endl;
    string ip3_v2 = "7";
    string op3_v2;
    keyCombi_v2(keypad, ip3_v2, op3_v2, 0);

    // Test Case 5: "" (empty input)
    cout << "\nTest 5: (empty input)" << endl;
    string ip5_v2 = "";
    string op5_v2;
    keyCombi_v2(keypad, ip5_v2, op5_v2, 0);
    return 0;
}