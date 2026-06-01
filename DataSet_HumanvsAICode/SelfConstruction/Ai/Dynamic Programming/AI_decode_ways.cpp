// =============================================================
// Dynamic Programming: Decode Ways
// =============================================================
// A message encoded as digits 1-26 maps to letters A-Z.
// Given a digit string, count the number of ways to decode it.
//   '1' -> A, '2' -> B, ..., '26' -> Z
//
// Subproblem: dp[i] = number of ways to decode s[0..i-1]
//
// Recurrence:
//   dp[0] = 1  (empty prefix: 1 way)
//   dp[i]:
//     oneDigit  = s[i-1]               (decode last 1 digit)
//     twoDigits = s[i-2..i-1]          (decode last 2 digits)
//
//     if oneDigit is valid (1-9):  dp[i] += dp[i-1]
//     if twoDigits is valid (10-26): dp[i] += dp[i-2]
//
// Time:  O(n)  |  Space: O(n), reducible to O(1)
// =============================================================

#include <iostream>
#include <string>
#include <vector>

// -------------------------------------------------------------
// Count decoding ways (handles '0' correctly)
// -------------------------------------------------------------
int decodeWays(const std::string& s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0; // Leading zero means invalid

    // dp[i] = number of ways to decode s[0..i-1]
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1; // Empty string: one way (base case for recurrence)
    dp[1] = 1; // First character: valid as long as it's not '0' (checked above)

    for (int i = 2; i <= n; i++) {
        // Decode using the last single digit
        int oneDigit = s[i - 1] - '0';
        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] += dp[i - 1];
        }

        // Decode using the last two digits
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

// -------------------------------------------------------------
// Space-Optimised: O(1) — only need prev2 and prev1
// -------------------------------------------------------------
int decodeWaysOptimised(const std::string& s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;

    int prev2 = 1; // dp[i-2]: ways to decode s[0..i-3]
    int prev1 = 1; // dp[i-1]: ways to decode s[0..i-2]

    for (int i = 2; i <= n; i++) {
        int current = 0;

        int oneDigit  = s[i - 1] - '0';
        int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

        if (oneDigit >= 1) current += prev1;
        if (twoDigits >= 10 && twoDigits <= 26) current += prev2;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

// -------------------------------------------------------------
// Enumerate all actual decodings (for understanding the problem)
// -------------------------------------------------------------
void enumerate(const std::string& s, int index, std::string current,
               std::vector<std::string>& results) {
    if (index == (int)s.size()) {
        results.push_back(current);
        return;
    }
    if (s[index] == '0') return; // '0' alone is invalid

    // Take one digit
    char letter1 = 'A' + (s[index] - '0') - 1;
    enumerate(s, index + 1, current + letter1, results);

    // Take two digits
    if (index + 1 < (int)s.size()) {
        int twoDigits = (s[index] - '0') * 10 + (s[index + 1] - '0');
        if (twoDigits <= 26) {
            char letter2 = 'A' + twoDigits - 1;
            enumerate(s, index + 2, current + letter2, results);
        }
    }
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::cout << "=== Decode Ways ===" << std::endl;

    std::vector<std::string> tests = {"12", "226", "06", "11106", "2101"};

    for (const auto& s : tests) {
        std::cout << "\nEncoded: \"" << s << "\"" << std::endl;
        std::cout << "Ways (DP)        : " << decodeWays(s) << std::endl;
        std::cout << "Ways (Optimised) : " << decodeWaysOptimised(s) << std::endl;

        std::vector<std::string> decodings;
        enumerate(s, 0, "", decodings);
        std::cout << "Decodings        : ";
        if (decodings.empty()) {
            std::cout << "(none)";
        } else {
            for (auto& d : decodings) std::cout << "\"" << d << "\" ";
        }
        std::cout << std::endl;
    }

    return 0;
}
