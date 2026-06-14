// =============================================================
// Dynamic Programming: Edit Distance (Levenshtein Distance)
// =============================================================
// Given two strings, find the minimum number of operations
// (insert, delete, replace) to transform one string into the other.
//
// Subproblem: dp[i][j] = min operations to convert word1[0..i-1]
//                         into word2[0..j-1]
//
// Recurrence:
//   dp[i][0] = i  (delete all i characters)
//   dp[0][j] = j  (insert all j characters)
//   If word1[i-1] == word2[j-1]: dp[i][j] = dp[i-1][j-1]  (no op)
//   Else: dp[i][j] = 1 + min(
//             dp[i-1][j],   // Delete from word1
//             dp[i][j-1],   // Insert into word1
//             dp[i-1][j-1]  // Replace in word1
//         )
//
// Time:  O(m * n)  |  Space: O(m * n), reducible to O(min(m,n))
// =============================================================

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Operation types for reconstruction
enum class Op { NONE, INSERT, DELETE, REPLACE, MATCH };

// -------------------------------------------------------------
// Compute edit distance
// -------------------------------------------------------------
int editDistance(const std::string& word1, const std::string& word2) {
    int m = word1.size();
    int n = word2.size();

    // dp[i][j] = edit distance between word1[0..i-1] and word2[0..j-1]
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    // Base cases: transforming to/from empty string
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Delete all
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Insert all

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match — free
            } else {
                dp[i][j] = 1 + std::min({
                    dp[i - 1][j],   // Delete word1[i-1]
                    dp[i][j - 1],   // Insert word2[j-1]
                    dp[i - 1][j - 1] // Replace word1[i-1] with word2[j-1]
                });
            }
        }
    }

    return dp[m][n];
}

// -------------------------------------------------------------
// Reconstruct the sequence of edit operations
// -------------------------------------------------------------
struct EditOp {
    std::string type;
    char character;
    int position;
};

std::vector<EditOp> getEditOperations(const std::string& word1, const std::string& word2) {
    int m = word1.size();
    int n = word2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    // Backtrack to find operations
    std::vector<EditOp> ops;
    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && word1[i - 1] == word2[j - 1]) {
            // Match — no operation
            i--; j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1] + 1) {
            ops.push_back({"Replace '" + std::string(1, word1[i-1]) +
                           "' -> '" + std::string(1, word2[j-1]) + "'", word2[j-1], i});
            i--; j--;
        } else if (j > 0 && dp[i][j] == dp[i][j-1] + 1) {
            ops.push_back({"Insert '" + std::string(1, word2[j-1]) + "'", word2[j-1], i});
            j--;
        } else {
            ops.push_back({"Delete '" + std::string(1, word1[i-1]) + "'", word1[i-1], i});
            i--;
        }
    }

    std::reverse(ops.begin(), ops.end());
    return ops;
}

// -------------------------------------------------------------
// Space-Optimised: O(min(m,n)) space
// -------------------------------------------------------------
int editDistanceOptimised(const std::string& word1, const std::string& word2) {
    // Always iterate over the longer string
    const std::string& shorter = (word1.size() <= word2.size()) ? word1 : word2;
    const std::string& longer  = (word1.size() <= word2.size()) ? word2 : word1;

    int m = longer.size();
    int n = shorter.size();

    std::vector<int> dp(n + 1);
    for (int j = 0; j <= n; j++) dp[j] = j;

    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (longer[i - 1] == shorter[j - 1]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + std::min({dp[j], dp[j - 1], prev});
            }
            prev = temp;
        }
    }

    return dp[n];
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::string word1 = "saturday";
    std::string word2 = "sunday";

    std::cout << "=== Edit Distance ===" << std::endl;
    std::cout << "Word 1: \"" << word1 << "\"" << std::endl;
    std::cout << "Word 2: \"" << word2 << "\"" << std::endl;

    std::cout << "\nEdit Distance          : " << editDistance(word1, word2) << std::endl;
    std::cout << "Edit Distance (Opt)    : " << editDistanceOptimised(word1, word2) << std::endl;

    std::cout << "\nEdit Operations:" << std::endl;
    for (auto& op : getEditOperations(word1, word2)) {
        std::cout << "  " << op.type << std::endl;
    }

    // More examples
    std::cout << "\n--- More Examples ---" << std::endl;
    std::cout << "\"kitten\" -> \"sitting\" : " << editDistance("kitten", "sitting") << std::endl;
    std::cout << "\"\" -> \"abc\"           : " << editDistance("", "abc") << std::endl;
    std::cout << "\"abc\" -> \"abc\"        : " << editDistance("abc", "abc") << std::endl;

    return 0;
}
