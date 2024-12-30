//
//  main.cpp
//  matrix_submatrixsumqueries
//
//  Created by CodeBreaker on 25/12/24.
//
/*
 Sub-matrix Sum Queries
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a matrix of integers A of size N x M and multiple queries Q, for each query, find and return the submatrix sum.
 Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix whose sum is to find out.
 NOTE:
 Rows are numbered from top to bottom, and columns are numbered from left to right.
 The sum may be large, so return the answer mod 109 + 7.
 Also, select the data type carefully, if you want to store the addition of some elements.
 Indexing given in B, C, D, and E arrays is 1-based.
 Top Left 0-based index = (B[i] - 1, C[i] - 1)
 Bottom Right 0-based index = (D[i] - 1, E[i] - 1)


 Problem Constraints
 1 <= N, M <= 1000
 -100000 <= A[i] <= 100000
 1 <= Q <= 100000
 1 <= B[i] <= D[i] <= N
 1 <= C[i] <= E[i] <= M


 Input Format
 The first argument given is the integer matrix A.
 The second argument given is the integer array B.
 The third argument given is the integer array C.
 The fourth argument given is the integer array D.
 The fifth argument given is the integer array E.
 (B[i], C[i]) represents the top left corner of the i'th query.
 (D[i], E[i]) represents the bottom right corner of the i'th query.


 Output Format
 Return an integer array containing the submatrix sum for each query.


 Example Input
 Input 1:
  A = [   [1, 2, 3]
          [4, 5, 6]
          [7, 8, 9]   ]
  B = [1, 2]
  C = [1, 2]
  D = [2, 3]
  E = [2, 3]
 Input 2:
  A = [   [5, 17, 100, 11]
          [0, 0,  2,   8]    ]
  B = [1, 1]
  C = [1, 4]
  D = [2, 2]
  E = [2, 4]


 Example Output
 Output 1:
  [12, 28]
 Output 2:
  [22, 19]


 Example Explanation
 Explanation 1:
  For query 1: Submatrix contains elements: 1, 2, 4 and 5. So, their sum is 12.
  For query 2: Submatrix contains elements: 5, 6, 8 and 9. So, their sum is 28.
 Explanation 2:
  For query 1: Submatrix contains elements: 5, 17, 0 and 0. So, their sum is 22.
  For query 2: Submatrix contains elements: 11 and 8. So, their sum is 19.
 */
#include <iostream>
#include<vector>
using namespace std;

vector<int> solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {
    vector<int> ans(B.size());
    size_t row=A.size(),col=A[0].size();
    vector<vector<long>> PFSM(row,vector<long>(col));
    int r=0;
    while(r<row)
    {
        PFSM[r][0]=A[r][0];
        for(int i=1;i<col;i++)
        {
            PFSM[r][i]=PFSM[r][i-1]+A[r][i];
        }
        r++;
    }
    int c=0;
    while(c<col)
    {
        PFSM[0][c] = PFSM[0][c];
        for(int i=1;i<row;i++)
        {
            PFSM[i][c]=PFSM[i-1][c]+PFSM[i][c];
        }
        c++;
    }
    size_t Q=B.size();
    for(int q=0;q<Q;q++)
    {
        int TLx = B[q]-1, TLy = C[q]-1;
        int BRx = D[q]-1, BRy = E[q]-1;
        long sum=0;
        sum = PFSM[BRx][BRy];
        if(TLx!=0 && TLy!=0)
        {
            sum+=PFSM[TLx-1][TLy-1];
        }
        if(TLy!=0)
        {
            sum-=PFSM[BRx][TLy-1];
        }
        if(TLx!=0)
        {
            sum-=PFSM[TLx-1][BRy];
        }// like -a%x = -a?x+x == id(-a%x<0)?-a%x%x+x:a%x;
        ans[q]=((sum%1000000007)<0?(sum%1000000007)+(1000000007):(sum%1000000007));//   this is to handle neagtive out of bound numbers
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, submatir query sum!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
    vector<int> B{1,2};
    vector<int> C{1,2};
    vector<int> D{2,3};
    vector<int> E{2,3};
    vector<int> ans =solve(A, B,C,D,E);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
