// =============================================================
// Dynamic Programming: Maximum Product Subarray
// =============================================================
// Given an integer array, find the contiguous subarray with the
// largest product.
//
// Challenge (vs Max Sum): A negative * negative = positive.
// So a large negative value today might become the best choice
// after multiplying by another negative.
//
// Key DP State:
//   maxEndingHere[i] = max product of subarray ending at index i
//   minEndingHere[i] = min product of subarray ending at index i
//   (min matters because it can flip to max when multiplied by negative)
//
// Recurrence:
//   maxEndingHere = max(nums[i],
//                       maxEndingHere * nums[i],
//                       minEndingHere * nums[i])
//   minEndingHere = min(nums[i],
//                       maxEndingHere * nums[i],
//                       minEndingHere * nums[i])
//
// Time:  O(n)  |  Space: O(1)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// -------------------------------------------------------------
// Main algorithm: find the maximum product subarray value
// -------------------------------------------------------------
int maxProductSubarray(const std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int maxEndingHere = nums[0]; // Best product ending at current position
    int minEndingHere = nums[0]; // Worst (most negative) product ending here
    int globalMax     = nums[0]; // Best product seen across all positions

    for (int i = 1; i < (int)nums.size(); i++) {
        // When multiplying by nums[i], max and min might swap
        // so we save the old max before updating
        int prevMax = maxEndingHere;
        int prevMin = minEndingHere;

        // New max: could be just nums[i], or extend max, or flip min
        maxEndingHere = std::max({nums[i], prevMax * nums[i], prevMin * nums[i]});

        // New min: could be just nums[i], or extend min, or flip max
        minEndingHere = std::min({nums[i], prevMax * nums[i], prevMin * nums[i]});

        globalMax = std::max(globalMax, maxEndingHere);
    }

    return globalMax;
}

// -------------------------------------------------------------
// Extended: also return the [left, right] index range of the subarray
// -------------------------------------------------------------
struct ProductResult {
    int maxProduct;
    int leftIndex;
    int rightIndex;
};

ProductResult maxProductWithIndices(const std::vector<int>& nums) {
    if (nums.empty()) return {0, -1, -1};

    int maxHere = nums[0], minHere = nums[0];
    int globalMax = nums[0];
    int left = 0, right = 0;

    for (int i = 1; i < (int)nums.size(); i++) {
        int prevMax = maxHere;
        int prevMin = minHere;

        // Compute all three candidates
        int cands[3] = {nums[i], prevMax * nums[i], prevMin * nums[i]};

        maxHere = *std::max_element(cands, cands + 3);
        minHere = *std::min_element(cands, cands + 3);

        // Update global best
        if (maxHere > globalMax) {
            globalMax = maxHere;
            right = i;
            // If starting fresh (nums[i] is best candidate), update left
            if (maxHere == nums[i]) left = i;
        }
    }

    return {globalMax, left, right};
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::cout << "=== Maximum Product Subarray ===" << std::endl;

    std::vector<std::vector<int>> tests = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-2, 3, -4},
        {2, -5, -2, -4, 3},
        {0, 2}
    };

    for (auto& nums : tests) {
        std::cout << "\nArray: ";
        for (int x : nums) std::cout << x << " ";
        std::cout << std::endl;

        int result = maxProductSubarray(nums);
        std::cout << "Max Product: " << result << std::endl;

        auto [mp, l, r] = maxProductWithIndices(nums);
        std::cout << "Subarray [" << l << ".." << r << "]: ";
        for (int i = l; i <= r; i++) std::cout << nums[i] << " ";
        std::cout << std::endl;
    }

    return 0;
}
