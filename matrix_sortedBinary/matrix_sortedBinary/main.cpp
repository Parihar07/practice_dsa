//
//  main.cpp
//  matrix_sortedBinary
//
//  Created by CodeBreaker on 02/01/25.
//
/*
 Row with maximum number of ones
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a binary sorted matrix A of size N x N. Find the row with the maximum number of 1.
 NOTE:
 If two rows have the maximum number of 1 then return the row which has a lower index.
 Rows are numbered from top to bottom and columns are numbered from left to right.
 Assume 0-based indexing.
 Assume each row to be sorted by values.
 Expected time complexity is O(rows + columns).


 Problem Constraints
 1 <= N <= 1000
 0 <= A[i] <= 1


 Input Format
 The only argument given is the integer matrix A.


 Output Format
 Return the row with the maximum number of 1.


 Example Input
 Input 1:
  A = [   [0, 1, 1]
          [0, 0, 1]
          [0, 1, 1]   ]
 Input 2:
  A = [   [0, 0, 0, 0]
          [0, 0, 0, 1]
          [0, 0, 1, 1]
          [0, 1, 1, 1]    ]


 Example Output
 Output 1:
  0
 Output 2:
  3


 Example Explanation
 Explanation 1:
  Row 0 has maximum number of 1s.
 Explanation 2:
  Row 3 has maximum number of 1s.
 */
#include <iostream>
#include<vector>
using namespace std;

int solve(vector<vector<int> > &A) {
    int ans=0;
    size_t row= A.size(), col = A[0].size();
    int r=0,c=(int)col-1;
    while(r<row && c>=0)
    {
        if(A[r][c]==1)
        {
            c--;ans=r;
        } else {
            r++;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Soreted matrix binary return row!\n";
    vector<vector<int>> A{{0,0,0,1,1},{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,1,1,1,1}};
    cout<<"row wit max ones : "<<solve(A)<<endl;
    return 0;
}
