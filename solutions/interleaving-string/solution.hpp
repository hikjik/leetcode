#pragma once

#include <string>
#include <vector>

/*
  97. Interleaving String
  https://leetcode.com/problems/interleaving-string/
  Difficulty: Medium
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static bool isInterleave(std::string s1, std::string s2, std::string s3) {
    const auto n = s1.size(), m = s2.size();
    if (n + m != s3.size()) {
      return false;
    }

    std::vector dp(n + 1, std::vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (size_t i = 0; i < n; ++i) {
      dp[i + 1][0] = dp[i][0] && s1[i] == s3[i];
    }
    for (size_t j = 0; j < m; ++j) {
      dp[0][j + 1] = dp[0][j] && s2[j] == s3[j];
    }
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < m; ++j) {
        dp[i + 1][j + 1] = (s1[i] == s3[i + j + 1] && dp[i][j + 1]) ||
                           (s2[j] == s3[i + j + 1] && dp[i + 1][j]);
      }
    }
    return dp[n][m];
  }
};
