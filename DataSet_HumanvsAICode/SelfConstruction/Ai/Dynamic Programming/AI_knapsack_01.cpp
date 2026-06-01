// =============================================================
// Dynamic Programming: 0/1 Knapsack Problem
// =============================================================
// Given n items each with a weight and a value, and a knapsack
// with maximum capacity W, find the maximum total value that
// can be placed in the knapsack.
//
// "0/1" means each item is either taken (1) or not (0) —
// you cannot take a fraction of an item.
//
// Subproblem: dp[i][w] = max value using first i items
//             with knapsack capacity w.
//
// Recurrence:
//   If weight[i] > w: dp[i][w] = dp[i-1][w]   (can't include item i)
//   Else:             dp[i][w] = max(dp[i-1][w],
//                                   dp[i-1][w - weight[i]] + value[i])
//
// Time:  O(n * W)  |  Space: O(n * W), reducible to O(W)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>

// -------------------------------------------------------------
// Approach 1: 2D DP Table
// Builds the full table — allows backtracking to find which
// items were selected.
// -------------------------------------------------------------
int knapsack2D(const std::vector<int>& weights,
               const std::vector<int>& values,
               int capacity) {
    int n = weights.size();

    // dp[i][w] = best value with first i items and capacity w
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            // Option 1: skip item i
            dp[i][w] = dp[i - 1][w];

            // Option 2: include item i (only if it fits)
            if (weights[i - 1] <= w) {
                int valueIfIncluded = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                dp[i][w] = std::max(dp[i][w], valueIfIncluded);
            }
        }
    }

    return dp[n][capacity];
}

// -------------------------------------------------------------
// Approach 2: 1D (Space-Optimised) DP
// Uses a single row iterated in reverse to prevent using an
// item more than once.
// -------------------------------------------------------------
int knapsack1D(const std::vector<int>& weights,
               const std::vector<int>& values,
               int capacity) {
    int n = weights.size();

    // dp[w] = best value achievable with capacity w
    std::vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        // Traverse capacity in reverse: ensures item i is used at most once
        for (int w = capacity; w >= weights[i]; w--) {
            dp[w] = std::max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[capacity];
}

// -------------------------------------------------------------
// Backtracking: find which items were selected (requires 2D table)
// -------------------------------------------------------------
std::vector<int> findSelectedItems(const std::vector<int>& weights,
                                   const std::vector<int>& values,
                                   int capacity) {
    int n = weights.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    // Build full table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(dp[i][w],
                    dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    // Trace back through table to find selected items
    std::vector<int> selectedItems;
    int w = capacity;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            // Item i was included
            selectedItems.push_back(i - 1); // 0-indexed
            w -= weights[i - 1];
        }
    }

    return selectedItems;
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    // Items: {weight, value}
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values  = {3, 4, 5, 6};
    int capacity = 8;

    std::cout << "=== 0/1 Knapsack ===" << std::endl;
    std::cout << "Items (weight, value): ";
    for (int i = 0; i < (int)weights.size(); i++) {
        std::cout << "(" << weights[i] << "," << values[i] << ") ";
    }
    std::cout << "\nKnapsack Capacity: " << capacity << std::endl;

    std::cout << "\n2D DP max value : " << knapsack2D(weights, values, capacity) << std::endl;
    std::cout << "1D DP max value : " << knapsack1D(weights, values, capacity) << std::endl;

    std::cout << "\nSelected items (0-indexed): ";
    std::vector<int> selected = findSelectedItems(weights, values, capacity);
    for (int idx : selected) {
        std::cout << idx << " (w=" << weights[idx] << ", v=" << values[idx] << ")  ";
    }
    std::cout << std::endl;

    return 0;
}
