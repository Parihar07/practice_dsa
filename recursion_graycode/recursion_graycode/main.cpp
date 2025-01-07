//
//  main.cpp
//  recursion_graycode
//
//  Created by CodeBreaker on 06/01/25.
//
/*
 Gray Code
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer A representing the total number of bits in the code, print the sequence of gray code.
 A gray code sequence must begin with 0.


 Problem Constraints
 1 <= A <= 16


 Input Format
 The first argument is an integer A.


 Output Format
 Return an array of integers representing the gray code sequence.


 Example Input
 Input 1:
 A = 2
 Input 1:
 A = 1


 Example Output
 output 1:
 [0, 1, 3, 2]
 output 2:
 [0, 1]


 Example Explanation
 Explanation 1:
 for A = 2 the gray code sequence is:
     00 - 0
     01 - 1
     11 - 3
     10 - 2
 So, return [0,1,3,2].
 Explanation 1:
 for A = 1 the gray code sequence is:
     00 - 0
     01 - 1
 So, return [0, 1].
 */
#include <iostream>
#include<vector>
using namespace std;

vector<int> grayCode(int A) {
    vector<int> ans(0);
    if(A==1)
    {
        vector<int> t{0,1};
        return t;
    }
    vector<int> rt = grayCode(A-1);
    size_t N = rt.size();
    
    for(int i=0;i<N;i++)
    {
        ans.push_back(rt[i]);
    }
    
    for(int i=N-1;i>=0;i--)
    {
        int t = rt[i];
        t=t|1<<(A-1);
        ans.push_back(t);
    }
    return ans;;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Gray Code!\n";
    vector<int> ans = grayCode(3);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
