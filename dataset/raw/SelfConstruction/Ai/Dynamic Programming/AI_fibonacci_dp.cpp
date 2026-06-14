// =============================================================
// Dynamic Programming: Fibonacci Sequence
// =============================================================
// The Fibonacci sequence is defined as:
//   F(0) = 0, F(1) = 1
//   F(n) = F(n-1) + F(n-2) for n >= 2
//
// Naive recursion has O(2^n) time due to overlapping subproblems.
// DP solves each subproblem once, reducing time to O(n).
//
// Two approaches are shown:
//   1. Top-Down (Memoization): Recursive + cache
//   2. Bottom-Up (Tabulation): Iterative table
// =============================================================

#include <iostream>
#include <vector>

// -------------------------------------------------------------
// Approach 1: Top-Down DP (Memoization)
// Time:  O(n)  |  Space: O(n) for memo table + O(n) call stack
// -------------------------------------------------------------
long long fibMemo(int n, std::vector<long long>& memo) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Return cached result if already computed
    if (memo[n] != -1) return memo[n];

    // Compute, cache, and return
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

long long fibTopDown(int n) {
    std::vector<long long> memo(n + 1, -1); // -1 means "not computed"
    return fibMemo(n, memo);
}

// -------------------------------------------------------------
// Approach 2: Bottom-Up DP (Tabulation)
// Time:  O(n)  |  Space: O(n)
// Fills the table from the smallest subproblem up to n.
// -------------------------------------------------------------
long long fibBottomUp(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    std::vector<long long> dp(n + 1);
    dp[0] = 0; // Base case
    dp[1] = 1; // Base case

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2]; // Build from previous results
    }

    return dp[n];
}

// -------------------------------------------------------------
// Approach 3: Space-Optimised Bottom-Up
// Time:  O(n)  |  Space: O(1)
// We only ever need the last two values, so no full table needed.
// -------------------------------------------------------------
long long fibOptimised(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    long long prev2 = 0; // F(i-2)
    long long prev1 = 1; // F(i-1)
    long long current = 0;

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    int n = 10;

    std::cout << "=== Fibonacci DP ===" << std::endl;
    std::cout << "Computing F(0) to F(" << n << "):" << std::endl;

    for (int i = 0; i <= n; i++) {
        std::cout << "F(" << i << ") = " << fibBottomUp(i) << std::endl;
    }

    std::cout << "\n--- Comparing all three approaches for F(40) ---" << std::endl;
    std::cout << "Top-Down   : " << fibTopDown(40)   << std::endl;
    std::cout << "Bottom-Up  : " << fibBottomUp(40)  << std::endl;
    std::cout << "Optimised  : " << fibOptimised(40) << std::endl;

    return 0;
}
