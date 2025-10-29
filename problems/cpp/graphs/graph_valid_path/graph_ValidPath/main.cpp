//
//  main.cpp
//  graph_ValidPath
//
//  Created by CodeBreaker on 02/03/25.
//
/*
 Valid Path
 Unsolved
 feature icon
 Using hints except Complete Solution is Penalty free now
 Use Hint
 Problem Description
 There is a rectangle with left bottom as (0, 0) and right up as (x, y).
 There are N circles such that their centers are inside the rectangle.
 Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.
 Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.


 Problem Constraints
 0 <= x , y, R <= 100
 1 <= N <= 1000
 Center of each circle would lie within the grid


 Input Format
 1st argument given is an Integer x , denoted by A in input.
 2nd argument given is an Integer y, denoted by B in input.
 3rd argument given is an Integer N, number of circles, denoted by C in input.
 4th argument given is an Integer R, radius of each circle, denoted by D in input.
 5th argument given is an Array A of size N, denoted by E in input, where A[i] = x cordinate of ith circle
 6th argument given is an Array B of size N, denoted by F in input, where B[i] = y cordinate of ith circle


 Output Format
 Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).


 Example Input
 Input 1:
  x = 2
  y = 3
  N = 1
  R = 1
  A = [2]
  B = [3]
 Input 2:
  x = 3
  y = 3
  N = 1
  R = 1
  A = [0]
  B = [3]


 Example Output
 Output 1:
  NO
 Output 2:
  YES


 Example Explanation
 Explanation 1:
  There is NO valid path in this case
 Explanation 2:
  There is many valid paths in this case.
  One of the path is (0, 0) -> (1, 0) -> (2, 0) -> (3, 0) -> (3, 1) -> (3, 2) -> (3, 3).
 */
#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>> &m, int i, int j)
{
    if(i<0||j<0||i>=m.size()||j>=m[0].size()) return;
    if(m[i][j]==1) return;
    m[i][j]=2;
    dfs(m,i+1,j); dfs(m,i-1,j); // up down
    dfs(m,i,j+1); dfs(m,i,j-1); // front rear
    dfs(m,i+1,j+1); dfs(m,i-1,j-1); //crosswards
    dfs(m,i-1,j+1); dfs(m,i+1,j-1); // across ward
}
string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    //create adjacency matrix
    vector<vector<int>> m(A+1,vector<int>(B+1));
    for(int i=0; i<=A; i++) {
            for(int j=0; j<=B; j++) {
                for(int k=0; k<C; k++) {
                    // Check if point (i,j) lies in circle k
                    int dx = i - E[k];
                    int dy = j - F[k];
                    if(dx*dx + dy*dy <= D*D) {
                        m[i][j] = 1;
                        break;
                    }
                 }
            }
        }
    
    
    dfs(m,0,0);
    
    if(m[A][B]==2)
        return "yes";
    else
        return "no";
}
string solve2(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> m(A+1, vector<int>(B+1, 0));

    // Mark circles
    for(int i=0; i<=A; i++) {
        for(int j=0; j<=B; j++) {
            for(int k=0; k<C; k++) {
                long long dx = i - E[k];
                long long dy = j - F[k];
                if(dx*dx + dy*dy <= (long long)D*D) {
                    m[i][j] = 1;
                    break;
                }
            }
        }
    }

    // If start or end is blocked
    if(m[0][0]==1 || m[A][B]==1) return "NO";

    // BFS instead of DFS
    queue<pair<int,int>> q;
    q.push({0,0});
    m[0][0] = 2;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int nx = x+i, ny = y+j;
                if(nx>=0 && nx<=A && ny>=0 && ny<=B && m[nx][ny]==0) {
                    m[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
        }
    }

    return m[A][B]==2 ? "YES" : "NO";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, valid path in rectanlge with obstacles!\n";
    vector<int> E{1,0,3};
    vector<int> F{3,2,1};
    cout<<"Path found : "<<solve2(4, 4, 3, 1, E, F)<<endl;
    return 0;
}
