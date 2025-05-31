//
//  main.cpp
//  recursion_palindrome
//
//  Created by CodeBreaker on 24/05/25.
//
/*
 Check Palindrome using Recursion
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Write a recursive function that checks whether string A is a palindrome or Not.
 Return 1 if the string A is a palindrome, else return 0.
 Note: A palindrome is a string that's the same when read forward and backward.


 Problem Constraints
 1 <= |A| <= 50000
 String A consists only of lowercase letters.


 Input Format
 The first and only argument is a string A.


 Output Format
 Return 1 if the string A is a palindrome, else return 0.


 Example Input
 Input 1:
  A = "naman"
 Input 2:
  A = "strings"


 Example Output
 Output 1:
  1
 Output 2:
  0


 Example Explanation
 Explanation 1:
  "naman" is a palindomic string, so return 1.
 Explanation 2:
  "strings" is not a palindrome, so return 0.

 */
#include <iostream>
#include <string>
using namespace std;

bool ifpalindrome1(string str)
{
    int s = 0, e = str.length()-1;
    
    while(s<e)
    {
        if(str[s]==str[e])
        {
            s++;e--;
        } else {
            return false;
        }
    }
    
    return true;
}

bool palindromHelper(string str, int s, int e)
{
    if(s>=e) return true;
    if(str[s]==str[e])
        return palindromHelper(str, s+1, e-1);
    else
        return false;
}

bool recuIfPalindrome(string str)
{
    int e = str.length()-1;
    return palindromHelper(str, 0, e);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, checking palindrome !\n";
    
    cout<<"chcek if \"naman\" is planidrome : "<<recuIfPalindrome("anaman")<<endl;
    return 0;
}
