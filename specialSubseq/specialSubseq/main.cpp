//
//  main.cpp
//  specialSubseq
//
//  Created by CodeBreaker on 10/08/1946 Saka.
//
/*
 Special Subsequences "AG"
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You have given a string A having Uppercase English letters.
 You have to find how many times subsequence "AG" is there in the given string.
 NOTE: Return the answer modulo 109 + 7 as the answer can be very large.


 Problem Constraints
 1 <= length(A) <= 105


 Input Format
 First and only argument is a string A.


 Output Format
 Return an integer denoting the answer.


 Example Input
 Input 1:
  A = "ABCGAG"
 Input 2:
  A = "GAB"


 Example Output
 Output 1:
  3
 Output 2:
  0


 Example Explanation
 Explanation 1:
  Subsequence "AG" is 3 times in given string
 Explanation 2:
  There is no subsequence "AG" in the given string.
 
 */

#include <iostream>
#include<string>

using namespace std;
int modulo=100000007;
int solveOptimum(string A) {
    int ans=0;
    int N=A.size();
    int cnt=0;
    for(int i=0;i<N;i++)
    {
        if(A[i]=='A')
        {
            cnt+=1;
        }
        else if(A[i]=='G')
        {
            ans+=cnt;
            ans%=modulo;
        }
    }
    return ans;
}

int solve(string A) {
    int ans=0;
    int N=A.size();
    for(int i=0;i<N;i++)
    {
        if(A[i]=='A')
        {
            for(int j=i+1;j<N;j++)
            {
                if(A[j]=='G')
                    ans+=1;
            }
        }
    }
    return modulo%ans;;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Special Subsequence!\n";
    string str = "ABCGAG";
    cout<<"Special SubSeq : " <<solveOptimum(str)<<endl;
    return 0;
}
