//
//  main.cpp
//  dp_totalways_matrix
//
//  Created by CodeBreaker on 17/06/25.
//
/*
 find the total number of ways(distinct paths) to traverse a grid from the top-left corner (0,0) to the bottom-right corner (N-1, M-1). You are only allowed to move down or right at each step.
 */
#include <iostream>
#include <vector>
using namespace std;

int totalWays(int sum, int r, int c, int rows , int cols)
{
//    int sum=0;
    //To handle the out grid or boundaries of matrix
    if(r>rows || c>cols){
        return 0;
    }
    //if the current cell is the bottom-right corner (destination), we have found one valid path, so we return 1.
    if(r == rows && c == cols){
        return 1;
    }
    
    sum = totalWays(sum, r+1, c, rows, cols) + totalWays(sum, r, c+1, rows, cols);
    return sum;
}
/*
 Solving same with Dynamic programing and memoization
 - DP state dp[i][j] -> this give distance form (0,0) to (i,j)
 - DP expression in the case to reach bottom right i can one row at a time so row +1 and col+1 tp total ways is if 1 is distace from (0,0) to (1 ,0) and (0,1) and rest be x, y then x+y is total ways hence dp[i+1][j] + dp[i][j+1]
 - Final ans will be find in dp[r][c] that is total dp size dp[rows][cols]
 - TC - DP states (rows * cols) * O(1) time taken to solve each state hence
 */

int totalways_dp(vector<vector<int>> &dp, int i, int j)
{
    if(i>=dp.size() || j>=dp[0].size())
    {
        return 0;
    }
    if(i==dp.size()-1 && j==dp[0].size()-1) return 1;
    //To reach the current cell (i, j), we could have come from either the cell above it (i-1, j) or the cell to its left (i, j-1). However, the code is written to calculate the number of ways from the current cell (i, j) to the bottom-right. Therefore, the expression calculates the number of ways by considering the next possible moves: going down to (i+1, j) or going right to (i, j+1). The total number of ways from the current cell is the sum of the ways from these two next possible cells.
    if(dp[i][j]==-1)
    {
        dp[i][j] = totalways_dp(dp, i+1, j) + totalways_dp(dp, i, j+1);
    }
    return dp[i][j];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, total way to traverse form [0,0] to [N,M]!\n";
    vector<vector<int>> dp(3,vector<int>(3,-1));
    cout<<"total ways to traverse 3X3 matrix : " << totalways_dp(dp, 0, 0)<<endl;
    return 0;
}
