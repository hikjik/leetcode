#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static int minFallingPathSum(const std::vector<std::vector<int>> &matrix) {
    const int n = matrix.size();
    std::vector<int> dp(n + 2);
    dp[0] = dp[n + 1] = INT_MAX;
    for (const auto &row : matrix) {
      std::vector<int> prev(dp);
      for (int j = 0; j < n; ++j) {
        dp[j + 1] = row[j] + std::min({prev[j], prev[j + 1], prev[j + 2]});
      }
    }
    return std::ranges::min(dp);
  }
};
