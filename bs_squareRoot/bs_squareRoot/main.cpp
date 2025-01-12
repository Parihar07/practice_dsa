//
//  main.cpp
//  bs_squareRoot
//
//  Created by CodeBreaker on 12/01/25.
//
/*
 Square Root of Integer
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given an integer A. Compute and return the square root of A.
 If A is not a perfect square, return floor(sqrt(A)).

 NOTE:
    The value of A*A can cross the range of Integer.
    Do not use the sqrt function from the standard library.
    Users are expected to solve this in O(log(A)) time.


 Problem Constraints
 0 <= A <= 109


 Input Format
 The first and only argument given is the integer A.


 Output Format
 Return floor(sqrt(A))


 Example Input
 Input 1:
  11
 Input 2:
  9


 Example Output
 Output 1:
  3
 Output 2:
  3


 Example Explanation
 Explanation 1:
 When A = 11 , square root of A = 3.316. It is not a perfect square so we return the floor which is 3.
 Explanatino 2:
 When A = 9 which is a perfect square of 3, so we return 3.
 */
#include <iostream>
#include <vector>
using namespace std;

int sqrt(int A) {
    if(A==0) return A;
    int l=1,h=A, ans=1;
    long long m=1;
    while(l<=h)
    {
        m = l+(h-l)/2;
        if(m==A/m)
        {
            return m;
        }
        if(m>A/m)
        {
            h=m-1;
        }
        else if(m<A/m)
        {
            ans = m;
            l=m+1;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<"Square root or less floor : "<<sqrt(2147483647)<<endl;
    return 0;
}
