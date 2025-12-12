/*
================================================================================
PROBLEM: Word Break - Find All Valid Word Breaks
================================================================================
Given a string and a dictionary of words, find all possible ways to break the
string into dictionary words.

EXAMPLE:
Input:  string = "ilikesamsung"
        dictionary = {"i", "like", "sam", "sung", "samsung", ...}
Output:
        i like sam sung
        i like samsung

APPROACH: Recursion with Backtracking
- From current position, try all possible word lengths
- If word is found in dictionary, recursively solve for remaining string
- Use backtracking to explore all valid partitions
- Time Complexity: O(2^n) in worst case (exponential)
- Space Complexity: O(n) for recursion stack

================================================================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// Check if a word exists in dictionary
bool check(const string &ip, const unordered_set<string> &db)
{
    return db.find(ip) != db.end();
}

// Recursive function to find all word breaks
// ip: input string
// db: dictionary set
// op: output vector to store current partition
// s: current starting position
// e: length of word to check from position s
void wbp(const string &ip, const unordered_set<string> &db, vector<string> &op, int s, int e)
{
    // Base case: reached end of string
    if (ip.length() == s)
    {
        for (auto i : op)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    // Try all possible word lengths from current position
    if (e <= (ip.length() - s) && check(ip.substr(s, e), db))
    {
        // Word found - add to result and recurse for remaining string
        op.push_back(ip.substr(s, e));
        wbp(ip, db, op, s + e, 1); // Reset e to 1 for next position
        op.pop_back();             // Backtrack
    }

    // Try extending the word length
    if (e < (ip.length() - s))
        wbp(ip, db, op, s, e + 1);
}

int main()
{
    cout << "================================================================================\n";
    cout << "WORD BREAK PROBLEM - Find All Valid Dictionary Partitions\n";
    cout << "================================================================================\n\n";

    // Dictionary of valid words
    unordered_set<string> db{"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "man", "go", "mango"};

    // Test Case 1: "ilikesamsung"
    cout << "TEST CASE 1: \"ilikesamsung\"\n";
    cout << "Dictionary: {i, like, sam, sung, samsung, ...}\n";
    cout << "Expected Output:\n";
    cout << "  i like sam sung\n";
    cout << "  i like samsung\n";
    cout << "Actual Output:\n";
    {
        vector<string> op;
        wbp("ilikesamsung", db, op, 0, 1);
    }
    cout << "\n";

    // Test Case 2: "ilike"
    cout << "TEST CASE 2: \"ilike\"\n";
    cout << "Dictionary: {i, like, sam, sung, samsung, ...}\n";
    cout << "Expected Output:\n";
    cout << "  i like\n";
    cout << "Actual Output:\n";
    {
        vector<string> op;
        wbp("ilike", db, op, 0, 1);
    }
    cout << "\n";

    // Test Case 3: "icecreamandgo"
    cout << "TEST CASE 3: \"icecreamandgo\"\n";
    cout << "Dictionary: {i, like, sam, sung, samsung, ...}\n";
    cout << "Expected Output:\n";
    cout << "  (no valid partition - 'and' not in dictionary)\n";
    cout << "Actual Output:\n";
    {
        vector<string> op;
        wbp("icecreamandgo", db, op, 0, 1);
    }
    cout << "\n";

    // Test Case 4: "icecreamman"
    cout << "TEST CASE 4: \"icecreamman\"\n";
    cout << "Dictionary: {i, like, sam, sung, samsung, ...}\n";
    cout << "Expected Output:\n";
    cout << "  ice cream man\n";
    cout << "Actual Output:\n";
    {
        vector<string> op;
        wbp("icecreamman", db, op, 0, 1);
    }
    cout << "\n";

    // Test Case 5: "mango"
    cout << "TEST CASE 5: \"mango\"\n";
    cout << "Dictionary: {i, like, sam, sung, samsung, ...}\n";
    cout << "Expected Output:\n";
    cout << "  mango\n";
    cout << "  man go\n";
    cout << "Actual Output:\n";
    {
        vector<string> op;
        wbp("mango", db, op, 0, 1);
    }
    cout << "\n";

    // Test Case 6: "mobile"
    cout << "TEST CASE 6: \"mobile\"\n";
    cout << "Dictionary: {i, like, sam, sung, samsung, ...}\n";
    cout << "Expected Output:\n";
    cout << "  mobile\n";
    cout << "Actual Output:\n";
    {
        vector<string> op;
        wbp("mobile", db, op, 0, 1);
    }
    cout << "\n";

    cout << "================================================================================\n";

    return 0;
}