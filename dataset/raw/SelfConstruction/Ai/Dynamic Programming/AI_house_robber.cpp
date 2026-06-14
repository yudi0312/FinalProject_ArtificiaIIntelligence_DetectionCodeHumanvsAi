// =============================================================
// Dynamic Programming: House Robber
// =============================================================
// A robber plans to rob houses along a street. Each house has
// a non-negative amount of money. Adjacent houses have connected
// security systems — robbing two adjacent houses triggers an alarm.
// Find the maximum amount of money that can be robbed.
//
// Subproblem: dp[i] = max money from first i houses
//
// Recurrence:
//   dp[0] = 0
//   dp[1] = nums[0]
//   dp[i] = max(dp[i-1], dp[i-2] + nums[i-1])
//          "skip house i" vs "rob house i"
//
// Time:  O(n)  |  Space: O(n), reducible to O(1)
//
// Extension: House Robber II (houses arranged in a circle)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>

// -------------------------------------------------------------
// Part 1: Linear arrangement of houses
// -------------------------------------------------------------
int houseRobber(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // dp[i] = max money robbing first i houses
    std::vector<int> dp(n + 1, 0);
    dp[1] = nums[0]; // Only one house: must take it

    for (int i = 2; i <= n; i++) {
        int robCurrent  = dp[i - 2] + nums[i - 1]; // Rob house i
        int skipCurrent = dp[i - 1];                // Skip house i
        dp[i] = std::max(robCurrent, skipCurrent);
    }

    return dp[n];
}

// -------------------------------------------------------------
// Space-Optimised: O(1) space
// We only need the previous two values.
// -------------------------------------------------------------
int houseRobberOptimised(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int twoBack = 0;       // dp[i-2]
    int oneBack = nums[0]; // dp[i-1]

    for (int i = 1; i < n; i++) {
        int current = std::max(oneBack, twoBack + nums[i]);
        twoBack = oneBack;
        oneBack = current;
    }

    return oneBack;
}

// -------------------------------------------------------------
// Part 2: House Robber II — houses are in a circle
// First and last houses are adjacent.
// Strategy: Run House Robber I twice:
//   (a) Exclude the last house  -> rob houses [0..n-2]
//   (b) Exclude the first house -> rob houses [1..n-1]
// Answer = max(a, b)
// -------------------------------------------------------------
int houseRobberCircle(const std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return std::max(nums[0], nums[1]);

    // Helper: linear rob on a subrange
    auto robRange = [&](int start, int end) -> int {
        int twoBack = 0;
        int oneBack = nums[start];
        for (int i = start + 1; i <= end; i++) {
            int current = std::max(oneBack, twoBack + nums[i]);
            twoBack = oneBack;
            oneBack = current;
        }
        return oneBack;
    };

    // Case (a): skip last house
    int caseA = robRange(0, n - 2);
    // Case (b): skip first house
    int caseB = robRange(1, n - 1);

    return std::max(caseA, caseB);
}

// -------------------------------------------------------------
// Reconstruct which houses were robbed
// -------------------------------------------------------------
std::vector<int> findRobbedHouses(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n + 1, 0);
    if (n >= 1) dp[1] = nums[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }

    // Backtrack
    std::vector<int> robbedIndices;
    int i = n;
    while (i >= 1) {
        if (i == 1 || dp[i] != dp[i - 1]) {
            robbedIndices.push_back(i - 1); // 0-indexed house
            i -= 2; // Skip adjacent house
        } else {
            i--;
        }
    }

    return robbedIndices;
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<int> nums = {2, 7, 9, 3, 1};

    std::cout << "=== House Robber ===" << std::endl;
    std::cout << "Houses: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "\nMax rob (linear, DP)       : " << houseRobber(nums) << std::endl;
    std::cout << "Max rob (linear, optimised): " << houseRobberOptimised(nums) << std::endl;
    std::cout << "Max rob (circular)         : " << houseRobberCircle(nums) << std::endl;

    std::cout << "\nHouses robbed (0-indexed): ";
    for (int idx : findRobbedHouses(nums)) {
        std::cout << idx << " ($" << nums[idx] << ") ";
    }
    std::cout << std::endl;

    // More examples
    std::cout << "\n--- More Examples ---" << std::endl;
    std::vector<int> ex1 = {1, 2, 3, 1};
    std::vector<int> ex2 = {2, 1, 1, 2};
    std::cout << "[1,2,3,1] linear: " << houseRobber(ex1) << std::endl;
    std::cout << "[2,1,1,2] circle: " << houseRobberCircle(ex2) << std::endl;

    return 0;
}
