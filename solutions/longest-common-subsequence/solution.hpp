#pragma once

#include <string>
#include <vector>

/*
  1143. Longest Common Subsequence
  https://leetcode.com/problems/longest-common-subsequence/
  Difficulty: Medium
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int longestCommonSubsequence(std::string text1, std::string text2) {
    int n = text1.size(), m = text2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[n][m];
  }
};