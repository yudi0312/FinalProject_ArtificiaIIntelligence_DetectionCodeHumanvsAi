// =============================================================
// Dynamic Programming: Subset Sum Problem
// =============================================================
// Given a set of non-negative integers and a target sum,
// determine if there exists a subset that adds up to the target.
//
// Subproblem: dp[i][s] = true if subset of first i elements
//             can sum to s.
//
// Recurrence:
//   dp[i][0] = true  (empty subset sums to 0)
//   dp[0][s] = false for s > 0
//   dp[i][s] = dp[i-1][s]                          (exclude element i)
//            | dp[i-1][s - arr[i-1]] if arr[i-1]<=s (include element i)
//
// Time:  O(n * target)  |  Space: O(n * target), reducible to O(target)
// =============================================================

#include <iostream>
#include <vector>

// -------------------------------------------------------------
// Approach 1: 2D DP Table — allows reconstruction of the subset
// -------------------------------------------------------------
bool subsetSum2D(const std::vector<int>& arr, int target) {
    int n = arr.size();

    // dp[i][s] = can first i elements sum to s?
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // Base case: sum 0 is always achievable (empty subset)
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            // Option 1: exclude arr[i-1]
            dp[i][s] = dp[i - 1][s];

            // Option 2: include arr[i-1] if it doesn't exceed current sum
            if (!dp[i][s] && arr[i - 1] <= s) {
                dp[i][s] = dp[i - 1][s - arr[i - 1]];
            }
        }
    }

    return dp[n][target];
}

// -------------------------------------------------------------
// Approach 2: Space-Optimised 1D DP — O(target) space
// Traverse target in reverse to avoid reusing elements.
// -------------------------------------------------------------
bool subsetSum1D(const std::vector<int>& arr, int target) {
    // dp[s] = true if sum s is achievable with elements seen so far
    std::vector<bool> dp(target + 1, false);
    dp[0] = true; // Empty subset

    for (int value : arr) {
        // Reverse traversal prevents using the same element twice
        for (int s = target; s >= value; s--) {
            dp[s] = dp[s] || dp[s - value];
        }
    }

    return dp[target];
}

// -------------------------------------------------------------
// Reconstruct the actual subset that sums to target
// Returns empty vector if no solution exists
// -------------------------------------------------------------
std::vector<int> findSubset(const std::vector<int>& arr, int target) {
    int n = arr.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            dp[i][s] = dp[i - 1][s];
            if (!dp[i][s] && arr[i - 1] <= s) {
                dp[i][s] = dp[i - 1][s - arr[i - 1]];
            }
        }
    }

    if (!dp[n][target]) return {}; // No solution

    // Backtrack: if dp[i][s] != dp[i-1][s], element i was included
    std::vector<int> subset;
    int s = target;
    for (int i = n; i >= 1; i--) {
        if (dp[i][s] && !dp[i - 1][s]) {
            subset.push_back(arr[i - 1]); // Element i-1 (0-indexed) was used
            s -= arr[i - 1];
        }
    }

    return subset;
}

// -------------------------------------------------------------
// Count the number of subsets that sum to target
// -------------------------------------------------------------
int countSubsets(const std::vector<int>& arr, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1; // One way to achieve sum 0 (empty subset)

    for (int value : arr) {
        for (int s = target; s >= value; s--) {
            dp[s] += dp[s - value];
        }
    }

    return dp[target];
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    std::cout << "=== Subset Sum ===" << std::endl;
    std::cout << "Array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\nTarget: " << target << std::endl;

    bool found2D = subsetSum2D(arr, target);
    bool found1D = subsetSum1D(arr, target);

    std::cout << "\nSubset exists (2D DP) : " << (found2D ? "Yes" : "No") << std::endl;
    std::cout << "Subset exists (1D DP) : " << (found1D ? "Yes" : "No") << std::endl;

    std::vector<int> subset = findSubset(arr, target);
    if (!subset.empty()) {
        std::cout << "One valid subset      : { ";
        for (int x : subset) std::cout << x << " ";
        std::cout << "}" << std::endl;
    }

    std::cout << "Number of subsets     : " << countSubsets(arr, target) << std::endl;

    // Unreachable target
    std::cout << "\nTarget 30 exists: "
              << (subsetSum1D(arr, 30) ? "Yes" : "No") << std::endl;

    return 0;
}
