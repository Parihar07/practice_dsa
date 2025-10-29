//
//  main.cpp
//  stack_bal_paranths
//
//  Created by CodeBreaker on 18/01/25.
//
/*
 Balanced Paranthesis
Solved
feature icon
Using hints except Complete Solution is Penalty free now
Use Hint
Problem Description
Given an expression string A, examine whether the pairs and the orders of “{“,”}”, ”(“,”)”, ”[“,”]” are correct in A.
Refer to the examples for more clarity.


Problem Constraints
1 <= |A| <= 100


Input Format
The first and the only argument of input contains the string A having the parenthesis sequence.


Output Format
Return 0 if the parenthesis sequence is not balanced.
Return 1 if the parenthesis sequence is balanced.


Example Input
Input 1:
 A = {([])}
Input 2:
 A = (){
Input 3:
 A = ()[]


Example Output
Output 1:
 1
Output 2:
 0
Output 3:
 1


Example Explanation
You can clearly see that the first and third case contain valid paranthesis.
In the second case, there is no closing bracket for {, thus the paranthesis sequence is invalid.
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution{
    string str;
public:
    Solution(string s):str(s){}
    int solve(string A);
    int solve2(string A);
};
int Solution::solve2(string A)
{
    stack<char> stk; int i=0;
    while(A[i]!='\0')
    {
        char ch=A[i];
        if(ch=='{' || ch=='[' || ch=='('){
            stk.push(ch);
        } else if(stk.empty())
        {
            return 0;
        } else {
            char chh = stk.top();
            if((chh=='[' && A[i]==']') ||
               (chh=='(' && A[i]==')') ||
               (chh=='{' && A[i]=='}'))
            {
                stk.pop();
            } else
            {
                return 0;
            }
        }
        i++;
    }
    return stk.empty()?1:0;
}
int Solution::solve(string A) {
    stack<char> stk;
    stk.push(A[0]); int i=1;
    while(A[i]!='\0')
    {
        if(!stk.empty())
        {
            char ch = stk.top();
            if((ch=='[' && A[i]==']') ||
               (ch=='(' && A[i]==')') ||
               (ch=='{' && A[i]=='}')
               )
            {
                stk.pop();
            }else {
                stk.push(A[i]);
            }
        } else {
            stk.push(A[i]);
        }
        i++;
    }
    return stk.empty()?1:0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, evaluating braces!\n";
    Solution s("{[()]}");
    cout<<"if is balanced - " << s.solve2("{[[}[]}(]}){") <<endl;
    
    return 0;
}
