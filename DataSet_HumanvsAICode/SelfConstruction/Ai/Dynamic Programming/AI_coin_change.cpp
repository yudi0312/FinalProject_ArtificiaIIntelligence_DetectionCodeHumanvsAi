// =============================================================
// Dynamic Programming: Coin Change
// =============================================================
// Given coin denominations and a target amount, find the
// MINIMUM number of coins needed to make up that amount.
// You have an unlimited supply of each coin denomination.
//
// Subproblem: dp[i] = minimum coins needed to make amount i.
//
// Recurrence:
//   dp[0] = 0  (zero coins needed for amount 0)
//   dp[i] = min(dp[i - coin] + 1)  for each coin <= i
//
// Time:  O(amount * numCoins)  |  Space: O(amount)
//
// Bonus: Also shows how to count the number of combinations.
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// -------------------------------------------------------------
// Part 1: Minimum number of coins
// Returns -1 if the amount cannot be made with given coins.
// -------------------------------------------------------------
int coinChangeMin(const std::vector<int>& coins, int amount) {
    // dp[i] = fewest coins to make amount i
    // Initialise to amount+1 (a value larger than any valid answer)
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // Base case: 0 coins needed for amount 0

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                // Try using this coin and take the best result
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] was never updated, amount is unreachable
    return (dp[amount] > amount) ? -1 : dp[amount];
}

// -------------------------------------------------------------
// Part 2: Total number of ways to make the amount (combinations)
// Order does NOT matter: {1,2} == {2,1}
// -------------------------------------------------------------
long long coinChangeWays(const std::vector<int>& coins, int amount) {
    // dp[i] = number of combinations that sum to i
    std::vector<long long> dp(amount + 1, 0);
    dp[0] = 1; // One way to make amount 0: use no coins

    // Outer loop over coins ensures combinations (not permutations)
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

// -------------------------------------------------------------
// Part 3: Backtrack to find one valid coin selection
// -------------------------------------------------------------
std::vector<int> findCoinsUsed(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, amount + 1);
    std::vector<int> usedCoin(amount + 1, -1); // tracks which coin was last used
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                usedCoin[i] = coin; // record the coin that improved dp[i]
            }
        }
    }

    if (dp[amount] > amount) return {}; // No solution

    // Reconstruct the coin list
    std::vector<int> result;
    int remaining = amount;
    while (remaining > 0) {
        result.push_back(usedCoin[remaining]);
        remaining -= usedCoin[remaining];
    }

    return result;
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<int> coins = {1, 5, 6, 9};
    int amount = 11;

    std::cout << "=== Coin Change ===" << std::endl;
    std::cout << "Coins: ";
    for (int c : coins) std::cout << c << " ";
    std::cout << "\nTarget amount: " << amount << std::endl;

    int minCoins = coinChangeMin(coins, amount);
    std::cout << "\nMinimum coins needed : " << minCoins << std::endl;

    long long ways = coinChangeWays(coins, amount);
    std::cout << "Number of ways       : " << ways << std::endl;

    std::vector<int> used = findCoinsUsed(coins, amount);
    std::cout << "One optimal selection: ";
    for (int c : used) std::cout << c << " ";
    std::cout << std::endl;

    // Edge cases
    std::cout << "\n--- Edge Cases ---" << std::endl;
    std::cout << "Amount 0, min coins : " << coinChangeMin(coins, 0) << std::endl;
    std::cout << "Amount 3 with {2}   : " << coinChangeMin({2}, 3) << " (expect -1)" << std::endl;

    return 0;
}
