# N-Queens Problem

This directory contains C++ solutions to the classic N-Queens puzzle.

## Problem Statement

The N-Queens puzzle is the problem of placing N chess queens on an N×N chessboard so that no two queens threaten each other. Thus, a solution requires that no two queens share the same row, column, or diagonal.

## Approach

The solutions are implemented using a **recursive backtracking** algorithm. The core idea is to place queens column by column, from left to right. For each column, we iterate through all rows and try to place a queen. If a placement is "safe" (i.e., not under attack from previously placed queens), we proceed to the next column by making a recursive call. If the recursive call fails to find a solution, we "backtrack" by removing the queen and trying the next row in the current column.

This directory includes two implementations with different strategies for the safety check:

1.  **`solveNQueens` (O(N) check)**: A straightforward implementation where the `isSafe` function checks for conflicts by iterating through the board's rows and diagonals. This check takes `O(N)` time for each potential placement.

2.  **`solveNQueens_optimized` (O(1) check)**: A more performant version. Instead of scanning the board, this approach uses boolean arrays to "hash" or mark which rows and diagonals are occupied. This allows the safety check to be performed in `O(1)` time. The hashing mechanism is explained in detail in the source code's architectural comments.

## Code Structure

-   `nq.cpp`: The C++ source file containing both implementations.
-   `makefile`: A standard makefile for compiling and running the code.

Key functions in `nq.cpp`:
-   `solveNQueens(...)`: The original recursive solution with an O(N) safety check.
-   `solveNQueens_optimized(...)`: The wrapper for the optimized solution.
-   `solveNQueens_optimized_util(...)`: The recursive helper for the optimized solution that performs an O(1) safety check using lookup tables.

## How to Compile and Run

A `makefile` is provided for convenience.

-   To compile the program, run:
    ```bash
    make
    ```
    This will create an executable named `nqueen.out`.

-   To run the program:
    ```bash
    make run
    ```

-   To clean up build artifacts:
    ```bash
    make clean
    ```

## Complexity Analysis

-   **Time Complexity**: `O(N!)`. While the algorithm explores a large search space, backtracking prunes many branches. The number of valid solutions is the dominant factor. The O(1) optimization for the safety check provides a significant constant-factor speedup but does not change the overall factorial nature of the problem's complexity.
-   **Space Complexity**: `O(N^2)`.
    -   `O(N^2)` is required for storing the chessboard.
    -   `O(N)` is used by the recursion call stack.
    -   The optimized solution uses an additional `O(N)` space for the hashing/lookup arrays.
