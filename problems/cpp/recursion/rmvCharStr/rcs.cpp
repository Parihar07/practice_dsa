#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Approach 1: Build new string (recommended)
// Time: O(n) - visits each character once
// Space: O(n) - new string + O(n) recursion stack
void rmvChar(string &str, string &ans,size_t ind, char ch){
    if(ind==str.length())
        return;

    if(str[ind]!=ch)
        ans.push_back(str[ind]);

    return rmvChar(str, ans, ind + 1, ch);
}

// Approach 2: In-place with shifting
// Time: O(n²) - worst case shifts n + (n-1) + ... + 1 characters
//              Example: "xxxx" removes each 'x', shifting remaining chars each time
// Space: O(1) extra data + O(n) recursion stack = O(n) total
// Note: Quadratic time makes this inefficient for strings with many matches
void inplace(string &str, char ch, size_t ind){
    if (ind == str.length())
        return;
    
    if(str[ind]==ch){
        // Shift all characters left (includes null terminator)
        for (size_t i = ind; i < str.length(); i++){
            str[i] = str[i + 1];
        }
        inplace(str, ch, ind);  // Check same index (new char shifted here)
    } else {
        inplace(str, ch, ind + 1);  // Move to next
    }
    return;
}

int main(){
    cout << "Testing Remove Character (Recursive)\n";
    cout << "======================================\n\n";

    string strr = "abxxdf";
    inplace(strr, 'x', 0);
    cout << strr << endl;

    // Test 1: Original test
    string str1 = "abxxdc", ans1;
    rmvChar(str1, ans1, 0, 'x');
    cout << "Test 1 - Remove 'x' from \"abxxdc\": " << ans1;
    cout << (ans1 == "abdc" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 2: Multiple occurrences
    string str2 = "abxxcdfexxd", ans2;
    rmvChar(str2, ans2, 0, 'x');
    cout << "Test 2 - Remove 'x' from \"abxxcdfexxd\": " << ans2;
    cout << (ans2 == "abcdfed" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 3: Character in middle
    string str3 = "hello world", ans3;
    rmvChar(str3, ans3, 0, 'l');
    cout << "Test 3 - Remove 'l' from \"hello world\": " << ans3;
    cout << (ans3 == "heo word" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 4: Remove all characters
    string str4 = "aaaa", ans4;
    rmvChar(str4, ans4, 0, 'a');
    cout << "Test 4 - Remove 'a' from \"aaaa\": \"" << ans4 << "\"";
    cout << (ans4 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 5: Character not present
    string str5 = "hello", ans5;
    rmvChar(str5, ans5, 0, 'z');
    cout << "Test 5 - Remove 'z' from \"hello\": " << ans5;
    cout << (ans5 == "hello" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 6: Empty string
    string str6 = "", ans6;
    rmvChar(str6, ans6, 0, 'a');
    cout << "Test 6 - Remove 'a' from \"\": \"" << ans6 << "\"";
    cout << (ans6 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 7: Single character (match)
    string str7 = "a", ans7;
    rmvChar(str7, ans7, 0, 'a');
    cout << "Test 7 - Remove 'a' from \"a\": \"" << ans7 << "\"";
    cout << (ans7 == "" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    // Test 8: Single character (no match)
    string str8 = "a", ans8;
    rmvChar(str8, ans8, 0, 'b');
    cout << "Test 8 - Remove 'b' from \"a\": " << ans8;
    cout << (ans8 == "a" ? " ✓ PASS" : " ✗ FAIL") << "\n";
    
    cout << "\n======================================\n";
    return 0;
}