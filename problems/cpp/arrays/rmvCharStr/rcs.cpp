/*
Remove Character from String

Problem Description:
Given a string and a character, remove all occurrences of that character from the string.

Input Format:
- A string str (1 <= str.length() <= 10000)
- A character ch to be removed

Output Format:
- Return a new string with all occurrences of ch removed

Constraints:
- String contains only printable ASCII characters
- Character ch is a single character
- If all characters are removed, return empty string

Example Input 1:
str = "abxxcdfexxd"
ch = 'x'

Example Output 1:
"abcdfed"

Example Input 2:
str = "hello world"
ch = 'l'

Example Output 2:
"heo word"

Example Input 3:
str = "aaaa"
ch = 'a'

Example Output 3:
""

Time Complexity: O(n) where n is length of string
Space Complexity: O(n) for the result string
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

string rmvCharStr(string str, char ch)
{
    if(str.empty())
        return "";
    int i = 0;
    string strAns;
    while (str[i] != '\0')
    {
        if(str[i]==ch) {
            i++;
            continue;
        }
        strAns.push_back(str[i]);
        i++;
    }
    return strAns;
}

int main(){
    cout << "Testing Remove Character from String\n";
    cout << "=====================================\n\n";
    
    // Test 1: From problem example
    string test1 = rmvCharStr("abxxcdfexxd", 'x');
    cout << "Test 1 - Remove 'x' from \"abxxcdfexxd\": ";
    cout << test1;
    cout << (test1 == "abcdfed" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: Remove from middle
    string test2 = rmvCharStr("hello world", 'l');
    cout << "Test 2 - Remove 'l' from \"hello world\": ";
    cout << test2;
    cout << (test2 == "heo word" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: Remove all characters
    string test3 = rmvCharStr("aaaa", 'a');
    cout << "Test 3 - Remove 'a' from \"aaaa\": ";
    cout << "\"" << test3 << "\"";
    cout << (test3 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: Character not present
    string test4 = rmvCharStr("hello", 'z');
    cout << "Test 4 - Remove 'z' from \"hello\": ";
    cout << test4;
    cout << (test4 == "hello" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Empty string
    string test5 = rmvCharStr("", 'a');
    cout << "Test 5 - Remove 'a' from \"\": ";
    cout << "\"" << test5 << "\"";
    cout << (test5 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: Single character (match)
    string test6 = rmvCharStr("a", 'a');
    cout << "Test 6 - Remove 'a' from \"a\": ";
    cout << "\"" << test6 << "\"";
    cout << (test6 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: Single character (no match)
    string test7 = rmvCharStr("a", 'b');
    cout << "Test 7 - Remove 'b' from \"a\": ";
    cout << test7;
    cout << (test7 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 8: Remove spaces
    string test8 = rmvCharStr("a b c d", ' ');
    cout << "Test 8 - Remove ' ' from \"a b c d\": ";
    cout << test8;
    cout << (test8 == "abcd" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n=====================================\n";
    return 0;
}