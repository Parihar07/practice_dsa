//
//  main.cpp
//  string_eord_reverse
//
//  Created by CodeBreaker on 23/01/25.
//
<<<<<<< HEAD

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
=======
/*
 everse the String
 Attempted
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a string A of size N.
 Return the string A after reversing the string word by word.
 NOTE:
 A sequence of non-space characters constitutes a word.
 Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
 If there are multiple spaces between words, reduce them to a single space in the reversed string.


 Problem Constraints
 1 <= N <= 3 * 105


 Input Format
 The only argument given is string A.


 Output Format
 Return the string A after reversing the string word by word.


 Example Input
 Input 1:
 A = "the sky is blue"
 Input 2:
 A = "this is ib"


 Example Output
 Output 1:
 "blue is sky the"
 Output 2:
 "ib is this"


 Example Explanation
 Explanation 1:
 We reverse the string word by word so the string becomes "blue is sky the".
 Explanation 2:
 We reverse the string word by word so the string becomes "ib is this".
 */
#include <iostream>
#include <string>
using namespace std;

void reversestring(string &str, int s, int e)
{
    while(s<e)
    {
        char ch = str[s];
        str[s] = str[e];
        str[e] = ch;
        s++;e--;
    }
    return;
}

string reverseWords(string &str)
{
    int s=0, e=(int)str.length()-1;
    string ans;
    reversestring(str, s, e);
    s=0;
    for(int i=0;i<=str.length();i++)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            e=i-1;
            reversestring(str, s, e);
            s=i+1;
        }
    }
    int cnt=-1;
    for(int i=0;i<=str.length();i++)
    {
        if(str[i]==' ' && cnt==-1) continue;
        if( str[i]==' ')
        {
            cnt+=1; continue;
        }
        if(cnt>0)
        {
            ans.push_back(' ');
        }
        ans.push_back(str[i]); cnt=0;
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Word reverse simple !\n";
    string s = "e jrkeymu coklj si vohl slje sxtpf xvak p kicqxoqaof uqwftidoi xixfvqbjey n tpkh ylqllzln ljo gvozwv";
    cout<<s<<endl;
    string ans = reverseWords(s);
    cout<<ans<<endl;
>>>>>>> d61fd74 (treetraversals)
    return 0;
}
