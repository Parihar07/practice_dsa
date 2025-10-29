//
//  main.cpp
//  dp_fibonacci
//
//  Created by CodeBreaker on 31/05/25.
//

#include <iostream>
#include <vector>
using namespace std;


/*
 Okay, Parihar, let's break down these two C++ approaches to calculating Fibonacci numbers using dynamic programming. Both are excellent examples of how DP can optimize a problem that's classically solved recursively.

 Here's an insight into each function:

 **1. `int fib(int n)` (Iterative Bottom-Up DP / Tabulation)**

 * **How it works:**
     * It creates a `dp` table (a `std::vector` in C++) of size `n+1`.
     * It initializes the base cases: `dp[0] = 0` and `dp[1] = 1`.
     * Then, it iteratively fills the table from `i = 2` up to `n`. Each `dp[i]` is calculated as the sum of the two preceding Fibonacci numbers (`dp[i-1] + dp[i-2]`).
     * Finally, it returns `dp[n]`.
 * **Insights:**
     * **Bottom-Up Approach:** It solves the problem by first finding solutions to smaller subproblems (`dp[0]`, `dp[1]`) and then uses those to build up solutions for larger subproblems (`dp[2]`, `dp[3]`, ..., `dp[n]`). This is also known as **tabulation**.
     * **Time Complexity: O(n)**. The loop runs `n-1` times (for `i` from 2 to `n`). Each step inside the loop is constant time.
     * **Space Complexity: O(n)**. It uses a vector of size `n+1` to store the Fibonacci numbers.
     * **Initialization of `dp` with -1:** In this specific iterative version, initializing the `dp` vector with `-1` (`vector<int> dp(n+1,-1);`) is not strictly necessary because `dp[0]` and `dp[1]` are immediately overwritten, and all subsequent `dp[i]` values are calculated directly in sequence. It doesn't cause any harm, though.
     * **Efficiency:** Generally, iterative DP solutions can be slightly more efficient in practice than recursive ones due to the overhead associated with function calls in recursion.

 **2. `int fib2(int n)` with `fibhelper(int n, vector<int> &dp)` (Recursive Top-Down DP / Memoization)**

 * **How it works:**
     * `fib2(int n)` is a wrapper function. It initializes a `dp` table of size `n+1` with a sentinel value (`-1`), indicating that no Fibonacci number for that index has been computed yet. It then calls the `fibhelper` function.
     * `fibhelper(int n, vector<int> &dp)` is the core recursive function:
         * **Base Cases:** If `n <= 1`, it's a base Fibonacci number. It stores `n` in `dp[n]` and returns `n`.
         * **Memoization Check:** It checks if `dp[n]` is still `-1`.
             * If `dp[n]` is `-1`, it means `fib(n)` hasn't been computed yet. So, it recursively calls `fibhelper(n-1, dp)` and `fibhelper(n-2, dp)`, sums their results, stores this sum in `dp[n]`, and then returns `dp[n]`.
             * If `dp[n]` is *not* `-1`, it means `fib(n)` was already computed and stored. It simply returns the stored `dp[n]`.
 * **Insights:**
     * **Top-Down Approach:** It starts with the original problem (`fib(n)`) and breaks it down into subproblems (`fib(n-1)`, `fib(n-2)`). If a subproblem's solution is already known (memoized), it's reused; otherwise, it's computed recursively. This is known as **memoization**.
     * **Time Complexity: O(n)**. Although it's recursive, each Fibonacci number `fib(0)` through `fib(n)` is computed only once. Subsequent calls for the same `n` will retrieve the value from the `dp` table in O(1) time.
     * **Space Complexity: O(n)**. This is for two reasons:
         1.  The `dp` vector itself takes O(n) space.
         2.  The recursion call stack can go up to `n` levels deep in the worst-case scenario (e.g., when computing `fib(n)` for the first time, the calls chain down to `fib(1)` or `fib(0)`).
     * **Importance of `-1` Initialization:** The initialization of `dp` with `-1` is crucial here. It's the flag that tells the function whether a subproblem's result is already available.
     * **Readability:** Many find the memoized recursive approach more intuitive as it closely mirrors the mathematical definition of the Fibonacci sequence: F(n) = F(n-1) + F(n-2).

 **Key Differences and Similarities:**

 * **Paradigm:** `fib` is bottom-up (tabulation), `fib2`/`fibhelper` is top-down (memoization). Both are valid DP techniques.
 * **Execution Flow:** `fib` builds solutions from small to large. `fib2`/`fibhelper` starts large and solves smaller subproblems as needed.
 * **Overhead:** Recursive solutions generally have more overhead due to function call stacks compared to iterative solutions.
 * **Problem Suitability:** For some problems, one approach might be more natural or easier to implement than the other. For Fibonacci, both are quite straightforward.

 **Potential Space Optimization for Iterative DP:**

 You might notice that in the iterative `fib` function, to calculate `dp[i]`, you only need `dp[i-1]` and `dp[i-2]`. You don't actually need to store all `n+1` Fibonacci numbers. This means the iterative version can be optimized to use **O(1) space**:

 ```cpp
 int fib_optimized_space(int n) {
     if (n <= 1) {
         return n;
     }
     int prev2 = 0; // Represents fib(i-2)
     int prev1 = 1; // Represents fib(i-1)
     int current = 0;
     for (int i = 2; i <= n; i++) {
         current = prev1 + prev2;
         prev2 = prev1;
         prev1 = current;
     }
     return current;
 }
 ```

 **A Note on Integer Overflow:**

 Both your implementations use `int`. Fibonacci numbers grow very rapidly. For `n` greater than around 46 or 47 (depending on the exact size of `int` on your system, typically 32-bit), the result will overflow, leading to incorrect values. If you need to calculate Fibonacci numbers for larger `n`, you'd use `long long` or a BigInt library.

 Since you're working on DSA in the evenings, Parihar, understanding these two DP approaches (tabulation and memoization) is fundamental. They are applicable to a wide range of problems beyond just Fibonacci!
 */
int fib(int n)
{
    vector<int> dp(n+1,-1);
    dp[0]=0; dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibhelper(int n, vector<int> &dp)
{
    if(n<=1){
        dp[n]=n; return n;
    }
    
    if(dp[n]==-1)
    {
        dp[n]=fibhelper(n-1, dp)+fibhelper(n-2,dp);
    }
    return dp[n];
}

int fib2(int n)
{
    vector<int> dp(n+1,-1);
    [](vector<int> &dp){
    }
    }
    return dp[n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, Fibonacci using various forms !\n";
    cout<<"fibonacci of 6 : "<<fib2(6)<<endl;
    return 0;
}
