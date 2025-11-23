#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Problem: Print All Strings with Equal Number of 'a' and 'b'

Given two integers a and b, print all possible strings that contain exactly 'a' occurrences of 'a' and 'b' occurrences of 'b', in any order.

Example:
Input: a = 2, b = 2
Output:
  aabb
  abab
  abba
  baab
  baba
  bbaa

Input: a = 1, b = 2
Output:
  abb
  bab
  bba

Approach:
- Use recursion and backtracking.
- At each step, if a > 0, add 'a' and recurse.
- If b > 0, add 'b' and recurse.
- When both a and b are zero, print the string.

Time Complexity: O((a+b)! / (a! * b!))  [number of unique permutations]
Space Complexity: O(a+b) (call stack and output string)
*/

void printEqCh(int a, int b, string &op){
    if(a==0 && b==0){
        cout << op << endl;
        return;
    }
    if(a>0){
        op.push_back('a');
        printEqCh(a - 1, b, op);
        op.pop_back();
    }
    if(b>0){
        op.push_back('b');
        printEqCh(a, b - 1, op);
        op.pop_back();
    }
}

int main(){
    cout<<"Hello, print equal number of given characters..\n";
    string op;
    // Test Case 1: a=2, b=2
    cout << "\nTest 1: a=2, b=2" << endl;
    printEqCh(2, 2, op);
    // Test Case 2: a=1, b=2
    cout << "\nTest 2: a=1, b=2" << endl;
    printEqCh(1, 2, op);
    // Test Case 3: a=3, b=1
    cout << "\nTest 3: a=3, b=1" << endl;
    printEqCh(3, 1, op);
    // Test Case 4: a=0, b=2
    cout << "\nTest 4: a=0, b=2" << endl;
    printEqCh(0, 2, op);
    // Test Case 5: a=2, b=0
    cout << "\nTest 5: a=2, b=0" << endl;
    printEqCh(2, 0, op);
    return 0;
}