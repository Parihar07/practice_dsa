//
//  main.cpp
//  graph_shortDistancePath
//
//  Created by CodeBreaker on 09/03/25.
//
/*
 Distance of nearest cell
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a matrix of integers A of size N x M consisting of 0 or 1.
 For each cell of the matrix find the distance of nearest 1 in the matrix.
 Distance between two cells (x1, y1) and (x2, y2) is defined as |x1 - x2| + |y1 - y2|.
 Find and return a matrix B of size N x M which defines for each cell in A distance of nearest 1 in the matrix A.
 NOTE: There is atleast one 1 is present in the matrix.


 Problem Constraints
 1 <= N, M <= 1000
 0 <= A[i][j] <= 1


 Input Format
 The first argument given is the integer matrix A.


 Output Format
 Return the matrix B.


 Example Input
 Input 1:
  A = [
        [0, 0, 0, 1]
        [0, 0, 1, 1]
        [0, 1, 1, 0]
      ]
 Input 2:
  A = [
        [1, 0, 0]
        [0, 0, 0]
        [0, 0, 0]
      ]


 Example Output
 Output 1:
  [
    [3, 2, 1, 0]
    [2, 1, 0, 0]
    [1, 0, 0, 1]
  ]
 Output 2:
  [
    [0, 1, 2]
    [1, 2, 3]
    [2, 3, 4]
  ]


 Example Explanation
 Explanation 1:
  A[0][0], A[0][1], A[0][2] will be nearest to A[0][3].
  A[1][0], A[1][1] will be nearest to A[1][2].
  A[2][0] will be nearest to A[2][1] and A[2][3] will be nearest to A[2][2].
 Explanation 2:
  There is only a single 1. Fill the distance from that 1.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > solve(vector<vector<int> > &A) {
    auto R = A.size(), C = A[0].size();
    auto q = queue<pair<int,int>>();
    vector<vector<int>> ans(R,vector<int>(C,INT_MAX));
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(A[i][j]==1){
                q.push({i,j});
                ans[i][j]=0;
            }
        }
    }
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty())
    {
        auto [x,y] =  q.front(); q.pop();
        
        for(auto [dx,dy] : directions)
        {
            int nx = x+dx, ny = y+dy;
            if(nx>=0 && nx<R && ny>=0 && ny<C)
            {
                if (ans[nx][ny] > ans[x][y] + 1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, hsortest distance form the given !\n";
    vector<vector<int>> A{{1,0,0},{0,1,0},{0,0,1}};
    auto ans = solve(A);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
