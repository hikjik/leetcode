#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minimumTotal(const std::vector<std::vector<int>> &triangle) {
    int n = triangle.back().size();

    std::vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
      }
    }
    return dp[0];
  }
};
