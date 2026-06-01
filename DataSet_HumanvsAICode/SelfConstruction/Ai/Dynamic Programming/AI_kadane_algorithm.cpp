// =============================================================
// Dynamic Programming: Kadane's Algorithm
// =============================================================
// Given an integer array, find the contiguous subarray with the
// largest sum. This is the Maximum Subarray problem.
//
// Key Insight (DP):
//   dp[i] = max subarray sum ending at index i
//   dp[i] = max(nums[i], dp[i-1] + nums[i])
//          "start fresh here" vs "extend previous subarray"
//
// Kadane's collapses this to O(1) space by observing that we
// only ever need dp[i-1].
//
// Time:  O(n)  |  Space: O(1)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// -------------------------------------------------------------
// Basic Kadane's Algorithm
// Returns the maximum subarray sum.
// Handles all-negative arrays correctly.
// -------------------------------------------------------------
int kadane(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxSumEndingHere = nums[0]; // Best sum of subarray ending at current index
    int globalMax        = nums[0]; // Best sum seen so far

    for (int i = 1; i < (int)nums.size(); i++) {
        // Either extend the existing subarray, or start a new one here
        maxSumEndingHere = std::max(nums[i], maxSumEndingHere + nums[i]);

        // Update the global best
        globalMax = std::max(globalMax, maxSumEndingHere);
    }

    return globalMax;
}

// -------------------------------------------------------------
// Extended Kadane's: also returns the subarray indices [left, right]
// -------------------------------------------------------------
struct SubarrayResult {
    int maxSum;
    int leftIndex;
    int rightIndex;
};

SubarrayResult kadaneWithIndices(const std::vector<int>& nums) {
    if (nums.empty()) return {0, -1, -1};

    int maxSumEndingHere = nums[0];
    int globalMax        = nums[0];

    int tempStart = 0;  // Start of the current candidate subarray
    int left      = 0;  // Start of the best subarray found
    int right     = 0;  // End   of the best subarray found

    for (int i = 1; i < (int)nums.size(); i++) {
        if (nums[i] > maxSumEndingHere + nums[i]) {
            // Starting fresh is better — reset candidate start
            maxSumEndingHere = nums[i];
            tempStart = i;
        } else {
            // Extend the current subarray
            maxSumEndingHere += nums[i];
        }

        if (maxSumEndingHere > globalMax) {
            globalMax = maxSumEndingHere;
            left  = tempStart;
            right = i;
        }
    }

    return {globalMax, left, right};
}

// -------------------------------------------------------------
// Variant: Maximum Circular Subarray Sum
// The subarray can wrap around the end to the beginning.
//
// Two cases:
//   1. Non-wrapping: standard Kadane
//   2. Wrapping:     total_sum - min_subarray_sum
//   Answer = max of the two cases.
//   (Edge case: if all elements are negative, return standard Kadane result)
// -------------------------------------------------------------
int maxCircularSubarraySum(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    // Case 1: best non-wrapping subarray (standard Kadane)
    int maxKadane = kadane(nums);

    // Case 2: wrapping subarray = totalSum - minSubarraySum
    int totalSum = 0;
    int minSumEndingHere = nums[0];
    int minSum = nums[0];

    for (int i = 0; i < (int)nums.size(); i++) {
        totalSum += nums[i];
    }

    for (int i = 1; i < (int)nums.size(); i++) {
        minSumEndingHere = std::min(nums[i], minSumEndingHere + nums[i]);
        minSum = std::min(minSum, minSumEndingHere);
    }

    int maxWrapping = totalSum - minSum;

    // If all elements are negative, maxWrapping would be 0 (wrong) — use Kadane
    if (maxWrapping == 0) return maxKadane;

    return std::max(maxKadane, maxWrapping);
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << "=== Kadane's Algorithm ===" << std::endl;
    std::cout << "Array: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << std::endl;

    std::cout << "\nMax Subarray Sum : " << kadane(nums) << std::endl;

    auto [maxSum, left, right] = kadaneWithIndices(nums);
    std::cout << "Subarray Range   : [" << left << ", " << right << "]" << std::endl;
    std::cout << "Subarray         : ";
    for (int i = left; i <= right; i++) std::cout << nums[i] << " ";
    std::cout << std::endl;

    std::cout << "\nMax Circular Sum : " << maxCircularSubarraySum(nums) << std::endl;

    // All negative array
    std::vector<int> allNeg = {-3, -1, -2};
    std::cout << "\n--- All Negative: [-3,-1,-2] ---" << std::endl;
    std::cout << "Max Subarray Sum : " << kadane(allNeg) << " (expect -1)" << std::endl;

    return 0;
}
