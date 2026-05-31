// =============================================================
// Dynamic Programming: Egg Dropping Problem
// =============================================================
// Given k eggs and n floors, find the minimum number of trials
// needed in the WORST CASE to determine the critical floor f:
//   - Eggs dropped from floor > f break.
//   - Eggs dropped from floor <= f don't break.
//
// Subproblem: dp[e][f] = min trials needed with e eggs and f floors
//
// Recurrence (O(k * n^2)):
//   dp[1][f] = f           (1 egg: must try each floor linearly)
//   dp[e][0] = 0, dp[e][1] = 1
//   dp[e][f] = min over x in [1,f] of:
//              1 + max(dp[e-1][x-1], dp[e][f-x])
//              "egg breaks: check below x" vs "egg survives: check above x"
//
// Optimised with binary search: O(k * n * log n)
// Even better DP formulation: O(k * n)
// =============================================================

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// -------------------------------------------------------------
// Approach 1: Classic 2D DP  —  O(k * n^2)
// Finds min trials for e eggs and n floors
// -------------------------------------------------------------
int eggDropDP(int eggs, int floors) {
    // dp[e][f] = min trials, e eggs, f floors
    std::vector<std::vector<int>> dp(eggs + 1, std::vector<int>(floors + 1, 0));

    // Base cases
    for (int e = 1; e <= eggs;  e++) dp[e][0] = 0; // 0 floors
    for (int e = 1; e <= eggs;  e++) dp[e][1] = 1; // 1 floor
    for (int f = 1; f <= floors; f++) dp[1][f] = f; // 1 egg: linear search

    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {
            dp[e][f] = INT_MAX;

            // Try dropping egg from every floor x
            for (int x = 1; x <= f; x++) {
                // Worst case between:
                //   egg breaks   -> dp[e-1][x-1] (search floors 1..x-1)
                //   egg survives -> dp[e][f-x]   (search floors x+1..f)
                int worstCase = 1 + std::max(dp[e - 1][x - 1], dp[e][f - x]);
                dp[e][f] = std::min(dp[e][f], worstCase);
            }
        }
    }

    return dp[eggs][floors];
}

// -------------------------------------------------------------
// Approach 2: Binary Search Optimised  —  O(k * n * log n)
// For each (e, f), the optimal x can be found via binary search
// because dp[e-1][x-1] is non-decreasing and dp[e][f-x] is
// non-increasing in x. Their maximum is minimised at the crossing.
// -------------------------------------------------------------
int eggDropBinarySearch(int eggs, int floors) {
    std::vector<std::vector<int>> dp(eggs + 1, std::vector<int>(floors + 1, 0));

    for (int e = 1; e <= eggs; e++)  dp[e][0] = 0;
    for (int e = 1; e <= eggs; e++)  dp[e][1] = 1;
    for (int f = 1; f <= floors; f++) dp[1][f] = f;

    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {
            dp[e][f] = INT_MAX;
            int lo = 1, hi = f;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int breakCase   = dp[e - 1][mid - 1]; // Egg breaks
                int surviveCase = dp[e][f - mid];      // Egg survives

                int worstCase = 1 + std::max(breakCase, surviveCase);
                dp[e][f] = std::min(dp[e][f], worstCase);

                // Move toward the crossing point
                if (breakCase < surviveCase) {
                    lo = mid + 1; // Need to go higher
                } else {
                    hi = mid - 1; // Need to go lower
                }
            }
        }
    }

    return dp[eggs][floors];
}

// -------------------------------------------------------------
// Approach 3: Alternative formulation — O(k * n)
// Instead of "min trials for f floors", ask:
//   "max floors we can check with e eggs and t trials"
//
// dp2[t][e] = max floors checkable with t trials and e eggs
// dp2[t][e] = dp2[t-1][e-1] + dp2[t-1][e] + 1
//
// Find smallest t where dp2[t][eggs] >= floors
// -------------------------------------------------------------
int eggDropOptimal(int eggs, int floors) {
    // dp2[t][e] = max floors with t trials and e eggs
    std::vector<std::vector<int>> dp2(floors + 1, std::vector<int>(eggs + 1, 0));

    int trials = 0;
    while (dp2[trials][eggs] < floors) {
        trials++;
        for (int e = 1; e <= eggs; e++) {
            dp2[trials][e] = dp2[trials - 1][e - 1] // Floor below (egg breaks)
                           + dp2[trials - 1][e]      // Floors above (egg survives)
                           + 1;                       // Current floor
        }
    }

    return trials;
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::cout << "=== Egg Dropping Problem ===" << std::endl;

    std::vector<std::pair<int,int>> tests = {{2,10},{2,36},{3,14},{1,100}};

    for (auto [eggs, floors] : tests) {
        std::cout << "\nEggs=" << eggs << ", Floors=" << floors << std::endl;
        std::cout << "  Classic DP     : " << eggDropDP(eggs, floors) << " trials" << std::endl;
        std::cout << "  Binary Search  : " << eggDropBinarySearch(eggs, floors) << " trials" << std::endl;
        std::cout << "  Optimal O(kn)  : " << eggDropOptimal(eggs, floors) << " trials" << std::endl;
    }

    return 0;
}
