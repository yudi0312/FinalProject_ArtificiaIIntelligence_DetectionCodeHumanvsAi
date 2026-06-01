// =============================================================
// Dynamic Programming: Rod Cutting Problem
// =============================================================
// Given a rod of length n and a price table where price[i] is
// the price of a rod of length i, find the maximum revenue
// obtainable by cutting up the rod and selling the pieces.
//
// Subproblem: dp[i] = max revenue from rod of length i
//
// Recurrence:
//   dp[0] = 0
//   dp[i] = max over j in [1, i] of (price[j] + dp[i - j])
//
// This is essentially an unbounded knapsack (each cut can be
// repeated) where weights == lengths and values == prices.
//
// Time:  O(n^2)  |  Space: O(n)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>

// -------------------------------------------------------------
// Compute maximum revenue from a rod of length n
// -------------------------------------------------------------
int rodCutting(const std::vector<int>& price, int rodLength) {
    // dp[i] = max revenue from a rod of length i
    std::vector<int> dp(rodLength + 1, 0);

    for (int i = 1; i <= rodLength; i++) {
        // Try every cut length j (1 to i)
        for (int j = 1; j <= i; j++) {
            // price[j-1] is price for piece of length j (0-indexed price array)
            // dp[i-j]    is best revenue from the remaining rod
            dp[i] = std::max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    return dp[rodLength];
}

// -------------------------------------------------------------
// Reconstruct the optimal cut sequence
// -------------------------------------------------------------
std::vector<int> findOptimalCuts(const std::vector<int>& price, int rodLength) {
    std::vector<int> dp(rodLength + 1, 0);
    std::vector<int> firstCut(rodLength + 1, 0); // firstCut[i] = best first cut for rod i

    for (int i = 1; i <= rodLength; i++) {
        for (int j = 1; j <= i; j++) {
            if (price[j - 1] + dp[i - j] > dp[i]) {
                dp[i] = price[j - 1] + dp[i - j];
                firstCut[i] = j; // Record the best first cut
            }
        }
    }

    // Reconstruct: follow firstCut until rod is fully consumed
    std::vector<int> cuts;
    int remaining = rodLength;
    while (remaining > 0) {
        cuts.push_back(firstCut[remaining]);
        remaining -= firstCut[remaining];
    }

    return cuts;
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    // price[i] = revenue from selling a rod of length (i+1)
    std::vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    // Lengths:                 1  2  3  4   5   6   7   8

    std::cout << "=== Rod Cutting Problem ===" << std::endl;
    std::cout << "Price table:" << std::endl;
    for (int i = 0; i < (int)price.size(); i++) {
        std::cout << "  Length " << (i + 1) << " -> $" << price[i] << std::endl;
    }

    for (int n = 1; n <= (int)price.size(); n++) {
        int maxRev = rodCutting(price, n);
        std::vector<int> cuts = findOptimalCuts(price, n);

        std::cout << "\nRod length " << n
                  << " | Max revenue: $" << maxRev
                  << " | Cuts: ";
        for (int c : cuts) std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}
