//
//  main.cpp
//  bm_countSetBits
//
//  Created by CodeBreaker on 25/08/1946 Saka.
//
/*
 Number of 1 Bits
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Write a function that takes an integer and returns the number of 1 bits present in its binary representation.


 Problem Constraints
 1 <= A <= 109


 Input Format
 First and only argument contains integer A


 Output Format
 Return an integer


 Example Input
 Input 1:
 11
 Input 2:
 6


 Example Output
 Output 1:
 3
 Output 2:
 2


 Example Explanation
 Explaination 1:
 11 is represented as 1011 in binary.
 Explaination 2:
 6 is represented as 110 in binary.
 */
#include <iostream>
using namespace std;
int numSetBits(int A) {
    int ans=0;
//    for(int i=31;i>=0;i--)
//    {
//        ans+=((A&(1<<i))?1:0);
//    }
    while(A)
    {
        ans+=A&1;
        A>>=1; // A = A>>1
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Count set bits!\n";
    cout<<"-------------\n";
    cout<<"set bits : "<<numSetBits(27)<<endl;
    return 0;
}
