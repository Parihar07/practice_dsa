/*
Sudoku Solver (Backtracking)
===========================
Given a partially filled N x N Sudoku grid, fill the empty cells ('.') so that every row, column, and subgrid contains all digits from 1 to N exactly once.

Rules:
- Each row must have the numbers 1 to N with no repeats.
- Each column must have the numbers 1 to N with no repeats.
- Each subgrid (sqrt(N) x sqrt(N)) must have the numbers 1 to N with no repeats.

Input:
- A 9x9 grid (for classic Sudoku) or 4x4 for mini Sudoku, with empty cells as '.'

Output:
- The filled grid, or a message if no solution exists.

Example Input (9x9):
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

Time Complexity: O(9^(N*N)) in the worst case (exponential, as each cell can branch up to 9 ways).
Space Complexity: O(N^2) for the grid and recursion stack.
*/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

// Overloaded version, as passing subgrids avoids recalculating sqrt each time
bool okaytokeep(vector<vector<char>> &grid, int r, int c, int val, int subgrids)
{
    int rows = grid.size(), cols = grid[0].size();
    // Check column
    for (int rr = 0; rr < rows; rr++)
        if ((grid[rr][c] - '0') == val)
            return false;
    // Check row
    for (int cc = 0; cc < cols; cc++)
        if ((grid[r][cc] - '0') == val)
            return false;
    // Check subgrid
    int sr = (r / subgrids) * subgrids;
    int sc = (c / subgrids) * subgrids;
    for (int i = sr; i < sr + subgrids; i++)
        for (int j = sc; j < sc + subgrids; j++)
            if ((grid[i][j] - '0') == val)
                return false;
    return true;
}

bool okaytokeep(vector<vector<char>> &grid, int r, int c, int val)
{
    int rows = grid.size(), cols = grid[0].size();
    // Check column
    for (int rr = 0; rr < rows; rr++)
        if ((grid[rr][c] - '0') == val)
            return false;
    // Check row
    for (int cc = 0; cc < cols; cc++)
        if ((grid[r][cc] - '0') == val)
            return false;
    // Check subgrid
    int subgrids = sqrt(rows);
    int sr = (r / subgrids) * subgrids;
    int sc = (c / subgrids) * subgrids;
    for (int i = sr; i < sr + subgrids; i++)
        for (int j = sc; j < sc + subgrids; j++)
            if ((grid[i][j] - '0') == val)
                return false;
    return true;
}

bool sudokuSolver(vector<vector<char>> &grid)
{
    int rows = grid.size(), cols = grid[0].size();
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == '.')
            {
                for (int v = 1; v <= rows; v++)
                {
                    if (okaytokeep(grid, r, c, v))
                    {
                        grid[r][c] = v + '0';
                        if (sudokuSolver(grid))
                            return true;
                        grid[r][c] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool optSudokuSolver(vector<vector<char>> &grid, int r, int c, int subgrid)
{
    if (r == grid.size())
        return true;
    if (c == grid[0].size()) // this mean cloumn is filled hence we need to go to next row
        return optSudokuSolver(grid, r + 1, 0, subgrid);
    if (grid[r][c] != '.') // if cell already filled, move to next column
        return optSudokuSolver(grid, r, c + 1, subgrid);

    for (int v = 1; v <= 9; v++)
    {
        if (okaytokeep(grid, r, c, v, subgrid))
        {
            grid[r][c] = v + '0';
            if (optSudokuSolver(grid, r, c + 1, subgrid))
                return true;
            grid[r][c] = '.';
        }
    }
    return false;
}

int main()
{
    cout << "Hello this is sudoku solver.\n";

    // vector<vector<char>> grid{{'1', '.', '.', '.'}, {'.', '2', '.', '.'}, {'.', '.', '4', '.'}, {'.', '.', '.', '3'}};
    vector<vector<char>> grid = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for (auto r : grid)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << "\n";
    }

    // sudokuSolver(grid);
    int subgrid = static_cast<int>(sqrt(grid.size()));
    optSudokuSolver(grid, 0, 0, subgrid);

    for (auto r : grid)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << "\n";
    }

    return 0;
}