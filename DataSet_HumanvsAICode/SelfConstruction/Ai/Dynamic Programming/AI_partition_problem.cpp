// =============================================================
// Dynamic Programming: Partition Problem
// =============================================================
// Given a set of integers, can it be partitioned into two
// subsets with equal sum?
//
// Key Insight: This reduces to Subset Sum.
//   - If total sum is odd, answer is always false.
//   - If total sum is even, check if subset with sum = total/2 exists.
//
// Extension: Minimum Difference Partition
//   Find a partition that minimises |sum1 - sum2|.
//   Approach: find the largest achievable sum <= total/2 using DP.
//
// Time:  O(n * total)  |  Space: O(total)
// =============================================================

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// -------------------------------------------------------------
// Part 1: Can the array be split into two equal-sum subsets?
// -------------------------------------------------------------
bool canPartitionEqual(const std::vector<int>& arr) {
    int total = std::accumulate(arr.begin(), arr.end(), 0);

    // If total is odd, equal partition is impossible
    if (total % 2 != 0) return false;

    int halfSum = total / 2;

    // Now solve Subset Sum: can we find a subset summing to halfSum?
    std::vector<bool> dp(halfSum + 1, false);
    dp[0] = true;

    for (int value : arr) {
        // Reverse traversal: each element used at most once
        for (int s = halfSum; s >= value; s--) {
            dp[s] = dp[s] || dp[s - value];
        }
    }

    return dp[halfSum];
}

// -------------------------------------------------------------
// Part 2: Minimum difference partition
// Find how to split array into two subsets minimising |S1 - S2|.
// -------------------------------------------------------------
int minPartitionDifference(const std::vector<int>& arr) {
    int total = std::accumulate(arr.begin(), arr.end(), 0);

    // dp[s] = true if sum s is achievable with some subset
    std::vector<bool> dp(total + 1, false);
    dp[0] = true;

    for (int value : arr) {
        for (int s = total; s >= value; s--) {
            dp[s] = dp[s] || dp[s - value];
        }
    }

    // Find the largest achievable sum <= total/2
    // The closer S1 is to total/2, the smaller |S1 - S2|
    int minDiff = total; // Worst case: entire array on one side
    for (int s = total / 2; s >= 0; s--) {
        if (dp[s]) {
            minDiff = total - 2 * s; // |S1 - S2| = total - 2*S1
            break;
        }
    }

    return minDiff;
}

// -------------------------------------------------------------
// Part 3: Reconstruct the two subsets for the equal-sum case
// -------------------------------------------------------------
std::pair<std::vector<int>, std::vector<int>> findEqualPartition(
    const std::vector<int>& arr) {

    int total = std::accumulate(arr.begin(), arr.end(), 0);
    if (total % 2 != 0) return {{}, {}}; // No solution

    int halfSum = total / 2;
    int n = arr.size();

    // Build 2D table for reconstruction
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(halfSum + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= halfSum; s++) {
            dp[i][s] = dp[i - 1][s];
            if (!dp[i][s] && arr[i - 1] <= s)
                dp[i][s] = dp[i - 1][s - arr[i - 1]];
        }
    }

    if (!dp[n][halfSum]) return {{}, {}}; // No valid partition

    // Backtrack to find subset 1
    std::vector<int> subset1, subset2;
    int s = halfSum;
    for (int i = n; i >= 1; i--) {
        if (dp[i][s] && !dp[i - 1][s]) {
            subset1.push_back(arr[i - 1]);
            s -= arr[i - 1];
        } else {
            subset2.push_back(arr[i - 1]);
        }
    }

    return {subset1, subset2};
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<int> arr1 = {1, 5, 11, 5};
    std::vector<int> arr2 = {1, 3, 5};
    std::vector<int> arr3 = {3, 1, 4, 2, 2, 1};

    std::cout << "=== Partition Problem ===" << std::endl;

    for (auto& arr : {arr1, arr2, arr3}) {
        std::cout << "\nArray: ";
        for (int x : arr) std::cout << x << " ";
        int total = std::accumulate(arr.begin(), arr.end(), 0);
        std::cout << "(sum=" << total << ")" << std::endl;

        bool canEqual = canPartitionEqual(arr);
        std::cout << "Equal partition possible : " << (canEqual ? "Yes" : "No") << std::endl;
        std::cout << "Min difference partition : " << minPartitionDifference(arr) << std::endl;

        if (canEqual) {
            auto [s1, s2] = findEqualPartition(arr);
            std::cout << "Subset 1: { ";
            for (int x : s1) std::cout << x << " ";
            std::cout << "}  Subset 2: { ";
            for (int x : s2) std::cout << x << " ";
            std::cout << "}" << std::endl;
        }
    }

    return 0;
}
