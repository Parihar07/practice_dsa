//
//  main.cpp
//  matrix_row_col_zero
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Row to Column Zero
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a 2D integer matrix A, make all the elements in a row or column zero if the A[i][j] = 0. Specifically, make entire ith row and jth column zero.


 Problem Constraints
 1 <= A.size() <= 103
 1 <= A[i].size() <= 103
 0 <= A[i][j] <= 103


 Input Format
 First argument is a 2D integer matrix A.


 Output Format
 Return a 2D matrix after doing required operations.


 Example Input
 Input 1:
 [1,2,3,4]
 [5,6,7,0]
 [9,2,0,4]


 Example Output
 Output 1:
 [1,2,0,0]
 [0,0,0,0]
 [0,0,0,0]


 Example Explanation
 Explanation 1:
 A[2][4] = A[3][3] = 0, so make 2nd row, 3rd row, 3rd column and 4th column zero.
 */
#include <iostream>
#include<vector>
using namespace std;

vector<vector<int> > solveOpt(vector<vector<int> > &A) {
    size_t M=A.size(),N=A[0].size();
    vector<vector<int>> ans(M,vector<int>(N,0));
    vector<int> R(M,1), C(N,1);
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            if(A[r][c]==0)
            {
                R[r]=0; C[c]=0;
            }
        }
    }
    
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            ans[r][c]=A[r][c]*R[r]*C[c];
        }
    }
    
    return ans;
}
vector<vector<int> > solve(vector<vector<int> > &A) {
    size_t M=A.size(),N=A[0].size();
    vector<vector<int>> ans(M,vector<int>(N,0));
    ans=A;
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
//            ans[r][c]=A[r][c];
            if(A[r][c]==0)
            {
                int k=0;
                while(k<M || k<N)
                {
                    if(k<N)  ans[r][k]*=0;
                    if(k<M) ans[k][c]*=0;
                    k++;
                }
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, row and column to zero!\n";
    vector<vector<int>> A{{1,2,3,4},{4,5,6,0},{7,8,0,9}};
//    vector<vector<int>> A{{1,1},{0,1}};
vector<vector<int> >ans = solveOpt(A);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r][c] << " ";
        }
        cout<<endl;
    }
    return 0;
}
