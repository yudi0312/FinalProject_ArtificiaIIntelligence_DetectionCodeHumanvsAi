// =============================================================
// Dynamic Programming: Longest Increasing Subsequence (LIS)
// =============================================================
// Given an array of integers, find the length of the longest
// strictly increasing subsequence.
//
// Example: [10, 9, 2, 5, 3, 7, 101, 18] -> LIS = [2,3,7,18] len 4
//
// Approach 1 - Classic DP:
//   dp[i] = length of LIS ending at index i
//   dp[i] = max(dp[j] + 1) for all j < i where arr[j] < arr[i]
//   Time: O(n^2)  |  Space: O(n)
//
// Approach 2 - Binary Search (Patience Sorting):
//   Maintain a "tails" array where tails[i] is the smallest tail
//   element of all increasing subsequences of length i+1.
//   Time: O(n log n)  |  Space: O(n)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>

// -------------------------------------------------------------
// Approach 1: Classic O(n^2) DP
// Also records the actual subsequence via a parent array.
// -------------------------------------------------------------
int lisDP(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    // dp[i] = LIS length ending exactly at index i
    std::vector<int> dp(n, 1); // Every element alone is a subsequence of length 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                // Extend the subsequence ending at j
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

// -------------------------------------------------------------
// Reconstruct the actual LIS (O(n^2) DP with parent tracking)
// -------------------------------------------------------------
std::vector<int> lisReconstruct(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> dp(n, 1);
    std::vector<int> parent(n, -1); // parent[i] = previous index in LIS

    int bestLength = 1;
    int bestEnd = 0; // Index where the best LIS ends

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > bestLength) {
            bestLength = dp[i];
            bestEnd = i;
        }
    }

    // Trace back through parent array
    std::vector<int> lis;
    for (int i = bestEnd; i != -1; i = parent[i]) {
        lis.push_back(arr[i]);
    }
    std::reverse(lis.begin(), lis.end());

    return lis;
}

// -------------------------------------------------------------
// Approach 2: O(n log n) — Patience Sorting / Binary Search
// tails[i] = smallest possible tail of any IS of length i+1
// -------------------------------------------------------------
int lisFast(const std::vector<int>& arr) {
    std::vector<int> tails; // Maintains the "patience piles"

    for (int value : arr) {
        // Find the first element in tails >= value (lower_bound for non-strictly increasing)
        // Use lower_bound for strictly increasing (replaces equal or larger)
        auto pos = std::lower_bound(tails.begin(), tails.end(), value);

        if (pos == tails.end()) {
            tails.push_back(value); // Extend the sequence
        } else {
            *pos = value; // Replace to keep tails as small as possible
        }
    }

    return tails.size(); // Length of tails == length of LIS
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    std::cout << "=== Longest Increasing Subsequence ===" << std::endl;
    std::cout << "Array: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "\nLIS Length (O(n^2) DP)     : " << lisDP(arr) << std::endl;
    std::cout << "LIS Length (O(n log n) BS) : " << lisFast(arr) << std::endl;

    std::vector<int> lis = lisReconstruct(arr);
    std::cout << "One actual LIS             : ";
    for (int x : lis) std::cout << x << " ";
    std::cout << std::endl;

    // Another example
    std::vector<int> arr2 = {0, 1, 0, 3, 2, 3};
    std::cout << "\n--- Another Example ---" << std::endl;
    std::cout << "Array: ";
    for (int x : arr2) std::cout << x << " ";
    std::cout << "\nLIS Length: " << lisFast(arr2) << std::endl;
    std::vector<int> lis2 = lisReconstruct(arr2);
    std::cout << "One actual LIS: ";
    for (int x : lis2) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
