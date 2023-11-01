#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  664. Strange Printer
  https://leetcode.com/problems/strange-printer/
  Difficulty: Hard
  Tags: String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int strangePrinter(std::string s) {
    const int n = s.size();

    std::vector dp(n, std::vector<int>(n, n));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int j = 0; j < n; ++j) {
      for (int i = j; i >= 0; --i) {
        for (int k = i; k < j; ++k) {
          dp[i][j] =
              std::min(dp[i][j], dp[i][k] + dp[k + 1][j] - (s[k] == s[j]));
        }
      }
    }

    return dp[0][n - 1];
  }
};
