# Generate All Valid Parentheses

## Problem Statement

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed (valid) parentheses.

### Examples

```
Input: n = 1
Output: ["()"]

Input: n = 2
Output: ["(())", "()()"]

Input: n = 3
Output: ["((()))", "(()())", "(())()", "()(())", "()()()"]

Input: n = 4
Output: 14 valid combinations
```

### Constraints
- 1 ≤ n ≤ 8
- Each valid combination has exactly `n` opening brackets and `n` closing brackets

## Approach: Backtracking

The solution uses a backtracking approach with two key rules:

1. **Add opening bracket `(`**: We can add an opening bracket if we still have remaining open brackets to use
2. **Add closing bracket `)`**: We can add a closing bracket ONLY if `close > open` (ensures we don't close a bracket before opening it)

### Algorithm Steps

```
1. Start with an empty string and counts: open = n, close = n
2. Base case: If open == 0 AND close == 0, we've used all brackets → print result
3. Recursive case:
   - If open > 0: Add '(' → recurse → backtrack (pop_back)
   - If close > open: Add ')' → recurse → backtrack (pop_back)
```

### Why `close > open` works?

- `open` = remaining open brackets to add
- `close` = remaining close brackets to add
- If `close > open`, it means we've added more opening brackets than closing brackets so far
- This ensures we never have `)` before its matching `(`

## Catalan Numbers

The number of valid parentheses combinations for `n` pairs follows the **Catalan Number** sequence.

### Definition

The nth Catalan number is:

$$C_n = \frac{1}{n+1}\binom{2n}{n} = \frac{(2n)!}{(n+1)! \cdot n!}$$

### Recurrence Relation

```
C₀ = 1
Cₙ = (2(2n-1))/(n+1) × Cₙ₋₁
```

Or using summation:
```
Cₙ₊₁ = Σ(i=0 to n) Cᵢ × Cₙ₋ᵢ
```

### Catalan Sequence

| n | Cₙ | Valid Parentheses Count |
|---|----|-----------------------|
| 0 | 1  | 1 (empty string)      |
| 1 | 1  | 1                     |
| 2 | 2  | 2                     |
| 3 | 5  | 5                     |
| 4 | 14 | 14                    |
| 5 | 42 | 42                    |
| 6 | 132| 132                   |
| 7 | 429| 429                   |
| 8 | 1430| 1430                 |

### Example Calculation for n=3

Using formula:
```
C₃ = (2×3)! / ((3+1)! × 3!)
   = 6! / (4! × 3!)
   = 720 / (24 × 6)
   = 720 / 144
   = 5
```

Using recurrence:
```
C₀ = 1
C₁ = (2×1)/(1+1) × C₀ = 2/2 × 1 = 1
C₂ = (2×3)/(2+1) × C₁ = 6/3 × 1 = 2
C₃ = (2×5)/(3+1) × C₂ = 10/4 × 2 = 5
```

## Other Applications of Catalan Numbers

1. **Binary Trees**: Number of structurally different binary trees with n nodes
2. **Path Counting**: Number of paths in a grid that don't cross the diagonal
3. **Polygon Triangulation**: Ways to triangulate a convex (n+2)-gon
4. **Stack Sequences**: Valid pop sequences for a given push sequence
5. **Mountain Ranges**: Ways to draw n upstrokes and n downstrokes
6. **Dyck Words**: Number of strings with n X's and n Y's such that no initial segment has more Y's than X's

## Complexity Analysis

### Time Complexity: O(4ⁿ / √n)

- This is approximately the nth Catalan number
- We generate exactly Cₙ valid combinations
- Each combination takes O(n) time to build and print
- Total: O(n × Cₙ) ≈ O(4ⁿ / √n)

### Space Complexity: O(n)

- **Recursion call stack**: Maximum depth is 2n (n opening + n closing)
- **Output string**: Maximum length is 2n
- We don't store all combinations (only print them)
- Total space: O(n)

## Code Structure

```cpp
void printValidParenthesis(string &op, int open, int close)
{
    // Base case: all brackets used
    if (open == 0 && close == 0) {
        cout << op << endl;
        return;
    }
    
    // Add opening bracket if available
    if (open > 0) {
        op.push_back('(');
        printValidParenthesis(op, open - 1, close);
        op.pop_back();  // backtrack
    }
    
    // Add closing bracket if valid
    if (close > 0 && close > open) {
        op.push_back(')');
        printValidParenthesis(op, open, close - 1);
        op.pop_back();  // backtrack
    }
}
```

## Key Insights

1. **Pass by reference (`string &op`)**: Avoids O(n) copy overhead on each recursive call
2. **Backtracking with `pop_back()`**: Restores state after exploring each branch
3. **Condition `close > open`**: The key constraint that ensures validity
4. **No storage needed**: We print directly, keeping space complexity at O(n)

## Building and Running

```bash
# Compile
make

# Run
make run

# Clean
make clean
```

## Example Output

```
Test 3: n = 3 (Expected: 5 combinations)
((()))
(()())
(())()
()(())
()()()
```

All 5 combinations are valid and unique! ✓
