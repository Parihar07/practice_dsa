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
- [rec_array](rec_array/) - Recursive array sum
- [recursion_fibinacci](recursion_fibinacci/) - Fibonacci sequence
- [recusrion_factorial](recusrion_factorial/) - Factorial calculation
- [recursion_palindrome](recursion_palindrome/) - Check palindrome recursively
- [recusrion_palindrome](recusrion_palindrome/) - Palindrome check (alternate)
- [recursion_pow](recursion_pow/) - Power function (x^n)
- [recursion_string](recursion_string/) - String manipulation with recursion
- [recursion_sum_n](recursion_sum_n/) - Sum of N natural numbers
- [recursion_sumdigits](recursion_sumdigits/) - Sum of digits
- [recursion_sumofdigits](recursion_sumofdigits/) - Sum of digits (alternate)
- [recusrion_sumdigits](recusrion_sumdigits/) - Sum of digits (third version)
- [recursion_towerofhanoi](recursion_towerofhanoi/) - Tower of Hanoi puzzle
- [recursion_graycode](recursion_graycode/) - Gray code generation
- [recusrion_fibnaci](recusrion_fibnaci/) - Fibonacci (alternate spelling)
- [recusrion_reverse_str](recusrion_reverse_str/) - Reverse string recursively
- [subseq_str](subseq_str/) - Generate all subsequences (3 approaches: vector, return, backtracking)
- [printvalidParanthesis](printvalidParanthesis/) - Generate all valid parentheses combinations (Catalan numbers)
- [printeq_a_b](printeq_a_b/) - Print all unique strings with given counts of 'a' and 'b' (multiset permutations)
- [printallcombi](printallcombi/) - Print all combinations (subsets) of a set (recursive and bitmasking)
- [permutation](permutation/) - Print all permutations of a string (handles duplicates)
- [keypad_prob](keypad_prob/) - Print all possible letter combinations for a phone keypad digit string (recursive/backtracking)

## Tips
- Always define a clear base case
- Make sure recursion progresses toward base case
- Watch out for stack overflow with deep recursion
- Consider iterative alternatives for tail-recursive functions
- Pass by const reference for large data structures
