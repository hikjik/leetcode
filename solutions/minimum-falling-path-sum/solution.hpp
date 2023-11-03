#pragma once

#include <algorithm>
#include <limits>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minFallingPathSum(const std::vector<std::vector<int>> &matrix) {
    const int n = matrix.size();

    std::vector<int> dp(n + 2, 0);
    dp[0] = dp[n + 1] = std::numeric_limits<int>::max();
    for (int i = n - 1; i >= 0; --i) {
      std::vector<int> prev(dp);
      for (int j = 1; j < n + 1; ++j) {
        dp[j] =
            std::min({prev[j - 1], prev[j], prev[j + 1]}) + matrix[i][j - 1];
      }
    }
    return *std::min_element(dp.begin(), dp.end());
  }
};
