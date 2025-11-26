
#include <iostream>
#include <vector>

// =================================================================================
// Original O(N) check solution
// =================================================================================

// Check if it's safe to place a queen at (row, col)
bool isSafe(const std::vector<std::vector<char>> &board, int row, int col)
{
    int n = board.size();
    // Check this row on left side
    for (int j = 0; j < col; ++j)
    {
        if (board[row][j] == 'Q')
            return false;
    }
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    // Check lower-left diagonal
    for (int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

// Recursive function to solve N-Queen using O(N) check
void solveNQueens(std::vector<std::vector<char>> &board, int col)
{
    int n = board.size();
    if (col == n)
    {
        // Print solution
        for (const auto &row : board)
        {
            for (char cell : row)
            {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "=================\n";
        return;
    }
    for (int row = 0; row < n; ++row)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q';
            solveNQueens(board, col + 1);
            board[row][col] = '.';
        }
    }
}

// =================================================================================
// Optimized O(1) check solution
// =================================================================================

/**
 * @brief System-level view of the O(1) checker.
 *
 * To achieve a constant-time check for queen placement, we use three boolean arrays
 * as hash maps. This avoids iterating through the board on every check.
 *
 * 1. `row_check`: A simple lookup table of size N. `row_check[i] = true` means row `i` is occupied.
 *
 * 2. `upper_diag_check`: For upper-left to lower-right diagonals (`\`), the sum of
 *    indices `(row + col)` is constant. This sum ranges from 0 to `2*N-2`.
 *    We can use this sum as a hash key to identify a specific diagonal.
 *    The size of this array is `2*N - 1`.
 *
 *    Memory Layout (N=4):
 *    (0,0) (0,1) (0,2) (0,3)   -> row+col
 *     0     1     2     3
 *    (1,0) (1,1) (1,2) (1,3)
 *     1     2     3     4
 *    (2,0) (2,1) (2,2) (2,3)
 *     2     3     4     5
 *    (3,0) (3,1) (3,2) (3,3)
 *     3     4     5     6
 *
 * 3. `lower_diag_check`: For lower-left to upper-right diagonals (`/`), the difference
 *    of indices `(col - row)` is constant. To map this to an array index (and avoid
 *    negatives), we offset it by `N-1`. The hash key becomes `(N - 1) + (col - row)`.
 *    This value ranges from 0 to `2*N-2`. The size is `2*N - 1`.
 *
 *    Memory Layout (N=4):
 *    (0,0) (0,1) (0,2) (0,3)   -> (N-1)+(col-row) = 3 + col - row
 *     3     4     5     6
 *    (1,0) (1,1) (1,2) (1,3)
 *     2     3     4     5
 *    (2,0) (2,1) (2,2) (2,3)
 *     1     2     3     4
 *    (3,0) (3,1) (3,2) (3,3)
 *     0     1     2     3
 *
 * By marking/unmarking these arrays, we can check for safety in O(1) time.
 * The recursive calls build up on the CPU stack, and on backtracking, stack frames
 * are unwound, and we reset the boolean flags, effectively unwinding the state.
 */
void solveNQueens_optimized_util(std::vector<std::vector<char>> &board, int col,
                                 std::vector<bool> &row_check,
                                 std::vector<bool> &upper_diag_check,
                                 std::vector<bool> &lower_diag_check)
{
    int n = board.size();
    if (col == n)
    {
        for (const auto &row : board)
        {
            for (char cell : row)
            {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
        std::cout << "=================\n";
        return;
    }

    for (int row = 0; row < n; ++row)
    {
        // O(1) check
        if (!row_check[row] &&
            !upper_diag_check[row + col] &&
            !lower_diag_check[(n - 1) + (col - row)])
        {
            board[row][col] = 'Q';
            row_check[row] = true;
            upper_diag_check[row + col] = true;
            lower_diag_check[(n - 1) + (col - row)] = true;

            solveNQueens_optimized_util(board, col + 1, row_check, upper_diag_check, lower_diag_check);

            // Backtrack
            board[row][col] = '.';
            row_check[row] = false;
            upper_diag_check[row + col] = false;
            lower_diag_check[(n - 1) + (col - row)] = false;
        }
    }
}

void solveNQueens_optimized(int n)
{
    std::vector<std::vector<char>> board(n, std::vector<char>(n, '.'));
    std::vector<bool> row_check(n, false);
    std::vector<bool> upper_diag_check(2 * n - 1, false);
    std::vector<bool> lower_diag_check(2 * n - 1, false);

    solveNQueens_optimized_util(board, 0, row_check, upper_diag_check, lower_diag_check);
}

int main()
{
    int n = 4; // Change n for different board sizes
    std::cout << "Hello. solving N-Queen problem with O(1) check.\n";
    solveNQueens_optimized(n);

    // To run the original O(N) check solution, uncomment the lines below:
    // std::cout << "\nHello. solving N-Queen problem with O(N) check.\n";
    // std::vector<std::vector<char>> board(n, std::vector<char>(n, '.'));
    // solveNQueens(board, 0);

    return 0;
}