//
//  main.cpp
//  matrix_row_sum
//
//  Created by CodeBreaker on 18/08/1946 Saka.
//
/*
 Row Sum
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Constraints
 1 <= A.size() <= 103
 1 <= A[i].size() <= 103
 1 <= A[i][j] <= 103


 Input Format
 First argument A is a 2D array of integers.(2D matrix).


 Output Format
 Return an array containing row-wise sums of original matrix.


 Example Input
 Input 1:
 [1,2,3,4]
 [5,6,7,8]
 [9,2,3,4]


 Example Output
 Output 1:
 [10,26,18]


 Example Explanation
 Explanation 1
 Row 1 = 1+2+3+4 = 10
 Row 2 = 5+6+7+8 = 26
 Row 3 = 9+2+3+4 = 18
 */
#include <iostream>
#include<vector>
using namespace std;
vector<int> solve(vector<vector<int> > &A) {
    size_t M=A.size(), N=A[0].size();
    vector<int> ans(M,0);
    for(int r=0; r<M;r++)
    {
        for(int c=0;c<N;c++)
        {
            ans[r]+=A[r][c];
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, row sum!\n";
    vector<vector<int>> A{{1,2,3},{4,5,6},{7,8,9}};
vector<int> ans = solve(A);
    cout<< "\n---------------------------\n";
    for (int r=0; r<ans.size(); r++) {
//        for (int c=0; c<ans[0].size(); c++) {
            cout<<ans[r] << " ";
        //}
        cout<<endl;
    }
    return 0;
}
