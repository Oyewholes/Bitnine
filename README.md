# Bitnine
An Internship question answered here

The provided code implements three different approaches to calculate the Fibonacci sequence based on the given piecewise recurrence relation F(n) = F(n/3)^3 + F(n/2), with initial conditions F(0) = 0, F(1) = 1, and F(2) = 2. Here's a summary of each approach:

1. Recursive Approach:
   - The `fibonacci_recursive` function implements the recurrence relation using recursive calls.
   - It checks the base cases for n = 0, 1, and 2, and recursively calculates F(n) using the given formula.
   - This approach is simple to understand but may have exponential time complexity and redundant computations.

2. Top-Down Dynamic Programming Approach:
   - The `fibonacci_top_down` function implements the recurrence relation using top-down dynamic programming with memoization.
   - It uses an array called `memo` to store and retrieve previously computed values to avoid redundant calculations.
   - Initially, the `memo` array is filled with -1. When computing F(n), the function first checks if it is already calculated and stored in the `memo` array.
   - If the value is not present, it recursively calculates F(n) using the given formula and stores it in the `memo` array for future use.
   - This approach improves efficiency by eliminating redundant computations and has better time complexity than the recursive approach.

3. Bottom-Up Dynamic Programming Approach:
   - The `fibonacci_bottom_up` function implements the recurrence relation using bottom-up dynamic programming.
   - It uses an array called `dp` to store the computed Fibonacci values iteratively.
   - The function starts by initializing `dp[0] = 0`, `dp[1] = 1`, and `dp[2] = 2`, which correspond to the given initial conditions.
   - Then, it iterates from 3 up to n, calculating F(i) using the given formula based on previously computed values in `dp`.
   - This approach avoids recursion and computes the Fibonacci sequence in a bottom-up manner, resulting in efficient computation.

It's important to note that the code assumes a maximum size for the arrays (`MAX_SIZE`), which can be adjusted according to the specific needs of the problem.
