#pragma once

#include <string>
#include <string_view>
#include <vector>

// Time: O(NM)
// Space: O(NM)

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector memo(text1.size(), std::vector<int>(text2.size(), -1));

    std::function<int(std::string_view, std::string_view)> lcs =
        [&](std::string_view s1, std::string_view s2) -> int {
      if (s1.empty() || s2.empty()) {
        return 0;
      }
      auto &ans = memo[s1.size() - 1][s2.size() - 1];
      if (ans == -1) {
        if (s1[0] == s2[0]) {
          ans = 1 + lcs(s1.substr(1), s2.substr(1));
        } else {
          ans = std::max(lcs(s1, s2.substr(1)), lcs(s1.substr(1), s2));
        }
      }
      return ans;
    };

    return lcs(text1, text2);
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static int longestCommonSubsequence(std::string text1, std::string text2) {
    const int n = text1.size(), m = text2.size();
    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }
    return dp[n][m];
  }
};

} // namespace dp

namespace opt {

// Time: O(NM)
// Space: O(min(N,M))
class Solution {
public:
  static int longestCommonSubsequence(std::string text1, std::string text2) {
    if (text1.size() < text2.size()) {
      std::swap(text1, text2);
    }
    std::vector<int> dp(text2.size() + 1);
    for (int i = 1; i <= std::ssize(text1); ++i) {
      int prev = 0;
      for (int j = 1; j <= std::ssize(text2); ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[j] = 1 + std::exchange(prev, dp[j]);
        } else {
          prev = std::exchange(dp[j], std::max(dp[j - 1], dp[j]));
        }
      }
    }
    return dp.back();
  }
};

} // namespace opt
