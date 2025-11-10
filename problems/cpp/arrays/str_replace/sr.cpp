#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Problem: Replace Character with String

Given a string, a character, and a replacement string, replace all occurrences 
of the character with the replacement string.

Input:
- string ip: input string
- char ch: character to be replaced
- string rep: replacement string

Output:
- Return modified string with all occurrences of ch replaced by rep

Examples:
1. Input: ip="axbx", ch='x', rep="klm"
   Output: "aklmbklm"
   
2. Input: ip="hello", ch='l', rep="LL"
   Output: "heLLLLo"
   
3. Input: ip="xxx", ch='x', rep="hello"
   Output: "hellohellohello"

Constraints:
- 0 <= ip.length() <= 10000
- rep can be empty string (removes character)
- If ch not found, return original string

Time Complexity: O(n × m) where n = input length, m = replacement length
                 Worst case: all chars match, each replacement copies m chars
Space Complexity: O(n × m) for result string in worst case
                  Example: "xxx" with rep="hello" → "hellohellohello"
*/

string strReplace(string ip, char ch, string rep){
    string ans;
    for (size_t i = 0; i < ip.size();i++){
        if(ip[i]==ch){
            for (size_t j = 0; j < rep.size();j++)
            {
                ans.push_back(rep[j]);
            }
        } else {
            ans.push_back(ip[i]);
        }
    }
        return ans;
}
int main(){
    cout << "Testing String Character Replace\n";
    cout << "=================================\n\n";
    
    // Test 1: Basic replacement
    string test1 = strReplace("axbx", 'x', "klm");
    cout << "Test 1 - Replace 'x' with \"klm\" in \"axbx\": " << test1;
    cout << (test1 == "aklmbklm" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: No matches
    string test2 = strReplace("hello", 'x', "abc");
    cout << "Test 2 - Replace 'x' with \"abc\" in \"hello\": " << test2;
    cout << (test2 == "hello" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: All characters match
    string test3 = strReplace("xxx", 'x', "hello");
    cout << "Test 3 - Replace 'x' with \"hello\" in \"xxx\": " << test3;
    cout << (test3 == "hellohellohello" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: Single character replacement
    string test4 = strReplace("abcd", 'b', "X");
    cout << "Test 4 - Replace 'b' with \"X\" in \"abcd\": " << test4;
    cout << (test4 == "aXcd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Empty replacement string
    string test5 = strReplace("axbxc", 'x', "");
    cout << "Test 5 - Replace 'x' with \"\" in \"axbxc\": " << test5;
    cout << (test5 == "abc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: Empty input string
    string test6 = strReplace("", 'x', "abc");
    cout << "Test 6 - Replace 'x' with \"abc\" in \"\": \"" << test6 << "\"";
    cout << (test6 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: First and last character
    string test7 = strReplace("xabcx", 'x', "12");
    cout << "Test 7 - Replace 'x' with \"12\" in \"xabcx\": " << test7;
    cout << (test7 == "12abc12" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 8: Consecutive matches
    string test8 = strReplace("axxxb", 'x', "o");
    cout << "Test 8 - Replace 'x' with \"o\" in \"axxxb\": " << test8;
    cout << (test8 == "aooob" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n=================================\n";
    return 0;
}