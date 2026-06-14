// =============================================================
// Dynamic Programming: Word Break Problem
// =============================================================
// Given a string s and a dictionary of words, determine if s
// can be segmented into a sequence of dictionary words.
//
// Subproblem: dp[i] = true if s[0..i-1] can be segmented
//
// Recurrence:
//   dp[0] = true  (empty string is always valid)
//   dp[i] = OR over j in [0, i-1] of:
//           dp[j] AND s[j..i-1] is in dictionary
//
// Time:  O(n^2 * L) where L = avg word length  |  Space: O(n)
// =============================================================

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// -------------------------------------------------------------
// Part 1: Can the string be segmented? (true/false)
// -------------------------------------------------------------
bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
    int n = s.size();
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

    // dp[i] = true if s[0..i-1] can be segmented using the dictionary
    std::vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty prefix is always valid

    for (int i = 1; i <= n; i++) {
        // Try every possible last word s[j..i-1]
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break; // No need to check further once true
            }
        }
    }

    return dp[n];
}

// -------------------------------------------------------------
// Part 2: Find all valid segmentations (backtracking + DP)
// DP memoises which positions can be reached to prune the search.
// -------------------------------------------------------------
void backtrack(const std::string& s,
               const std::unordered_set<std::string>& dict,
               int start,
               std::vector<std::string>& current,
               std::vector<std::string>& results) {
    if (start == (int)s.size()) {
        // Assembled a complete valid segmentation
        std::string sentence;
        for (int i = 0; i < (int)current.size(); i++) {
            if (i > 0) sentence += " ";
            sentence += current[i];
        }
        results.push_back(sentence);
        return;
    }

    for (int end = start + 1; end <= (int)s.size(); end++) {
        std::string word = s.substr(start, end - start);
        if (dict.count(word)) {
            current.push_back(word);
            backtrack(s, dict, end, current, results);
            current.pop_back(); // Undo choice
        }
    }
}

std::vector<std::string> wordBreakAll(const std::string& s,
                                      const std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

    // First check feasibility to avoid exponential backtracking on impossible inputs
    if (!wordBreak(s, wordDict)) return {};

    std::vector<std::string> results;
    std::vector<std::string> current;
    backtrack(s, dict, 0, current, results);
    return results;
}

// -------------------------------------------------------------
// Part 3: Count distinct segmentations
// -------------------------------------------------------------
int wordBreakCount(const std::string& s, const std::vector<std::string>& wordDict) {
    int n = s.size();
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

    // dp[i] = number of ways to segment s[0..i-1]
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] > 0 && dict.count(s.substr(j, i - j))) {
                dp[i] += dp[j];
            }
        }
    }

    return dp[n];
}

// -------------------------------------------------------------
// Example Usage
// -------------------------------------------------------------
int main() {
    std::cout << "=== Word Break Problem ===" << std::endl;

    // Test 1
    {
        std::string s = "leetcode";
        std::vector<std::string> dict = {"leet", "code"};
        std::cout << "\ns = \"" << s << "\", dict = {leet, code}" << std::endl;
        std::cout << "Can segment: " << (wordBreak(s, dict) ? "Yes" : "No") << std::endl;
        std::cout << "Count      : " << wordBreakCount(s, dict) << std::endl;
        for (auto& seg : wordBreakAll(s, dict)) std::cout << "  \"" << seg << "\"" << std::endl;
    }

    // Test 2
    {
        std::string s = "catsanddog";
        std::vector<std::string> dict = {"cat", "cats", "and", "sand", "dog"};
        std::cout << "\ns = \"" << s << "\", dict = {cat, cats, and, sand, dog}" << std::endl;
        std::cout << "Can segment: " << (wordBreak(s, dict) ? "Yes" : "No") << std::endl;
        std::cout << "Count      : " << wordBreakCount(s, dict) << std::endl;
        for (auto& seg : wordBreakAll(s, dict)) std::cout << "  \"" << seg << "\"" << std::endl;
    }

    // Test 3 — impossible
    {
        std::string s = "applepenapple";
        std::vector<std::string> dict = {"apple", "pen"};
        std::cout << "\ns = \"" << s << "\", dict = {apple, pen}" << std::endl;
        std::cout << "Can segment: " << (wordBreak(s, dict) ? "Yes" : "No") << std::endl;
        for (auto& seg : wordBreakAll(s, dict)) std::cout << "  \"" << seg << "\"" << std::endl;
    }

    return 0;
}
