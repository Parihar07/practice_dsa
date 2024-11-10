//
//  main.cpp
//  matrix_equal
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Are Matrices Same ?
 Solved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given two matrices A and B of equal dimensions and you have to check whether two matrices are equal or not.

 NOTE: Both matrices are equal if A[i][j] == B[i][j] for all i and j.


 Problem Constraints
 1 <= A.size(), B.size() <= 1000
 1 <= A[i].size(), B[i].size() <= 1000
 1 <= A[i][j], B[i][j] <= 1000
 A.size() == B.size()
 A[i].size() == B[i].size()


 Input Format
 First argument is 2-D array of integers representing matrix A.
 Second argument is 2-D array of integers representing matrix B.


 Output Format
 Return 1 if both matrices are equal or return 0.


 Example Input
 Input 1:
 A = [[1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
 B = [[1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
 Input 2:
 A = [[1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
 B = [[1, 2, 3],
      [7, 8, 9],
      [4, 5, 6]]


 Example Output
 Output 1:
 1
 Output 2:
 0


 Example Explanation
 Explanation 1:
 ==> Clearly all the elements of both matrices are equal at respective positions.
 Explanation 2:
 ==> Clearly, there are mismatches at (1, 0), (1, 1), (1, 2), (2, 0), (2, 1) and (2, 2).
 A = [[1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
 B = [[1, 2, 3],
      [7, 8, 9],
      [4, 5, 6]]
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    size_t M=A.size(), N=A[0].size(), O=B.size(), P=B[0].size();
    if( M!=O || N!=P ) return 0;
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            if(A[r][c]!=B[r][c]) return 0;
        }
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Equal Matrix!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> B{{1,2,3},{4,5,6},{7,8,9}};
    
    cout<< "\n---------------------------\n";
    cout<<"Equal Matrix : "<<solve(A, B)<<endl;
    return 0;
}
