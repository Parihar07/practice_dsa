#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Problem: Replace Character with String (Recursive In-Place)

Given a string, a character, and a replacement string, replace all occurrences 
of the character with the replacement string using recursion and in-place modification.

Input:
- string &str: input string (modified in-place)
- string rep: replacement string
- char ch: character to be replaced
- size_t ind: current index (start with 0)

Output:
- Modifies str in-place with all occurrences of ch replaced by rep

Examples:
1. Input: str="axbx", ch='x', rep="lux"
   Output: "aluxblux"
   
2. Input: str="hello", ch='l', rep="LL"
   Output: "heLLLLo"
   
3. Input: str="xxx", ch='x', rep="o"
   Output: "ooo"

Approach:
1. Base case: reached end of string
2. If current char matches:
   - Resize string to accommodate replacement
   - Shift characters right to make space
   - Insert replacement string at current position
   - Recurse from position after replacement
3. Else: recurse to next position

Time Complexity: O(n × m × k) where:
                 - n = number of matches
                 - m = replacement string length
                 - k = characters to shift per match
                 Worst case: O(n²×m) when all chars match
                 
Space Complexity: O(n) for recursion stack depth

Note: This is less efficient than building a new string due to:
      - Multiple resize operations
      - Repeated shifting of characters
      But demonstrates in-place recursive modification technique
*/

void repStr(string &str, string rep, char ch, size_t ind){

    if(str.length()==ind)
        return;
    if(str[ind]==ch){
        int rl = rep.length();
        int sl = str.length();
        str.resize(str.length() + rep.length() - 1);
        for (size_t i = sl; i > ind; i--)
        {
            str[i + (rl - 1)] = str[i];
        }
        for (size_t i = 0; i < rep.size();i++){
            str[ind] = rep[i];
            ind++;
        }
        repStr(str, rep, ch, ind);
    }
    else
    {
        repStr(str, rep, ch, ind + 1);
    }
}


int main(){
    cout << "Testing String Replace (Recursive In-Place)\n";
    cout << "============================================\n\n";
    
    // Test 1: Basic replacement
    string test1 = "axbx";
    repStr(test1, "lux", 'x', 0);
    cout << "Test 1 - Replace 'x' with \"lux\" in \"axbx\": " << test1;
    cout << (test1 == "aluxblux" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: No matches
    string test2 = "hello";
    repStr(test2, "abc", 'x', 0);
    cout << "Test 2 - Replace 'x' with \"abc\" in \"hello\": " << test2;
    cout << (test2 == "hello" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: All characters match
    string test3 = "xxx";
    repStr(test3, "o", 'x', 0);
    cout << "Test 3 - Replace 'x' with \"o\" in \"xxx\": " << test3;
    cout << (test3 == "ooo" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: Longer replacement
    string test4 = "axb";
    repStr(test4, "hello", 'x', 0);
    cout << "Test 4 - Replace 'x' with \"hello\" in \"axb\": " << test4;
    cout << (test4 == "ahellob" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Single character
    string test5 = "x";
    repStr(test5, "abc", 'x', 0);
    cout << "Test 5 - Replace 'x' with \"abc\" in \"x\": " << test5;
    cout << (test5 == "abc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: First and last character
    string test6 = "xabcx";
    repStr(test6, "12", 'x', 0);
    cout << "Test 6 - Replace 'x' with \"12\" in \"xabcx\": " << test6;
    cout << (test6 == "12abc12" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: Consecutive matches
    string test7 = "axxxb";
    repStr(test7, "o", 'x', 0);
    cout << "Test 7 - Replace 'x' with \"o\" in \"axxxb\": " << test7;
    cout << (test7 == "aooob" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 8: Same length replacement
    string test8 = "abc";
    repStr(test8, "X", 'b', 0);
    cout << "Test 8 - Replace 'b' with \"X\" in \"abc\": " << test8;
    cout << (test8 == "aXc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n============================================\n";
    return 0;
}