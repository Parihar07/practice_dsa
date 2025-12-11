# Recursion

Problems exploring recursive thinking, backtracking, and divide-and-conquer approaches.

## Key Concepts Covered
- Base case and recursive case design
- Call stack understanding
- Tail recursion optimization
- Backtracking algorithms
- Divide and conquer
- Memoization (leading to DP)
- Tree recursion vs linear recursion

## Problems in this Directory
- [fibonaci](fibonaci/) - Fibonacci sequence implementation
- [keypad_prob](keypad_prob/) - Print all possible letter combinations for a phone keypad digit string (recursive/backtracking)
- [matrix_traversal](matrix_traversal/) - Find all paths from top-left to bottom-right in a matrix (backtracking)
- [nqueen](nqueen/) - N-Queens problem with backtracking (O(N) and O(1) checks)
- [permutation](permutation/) - Print all permutations of a string (handles duplicates)
- [printallcombi](printallcombi/) - Print all combinations (subsets) of a set (recursive and bitmasking)
- [printeq_a_b](printeq_a_b/) - Print all unique strings with given counts of 'a' and 'b' (multiset permutations)
- [printvalidParanthesis](printvalidParanthesis/) - Generate all valid parentheses combinations (Catalan numbers)
- [rec_SumArray](rec_SumArray/) - Recursive array sum
- [rec_arrayIsSorted](rec_arrayIsSorted/) - Check if array is sorted recursively
- [recursion_fibinacci](recursion_fibinacci/) - Fibonacci sequence
- [recursion_graycode](recursion_graycode/) - Gray code generation
- [recursion_palindrome](recursion_palindrome/) - Check palindrome recursively
- [recursion_pow](recursion_pow/) - Power function (x^n)
- [recursion_string](recursion_string/) - String manipulation with recursion
- [recursion_sum_n](recursion_sum_n/) - Sum of N natural numbers
- [recursion_sumdigits](recursion_sumdigits/) - Sum of digits
- [recursion_sumofdigits](recursion_sumofdigits/) - Sum of digits (alternate)
- [recursion_towerofhanoi](recursion_towerofhanoi/) - Tower of Hanoi puzzle
- [recusrion_factorial](recusrion_factorial/) - Factorial calculation
- [recusrion_fibnaci](recusrion_fibnaci/) - Fibonacci (alternate spelling)
- [recusrion_palindrome](recusrion_palindrome/) - Palindrome check (alternate)
- [recusrion_reverse_str](recusrion_reverse_str/) - Reverse string recursively
- [recusrion_sumdigits](recusrion_sumdigits/) - Sum of digits (third version)
- [rev_array](rev_array/) - Reverse array recursively
- [rmvCharStr](rmvCharStr/) - Remove specific character from string
- [spacePermutation](spacePermutation/) - Print all strings formed by inserting spaces between characters (recursive/backtracking)
- [str_remvRep](str_remvRep/) - Remove consecutive repeated characters from string
- [str_rep_str](str_rep_str/) - Replace substring in string recursively
- [subseq_str](subseq_str/) - Generate all subsequences (3 approaches: vector, return, backtracking)
- [sudoku](sudoku/) - Sudoku solver using recursive backtracking (supports 4x4 and 9x9 grids)
- [wordrbeakproblem](wordrbeakproblem/) - Word break problem using backtracking

## Tips
- Always define a clear base case
- Make sure recursion progresses toward base case
- Watch out for stack overflow with deep recursion
- Consider iterative alternatives for tail-recursive functions
- Pass by const reference for large data structures
