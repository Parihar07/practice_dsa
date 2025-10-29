//
//  main.cpp
//  recusrion_fibnaci
//
//  Created by CodeBreaker on 30/11/24.
//
/*
 Check Palindrome using Recursion
 Unsolved
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
using namespace std;

int findAthFibonacci(int A) {
    if(A<3) return 1;
    return findAthFibonacci(A-1) + findAthFibonacci(A-2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"Fibonacci : "<<findAthFibonacci(4)<<endl;
    return 0;
}
