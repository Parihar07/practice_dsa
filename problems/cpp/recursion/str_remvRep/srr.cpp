#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Problem: Remove Consecutive Duplicate Characters (Recursive)

Given a string, remove all consecutive duplicate characters using recursion,
keeping only one occurrence of each character in a sequence.

Input:
- string &ip: input string (modified in-place)
- size_t ind: current index (start with 0)

Output:
- Modifies string in-place, removing consecutive duplicates

Examples:
1. Input: "aaabcbbd"
   Output: "abcbd"
   Explanation: "aaa" → "a", "bb" → "b"
   
2. Input: "aabbcc"
   Output: "abc"
   
3. Input: "hheelllloo"
   Output: "helo"

Approach (Recursive):
1. Base case: reached end of string ('\0')
2. If current char equals next char:
   - Shift all characters left to remove duplicate
   - Resize string to update length
   - Recurse on SAME index (re-check position after shift)
3. Else: recurse on next index (ind + 1)

Time Complexity: O(n²)
                 - Each duplicate removal: O(n) for shifting
                 - Multiple recursive calls
                 - Worst case: "aaaa" requires O(n) removals × O(n) shifts
                 
Space Complexity: O(n) for recursion stack depth

Note: This is less efficient than iterative two-pointer O(n) approach,
      but demonstrates recursive in-place string modification.
*/

void rmvRepChar(string &ip, size_t ind){
    if(ip[ind]=='\0')
        return;
    if(ip[ind]==ip[ind+1]){
        for (size_t i = ind; ip[i]!='\0'; i++)
        {
            ip[i] = ip[i + 1];
        }
        ip.resize(ip.length() - 1);
        rmvRepChar(ip, ind);
    }
    else
    {
        rmvRepChar(ip, ind + 1);
    }
}

int main(){
    cout << "Testing Remove Consecutive Duplicates (Recursive)\n";
    cout << "==================================================\n\n";
    
    // Test 1: Multiple consecutive duplicates
    string test1 = "aaabcbbd";
    rmvRepChar(test1, 0);
    cout << "Test 1 - \"aaabcbbd\": " << test1;
    cout << (test1 == "abcbd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: All same characters
    string test2 = "aaaa";
    rmvRepChar(test2, 0);
    cout << "Test 2 - \"aaaa\": " << test2;
    cout << (test2 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: No duplicates
    string test3 = "abcd";
    rmvRepChar(test3, 0);
    cout << "Test 3 - \"abcd\": " << test3;
    cout << (test3 == "abcd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: All consecutive duplicates
    string test4 = "aabbcc";
    rmvRepChar(test4, 0);
    cout << "Test 4 - \"aabbcc\": " << test4;
    cout << (test4 == "abc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Single character
    string test5 = "a";
    rmvRepChar(test5, 0);
    cout << "Test 5 - \"a\": " << test5;
    cout << (test5 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: Two same characters
    string test6 = "aa";
    rmvRepChar(test6, 0);
    cout << "Test 6 - \"aa\": " << test6;
    cout << (test6 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: Alternating with duplicates
    string test7 = "aabbaabbaa";
    rmvRepChar(test7, 0);
    cout << "Test 7 - \"aabbaabbaa\": " << test7;
    cout << (test7 == "ababa" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 8: Mixed duplicates
    string test8 = "hheelllloo";
    rmvRepChar(test8, 0);
    cout << "Test 8 - \"hheelllloo\": " << test8;
    cout << (test8 == "helo" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n==================================================\n";
    return 0;
}