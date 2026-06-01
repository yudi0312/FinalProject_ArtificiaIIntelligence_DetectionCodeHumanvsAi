// =============================================================
// Dynamic Programming: Matrix Chain Multiplication
// =============================================================
// Given a sequence of matrices A1, A2, ..., An, find the
// optimal parenthesisation that minimises the total number of
// scalar multiplications needed to compute their product.
//
// Matrix Ai has dimensions dims[i-1] x dims[i].
//
// Subproblem: dp[i][j] = min cost to multiply matrices i..j
//
// Recurrence:
//   dp[i][i] = 0  (single matrix, no multiplication needed)
//   dp[i][j] = min over k in [i, j-1] of:
//              dp[i][k] + dp[k+1][j] + dims[i-1]*dims[k]*dims[j]
//
// Time:  O(n^3)  |  Space: O(n^2)
// =============================================================

#include <iostream>
#include <vector>
#include <climits>
#include <string>

// -------------------------------------------------------------
// Compute minimum multiplication cost + record split points
// -------------------------------------------------------------
struct MCMResult {
    int minCost;
    std::vector<std::vector<int>> dp;     // Cost table
    std::vector<std::vector<int>> split;  // Optimal split point k
};

MCMResult matrixChainOrder(const std::vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices

    // dp[i][j]    = min scalar multiplications for matrices i..j (1-indexed)
    // split[i][j] = optimal k that splits i..j into (i..k) and (k+1..j)
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<int>> split(n + 1, std::vector<int>(n + 1, 0));

    // len = chain length (number of matrices in the sub-chain)
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1; // End of sub-chain

            dp[i][j] = INT_MAX;

            // Try every possible split point k
            for (int k = i; k < j; k++) {
                // Cost = multiply left sub-chain + multiply right sub-chain
                //      + cost of final matrix multiplication
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + dims[i - 1] * dims[k] * dims[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k; // Record where we split
                }
            }
        }
    }

    return {dp[1][n], dp, split};
}

// -------------------------------------------------------------
// Reconstruct the optimal parenthesisation as a string
// -------------------------------------------------------------
std::string buildParenthesisation(const std::vector<std::vector<int>>& split,
                                  int i, int j) {
    if (i == j) {
        return "A" + std::to_string(i);
    }

    int k = split[i][j];
    std::string left  = buildParenthesisation(split, i, k);
    std::string right = buildParenthesisation(split, k + 1, j);

    return "(" + left + " x " + right + ")";
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    // dims[i-1] x dims[i] is the dimension of matrix i
    // Here: A1=30x35, A2=35x15, A3=15x5, A4=5x10, A5=10x20, A6=20x25
    std::vector<int> dims = {30, 35, 15, 5, 10, 20, 25};
    int n = dims.size() - 1;

    std::cout << "=== Matrix Chain Multiplication ===" << std::endl;
    std::cout << "Number of matrices: " << n << std::endl;
    std::cout << "Dimensions: ";
    for (int i = 0; i < n; i++) {
        std::cout << "A" << (i + 1) << "(" << dims[i] << "x" << dims[i + 1] << ")";
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    MCMResult result = matrixChainOrder(dims);

    std::cout << "\nMinimum scalar multiplications: " << result.minCost << std::endl;
    std::cout << "Optimal parenthesisation: "
              << buildParenthesisation(result.split, 1, n) << std::endl;

    // Print DP cost table
    std::cout << "\nDP Cost Table (dp[i][j]):" << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < i)
                std::cout << "     0";
            else
                std::cout.width(6), std::cout << result.dp[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
