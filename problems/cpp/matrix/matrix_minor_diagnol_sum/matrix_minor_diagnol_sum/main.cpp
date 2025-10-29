//
//  main.cpp
//  matrix_minor_diagnol_sum
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Minor Diagonal Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a N X N integer matrix. You have to find the sum of all the minor diagonal elements of A.
 Minor diagonal of a M X M matrix A is a collection of elements A[i, j] such that i + j = M + 1 (where i, j are 1-based).


 Problem Constraints
 1 <= N <= 103
 -1000 <= A[i][j] <= 1000


 Input Format
 First and only argument is a 2D integer matrix A.


 Output Format
 Return an integer denoting the sum of minor diagonal elements.


 Example Input
 Input 1:
  A = [[1, -2, -3],
       [-4, 5, -6],
       [-7, -8, 9]]
 Input 2:
  A = [[3, 2],
       [2, 3]]


 Example Output
 Output 1:
  -5
 Output 2:
  4


 Example Explanation
 Explanation 1:
  A[1][3] + A[2][2] + A[3][1] = (-3) + 5 + (-7) = -5
 Explanation 2:
  A[1][2] + A[2][1] = 2 + 2 = 4
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(const vector<vector<int> > &A) {
    int ans=0;
    size_t N=A.size();
    int r=0,c=N-1;
    
    while(r<N&&c>=0)
    {
        ans+=A[r][c];
        r++;c--;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Minor diagnol sum!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    cout<< "\n---------------------------\n";
    cout<<"Minor Diagnol Sum : "<<solve(A)<<endl;
    return 0;
}
