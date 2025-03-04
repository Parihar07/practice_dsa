//
//  main.cpp
//  graphs_rottenorange
//
//  Created by CodeBreaker on 28/02/25.
//
/*
 Rotten Oranges
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 Given a matrix of integers A of size N x M consisting of 0, 1 or 2.
 Each cell can have three values:
 The value 0 representing an empty cell.
 The value 1 representing a fresh orange.
 The value 2 representing a rotten orange.
 Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.
 Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.


 Problem Constraints
 1 <= N, M <= 1000
 0 <= A[i][j] <= 2


 Input Format
 The first argument given is the integer matrix A.


 Output Format
 Return the minimum number of minutes that must elapse until no cell has a fresh orange.
 If this is impossible, return -1 instead.


 Example Input
 Input 1:
 A = [   [2, 1, 1]
         [1, 1, 0]
         [0, 1, 1]   ]
 Input 2:
  
 A = [   [2, 1, 1]
         [0, 1, 1]
         [1, 0, 1]   ]


 Example Output
 Output 1:
  4
 Output 2:
  -1


 Example Explanation
 Explanation 1:
 Minute 0: [ [2, 1, 1]
             [1, 1, 0]
             [0, 1, 1] ]
 Minute 1: [ [2, 2, 1]
             [2, 1, 0]
             [0, 1, 1] ]
 Minute 2: [ [2, 2, 2]
             [2, 2, 0]
             [0, 1, 1] ]
 Minute 3: [ [2, 2, 2]
             [2, 2, 0]
             [0, 2, 1] ]
 Minute 4: [ [2, 2, 2]
             [2, 2, 0]
             [0, 2, 2] ]
 At Minute 4, all the oranges are rotten.
 Explanation 2:
 The fresh orange at 2nd row and 0th column cannot be rotten, So return -1.
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(vector<vector<int> > &A) {
    auto R = A.size();
    auto C = A[0].size();
    auto q = queue<pair<int, int>>();
    for(auto i=0;i<R;i++)
    {
        for(auto j=0;j<C;j++)
        {
            if(A[i][j]==2)
            {
                q.push({i,j});
            }
        }
    }
    int time=0;
    while(!q.empty())
    {
        auto n = q.size();
        time++;
        for(int i=0;i<n;i++)
        {
            
            auto t = q.front();q.pop();
            auto r = t.first;
            auto c = t.second;
            if(r-1>=0 && A[r-1][c]==1) {
                A[r-1][c]=2;
                q.push({r-1,c});
                
            }
            if(r+1<R && A[r+1][c]==1) {
                A[r+1][c]=2;
                q.push({r+1,c});
            }
            if(c-1>=0 && A[r][c-1]==1) {
                A[r][c-1]=2;
                q.push({r,c-1});
            }
            if(c+1<C && A[r][c+1]==1){
                A[r][c+1]=2;
                q.push({r,c+1});
            }
        }
    }
    
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(A[i][j]==1) return -1;
        }
    }
    
    return time-1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Rotten oranges ..!\n";
//    vector<vector<int>> A{{1,0,1,2,1},{1,1,1,1,1},{0,2,0,1,0},{0,1,1,1,1},{1,1,1,2,1}};
    vector<vector<int>> A{{2,1,1},{1,1,0},{0,1,1}};
    cout<<"time taken to spoil oranges is : "<<solve(A)<<endl;
    return 0;
}
