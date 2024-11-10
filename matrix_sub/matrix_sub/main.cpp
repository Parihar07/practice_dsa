//
//  main.cpp
//  matrix_sub
//
//  Created by CodeBreaker on 16/08/1946 Saka.
//
/*
 Matrix Subtraction
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given two integer matrices A and B having same size(Both having same number of rows (N) and columns (M). You have to subtract matrix B from A and return the resultant matrix. (i.e. return the matrix A - B).
 If A and B are two matrices of the same order (same dimensions). Then A - B is a matrix of the same order as A and B and its elements are obtained by doing an element wise subtraction of A from B.

 Problem Constraints
 1 <= N, M <= 103
 -109 <= A[i][j], B[i][j] <= 109


 Input Format
 The first argument is the 2D integer array A
 The second argument is the 2D integer array B


 Output Format
 Return a 2D matrix denoting A - B.


 Example Input
 Input 1:
 A =  [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]

 B =  [[9, 8, 7],
       [6, 5, 4],
       [3, 2, 1]]
 Input 2:
 A = [[1, 1]]
  
 B = [[2, 3]]


 Example Output
 Output 1:
  [[-8, -6, -4],
   [-2, 0, 2],
   [4, 6, 8]]
 Output 2:
  [[-1, -2]]


 Example Explanation
 Explanation 1:
  image
 Explanation 2:
  [[1, 1]] - [[2, 3]] = [[1 - 2, 1 - 3]] = [[-1, -2]]
 */
#include <iostream>
#include<vector>

using namespace std;

vector<vector<int> > solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    int N=A.size(), M=A[0].size();
    vector<vector<int>> ans(N, vector<int>(M,0));
    for(int r=0;r<N;r++)
    {
        for(int c=0;c<M;c++)
        {
            ans[r][c]=A[r][c]-B[r][c];
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Matrix substraction!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> B{{9,8,7},{6,5,4},{3,2,1}};
    vector<vector<int>> ans = solve(A,B);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r][c] << " ";
        }
        cout<<endl;
    }
    return 0;
}
