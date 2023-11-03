#pragma once

#include <string>
#include <vector>

// Time: O(NM), where N is the length of s1, M is the length of s2
// Space: O(min(N, M))

namespace memo {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    std::vector memo(s1.size() + 1, std::vector<char>(s2.size() + 1, -1));
    memo[0][0] = 1;
    return isInterleave(std::string_view(s1), std::string_view(s2),
                        std::string_view(s3), &memo);
  }

private:
  static bool isInterleave(std::string_view s1, std::string_view s2,
                           std::string_view s3,
                           std::vector<std::vector<char>> *memo) {
    auto &cache = (*memo)[s1.size()][s2.size()];
    if (cache != -1) {
      return cache;
    }
    return cache = !s1.empty() && s1[0] == s3[0] &&
                       isInterleave(s1.substr(1), s2, s3.substr(1), memo) ||
                   !s2.empty() && s2[0] == s3[0] &&
                       isInterleave(s1, s2.substr(1), s3.substr(1), memo);
  }
};

} // namespace memo

namespace dp {

// Time: O(NM)
// Space: O(NM)
class Solution {
public:
  static bool isInterleave(std::string s1, std::string s2, std::string s3) {
    const int n = s1.size(), m = s2.size(), k = s3.size();
    if (n + m != k) {
      return false;
    }

    std::vector dp(n + 1, std::vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
      dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
    }
    for (int j = 0; j < m; ++j) {
      dp[0][j + 1] = dp[0][j] && s2[j] == s3[j];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && dp[i][j + 1]) ||
                           (s2[j] == s3[i + j + 1] && dp[i + 1][j]);
      }
    }
    return dp[n][m];
  }
};

} // namespace dp

namespace optimized {

// Time: O(NM)
// Space: O(min(N, M))
class Solution {
public:
  static bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }
    if (s2.size() > s1.size()) {
      std::swap(s1, s2);
    }
    std::vector<bool> dp(s2.size() + 1);
    for (int i = 0; i <= std::ssize(s1); ++i) {
      for (int j = 0; j <= std::ssize(s2); ++j) {
        if (i == 0 && j == 0) {
          dp[j] = true;
        } else {
          dp[j] = i && s1[i - 1] == s3[i + j - 1] && dp[j] ||
                  j && s2[j - 1] == s3[i + j - 1] && dp[j - 1];
        }
      }
    }
    return dp.back();
  }
};

} // namespace optimized
