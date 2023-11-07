#pragma once

#include <algorithm>
#include <vector>

// Time: O(N^2)
// Space: O(N)

class Solution {
public:
  static int minimumTotal(const std::vector<std::vector<int>> &triangle) {
    std::vector<int> dp(triangle.size() + 1);
    for (int i = dp.size() - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    return dp[0];
  }
};
