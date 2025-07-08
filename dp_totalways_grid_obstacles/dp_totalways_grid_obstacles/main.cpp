//
//  main.cpp
//  dp_totalways_grid_obstacles
//
//  Created by CodeBreaker on 18/06/25.
//

#include <iostream>
#include <vector>
using namespace std;

int totalWaysObstacles(vector<vector<int>> &dp, vector<vector<int>> &grid, int i, int j)
{
    if(i>=dp.size() || j>=dp[0].size()) return 0; // handling out of grid
    if(grid[i][j]==0) return 0; //if grid has 0 it means blockage will not proceef further
    if(i==dp.size()-1 && j==dp[0].size()-1) return 1; // once you reach bottom right then it 1 path form above
    if(dp[i][j]==-1) // memoization
    {
        dp[i][j] = totalWaysObstacles(dp, grid, i+1, j)+totalWaysObstacles(dp, grid, i, j+1);
    }
    return dp[i][j];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, total ways to reach (0,0) to bottom right!\n";
    vector<vector<int>> grid{{1,1,1,1},{1,0,1,1},{0,1,1,0},{1,0,1,1},{1,1,1,1}};
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    cout<<"total ways to go form 00 to bottom right : "<<totalWaysObstacles(dp, grid, 0, 0)<<endl;
    return 0;
}
