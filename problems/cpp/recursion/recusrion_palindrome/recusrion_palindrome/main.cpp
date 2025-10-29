//
//  main.cpp
//  recusrion_palindrome
//
//  Created by CodeBreaker on 30/11/24.
//
/*
 Find Fibonacci - II
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 The Fibonacci numbers are the numbers in the following integer sequence.
 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
 In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation:
 Fn = Fn-1 + Fn-2
 Given a number A, find and return the Ath Fibonacci Number using recursion.
 Given that F0 = 0 and F1 = 1.


 Problem Constraints
 0 <= A <= 20


 Input Format
 First and only argument is an integer A.


 Output Format
 Return an integer denoting the Ath term of the sequence.


 Example Input
 Input 1:
  A = 2
 Input 2:
  A = 9


 Example Output
 Output 1:
  1
 Output 2:
  34


 Example Explanation
 Explanation 1:
  f(2) = f(1) + f(0) = 1
 Explanation 2:
  f(9) = f(8) + f(7) = 21 + 13  = 34
 */
#include <iostream>
#include<string>
using namespace std;

int chkPalindrome(string str, int s, int e)
{
    if(s>e) return 1;
    if(str[s]!=str[e]) return 0;
    return chkPalindrome(str, s+1, e-1);
}

int solve(string A) {
    int s = 0, e=A.length()-1;
    return chkPalindrome(A, s, e);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, chcek palindrome!\n";
    cout<<"Checking palindrome : "<<solve("namaan")<<endl;
    return 0;
}
