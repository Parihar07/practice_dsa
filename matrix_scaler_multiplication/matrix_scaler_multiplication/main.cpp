//
//  main.cpp
//  matrix_scaler_multiplication
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Matrix Scalar Product
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a matrix A and and an integer B, you have to perform scalar multiplication of matrix A with an integer B.


 Problem Constraints
 1 <= A.size() <= 1000
 1 <= A[i].size() <= 1000
 1 <= A[i][j] <= 1000
 1 <= B <= 1000


 Input Format
 First argument is 2D array of integers A representing matrix.
 Second argument is an integer B.


 Output Format
 You have to return a 2D array of integers after doing required operations.


 Example Input
 Input 1:
 A = [[1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
 B = 2
 Input 2:
 A = [[1]]
 B = 5


 Example Output
 Output 1:
 [[2, 4, 6],
 [8, 10, 12],
 [14, 16, 18]]
 Output 2:
 [[5]]


 Example Explanation
 Explanation 1:
 ==> ( [[1, 2, 3],[4, 5, 6],[7, 8, 9]] ) * 2

 ==> [[2*1, 2*2, 2*3],
      [2*4, 2*5, 2*6],
      [2*7, 2*8, 2*9]]

 ==> [[2,   4,  6],
      [8,  10, 12],
      [14, 16, 18]]
 Explanation 2:
 ==> ( [[1]] ) * 5

 ==> [[5*1]]

 ==> [[5]]
 */
#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > solve(vector<vector<int> > &A, int B) {
    size_t M=A.size(), N=A[0].size();
    vector<vector<int>> ans(M, vector<int>(N));
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            ans[r][c]=B*A[r][c];
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Matrix scler multiplication!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> ans = solve(A,2);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r][c] << " ";
        }
        cout<<endl;
    }
    return 0;
}
