#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static int numDistinct(std::string s, std::string t) {
    const auto n = s.size(), m = t.size();
    std::vector dp(n + 1, std::vector<unsigned long long>(m + 1, 0));

    for (size_t i = 0; i <= n; ++i) {
      dp[i][0] = 1;
    }

    for (size_t i = 1; i <= n; ++i) {
      for (size_t j = 1; j <= m; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[n][m];
  }
};
