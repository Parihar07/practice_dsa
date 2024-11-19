//
//  main.cpp
//  ma_A_B_Modulo
//
//  Created by CodeBreaker on 27/08/1946 Saka.
//
/*A, B and Modulo
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given two integers A and B, find the greatest possible positive integer M, such that A % M = B % M.


 Problem Constraints
 1 <= A, B <= 109
 A != B


 Input Format
 The first argument is an integer A.
 The second argument is an integer B.


 Output Format
 Return an integer denoting the greatest possible positive M.


 Example Input
 Input 1:
 A = 1
 B = 2
 Input 2:
 A = 5
 B = 10


 Example Output
 Output 1:
 1
 Output 2:
 5


 Example Explanation
 Explanation 1:
 1 is the largest value of M such that A % M == B % M.
 Explanation 2:
 For M = 5, A % M = 0 and B % M = 0.

 No value greater than M = 5, satisfies the condition.
 */


#include <iostream>
using  namespace std;

int solve(int A, int B) {
    return abs(B-A);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, A B Modulo!\n";
    cout<<"----------------\n";
    cout<<"Greated divisor of A and B : "<<solve(23, 53)cout<<endl;;
    return 0;
}
