#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Problem: Remove Consecutive Duplicate Characters

Given a string, remove all consecutive duplicate characters, keeping only one 
occurrence of each character in a sequence.

Input:
- string &ip: input string (modified in-place)

Output:
- Modifies string in-place, removing consecutive duplicates

Examples:
1. Input: "aaabcbbd"
   Output: "abcbd"
   Explanation: "aaa" → "a", "bb" → "b"
   
2. Input: "aabbcc"
   Output: "abc"
   
3. Input: "abcd"
   Output: "abcd"
   Explanation: No consecutive duplicates

Constraints:
- 0 <= ip.length() <= 10000
- String contains printable ASCII characters

Approach:
1. Iterate through string with index i
2. If current char equals next char:
   - Shift all characters left to remove duplicate
   - Decrement i to re-check same position (new char shifted in)
3. Increment i to move forward

Time Complexity: O(n²) 
                 - Outer loop: O(n)
                 - Shift operation per duplicate: O(n)
                 - Worst case: "aaaa" requires multiple shifts
                 
Space Complexity: O(1) - in-place modification, no extra space

Note: This approach uses shifting which is O(n²) in worst case.
      More efficient: Two-pointer O(n) approach (build result without shifting)
*/

// Approach 1: Manual shifting (more explicit, easier to understand)
void rmvRepeatedChar(string &ip){
    if(ip.empty())
        return; 
    int i = 0;
    while (ip[i] != '\0')
    {
        if (ip[i] == ip[i + 1])
        {
            // Shift all characters left
            for (size_t j = i + 1; ip[j] != '\0'; j++)
            {
                ip[j] = ip[j + 1];
            }
            // Update string length after shifting
            ip.resize(ip.length() - 1);
            // Don't increment i - recheck same position
        }
        else
        {
            i++;  // Only increment when no duplicate found
        }
    }
    return;
}

// Approach 2: Using STL erase (more concise)
void rmvRepeatedCharV2(string &ip){
    if(ip.empty())
        return; 
    int i = 0;
    while (i < (int)ip.length())
    {
        if (i + 1 < (int)ip.length() && ip[i] == ip[i + 1])
        {
            ip.erase(i + 1, 1);  // Remove duplicate at i+1 (handles shift + resize)
            // Don't increment i - recheck same position
        }
        else
        {
            i++;  // Only increment when no duplicate found
        }
    }
    return;
}

// Approach 3: Two-Pointer Optimization (O(n) - Best)
void rmvRepeatedCharOptimized(string &ip){
    if(ip.empty()) return;
    
    int writeIdx = 0;  // Where to write unique chars
    
    // Single pass through string
    for(size_t i = 0; i < ip.length(); i++){
        // Write current char if:
        // 1. It's first char (writeIdx == 0), OR
        // 2. Different from previous written char
        if(writeIdx == 0 || ip[i] != ip[writeIdx - 1]){
            ip[writeIdx++] = ip[i];
        }
        // Skip duplicates automatically (don't increment writeIdx)
    }
    
    ip.resize(writeIdx);  // Single resize at end
    return;
}

int main(){
    cout << "Testing Remove Consecutive Duplicates\n";
    cout << "======================================\n\n";
    
    cout << "Approach 1: Manual Shifting\n";
    cout << "----------------------------\n";
    
    // Test 1: Multiple consecutive duplicates
    string test1 = "aaabcbbd";
    rmvRepeatedChar(test1);
    cout << "Test 1 - \"aaabcbbd\": \"" << test1 << "\"";
    cout << (test1 == "abcbd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: All same characters
    string test2 = "aaaa";
    rmvRepeatedChar(test2);
    cout << "Test 2 - \"aaaa\": " << test2;
    cout << (test2 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: No duplicates
    string test3 = "abcd";
    rmvRepeatedChar(test3);
    cout << "Test 3 - \"abcd\": " << test3;
    cout << (test3 == "abcd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: All consecutive duplicates
    string test4 = "aabbcc";
    rmvRepeatedChar(test4);
    cout << "Test 4 - \"aabbcc\": " << test4;
    cout << (test4 == "abc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Single character
    string test5 = "a";
    rmvRepeatedChar(test5);
    cout << "Test 5 - \"a\": " << test5;
    cout << (test5 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: Two same characters
    string test6 = "aa";
    rmvRepeatedChar(test6);
    cout << "Test 6 - \"aa\": " << test6;
    cout << (test6 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: Alternating with duplicates
    string test7 = "aabbaabbaa";
    rmvRepeatedChar(test7);
    cout << "Test 7 - \"aabbaabbaa\": " << test7;
    cout << (test7 == "ababa" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 8: Mixed duplicates
    string test8 = "hheelllloo";
    rmvRepeatedChar(test8);
    cout << "Test 8 - \"hheelllloo\": " << test8;
    cout << (test8 == "helo" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\nApproach 2: Using STL erase()\n";
    cout << "------------------------------\n";
    
    // Test with Version 2
    string test9 = "aaabcbbd";
    rmvRepeatedCharV2(test9);
    cout << "Test 9 - \"aaabcbbd\": " << test9;
    cout << (test9 == "abcbd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    string test10 = "aabbcc";
    rmvRepeatedCharV2(test10);
    cout << "Test 10 - \"aabbcc\": " << test10;
    cout << (test10 == "abc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    string test11 = "hheelllloo";
    rmvRepeatedCharV2(test11);
    cout << "Test 11 - \"hheelllloo\": " << test11;
    cout << (test11 == "helo" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\nApproach 3: Two-Pointer (O(n) - Optimized)\n";
    cout << "-------------------------------------------\n";
    
    // Test with Optimized Version
    string test12 = "aaabcbbd";
    rmvRepeatedCharOptimized(test12);
    cout << "Test 12 - \"aaabcbbd\": " << test12;
    cout << (test12 == "abcbd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    string test13 = "aabbcc";
    rmvRepeatedCharOptimized(test13);
    cout << "Test 13 - \"aabbcc\": " << test13;
    cout << (test13 == "abc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    string test14 = "hheelllloo";
    rmvRepeatedCharOptimized(test14);
    cout << "Test 14 - \"hheelllloo\": " << test14;
    cout << (test14 == "helo" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    string test15 = "aaaa";
    rmvRepeatedCharOptimized(test15);
    cout << "Test 15 - \"aaaa\": " << test15;
    cout << (test15 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n======================================\n";
    return 0;
}