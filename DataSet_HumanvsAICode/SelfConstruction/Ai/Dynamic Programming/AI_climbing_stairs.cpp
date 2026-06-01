// =============================================================
// Dynamic Programming: Climbing Stairs
// =============================================================
// You are climbing a staircase with n steps. Each time you can
// climb 1 or 2 steps. How many distinct ways can you reach the top?
//
// This is equivalent to Fibonacci: ways(n) = ways(n-1) + ways(n-2)
//   - From step n-1, take 1 step
//   - From step n-2, take 2 steps
//
// Extension: generalised to k step sizes {1, 2, ..., k}
//
// Time:  O(n)  |  Space: O(n), reducible to O(1) for 2-step case
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>

// -------------------------------------------------------------
// Part 1: Classic 2-step climbing
// -------------------------------------------------------------
long long climbStairs(int n) {
    if (n <= 2) return n;

    long long prev2 = 1; // ways(1)
    long long prev1 = 2; // ways(2)

    for (int i = 3; i <= n; i++) {
        long long current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

// -------------------------------------------------------------
// Part 2: Generalised — allowed step sizes in a set
// dp[i] = number of ways to reach step i
// dp[i] = sum of dp[i - step] for each valid step size
// -------------------------------------------------------------
long long climbStairsGeneral(int n, const std::vector<int>& steps) {
    // dp[i] = ways to reach step i
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1; // One way to stand at ground level (do nothing)

    for (int i = 1; i <= n; i++) {
        for (int step : steps) {
            if (step <= i) {
                dp[i] += dp[i - step]; // Come from i-step steps below
            }
        }
    }

    return dp[n];
}

// -------------------------------------------------------------
// Part 3: Minimum cost climbing stairs
// Each stair has a cost. You can step off the top from any stair.
// Find the minimum cost to reach the top.
//
// dp[i] = min cost to reach step i
// dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
// Answer: min(dp[n-1], dp[n-2])  (step off from last or second-last)
// -------------------------------------------------------------
int minCostClimbingStairs(const std::vector<int>& cost) {
    int n = cost.size();
    if (n == 0) return 0;
    if (n == 1) return cost[0];

    // dp[i] = min cost to step on stair i
    std::vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + std::min(dp[i - 1], dp[i - 2]);
    }

    // Can reach top from last or second-to-last stair
    return std::min(dp[n - 1], dp[n - 2]);
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::cout << "=== Climbing Stairs ===" << std::endl;

    // Classic 2-step
    std::cout << "\n-- Classic (1 or 2 steps) --" << std::endl;
    for (int n = 1; n <= 10; n++) {
        std::cout << "n=" << n << " -> " << climbStairs(n) << " ways" << std::endl;
    }

    // Generalised step sizes
    std::cout << "\n-- Generalised {1,2,3} steps, n=5 --" << std::endl;
    std::vector<int> steps = {1, 2, 3};
    std::cout << "Ways to climb 5 stairs: " << climbStairsGeneral(5, steps) << std::endl;

    std::cout << "\n-- Generalised {1,3,5} steps, n=10 --" << std::endl;
    std::cout << "Ways to climb 10 stairs: " << climbStairsGeneral(10, {1, 3, 5}) << std::endl;

    // Minimum cost
    std::cout << "\n-- Minimum Cost Climbing --" << std::endl;
    std::vector<int> cost1 = {10, 15, 20};
    std::vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    std::cout << "cost=[10,15,20]       min cost = " << minCostClimbingStairs(cost1) << std::endl;
    std::cout << "cost=[1,100,1,1,1,100,1,1,100,1] min cost = "
              << minCostClimbingStairs(cost2) << std::endl;

    return 0;
}
