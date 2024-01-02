#pragma once

#include <ranges>
#include <string>
#include <vector>

// K = strs.size(), L = strs[i].size()
// Time: O(MNK+KL)
// Space: O(MN)

class Solution {
public:
  static int findMaxForm(const std::vector<std::string> &strs, int m, int n) {
    std::vector dp(m + 1, std::vector<int>(n + 1));
    for (const auto &s : strs) {
      const int zeros = std::ranges::count(s, '0');
      const int ones = s.size() - zeros;
      for (int i = m; i >= zeros; --i) {
        for (int j = n; j >= ones; --j) {
          dp[i][j] = std::max(dp[i][j], 1 + dp[i - zeros][j - ones]);
        }
      }
    }
    return dp[m][n];
  }
};
