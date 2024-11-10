//
//  main.cpp
//  matrix_rotate
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Rotate Matrix
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a n x n 2D matrix A representing an image.
 Rotate the image by 90 degrees (clockwise).
 You need to do this in place.
 Note: If you end up using an additional array, you will only receive partial score.


 Problem Constraints
 1 <= n <= 1000


 Input Format
 First argument is a 2D matrix A of integers


 Output Format
 Return the 2D rotated matrix.


 Example Input
 Input 1:
  [
     [1, 2],
     [3, 4]
  ]
 Input 2:
  [
     [1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]
  ]


 Example Output
 Output 1:
  [
     [3, 1],
     [4, 2]
  ]
 Output 2:
  [
     [7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]
  ]


 Example Explanation
 Explanation 1:
  After rotating the matrix by 90 degree:
  1 goes to 2, 2 goes to 4
  4 goes to 3, 3 goes to 1
 Explanation 2:
  After rotating the matrix by 90 degree:
  1 goes to 3, 3 goes to 9
  2 goes to 6, 6 goes to 8
  9 goes to 7, 7 goes to 1
  8 goes to 4, 4 goes to 2
 */
#include <iostream>
#include<vector>
using namespace std;
void solve(vector<vector<int> > &A) {
    int M=A.size(), N=A[0].size();
    vector<vector<int>> ans(N,vector<int>(M,0));
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            ans[c][r]=A[r][c];
        }
    }
    
    for(int r=0;r<N;r++)
    {
        int t=M-1;
        for(int c=0;c<t;c++)
        {
            int v = ans[r][c];
            ans[r][c]=ans[r][t];
            ans[r][t]=v;
            t--;
        }
    }
    
    A=ans;
    
    return;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, matrix rotation!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
//    vector<vector<int>> ans =
    solve(A);
    cout<< "\n---------------------------\n";
    for (int r=0; r<A.size(); r++) {
        for (int c=0; c<A[0].size(); c++) {
            cout<<A[r][c] << " ";
        }
        cout<<endl;
    }
    return 0;
}
