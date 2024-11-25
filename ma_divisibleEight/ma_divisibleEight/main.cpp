//
//  main.cpp
//  ma_divisibleEight
//
//  Created by CodeBreaker on 23/11/24.
//
/*
 Divisibility by 8
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a number A in the form of a string. Check if the number is divisible by eight or not.

 Return 1 if it is divisible by eight else, return 0.


 Problem Constraints
 1 <= length of the String <= 100000
 '0' <= A[i] <= '9'


 Input Format
 The only argument given is a string A.


 Output Format
 Return 1 if it is divisible by eight else return 0.


 Example Input
 Input 1:
 A = "16"
 Input 2:
 A = "123"


 Example Output
 Output 1:
 1
 Output 2:
 0


 Example Explanation
 Explanation 1:
  16 = 8 * 2
 Explanation 2:
 123 = 15 * 8 + 3
 
 */
#include <iostream>
#include<string>
using namespace std;

int solve(string A) {
    int num=0;
    size_t N = A.length();
    int s=0,e=N-1;
    while(s<e)
    {
        char ch = A[s];
        A[s]=A[e];
        A[e]=ch;
        s++; e--;
    }
    int tens=1;
    for(int i=0;i<N;i++) // this can be still few iterations by divisiblity rule, which says if last three digit of number is divisible then number is divisiable.
    {
        num+=((int)A[i]-48)*tens;
        tens*=10;
    }
    
    return (num%8==0) ? 1 : 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Divisible by 8!\n";
    cout<<"-------------------\n";
    string str="123";
    cout<<"if divisible : "<<solve(str)<<endl;
    return 0;
}
