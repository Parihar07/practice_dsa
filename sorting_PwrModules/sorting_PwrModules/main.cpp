//
//  main.cpp
//  sorting_PwrModules
//
//  Created by CodeBreaker on 26/11/24.
//
/*
 Power with Modules
 Attempted
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given A, B and C .
 Calculate the value of (A ^ B) % C


 Problem Constraints
 1 <= A <= 109
 0 <= B <= 105
 1 <= C <= 109


 Input Format
 Given three integers A, B and C.


 Output Format
 Return an integer.


 Example Input
 Input 1:
 A = 2
 B = 3
 C = 3
 Input 2:
 A = 5
 B = 2
 C = 4


 Example Output
 Output 1:
 2
 Output 2:
 1
 */

#include <iostream>
using namespace std;

int solve(int A, int B, int C) {
    long ans=1;
    for(int i=0;i<B;i++)
    {
        ans= (ans % C) * A;
    }
    return ans%C;
}

int main(int argc, const char * argv[]) {
    // insert code here... Calculate the value of (A ^ B) % C
    
    std::cout << "Hello, Poer Modulus!\n";
    cout<<"--------------------------------\n";
    cout<<"Power Modules : "<< solve(76277, 376, 2417)<<endl;
    return 0;
}
