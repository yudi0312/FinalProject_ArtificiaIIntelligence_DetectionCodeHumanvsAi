// =============================================================
// Dynamic Programming: Minimum Path Sum
// =============================================================
// Given a grid filled with non-negative numbers, find a path
// from the top-left to the bottom-right corner that minimises
// the sum of all numbers along the path.
// You can only move right or down.
//
// Subproblem: dp[i][j] = min path sum to reach cell (i, j)
//
// Recurrence:
//   dp[0][0] = grid[0][0]
//   dp[i][0] = dp[i-1][0] + grid[i][0]    (only from above)
//   dp[0][j] = dp[0][j-1] + grid[0][j]    (only from left)
//   dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
//
// Time:  O(m * n)  |  Space: O(m * n), reducible to O(n)
// =============================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// -------------------------------------------------------------
// Compute minimum path sum using a 2D DP table
// Also records the path taken.
// -------------------------------------------------------------
int minPathSum(const std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int m = grid.size();
    int n = grid[0].size();

    // dp[i][j] = min cost to reach (i, j)
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = grid[0][0];

    // Fill first column (can only come from above)
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill first row (can only come from left)
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill remaining cells
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m - 1][n - 1];
}

// -------------------------------------------------------------
// Reconstruct the actual minimum path
// Returns sequence of (row, col) pairs
// -------------------------------------------------------------
std::vector<std::pair<int,int>> findMinPath(const std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);

    // Backtrack from bottom-right to top-left
    std::vector<std::pair<int,int>> path;
    int i = m - 1, j = n - 1;
    path.push_back({i, j});
    while (i > 0 || j > 0) {
        if (i == 0) {
            j--; // Can only go left
        } else if (j == 0) {
            i--; // Can only go up
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            i--; // Came from above
        } else {
            j--; // Came from left
        }
        path.push_back({i, j});
    }

    std::reverse(path.begin(), path.end());
    return path;
}

// -------------------------------------------------------------
// Space-Optimised: O(n) — use single row DP
// -------------------------------------------------------------
int minPathSumOptimised(const std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < m; i++) {
        dp[0] += grid[i][0]; // First column: always add from above
        for (int j = 1; j < n; j++) {
            dp[j] = grid[i][j] + std::min(dp[j],      // From above
                                           dp[j - 1]); // From left
        }
    }

    return dp[n - 1];
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    std::cout << "=== Minimum Path Sum ===" << std::endl;
    std::cout << "Grid:" << std::endl;
    for (auto& row : grid) {
        for (int v : row) std::cout << v << " ";
        std::cout << std::endl;
    }

    std::cout << "\nMin path sum (2D DP)     : " << minPathSum(grid) << std::endl;
    std::cout << "Min path sum (Optimised) : " << minPathSumOptimised(grid) << std::endl;

    std::cout << "\nPath taken: ";
    for (auto [r, c] : findMinPath(grid)) {
        std::cout << "(" << r << "," << c << ")=" << grid[r][c] << " ";
    }
    std::cout << std::endl;

    // Larger example
    std::vector<std::vector<int>> grid2 = {
        {1, 2, 5},
        {3, 2, 1}
    };
    std::cout << "\nGrid2 min path sum: " << minPathSum(grid2) << " (expect 6)" << std::endl;

    return 0;
}
