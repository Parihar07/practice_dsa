//
//  main.cpp
//  matrix_col_sum
//
//  Created by CodeBreaker on 16/08/1946 Saka.
//
/*
 Column Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 You are given a 2D integer matrix A, return a 1D integer array containing column-wise sums of original matrix.


 Problem Constraints
 1 <= A.size() <= 103
 1 <= A[i].size() <= 103
 1 <= A[i][j] <= 103


 Input Format
 First argument is a 2D array of integers.(2D matrix).


 Output Format
 Return an array containing column-wise sums of original matrix.


 Example Input
 Input 1:
 [1,2,3,4]
 [5,6,7,8]
 [9,2,3,4]


 Example Output
 Output 1:
 {15,10,13,16}


 Example Explanation
 Explanation 1
 Column 1 = 1+5+9 = 15
 Column 2 = 2+6+2 = 10
 Column 3 = 3+7+3 = 13
 Column 4 = 4+8+4 = 16
 */
#include <iostream>
#include<vector>

using namespace std;

vector<int> solve(vector<vector<int> > &A) {
    int M=A.size(), N=A[0].size();
    vector<int> ans(N,0);
    for(int r=0;r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            ans[c]+=A[r][c];
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, matrix column sum!\n";
    vector<vector<int>> A{{1,2,3,4},{5,6,7,8},{9,2,3,4}};
    vector<int> ans = solve(A);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
       // for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r] << " ";
        //}
        cout<<endl;
        }
    return 0;
}
