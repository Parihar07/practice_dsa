//
//  main.cpp
//  hash_colorfull
//
//  Created by CodeBreaker on 29/11/24.
//
/*
 Colorful Number
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a number A, find if it is COLORFUL number or not.
 If number A is a COLORFUL number return 1 else, return 0.
 What is a COLORFUL Number:
 A number can be broken into different consecutive sequence of digits.
 The number 3245 can be broken into sequences like 3, 2, 4, 5, 32, 24, 45, 324, 245 and 3245.
 This number is a COLORFUL number, since the product of every consecutive sequence of digits is different


 Problem Constraints
 1 <= A <= 2 * 109


 Input Format
 The first and only argument is an integer A.


 Output Format
 Return 1 if integer A is COLORFUL else return 0.


 Example Input
 Input 1:
  A = 23
 Input 2:
  A = 236


 Example Output
 Output 1:
  1
 Output 2:
  0


 Example Explanation
 Explanation 1:
  Possible Sub-sequences: [2, 3, 23] where
  2 -> 2
  3 -> 3
  23 -> 6  (product of digits)
  This number is a COLORFUL number since product of every digit of a sub-sequence are different.
 Explanation 2:
  Possible Sub-sequences: [2, 3, 6, 23, 36, 236] where
  2 -> 2
  3 -> 3
  6 -> 6
  23 -> 6  (product of digits)
  36 -> 18  (product of digits)
  236 -> 36  (product of digits)
  This number is not a COLORFUL number since the product sequence 23  and sequence 6 is same.
 */
#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int colorful(int A) {
    vector<int> vA(0);
    unordered_set<int> us; //stroing product of element
    int n=A;
    while(n)
    {
        vA.push_back(n%10);
        n/=10;
    }
    size_t N=vA.size();
    
    for(int i=0;i<N;i++)
    {
        int k=1;
        for(int j=i;j<N;j++)
        {
            k*=vA[j];
            if(us.find(k)!=us.end())
            {
                return 0;
            }
            us.insert(k);
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, colorfull number!\n";
    cout<<"--------------\n";
    cout<<"Chceking colorful "<<colorful(236)<<endl;
    return 0;
}
