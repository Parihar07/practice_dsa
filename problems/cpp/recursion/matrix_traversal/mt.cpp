/*
Matrix Traversal (All Paths from Top-Left to Bottom-Right)
=========================================================
Given an N x N binary matrix (0s and 1s), print all possible paths from the top-left cell (0,0) to the bottom-right cell (N-1,N-1).
You can move in four directions: up, down, left, right. You may only move to cells with value 1 and cannot visit the same cell twice in a path.

Print each path as a matrix of 0s and 1s, where 1s indicate the path taken.

Example Input:
--------------
mat =
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1

Sample Output (paths as matrices):
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
===============

1 0 0 0
1 1 0 0
0 1 0 0
0 0 0 1
===============

Time Complexity: O(4^(N^2)) in the worst case (exponential, as each cell can branch in 4 directions).
Space Complexity: O(N^2) for the path matrix and recursion stack.

Test Cases:
-----------
1. Input:
    mat = [[1, 0],
             [1, 1]]
    Output:
    1 0
    1 1
    ===============

2. Input:
    mat = [[1, 0, 0],
             [1, 1, 0],
             [0, 1, 1]]
    Output:
    1 0 0
    1 1 0
    0 1 1
    ===============

3. Input:
    mat = [[1, 0],
             [0, 1]]
    Output:
    (no output, as there is no path)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Matrix traversal give starting pint way to reach end

void traverse(vector<vector<int>> &mat, vector<vector<int>> &path, int r, int c)
{
    int n = mat.size(), m = mat[0].size();
    if (r == n - 1 && c == m - 1)
    {
        path[r][c] = 1;
        for (const auto &row : path)
        {
            for (int cell : row)
                cout << cell << " ";
            cout << "\n";
        }
        cout << "===============\n";
        path[r][c] = 0;
        return;
    }
    path[r][c] = 1;
    // down
    if (r + 1 < n && mat[r + 1][c] && !path[r + 1][c])
        traverse(mat, path, r + 1, c);
    // up
    if (r - 1 >= 0 && mat[r - 1][c] && !path[r - 1][c])
        traverse(mat, path, r - 1, c);
    // right
    if (c + 1 < m && mat[r][c + 1] && !path[r][c + 1])
        traverse(mat, path, r, c + 1);
    // left
    if (c - 1 >= 0 && mat[r][c - 1] && !path[r][c - 1])
        traverse(mat, path, r, c - 1);
    path[r][c] = 0;
}

int main()
{
    cout << "Hello recursion matrix traversal.\n";
    vector<vector<int>> mat{{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<int>> path(4, vector<int>(4, 0));
    traverse(mat, path, 0, 0);
    return 0;
}