#pragma once

#include <regex>
#include <string>

class Solution {
public:
  static bool isMatch(std::string s, std::string p) {
    const int n = s.size(), m = p.size();

    std::vector dp(n + 1, std::vector<bool>(m + 1));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
      dp[0][j] = p[j - 1] == '*' && dp[0][j - 2];
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (p[j - 1] == '*') {
          if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
            dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
          } else {
            dp[i][j] = dp[i][j - 2];
          }
        } else if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }

    return dp[n][m];
  }
};
