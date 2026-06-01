// =============================================================
// Dynamic Programming: Longest Common Subsequence (LCS)
// =============================================================
// Given two strings X and Y, find the length of their longest
// common subsequence. A subsequence preserves relative order
// but need not be contiguous.
//
// Example: X = "ABCBDAB", Y = "BDCABA" -> LCS = "BCBA" (len 4)
//
// Subproblem: dp[i][j] = LCS length of X[0..i-1] and Y[0..j-1]
//
// Recurrence:
//   dp[i][0] = dp[0][j] = 0  (empty string base cases)
//   If X[i-1] == Y[j-1]: dp[i][j] = dp[i-1][j-1] + 1
//   Else:                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//
// Time:  O(m * n)  |  Space: O(m * n), reducible to O(min(m,n))
// =============================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// -------------------------------------------------------------
// Part 1: Compute LCS length using full 2D table
// -------------------------------------------------------------
int lcsLength(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();

    // dp[i][j] = LCS length of first i chars of X, first j chars of Y
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                // Characters match: extend the LCS by 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Characters differ: take best of excluding one char from either string
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// -------------------------------------------------------------
// Part 2: Reconstruct the actual LCS string
// -------------------------------------------------------------
std::string lcsString(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack from dp[m][n] to reconstruct the LCS
    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1]; // Part of LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up
        } else {
            j--; // Move left
        }
    }

    // Reverse because we built it backwards
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

// -------------------------------------------------------------
// Part 3: Space-Optimised — only O(n) space
// Cannot reconstruct the actual subsequence, only the length.
// -------------------------------------------------------------
int lcsSpaceOptimised(const std::string& X, const std::string& Y) {
    int m = X.size();
    int n = Y.size();

    // Use two rows alternately
    std::vector<int> prev(n + 1, 0);
    std::vector<int> curr(n + 1, 0);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = std::max(prev[j], curr[j - 1]);
            }
        }
        std::swap(prev, curr);
    }

    return prev[n];
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::string X = "ABCBDAB";
    std::string Y = "BDCABA";

    std::cout << "=== Longest Common Subsequence ===" << std::endl;
    std::cout << "X = \"" << X << "\"" << std::endl;
    std::cout << "Y = \"" << Y << "\"" << std::endl;

    std::cout << "\nLCS Length (2D DP)     : " << lcsLength(X, Y) << std::endl;
    std::cout << "LCS String             : \"" << lcsString(X, Y) << "\"" << std::endl;
    std::cout << "LCS Length (Optimised) : " << lcsSpaceOptimised(X, Y) << std::endl;

    // Another example
    std::string A = "AGGTAB";
    std::string B = "GXTXAYB";
    std::cout << "\n--- Another Example ---" << std::endl;
    std::cout << "A = \"" << A << "\", B = \"" << B << "\"" << std::endl;
    std::cout << "LCS = \"" << lcsString(A, B) << "\" (length " << lcsLength(A, B) << ")" << std::endl;

    return 0;
}
