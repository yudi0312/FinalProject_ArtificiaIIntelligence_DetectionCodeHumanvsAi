// =============================================================
// Dynamic Programming: Target Sum
// =============================================================
// Given an integer array nums and a target, assign '+' or '-'
// to each number to build an expression. Count the number of
// ways to reach the target.
//
// Example: nums=[1,1,1,1,1], target=3 -> 5 ways
//
// Reduction to Subset Sum:
//   Let P = set of numbers with '+', N = set with '-'.
//   sum(P) - sum(N) = target
//   sum(P) + sum(N) = total
//   => 2 * sum(P)  = target + total
//   => sum(P) = (target + total) / 2
//
//   So count subsets of nums that sum to (target + total) / 2.
//   (If target+total is odd, answer is 0.)
//
// Time:  O(n * total)  |  Space: O(total)
// =============================================================

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

// -------------------------------------------------------------
// Approach 1: DP via Subset Sum reduction
// Count subsets summing to a specific value (knapsack style).
// -------------------------------------------------------------
int targetSumDP(const std::vector<int>& nums, int target) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);

    // Check feasibility
    if (std::abs(target) > total) return 0;
    if ((target + total) % 2 != 0) return 0; // Must be even

    int subsetTarget = (target + total) / 2;

    // dp[s] = number of subsets that sum to s
    std::vector<int> dp(subsetTarget + 1, 0);
    dp[0] = 1; // One way to reach sum 0 (empty selection)

    for (int num : nums) {
        // Reverse to avoid counting the same element twice
        for (int s = subsetTarget; s >= num; s--) {
            dp[s] += dp[s - num];
        }
    }

    return dp[subsetTarget];
}

// -------------------------------------------------------------
// Approach 2: DFS with Memoisation (handles negative numbers)
// The DP reduction assumes non-negative nums.
// This approach works even with zeros or negatives.
// -------------------------------------------------------------
int dfsHelper(const std::vector<int>& nums,
              int index,
              int remaining,
              std::unordered_map<std::string, int>& memo) {
    // Base case: no more numbers
    if (index == (int)nums.size()) {
        return remaining == 0 ? 1 : 0;
    }

    // Encode state as a string key
    std::string key = std::to_string(index) + "," + std::to_string(remaining);
    if (memo.count(key)) return memo[key];

    // Try '+' and '-'
    int addPlus  = dfsHelper(nums, index + 1, remaining - nums[index], memo);
    int addMinus = dfsHelper(nums, index + 1, remaining + nums[index], memo);

    memo[key] = addPlus + addMinus;
    return memo[key];
}

int targetSumDFS(const std::vector<int>& nums, int target) {
    std::unordered_map<std::string, int> memo;
    return dfsHelper(nums, 0, target, memo);
}

// -------------------------------------------------------------
// Enumerate all expressions (for small inputs)
// -------------------------------------------------------------
void enumerate(const std::vector<int>& nums,
               int index,
               int current,
               int target,
               std::string& expression,
               int& count) {
    if (index == (int)nums.size()) {
        if (current == target) {
            std::cout << "    " << expression << " = " << target << std::endl;
            count++;
        }
        return;
    }

    // Try '+'
    expression += "+" + std::to_string(nums[index]);
    enumerate(nums, index + 1, current + nums[index], target, expression, count);
    expression.resize(expression.size() - 1 - std::to_string(nums[index]).size());

    // Try '-'
    expression += "-" + std::to_string(nums[index]);
    enumerate(nums, index + 1, current - nums[index], target, expression, count);
    expression.resize(expression.size() - 1 - std::to_string(nums[index]).size());
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::cout << "=== Target Sum ===" << std::endl;

    // Example 1
    {
        std::vector<int> nums = {1, 1, 1, 1, 1};
        int target = 3;
        std::cout << "\nnums = [1,1,1,1,1], target = " << target << std::endl;
        std::cout << "Ways (DP)  : " << targetSumDP(nums, target)  << std::endl;
        std::cout << "Ways (DFS) : " << targetSumDFS(nums, target) << std::endl;
    }

    // Example 2 with enumeration
    {
        std::vector<int> nums = {1, 2, 3};
        int target = 0;
        std::cout << "\nnums = [1,2,3], target = " << target << std::endl;
        std::cout << "Ways (DP)  : " << targetSumDP(nums, target)  << std::endl;
        std::cout << "Ways (DFS) : " << targetSumDFS(nums, target) << std::endl;
        std::cout << "Expressions:" << std::endl;
        std::string expr;
        int count = 0;
        enumerate(nums, 0, 0, target, expr, count);
    }

    return 0;
}
