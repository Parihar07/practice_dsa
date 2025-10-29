//
//  main.cpp
//  matrix_multi
//
//  Created by CodeBreaker on 16/08/1946 Saka.
//
/*
 Matrix Multiplication
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given two integer matrices A(having M X N size) and B(having N X P). You have to multiply matrix A with B and return the resultant matrix. (i.e. return the matrix AB).

 Matrix Multiplication


 Problem Constraints
 1 <= M, N, P <= 100
 -100 <= A[i][j], B[i][j] <= 100


 Input Format
 The first argument given is the 2-D integer matrix A.
 The second argument given is the 2-D integer matrix B.


 Output Format
 Return a 2D integer matrix denoting AB.


 Example Input
 Input 1:
 A = [[1, 2],
      [3, 4]]
 B = [[5, 6],
      [7, 8]]
 Input 2:
 A = [[1, 1]]
 B = [[2],
      [3]]


 Example Output
 Output 1:
  [[19, 22],
   [43, 50]]
 Output 2:
  [[5]]


 Example Explanation
 Explanation 1:
  image
 Explanation 2:
  [[1, 1]].[[2], [3]] = [[1 * 2 + 1 * 3]] = [[5]]
 */
#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    size_t M=A.size();
    size_t N=A[0].size();
    size_t O=B.size();
    size_t P=B[0].size();
    if(N!=O) return vector<vector<int>>();
    vector<vector<int>> ans(M,vector<int>(P,0));
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<P;c++)
        {
            int t=0;
            for(int k=0;k<N;k++)
            {
                t+=A[r][k]*B[k][c];
            }
            ans[r][c]=t;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Matrix Multiplication!\n";
    vector<vector<int>> A{{1,2},{3,4}};
    vector<vector<int>> B{{5,6},{7,8}};
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
