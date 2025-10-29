//
//  main.cpp
//  dp_maxpathMatrix
//
//  Created by CodeBreaker on 14/02/25.
//
/*
 Max path to reach in matrixx
 constraints:
  -> go right
  -> go left below
 */
#include <iostream>
#include <vector>
using namespace std;

int getPathWays(int i, int j, vector<vector<int>> &dp)
{
    if(i<0||j<0) return 0;
    if(i==0 && j==0) return 1;
    
    if(dp[i][j]==-1)
    {
        dp[i][j] = getPathWays(i, j-1, dp) + getPathWays(i-1, j, dp);
    }
    return dp[i][j];
}

int uniquePathsWithOutObstacles(vector<vector<int> > &A) {
    size_t r = A.size(), c = A[0].size();
    vector<vector<int>> dp(r, vector<int>(c, -1));
    getPathWays(2, 2, dp);
    return dp[r-1][c-1];
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Dynamic Programming unique paths in grid!\n";
    vector<vector<int>> A(3,vector<int>(3));
    cout<< " Unique path without obstacles : " << uniquePathsWithOutObstacles(A) <<endl;
    return 0;
}
