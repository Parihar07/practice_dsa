#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Method 1: Array-based approach with substr
// Time Complexity: O(n * 2^n) - 2^n subsequences, each substr() takes O(n)
// Space Complexity: O(n * 2^n) - call stack O(n), output array O(2^n), each string O(n)
int subSeq(string ip, string op[])
{
    // if string input is empty just return 1 as empty string ill also have one empty string output
    if (ip.size() == 0)
    {
        op[0] = "";
        return 1;
    }
    size_t total = subSeq(ip.substr(1), op);
    for (size_t i = 0; i < total; i++)
    {
        op[i + total] = ip[0] + op[i];
    }
    return total * 2;
}

// Method 2: Vector-based approach with substr
// Time Complexity: O(n * 2^n) - 2^n subsequences, each substr() takes O(n)
// Space Complexity: O(n * 2^n) - call stack O(n), vector stores O(2^n) strings, each O(n)
size_t subSeqVec(string ip, vector<string> &op)
{
    if (ip.size() == 0)
    {
        op.push_back("");
        return 1;
    }
    size_t total = subSeqVec(ip.substr(1), op);
    for (size_t i = 0; i < total; i++)
    {
        op.push_back(ip[0] + op[i]);
    }
    return total * 2;
}

// Method 3: Return vector approach with substr
// Time Complexity: O(n * 2^n) - 2^n subsequences, each substr() takes O(n)
// Space Complexity: O(n * 2^n) - call stack O(n), creates new vectors at each level
vector<string> subSeqRet(string ip)
{
    if (ip.size() == 0)
        return {""};

    vector<string> res = subSeqRet(ip.substr(1));
    vector<string> result = res;
    for (auto i : res)
    {
        result.push_back(ip[0] + i);
    }
    return result;
}

// Method 4: Optimized index-based vector approach (avoids substr overhead)
// Time Complexity: O(n * 2^n) - 2^n subsequences, building each string takes O(n)
// Space Complexity: O(n * 2^n) - call stack O(n), vector stores O(2^n) strings, each O(n)
// Note: Faster than methods 1-3 as no substr() overhead, but still builds strings
void subSeqVecOpt(string &str, vector<string> &op, size_t ind, string current = "")
{
    if (ind == str.size())
    {
        op.push_back(current);
        return;
    }
    // Exclude current character
    subSeqVecOpt(str, op, ind + 1, current);
    // Include current character
    subSeqVecOpt(str, op, ind + 1, current + str[ind]);
}

// Method 5: Optimized index-based return vector (avoids substr overhead)
// Time Complexity: O(n * 2^n) - 2^n subsequences, building each string takes O(n)
// Space Complexity: O(n * 2^n) - call stack O(n), creates vectors at each level
vector<string> subSeqRetOpt(string &str, size_t ind = 0)
{
    if (ind == str.size())
        return {""};

    vector<string> res = subSeqRetOpt(str, ind + 1);
    vector<string> result = res;
    for (auto &i : res)
    {
        result.push_back(str[ind] + i);
    }
    return result;
}

// Method 6: Backtracking with print (include/exclude pattern) - MOST EFFICIENT for printing
// Time Complexity: O(2^n) - only 2^n function calls, no string building overhead
// Space Complexity: O(n) - call stack O(n), output string O(n), no storage of all subsequences
// Note: Best approach when you just need to print/process subsequences, not store them
// Theory: At each index, either include character or exclude it, recursion handles rest
void subSeq2(string str, string &op, size_t ind)
{
    if (ind == str.size())
    {
        cout << op << endl;
        return;
    }
    op.push_back(str[ind]);
    subSeq2(str, op, ind + 1);
    op.pop_back();
    subSeq2(str, op, ind + 1);
}

int main()
{
    cout << "Hello subsequence problem using recursion..\n";

    // Test Case 1: Basic string "abc"
    cout << "\nTest 1: subSeqVec with 'abc'" << endl;
    vector<string> vop;
    size_t tv = subSeqVec("abc", vop);
    cout << "Count: " << tv << " | Output: ";
    for (size_t i = 0; i < tv; i++)
    {
        cout << "\"" << vop[i] << "\" ";
    }
    cout << endl;

    // Test Case 2: Return vector approach
    cout << "\nTest 2: subSeqRet with 'abc'" << endl;
    auto res = subSeqRet("abc");
    cout << "Count: " << res.size() << " | Output: ";
    for (auto i : res)
    {
        cout << "\"" << i << "\" ";
    }
    cout << endl;

    // Test Case 3: Print approach (include/exclude pattern)
    cout << "\nTest 3: subSeq2 with 'abc'" << endl;
    string output = "";
    subSeq2("abc", output, 0);

    // Test Case 4: Empty string
    cout << "\nTest 4: Empty string" << endl;
    vector<string> empty_vop;
    size_t empty_count = subSeqVec("", empty_vop);
    cout << "Count: " << empty_count << " | Output: \"" << empty_vop[0] << "\"" << endl;

    // Test Case 5: Single character
    cout << "\nTest 5: Single char 'a'" << endl;
    auto single_res = subSeqRet("a");
    cout << "Count: " << single_res.size() << " | Output: ";
    for (auto i : single_res)
    {
        cout << "\"" << i << "\" ";
    }
    cout << endl;

    // Test Case 6: Two characters
    cout << "\nTest 6: subSeq2 with 'xy'" << endl;
    string xy_output = "";
    subSeq2("xy", xy_output, 0);

    // Test Case 7: Four characters (2^4 = 16 subsequences)
    cout << "\nTest 7: subSeqVec with 'abcd' (should have 16 subsequences)" << endl;
    vector<string> four_char;
    size_t four_count = subSeqVec("abcd", four_char);
    cout << "Count: " << four_count << endl;

    // Test Case 8: Optimized vector approach
    cout << "\nTest 8: subSeqVecOpt with 'abc' (optimized, no substr)" << endl;
    vector<string> opt_vop;
    string test_str = "abc";
    subSeqVecOpt(test_str, opt_vop, 0);
    cout << "Count: " << opt_vop.size() << " | Output: ";
    for (auto &s : opt_vop)
    {
        cout << "\"" << s << "\" ";
    }
    cout << endl;

    // Test Case 9: Optimized return vector approach
    cout << "\nTest 9: subSeqRetOpt with 'abc' (optimized, no substr)" << endl;
    string test_str2 = "abc";
    auto opt_res = subSeqRetOpt(test_str2);
    cout << "Count: " << opt_res.size() << " | Output: ";
    for (auto &s : opt_res)
    {
        cout << "\"" << s << "\" ";
    }
    cout << endl;

    cout << "\nAll tests completed!" << endl;
    return 0;
}