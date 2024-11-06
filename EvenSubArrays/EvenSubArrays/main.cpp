//
//  main.cpp
//  EvenSubArrays
//
//  Created by CodeBreaker on 11/08/1946 Saka.
//
/*
 Even Subarrays
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given an integer array A.
 Decide whether it is possible to divide the array into one or more subarrays of even length such that the first and last element of all subarrays will be even.
 Return "YES" if it is possible; otherwise, return "NO" (without quotes).


 Problem Constraints
 1 <= |A|, A[i] <= 106


 Input Format
 The first and the only input argument is an integer array, A.


 Output Format
 Return a string "YES" or "NO" denoting the answer.


 Example Input
 Input 1:
  A = [2, 4, 8, 6]
 Input 2:
  A = [2, 4, 8, 7, 6]


 Example Output
 Output 1:
  "YES"
 Output 2:
  "NO"


 Example Explanation
 Explanation 1:
  We can divide A into [2, 4] and [8, 6].
 Explanation 2:
  There is no way to divide the array into even length subarrays.
 */
#include <iostream>
#include<vector>

using namespace std;

string solve(vector<int> &A) {
    string ans="NO";
    int N=A.size();
    if(N%2==0 && A[0]%2==0 && A[N-1]%2==0) return "YES";
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Even SubbArrays!\n";
    vector<int> v{2,4,6,8};
    cout<<"even array "<<solve(v)<<endl;
    return 0;
}
