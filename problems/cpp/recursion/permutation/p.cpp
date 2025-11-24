#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/*
Problem: Print All Permutations of a String

Given a string, print all possible permutations of its characters.

Example:
Input: "abc"
Output:
  abc
  acb
  bac
  bca
  cab
  cba

Input: "aab"
Output:
  aab
  aba
  aab
  aba
  baa
  baa

Approach:
- Use recursion and backtracking.
- At each index, swap every character from idx to end with idx, recurse, then swap back.
- Base case: when idx == length, print the string.

Time Complexity: O(n!) (n factorial permutations for n unique characters)
Space Complexity: O(n) (call stack)
*/

void permutations(std::string &ip, int idx)
{
    if (idx == ip.length())
    {
        std::cout << ip << "\n";
        return;
    }
    for (int i = idx; i < ip.length(); i++)
    {
        std::swap(ip[i], ip[idx]);
        permutations(ip, idx + 1);
        std::swap(ip[idx], ip[i]); // backtrack
    }
}

// Handles duplicates: prints only unique permutations
void uniquePermutations(std::string &ip, int idx)
{
    if (idx == ip.length())
    {
        std::cout << ip << "\n";
        return;
    }
    std::unordered_set<char> used;
    for (int i = idx; i < ip.length(); ++i)
    {
        if (used.count(ip[i]))
            continue; // skip duplicate
        used.insert(ip[i]);
        std::swap(ip[i], ip[idx]);
        uniquePermutations(ip, idx + 1);
        std::swap(ip[idx], ip[i]); // backtrack
    }
}

int main()
{
    std::cout << "Hello, printing all the permutations.\n";
    // Test Case 1: "abc"
    std::cout << "\nTest 1: abc" << std::endl;
    std::string s1 = "abc";
    permutations(s1, 0);
    // Test Case 2: "aab" (with duplicates)
    std::cout << "\nTest 2: aab" << std::endl;
    std::string s2 = "aab";
    permutations(s2, 0);
    // Test Case 3: "ab"
    std::cout << "\nTest 3: ab" << std::endl;
    std::string s3 = "ab";
    permutations(s3, 0);
    // Test Case 4: "a" (single character)
    std::cout << "\nTest 4: a" << std::endl;
    std::string s4 = "a";
    permutations(s4, 0);
    // Test Case 5: "" (empty string)
    std::cout << "\nTest 5: (empty string)" << std::endl;
    std::string s5 = "";
    permutations(s5, 0);
    // Test Case 6: Unique permutations for "aab"
    std::cout << "\nTest 6: Unique permutations for aab" << std::endl;
    std::string s6 = "aab";
    // Note: Sorting is not required for this specific implementation using unordered_set,
    // but it would be for other common approaches to this problem.
    uniquePermutations(s6, 0);
    return 0;
}